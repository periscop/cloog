
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
 * This library is free software; you can redistribute it and/or              *
 * modify it under the terms of the GNU Lesser General Public                 *
 * License as published by the Free Software Foundation; either               *
 * version 2.1 of the License, or (at your option) any later version.         *
 *                                                                            *
 * This library is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU          *
 * Lesser General Public License for more details.                            *
 *                                                                            *
 * You should have received a copy of the GNU Lesser General Public           *
 * License along with this library; if not, write to the Free Software        *
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,                         *
 * Boston, MA  02110-1301  USA                                                *
 *                                                                            *
 * CLooG, the Chunky Loop Generator                                           *
 * Written by Cedric Bastoul, Cedric.Bastoul@inria.fr                         *
 *                                                                            *
 ******************************************************************************/
/* CAUTION: the english used for comments is probably the worst you ever read,
 *          please feel free to correct and improve it !
 */

/* June    22nd 2005: General adaptation for GMP.
 * October 26th 2005: General adaptation from CloogDomain to Matrix data
 *                    structure for all constraint systems.
 * October 27th 2005: General adaptation from CloogEqual to Matrix data
 *                    structure for equality spreading.
 */

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
#include <assert.h>
# include "../include/cloog/cloog.h"

#ifdef OSL_SUPPORT
#include <osl/util.h>
#include <osl/body.h>
#include <osl/statement.h>
#include <osl/scop.h>
#endif


static void pprint_name(FILE *dst, struct clast_name *n);
static void pprint_term(struct cloogoptions *i, FILE *dst, struct clast_term *t);
static void pprint_sum(struct cloogoptions *opt,
			FILE *dst, struct clast_reduction *r);
static void pprint_binary(struct cloogoptions *i,
			FILE *dst, struct clast_binary *b);
static void pprint_minmax_f(struct cloogoptions *info,
			FILE *dst, struct clast_reduction *r);
static void pprint_minmax_c(struct cloogoptions *info,
			FILE *dst, struct clast_reduction *r);
static void pprint_reduction(struct cloogoptions *i,
			FILE *dst, struct clast_reduction *r);
static void pprint_expr(struct cloogoptions *i, FILE *dst, struct clast_expr *e);
static void pprint_equation(struct cloogoptions *i,
			FILE *dst, struct clast_equation *eq);
static void pprint_assignment(struct cloogoptions *i, FILE *dst, 
			struct clast_assignment *a);
static void pprint_user_stmt(struct cloogoptions *options, FILE *dst,
		       struct clast_user_stmt *u);
static void pprint_guard(struct cloogoptions *options, FILE *dst, int indent,
		   struct clast_guard *g);
static void pprint_for(struct cloogoptions *options, FILE *dst, int indent,
		 struct clast_for *f);
static void pprint_stmt_list(struct cloogoptions *options, FILE *dst, int indent,
		       struct clast_stmt *s);


void pprint_name(FILE *dst, struct clast_name *n)
{
    fprintf(dst, "%s", n->name);
}

/**
 * This function returns a string containing the printing of a value (possibly
 * an iterator or a parameter with its coefficient or a constant).
 * - val is the coefficient or constant value,
 * - name is a string containing the name of the iterator or of the parameter,
 */
void pprint_term(struct cloogoptions *i, FILE *dst, struct clast_term *t)
{
    if (t->var) {
	int group = t->var->type == clast_expr_red &&
		    ((struct clast_reduction*) t->var)->n > 1;
	if (cloog_int_is_one(t->val))
	    ;
	else if (cloog_int_is_neg_one(t->val))
	    fprintf(dst, "-");
        else {
	    cloog_int_print(dst, t->val);
	    fprintf(dst, "*");
	}
	if (group)
	    fprintf(dst, "(");
	pprint_expr(i, dst, t->var);
	if (group)
	    fprintf(dst, ")");
    } else
	cloog_int_print(dst, t->val);
}

void pprint_sum(struct cloogoptions *opt, FILE *dst, struct clast_reduction *r)
{
    int i;
    struct clast_term *t;

    assert(r->n >= 1);
    assert(r->elts[0]->type == clast_expr_term);
    t = (struct clast_term *) r->elts[0];
    pprint_term(opt, dst, t);

    for (i = 1; i < r->n; ++i) {
	assert(r->elts[i]->type == clast_expr_term);
	t = (struct clast_term *) r->elts[i];
	if (cloog_int_is_pos(t->val))
	    fprintf(dst, "+");
	pprint_term(opt, dst, t);
    }
}

