
   /**-------------------------------------------------------------------**
    **                               CLooG                               **
    **-------------------------------------------------------------------**
    **                             domain.h                              **
    **-------------------------------------------------------------------**
    **                  First version: october 28th 2001                 **
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


#ifndef CLOOG_DOMAIN_H
#define CLOOG_DOMAIN_H
#if defined(__cplusplus)
extern "C" 
  {
#endif 


#ifdef CLOOG_POLYLIB
#include <cloog/polylib/domain.h>
#else
struct cloogdomain;
typedef struct cloogdomain CloogDomain ;
#endif


/**
 * CloogDomainList structure:
 * this structure reprensents a node of a linked list of CloogDomain structures.
 */
struct cloogdomainlist
{ CloogDomain * domain ;         /**< An element of the list. */
  struct cloogdomainlist * next ;/**< Pointer to the next element of the list.*/
} ;
typedef struct cloogdomainlist CloogDomainList ;


/******************************************************************************
 *                              PolyLib interface                             *
 ******************************************************************************/
void          cloog_domain_print(FILE *, CloogDomain *) ;
void          cloog_domain_print_constraints(FILE *, CloogDomain *,
						int print_number);
void          cloog_domain_free(CloogDomain *) ;
CloogDomain * cloog_domain_copy(CloogDomain *) ;
CloogDomain * cloog_domain_convex(CloogDomain * Pol) ;
CloogDomain * cloog_domain_simple_convex(CloogDomain * domain, int nb_par);
CloogDomain * cloog_domain_simplify(CloogDomain *, CloogDomain *) ;
CloogDomain * cloog_domain_union(CloogDomain *, CloogDomain *) ;
CloogDomain * cloog_domain_intersection(CloogDomain *, CloogDomain *) ;
CloogDomain * cloog_domain_difference(CloogDomain *, CloogDomain *) ;
CloogDomain * cloog_domain_addconstraints(CloogDomain *, CloogDomain *) ;
void          cloog_domain_sort(CloogDomain**,unsigned,unsigned,unsigned,int *);
CloogDomain * cloog_domain_empty(int) ;


/******************************************************************************
 *                          Structure display function                        *
 ******************************************************************************/
void cloog_domain_print_structure(FILE *file, CloogDomain *domain, int level,
				  const char *name);
void cloog_domain_list_print(FILE *, CloogDomainList *) ;


/******************************************************************************
 *                         Memory deallocation function                       *
 ******************************************************************************/
void cloog_domain_list_free(CloogDomainList *) ;


/*+****************************************************************************
 *                               Reading function                             *
 ******************************************************************************/
CloogDomain * cloog_domain_read(FILE *) ;
CloogDomain * cloog_domain_union_read(FILE *) ;
CloogDomainList * cloog_domain_list_read(FILE *) ;


/******************************************************************************
 *                            Processing functions                            *
 ******************************************************************************/
CloogConstraints *cloog_domain_constraints(CloogDomain *);
int           cloog_domain_isempty(CloogDomain *) ;
int           cloog_domain_universe(CloogDomain *) ;
CloogDomain * cloog_domain_project(CloogDomain *, int, int) ;
CloogDomain * cloog_domain_extend(CloogDomain *, int, int) ;
int           cloog_domain_never_integral(CloogDomain *) ;
void          cloog_domain_stride(CloogDomain *, int, int, cloog_int_t *, cloog_int_t *);
int           cloog_domain_integral_lowerbound(CloogDomain *, int, cloog_int_t *);
void          cloog_domain_lowerbound_update(CloogDomain *, int, cloog_int_t);
int           cloog_domain_lazy_disjoint(CloogDomain *, CloogDomain *) ;
int           cloog_domain_lazy_equal(CloogDomain *, CloogDomain *) ;
int           cloog_domain_lazy_block(CloogDomain *, CloogDomain *,
                                      CloogDomainList *, int) ;
int           cloog_domain_lazy_isscalar(CloogDomain *, int) ;
int           cloog_domain_list_lazy_same(CloogDomainList *) ;
void          cloog_domain_scalar(CloogDomain *, int, cloog_int_t *);
CloogDomain * cloog_domain_cut_first(CloogDomain *) ;
CloogDomain * cloog_domain_erase_dimension(CloogDomain *, int) ;

int           cloog_domain_dimension(CloogDomain *) ;
int           cloog_domain_isconvex(CloogDomain *) ;
int           cloog_scattering_fully_specified(CloogDomain *scattering,
						CloogDomain *domain);

#if defined(__cplusplus)
  }
#endif 
#endif /* define _H */
