
   /**-------------------------------------------------------------------**
    **                               CLooG                               **
    **-------------------------------------------------------------------**
    **                             matrix.h                              **
    **-------------------------------------------------------------------**
    **                    First version: april 17th 2005                 **
    **-------------------------------------------------------------------**/


/******************************************************************************
 *               CLooG : the Chunky Loop Generator (experimental)             *
 ******************************************************************************
 *                                                                            *
 * Copyright (C) 2005 Cedric Bastoul                                          *
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


#ifndef CLOOG_MATRIX_H
#define CLOOG_MATRIX_H
#if defined(__cplusplus)
extern "C" 
  {
#endif 


/* The Matrix structure comes directly from PolyLib (defined in polylib/types.h)
 * here is how it looks like (at least in PolyLib 5.20.0 version).
 *
 * typedef struct matrix {
 *  unsigned NbRows;    // The number of rows (= NbConstraints in Polyhedron).
 *  unsigned NbColumns; // The number of columns (= Dimension+2 in Polyhedron).
 *  Value **p;          // An array of pointers to the beginning of each row.
 *  Value *p_Init;      // The matrix is stored here, contiguously in memory.
 *  int p_Init_size;    // Needed to free the memory allocated by mpz_init.
 *  Matrix;
 */

typedef Matrix CloogMatrix;
typedef Matrix CloogConstraints;

struct cloogequalities {
	CloogConstraints	*constraints;
	int			*types;
};
typedef struct cloogequalities CloogEqualities;

/******************************************************************************
 *                              PolyLib interface                             *
 ******************************************************************************/
void          cloog_matrix_print(FILE *, CloogMatrix *) ;
void          cloog_matrix_free(CloogMatrix *) ;
CloogMatrix * cloog_matrix_alloc(unsigned, unsigned) ;
CloogMatrix * cloog_matrix_matrix(Matrix *);


/******************************************************************************
 *                          Structure display function                        *
 ******************************************************************************/
void          cloog_matrix_print_structure(FILE *, CloogMatrix *, int) ;

/******************************************************************************
 *                               Reading function                             *
 ******************************************************************************/
CloogMatrix * cloog_matrix_read(FILE *) ;

/******************************************************************************
 *                        Equalities spreading functions                      *
 ******************************************************************************/
CloogEqualities *cloog_equal_alloc(int n, int nb_levels,
			int nb_parameters);
void		 cloog_equal_free(CloogEqualities *equal);
int              cloog_equal_count(CloogEqualities *equal);
CloogConstraints *cloog_equal_constraints(CloogEqualities *equal);
int              cloog_equal_type(CloogEqualities *equal, int level);
void             cloog_equal_add(CloogEqualities *equal,
				  CloogConstraints *constraints,
				  int level, int line, int nb_par);
void             cloog_equal_del(CloogEqualities *equal, int level);

/******************************************************************************
 *                            Processing functions                            *
 ******************************************************************************/
void          cloog_constraints_normalize(CloogConstraints *, int);
void          cloog_constraints_free(CloogConstraints *);
int           cloog_constraints_contain_level(CloogConstraints *constraints,
			int level, int nb_parameters);
int           cloog_constraints_defining_equality(CloogConstraints *matrix,
			int level);
int           cloog_constraints_defining_inequalities(CloogConstraints *matrix,
			int level, int *lower, int nb_parameters);
int           cloog_constraints_total_dimension(CloogConstraints *constraints);
CloogConstraints *cloog_constraints_copy(CloogConstraints *);
Value       * cloog_matrix_vector_copy(Value *, int) ;
CloogConstraints *cloog_constraints_simplify(CloogConstraints *, CloogEqualities *, int, int);
int           cloog_constraints_count(CloogConstraints *constraints);
int           cloog_constraint_involves(CloogConstraints *constraints, int c, int v);
int           cloog_constraint_is_lower_bound(CloogConstraints *constraints, int c, int v);
int           cloog_constraint_is_upper_bound(CloogConstraints *constraints, int c, int v);
int           cloog_constraint_is_equality(CloogConstraints *constraints, int c);
void          cloog_constraint_constant_get(CloogConstraints *constraints,
			int c, Value *val);
void          cloog_constraint_coefficient_get(CloogConstraints *constraints,
			int c, int var, Value *val);
void          cloog_constraint_coefficient_set(CloogConstraints *constraints,
			int c, int var, Value val);
void          cloog_constraint_clear(CloogConstraints *constraints, int c);
void          cloog_constraint_copy(CloogConstraints *constraints, int c,
			Value *dst);
void          cloog_matrix_vector_free(Value *, int) ;

#if defined(__cplusplus)
  }
#endif 
#endif /* define _H */
