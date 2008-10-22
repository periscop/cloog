
   /**-------------------------------------------------------------------**
    **                              CLooG                                **
    **-------------------------------------------------------------------**
    **                             pprint.c                              **
    **-------------------------------------------------------------------**
    **                  First version: october 26th 2001                 **
    **-------------------------------------------------------------------**/


/******************************************************************************
 *               CLooG : the Chunky Loop Generator (experimental)             *
 ******************************************************************************
 *                                                                            *
 * Copyright (C) 2001-2005 Cedric Bastoul                                     *
 *                                                                            *
 * This is free software; you can redistribute it and/or modify it under the  *
 * terms of the GNU General Public License as published by the Free Software  *
 * Foundation; either version 2 of the License, or (at your option) any later *
 * version.                                                                   *
 *                                                                            *
 * This software is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY *
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License   *
 * for more details.                                                          *
 *                                                                            *
 * You should have received a copy of the GNU General Public License along    *
 * with software; if not, write to the Free Software Foundation, Inc.,        *
 * 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA                     *
 *                                                                            *
 * CLooG, the Chunky Loop Generator                                           *
 * Written by Cedric Bastoul, Cedric.Bastoul@inria.fr                         *
 *                                                                            *
 ******************************************************************************/
/* CAUTION: the english used for comments is probably the worst you ever read,
 *          please feel free to correct and improve it !
 */

/* June    22nd 2005: General adaptation for GMP.
 * October 26th 2005: General adaptation from CloogDomain to CloogMatrix data 
 *                    structure for all constraint systems.
 * October 27th 2005: General adaptation from CloogEqual to CloogMatrix data 
 *                    structure for equality spreading.
 */

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
#include <assert.h>
# include "../include/cloog/cloog.h"


/******************************************************************************
 *                             Types                                          *
 ******************************************************************************/



/**
 * This function returns a string containing the printing of a value (possibly
 * an iterator or a parameter with its coefficient or a constant).
 * - val is the coefficient or constant value,
 * - name is a string containing the name of the iterator or of the parameter,
 */
void pprint_term(FILE *dst, struct clast_term *t)
{
    if (t->var) {
	if (cloog_int_is_one(t->val))
	    fprintf(dst, "%s", t->var);
	else if (cloog_int_is_neg_one(t->val))
	    fprintf(dst, "-%s", t->var);
        else {
	    cloog_int_print(dst, t->val);
	    fprintf(dst, "*%s", t->var);
	}
    } else
	cloog_int_print(dst, t->val);
}

void pprint_sum(FILE *dst, struct clast_reduction *r)
{
    int i;
    struct clast_term *t;

    assert(r->n >= 1);
    assert(r->elts[0]->type == expr_term);
    t = (struct clast_term *) r->elts[0];
    pprint_term(dst, t);

    for (i = 1; i < r->n; ++i) {
	assert(r->elts[i]->type == expr_term);
	t = (struct clast_term *) r->elts[i];
	if (cloog_int_is_pos(t->val))
	    fprintf(dst, "+");
	pprint_term(dst, t);
    }
}

void pprint_expr(struct cloogoptions *i, FILE *dst, struct clast_expr *e);

void pprint_binary(struct cloogoptions *i, FILE *dst, struct clast_binary *b)
{
    const char *s1 = NULL, *s2 = NULL, *s3 = NULL;
    int group = b->LHS->type == expr_red && 
		((struct clast_reduction*) b->LHS)->n > 1;
    if (i->language == LANGUAGE_FORTRAN) {
	switch (b->type) {
	case clast_bin_fdiv:
	    s1 = "FLOOR(REAL(", s2 = ")/REAL(", s3 = "))";
	    break;
	case clast_bin_cdiv:
	    s1 = "CEILING(REAL(", s2 = ")/REAL(", s3 = "))";
	    break;
	case clast_bin_div:
	    if (group)
		s1 = "(", s2 = ")/", s3 = "";
	    else
		s1 = "", s2 = "/", s3 = "";
	    break;
	case clast_bin_mod:
	    s1 = "MOD(", s2 = ", ", s3 = ")";
	    break;
	}
    } else {
	switch (b->type) {
	case clast_bin_fdiv:
	    s1 = "floord(", s2 = ",", s3 = ")";
	    break;
	case clast_bin_cdiv:
	    s1 = "ceild(", s2 = ",", s3 = ")";
	    break;
	case clast_bin_div:
	    if (group)
		s1 = "(", s2 = ")/", s3 = "";
	    else
		s1 = "", s2 = "/", s3 = "";
	    break;
	case clast_bin_mod:
	    if (group)
		s1 = "(", s2 = ")%", s3 = "";
	    else
		s1 = "", s2 = "%", s3 = "";
	    break;
	}
    }
    fprintf(dst, "%s", s1);
    pprint_expr(i, dst, b->LHS);
    fprintf(dst, "%s", s2);
    cloog_int_print(dst, b->RHS);
    fprintf(dst, "%s", s3);
}

