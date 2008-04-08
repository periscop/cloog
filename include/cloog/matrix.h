
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
 *                            Processing functions                            *
 ******************************************************************************/
void          cloog_matrix_normalize(CloogMatrix *, int) ;
void          cloog_matrix_equality_update(CloogMatrix *, int, int) ;
CloogMatrix * cloog_matrix_copy(CloogMatrix *) ;
Value       * cloog_matrix_vector_copy(Value *, int) ;
Value       * cloog_matrix_vector_simplify(Value*, CloogMatrix*, int, int, int);
CloogMatrix * cloog_matrix_simplify(CloogMatrix *, CloogMatrix *, int, int) ;
void          cloog_matrix_vector_free(Value *, int) ;

#if defined(__cplusplus)
  }
#endif 
#endif /* define _H */