void pprint_binary(struct cloogoptions *i, FILE *dst, struct clast_binary *b)
{
    const char *s1 = NULL, *s2 = NULL, *s3 = NULL;
    int group = b->LHS->type == clast_expr_red &&
		((struct clast_reduction*) b->LHS)->n > 1;
    if (i->language == CLOOG_LANGUAGE_FORTRAN) {
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
	pprint_sum(i, dst, r);
	break;
    case clast_red_min:
    case clast_red_max:
	if (r->n == 1) {
	    pprint_expr(i, dst, r->elts[0]);
	    break;
	}
	if (i->language == CLOOG_LANGUAGE_FORTRAN)
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
    case clast_expr_name:
	pprint_name(dst, (struct clast_name*) e);
	break;
    case clast_expr_term:
	pprint_term(i, dst, (struct clast_term*) e);
	break;
    case clast_expr_red:
	pprint_reduction(i, dst, (struct clast_reduction*) e);
	break;
    case clast_expr_bin:
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


/**
 * pprint_osl_body function:
 * this function pretty-prints the OpenScop body of a given statement.
 * It returns 1 if it succeeds to find an OpenScop body to print for
 * that statement, 0 otherwise.
 * \param[in] options CLooG Options.
 * \param[in] dst     Output stream.
 * \param[in] u       Statement to print the OpenScop body.
 * \return 1 on success to pretty-print an OpenScop body for u, 0 otherwise.
 */
int pprint_osl_body(struct cloogoptions *options, FILE *dst,
                    struct clast_user_stmt *u) {
#ifdef OSL_SUPPORT
  int i;
  char *expr, *tmp;
  struct clast_stmt *t;
  osl_scop_p scop = options->scop;
  osl_statement_p stmt;
  osl_body_p body;

  if ((scop != NULL) &&
      (osl_statement_number(scop->statement) >= u->statement->number)) {
    stmt = scop->statement;

    /* Go to the convenient statement in the SCoP. */
    for (i = 1; i < u->statement->number; i++)
      stmt = stmt->next;

    /* Ensure it has a printable body. */
    if ((osl_generic_has_URI(stmt->body, OSL_URI_BODY)) &&
        ((body = stmt->body->data) != NULL) &&
        (body->expression != NULL) &&
        (body->iterators != NULL)) {
      expr = osl_util_identifier_substitution(body->expression->string[0],
                                              body->iterators->string);
      tmp = expr;
      /* Print the body expression, substituting the @...@ markers. */
      while (*expr) {
        if (*expr == '@') {
          int iterator;
          expr += sscanf(expr, "@%d", &iterator) + 2; /* 2 for the @s */
          t = u->substitutions;
          for (i = 0; i < iterator; i++)
            t = t->next;
          pprint_assignment(options, dst, (struct clast_assignment *)t);
        } else {
          fprintf(dst, "%c", *expr++);
        }
      }
      fprintf(dst, "\n");
      free(tmp);
      return 1;
    }
  }
#endif
  return 0;
}

void pprint_user_stmt(struct cloogoptions *options, FILE *dst,
		       struct clast_user_stmt *u)
{
    struct clast_stmt *t;

    if (pprint_osl_body(options, dst, u))
      return;
    
    if (u->statement->name)
	fprintf(dst, "%s", u->statement->name);
    else
	fprintf(dst, "S%d", u->statement->number);
    fprintf(dst, "(");
    for (t = u->substitutions; t; t = t->next) {
	assert(CLAST_STMT_IS_A(t, stmt_ass));
	pprint_assignment(options, dst, (struct clast_assignment *)t);
	if (t->next)
	    fprintf(dst, ",");
    }
    fprintf(dst, ")");
    if (options->language != CLOOG_LANGUAGE_FORTRAN)
	fprintf(dst, ";");
    fprintf(dst, "\n");
}

void pprint_guard(struct cloogoptions *options, FILE *dst, int indent,
		   struct clast_guard *g)
{
    int k;
    if (options->language == CLOOG_LANGUAGE_FORTRAN)
	fprintf(dst,"IF ");
    else
	fprintf(dst,"if ");
    if (g->n > 1)
	fprintf(dst,"(");
    for (k = 0; k < g->n; ++k) {
	if (k > 0) {
	    if (options->language == CLOOG_LANGUAGE_FORTRAN)
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
    if (options->language == CLOOG_LANGUAGE_FORTRAN)
	fprintf(dst," THEN\n");
    else
	fprintf(dst," {\n");

    pprint_stmt_list(options, dst, indent + INDENT_STEP, g->then);

    fprintf(dst, "%*s", indent, "");
    if (options->language == CLOOG_LANGUAGE_FORTRAN)
	fprintf(dst,"END IF\n"); 
    else
	fprintf(dst,"}\n"); 
}

void pprint_for(struct cloogoptions *options, FILE *dst, int indent,
		 struct clast_for *f)
{
    if (options->language == CLOOG_LANGUAGE_FORTRAN)
	fprintf(dst, "DO ");
    else
	fprintf(dst, "for (");

    if (f->LB) {
	fprintf(dst, "%s=", f->iterator);
	pprint_expr(options, dst, f->LB);
    } else if (options->language == CLOOG_LANGUAGE_FORTRAN)
	cloog_die("unbounded loops not allowed in FORTRAN.\n");

    if (options->language == CLOOG_LANGUAGE_FORTRAN)
	fprintf(dst,", ");
    else
	fprintf(dst,";");

    if (f->UB) { 
	if (options->language != CLOOG_LANGUAGE_FORTRAN)
	    fprintf(dst,"%s<=", f->iterator);
	pprint_expr(options, dst, f->UB);
    } else if (options->language == CLOOG_LANGUAGE_FORTRAN)
	cloog_die("unbounded loops not allowed in FORTRAN.\n");

    if (options->language == CLOOG_LANGUAGE_FORTRAN) {
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
    if (options->language == CLOOG_LANGUAGE_FORTRAN)
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
	    if (options->language != CLOOG_LANGUAGE_FORTRAN)
		fprintf(dst, ";");
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

void clast_pprint(FILE *foo, struct clast_stmt *root,
		  int indent, CloogOptions *options)
{
    pprint_stmt_list(options, foo, indent, root);
}