void pprint_minmax_f(struct cloogoptions *info, FILE *dst, struct clast_reduction *r)
{
    int i;
    if (r->n == 0)
	return;
    fprintf(dst, r->type == clast_red_max ? "MAX(" : "MIN(");
    pprint_expr(info, dst, r->elts[0]);
    for (i = 1; i < r->n; ++i) {
	fprintf(dst, ",");
	pprint_expr(info, dst, r->elts[i]);
    }
    fprintf(dst, ")");
}

void pprint_minmax_c(struct cloogoptions *info, FILE *dst, struct clast_reduction *r)
{
    int i;
    for (i = 1; i < r->n; ++i)
	fprintf(dst, r->type == clast_red_max ? "max(" : "min(");
    if (r->n > 0)
	pprint_expr(info, dst, r->elts[0]);
    for (i = 1; i < r->n; ++i) {
	fprintf(dst, ",");
	pprint_expr(info, dst, r->elts[i]);
	fprintf(dst, ")");
    }
}

void pprint_reduction(struct cloogoptions *i, FILE *dst, struct clast_reduction *r)
{
    switch (r->type) {
    case clast_red_sum:
	pprint_sum(dst, r);
	break;
    case clast_red_min:
    case clast_red_max:
	if (r->n == 1) {
	    pprint_expr(i, dst, r->elts[0]);
	    break;
	}
	if (i->language == LANGUAGE_FORTRAN)
	    pprint_minmax_f(i, dst, r);
	else
	    pprint_minmax_c(i, dst, r);
	break;
    default:
	assert(0);
    }
}

void pprint_expr(struct cloogoptions *i, FILE *dst, struct clast_expr *e)
{
    if (!e)
	return;
    switch (e->type) {
    case expr_term:
	pprint_term(dst, (struct clast_term*) e);
	break;
    case expr_red:
	pprint_reduction(i, dst, (struct clast_reduction*) e);
	break;
    case expr_bin:
	pprint_binary(i, dst, (struct clast_binary*) e);
	break;
    default:
	assert(0);
    }
}

void pprint_equation(struct cloogoptions *i, FILE *dst, struct clast_equation *eq)
{
    pprint_expr(i, dst, eq->LHS);
    if (eq->sign == 0)
	fprintf(dst, " == ");
    else if (eq->sign > 0)
	fprintf(dst, " >= ");
    else
	fprintf(dst, " <= ");
    pprint_expr(i, dst, eq->RHS);
}

void pprint_assignment(struct cloogoptions *i, FILE *dst, 
			struct clast_assignment *a)
{
    if (a->LHS)
	fprintf(dst, "%s = ", a->LHS);
    pprint_expr(i, dst, a->RHS);
}

void pprint_user_stmt(struct cloogoptions *options, FILE *dst,
		       struct clast_user_stmt *u)
{
    struct clast_stmt *t;
    fprintf(dst, "S%d", u->statement->number);
    if (options->cpp || u->substitutions)
	fprintf(dst, "(");
    for (t = u->substitutions; t; t = t->next) {
	assert(CLAST_STMT_IS_A(t, stmt_ass));
	pprint_assignment(options, dst, (struct clast_assignment *)t);
	if (t->next)
	    fprintf(dst, ",");
    }
    if (options->cpp || u->substitutions)
	fprintf(dst, ")");
    if (options->language != LANGUAGE_FORTRAN)
	fprintf(dst, " ;");
    fprintf(dst, "\n");
}

void pprint_stmt_list(struct cloogoptions *options, FILE *dst, int indent,
		       struct clast_stmt *s);

void pprint_guard(struct cloogoptions *options, FILE *dst, int indent,
		   struct clast_guard *g)
{
    int k;
    if (options->language == LANGUAGE_FORTRAN)
	fprintf(dst,"IF ");
    else
	fprintf(dst,"if ");
    if (g->n > 1)
	fprintf(dst,"(");
    for (k = 0; k < g->n; ++k) {
	if (k > 0) {
	    if (options->language == LANGUAGE_FORTRAN)
		fprintf(dst," .AND. ");
	    else
		fprintf(dst," && ");
	}
	fprintf(dst,"(");
        pprint_equation(options, dst, &g->eq[k]);
	fprintf(dst,")");
    }
    if (g->n > 1)
	fprintf(dst,")");
    if (options->language == LANGUAGE_FORTRAN)
	fprintf(dst," THEN\n");
    else
	fprintf(dst," {\n");

    pprint_stmt_list(options, dst, indent + INDENT_STEP, g->then);

    fprintf(dst, "%*s", indent, "");
    if (options->language == LANGUAGE_FORTRAN)
	fprintf(dst,"END IF\n"); 
    else
	fprintf(dst,"}\n"); 
}

void pprint_for(struct cloogoptions *options, FILE *dst, int indent,
		 struct clast_for *f)
{
    if (options->language == LANGUAGE_FORTRAN)
	fprintf(dst, "DO ");
    else
	fprintf(dst, "for (");

    if (f->LB) {
	fprintf(dst, "%s=", f->iterator);
	pprint_expr(options, dst, f->LB);
    } else if (options->language == LANGUAGE_FORTRAN)
	cloog_die("unbounded loops not allowed in FORTRAN.\n");

    if (options->language == LANGUAGE_FORTRAN)
	fprintf(dst,", ");
    else
	fprintf(dst,";");

    if (f->UB) { 
	if (options->language != LANGUAGE_FORTRAN)
	    fprintf(dst,"%s<=", f->iterator);
	pprint_expr(options, dst, f->UB);
    } else if (options->language == LANGUAGE_FORTRAN)
	cloog_die("unbounded loops not allowed in FORTRAN.\n");

    if (options->language == LANGUAGE_FORTRAN) {
	if (cloog_int_gt_si(f->stride, 1))
	    cloog_int_print(dst, f->stride);
	fprintf(dst,"\n");
    }
    else {
	if (cloog_int_gt_si(f->stride, 1)) {
	    fprintf(dst,";%s+=", f->iterator);
	    cloog_int_print(dst, f->stride);
	    fprintf(dst, ") {\n");
      } else
	fprintf(dst, ";%s++) {\n", f->iterator);
    }

    pprint_stmt_list(options, dst, indent + INDENT_STEP, f->body);

    fprintf(dst, "%*s", indent, "");
    if (options->language == LANGUAGE_FORTRAN)
	fprintf(dst,"END DO\n") ; 
    else
	fprintf(dst,"}\n") ; 
}

void pprint_stmt_list(struct cloogoptions *options, FILE *dst, int indent,
		       struct clast_stmt *s)
{
    for ( ; s; s = s->next) {
	if (CLAST_STMT_IS_A(s, stmt_root))
	    continue;
	fprintf(dst, "%*s", indent, "");
	if (CLAST_STMT_IS_A(s, stmt_ass)) {
	    pprint_assignment(options, dst, (struct clast_assignment *) s);
	    if (options->language != LANGUAGE_FORTRAN)
		fprintf(dst, " ;");
	    fprintf(dst, "\n");
	} else if (CLAST_STMT_IS_A(s, stmt_user)) {
	    pprint_user_stmt(options, dst, (struct clast_user_stmt *) s);
	} else if (CLAST_STMT_IS_A(s, stmt_for)) {
	    pprint_for(options, dst, indent, (struct clast_for *) s);
	} else if (CLAST_STMT_IS_A(s, stmt_guard)) {
	    pprint_guard(options, dst, indent, (struct clast_guard *) s);
	} else if (CLAST_STMT_IS_A(s, stmt_block)) {
	    fprintf(dst, "{\n");
	    pprint_stmt_list(options, dst, indent + INDENT_STEP, 
				((struct clast_block *)s)->body);
	    fprintf(dst, "%*s", indent, "");
	    fprintf(dst, "}\n");
	} else {
	    assert(0);
	}
    }
}


/******************************************************************************
 *                       Pretty Printing (dirty) functions                    *
 ******************************************************************************/

void pprint(FILE *foo, struct clast_stmt *root, int indent, CloogOptions *options)
{
    pprint_stmt_list(options, foo, indent, root);
}
