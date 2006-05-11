
   /**-------------------------------------------------------------------**
    **                               CLooG                               **
    **-------------------------------------------------------------------**
    **                             matrix.c                              **
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
/* CAUTION: the english used for comments is probably the worst you ever read,
 *          please feel free to correct and improve it !
 */


# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include "../include/cloog/cloog.h"



/******************************************************************************
 *                             Memory leaks hunting                           *
 ******************************************************************************/


/**
 * These functions and global variables are devoted to memory leaks hunting: we
 * want to know at each moment how many CloogMatrix structures are allocated
 * (cloog_matrix_allocated) and how many had been freed (cloog_matrix_freed).
 * Each time a CloogMatrix structure is allocated, a call to the function
 * cloog_matrix_leak_up() must be carried out, and respectively
 * cloog_matrix_leak_down() when a CloogMatrix structure is freed. The special
 * variable cloog_matrix_max gives the maximal number of CloogMatrix structures
 * simultaneously alive (i.e. allocated and non-freed) in memory.
 * - April 17th 2005: first version.
 */


int cloog_matrix_allocated = 0 ;
int cloog_matrix_freed = 0 ;
int cloog_matrix_max = 0 ;


void cloog_matrix_leak_up()
{ cloog_matrix_allocated ++ ;
  if ((cloog_matrix_allocated-cloog_matrix_freed) > cloog_matrix_max)
  cloog_matrix_max = cloog_matrix_allocated - cloog_matrix_freed ;
}


void cloog_matrix_leak_down()
{ cloog_matrix_freed ++ ;
}


/******************************************************************************
 *                              PolyLib interface                             *
 ******************************************************************************/


/**
 * CLooG makes an intensive use of matrix operations and the PolyLib do
 * the job. Here are the interfaces to all the PolyLib calls (CLooG uses 18
 * PolyLib functions), with or without some adaptations. If another matrix
 * library can be used, only these functions have to be changed.
 */


/**
 * cloog_matrix_print function:
 * This function prints the content of a CloogMatrix structure (matrix) into a
 * file (foo, possibly stdout).
 */
void cloog_matrix_print(FILE * foo, CloogMatrix * matrix)
{ Matrix_Print(foo,P_VALUE_FMT,matrix) ;
}


/**
 * cloog_matrix_free function:
 * This function frees the allocated memory for a CloogMatrix structure
 * (matrix).
 */
void cloog_matrix_free(CloogMatrix * matrix)
{ cloog_matrix_leak_down() ;
  Matrix_Free(matrix) ;
}


/**
 * cloog_matrix_alloc function:
 * This function allocates the memory space for a CloogMatrix structure having
 * nb_rows rows and nb_columns columns, it set its elements to 0.
 */
CloogMatrix * cloog_matrix_alloc(unsigned nb_rows, unsigned nb_columns)
{ cloog_matrix_leak_up() ;
  return Matrix_Alloc(nb_rows,nb_columns) ;
}


/******************************************************************************
 *                          Structure display function                        *
 ******************************************************************************/


/**
 * cloog_loop_print_structure function:
 * Displays a CloogMatrix structure (matrix) into a file (file, possibly stdout)
 * in a way that trends to be understandable without falling in a deep
 * depression or, for the lucky ones, getting a headache... It includes an
 * indentation level (level) in order to work with others print_structure
 * functions. Written by Olivier Chorier, Luc Marchaud, Pierre Martin and
 * Romain Tartiere.
 * - April 24th 2005: Initial version.
 * - June   2nd 2005: (Ced) Extraction from cloog_loop_print_structure and
 *                   integration in matrix.c.
 * - June  22rd 2005: Adaptation for GMP.
 */
void cloog_matrix_print_structure(FILE * file, CloogMatrix * matrix, int level)
{ int i, j ;
  
  /* Display the matrix. */
  for (i=0; i<matrix->NbRows; i++)
  { for(j=0; j<=level; j++)
    fprintf(file,"|\t") ;
      
    fprintf(file,"[ ") ;
      
    for (j=0; j<matrix->NbColumns; j++)
    { value_print(file,P_VALUE_FMT,matrix->p[i][j]) ;
      fprintf(file," ") ;
    }      

    fprintf(file,"]\n") ;
  }
}


/******************************************************************************
 *                               Reading function                             *
 ******************************************************************************/


/**
 * cloog_matrix_read function:
 * Adaptation from the PolyLib. This function reads a matrix into a file (foo,
 * posibly stdin) and returns a pointer this matrix.
 * October 18th 2001: first version.
 * - April 17th 2005: this function moved from domain.c to here.
 * - June  21rd 2005: Adaptation for GMP (based on S. Verdoolaege's version of
 *                    CLooG 0.12.1).
 */
CloogMatrix * cloog_matrix_read(FILE * foo)
{ unsigned NbRows, NbColumns ;
  int i, j, n ;
  char *c, s[MAX_STRING], str[MAX_STRING] ;
  CloogMatrix * matrix ;
  Value * p ;
  
  while (fgets(s,MAX_STRING,foo) == 0) ;
  while ((*s=='#' || *s=='\n') || (sscanf(s," %u %u",&NbRows,&NbColumns)<2))
  fgets(s,MAX_STRING,foo) ;
  
  matrix = cloog_matrix_alloc(NbRows,NbColumns) ;

  p = matrix->p_Init ;
  for (i=0;i<matrix->NbRows;i++) 
  { do 
    { c = fgets(s,MAX_STRING,foo) ;
      while ((c != NULL) && isspace(*c) && (*c != '\n'))
      c++ ;
    }
    while (c != NULL && (*c == '#' || *c == '\n'));
    
    if (c == NULL) 
    { fprintf(stderr, "[CLooG]ERROR: not enough rows.\n") ;
      exit(1) ;
    }
    for (j=0;j<matrix->NbColumns;j++) 
    { if (c == NULL || *c == '#' || *c == '\n')
      { fprintf(stderr, "[CLooG]ERROR: not enough columns.\n") ;
        exit(1) ;
      }
      /* NdCed : Dans le n ca met strlen(str). */
      if (sscanf(c,"%s%n",str,&n) == 0) 
      { fprintf(stderr, "[CLooG]ERROR: not enough rows.\n") ;
        exit(1) ;
      }
      value_read(*(p++),str) ;
      c += n ;
    }
  }
  
  return(matrix) ;
}


/******************************************************************************
 *                            Processing functions                            *
 ******************************************************************************/


/**
 * Function cloog_matrix_normalize:
 * This function will modify the constraint system in such a way that when
 * there is an equality depending on the element at level 'level', there are
 * no more (in)equalities depending on this element. For instance, try
 * test/valilache.cloog with options -f 8 -l 9, with and without the call
 * to this function. At a given moment, for the level L we will have
 * 32*P=L && L>=1 (P is a lower level), this constraint system cannot be
 * translated directly into a source code. Thus, we normalize the domain to
 * remove L from the inequalities. In our example, this leads to
 * 32*P=L && 32*P>=1, that can be transated to the code
 * if (P>=1) { L=32*P ; ... }. This function solves the DaeGon Kim bug.
 * WARNING: Remember that if there is another call to Polylib after a call to
 * this function, we have to recall this function.
 *  -June    16th 2005: first version (adaptation from URGent June-7th-2005 by
 *                      N. Vasilache).
 * - June    21rd 2005: Adaptation for GMP.
 * - November 4th 2005: Complete rewriting, simpler and faster. It is no more an
 *                      adaptation from URGent. 
 */
void cloog_matrix_normalize(CloogMatrix * matrix, int level)
{ int ref, i, j ;
  Value factor_i, factor_ref, temp_i, temp_ref, gcd ;
    
  if (matrix == NULL)
  return ;

  /* Don't "normalize" the constant term. */
  if (level == matrix->NbColumns-1)
    return;

  /* Let us find an equality for the current level that can be propagated. */
  for (ref=0;ref<matrix->NbRows;ref++)
  if (value_zero_p(matrix->p[ref][0]) && value_notzero_p(matrix->p[ref][level]))
  { value_init_c(gcd) ;
    value_init_c(temp_i) ;
    value_init_c(temp_ref) ;
    value_init_c(factor_i) ;
    value_init_c(factor_ref) ;
  
    /* Row "ref" is the reference equality, now let us find a row to simplify.*/
    for (i=ref+1;i<matrix->NbRows;i++)
    if (value_notzero_p(matrix->p[i][level]))
    { /* Now let us set to 0 the "level" coefficient of row "j" using "ref".
       * First we compute the factors to apply to each row vector element.
       */
      Gcd(matrix->p[ref][level],matrix->p[i][level],&gcd) ;
      value_division(factor_i,matrix->p[ref][level],gcd) ;
      value_division(factor_ref,matrix->p[i][level],gcd) ;
      
      /* Maybe we are simplifying an inequality: factor_i must not be <0. */
      if (value_neg_p(factor_i))
      { value_absolute(factor_i,factor_i) ;
        value_oppose(factor_ref,factor_ref) ;
      }
      
      /* Now update the vector. */
      for (j=1;j<matrix->NbColumns;j++)
      { value_multiply(temp_i,factor_i,matrix->p[i][j]) ;
        value_multiply(temp_ref,factor_ref,matrix->p[ref][j]) ;
        value_substract(matrix->p[i][j],temp_i,temp_ref) ;
      }
    
      /* Normalize (divide by GCD of all elements) the updated vector. */
      Vector_Normalize(&(matrix->p[i][1]),matrix->NbColumns-1) ;
    }
    
    value_clear_c(gcd) ;
    value_clear_c(temp_i) ;
    value_clear_c(temp_ref) ;
    value_clear_c(factor_i) ;
    value_clear_c(factor_ref) ;
    break ;
  }
}


/**
 * cloog_matrix_equality_update function:
 * this function updates a matrix of equalities where each row corresponds to
 * the equality "=0" of an affine expression such that the entry at column
 * "row" (="level") is not zero. This matrix is upper-triangular, except the
 * row number "level-1" which has to be updated for the matrix to be triangular.
 * The first element of each row gives the equality type and is not related to
 * the expression which is equal to zero. This function achieves the processing.
 * - equal is the matrix to be updated,
 * - level gives the row that has to be updated (it is actually row "level-1"),
 * - nb_par is the number of parameters of the program.
 **
 * - September 20th 2005: first version.
 */
void cloog_matrix_equality_update(CloogMatrix * equal, int level, int nb_par)
{ int i, j ;
  Value gcd, factor_level, factor_outer, temp_level, temp_outer ;
  
  value_init_c(gcd) ;
  value_init_c(temp_level) ;
  value_init_c(temp_outer) ;
  value_init_c(factor_level) ;
  value_init_c(factor_outer) ;
  
  /* For each previous level, */
  for (i=level-2;i>=0;i--)
  { /* if the corresponding iterator is inside the current equality and is equal
     * to something,
     */
    if (value_notzero_p(equal->p[level-1][i+1]) &&
        value_notzero_p(equal->p[i][0]))
    { /* Compute the Greatest Common Divisor. */ 
      Gcd(equal->p[level-1][i+1],equal->p[i][i+1],&gcd) ;
      
      /* Compute the factors to apply to each row vector element. */
      value_division(factor_level,equal->p[i][i+1],gcd) ;
      value_division(factor_outer,equal->p[level-1][i+1],gcd) ;
            
      /* Now update the row 'level'. */
      /* - the iterators, up to level, */
      for (j=1;j<=level;j++)
      { value_multiply(temp_level,factor_level,equal->p[level-1][j]) ;
        value_multiply(temp_outer,factor_outer,equal->p[i][j]) ;
        value_substract(equal->p[level-1][j],temp_level,temp_outer) ;
      }
      /* - between last useful iterator (level) and the first parameter, the
       *   matrix is sparse (full of zeroes), we just do nothing there. 
       * - the parameters and the scalar.
       */
      for (j=0;j<nb_par+1;j++)
      { value_multiply(temp_level,factor_level,
                       equal->p[level-1][equal->NbColumns-j-1]) ;
        value_multiply(temp_outer,factor_outer,
                       equal->p[i][equal->NbColumns-j-1]) ;
        value_substract(equal->p[level-1][equal->NbColumns-j-1],
	               temp_level,temp_outer) ;
      }
    }
  }
  
  /* Normalize (divide by GCD of all elements) the updated equality. */
  Vector_Normalize(&(equal->p[level-1][1]),equal->NbColumns-1) ;

  value_clear_c(gcd) ;
  value_clear_c(temp_level) ;
  value_clear_c(temp_outer) ;
  value_clear_c(factor_level) ;
  value_clear_c(factor_outer) ;
}


/**
 * cloog_matrix_copy function:
 * this functions builds and returns a "hard copy" (not a pointer copy) of a
 * CloogMatrix data structure.
 * - October 26th 2005: first version.
 */
CloogMatrix * cloog_matrix_copy(CloogMatrix * matrix)
{ int i, j ;
  CloogMatrix * copy ;

  copy = cloog_matrix_alloc(matrix->NbRows,matrix->NbColumns) ;
  
  for (i=0;i<matrix->NbRows;i++)
  for (j=0;j<matrix->NbColumns;j++)
  value_assign(copy->p[i][j],matrix->p[i][j]) ;
  
  return copy ;
}


/**
 * cloog_matrix_vector_copy function:
 * this function rutuns a hard copy of the vector "vector" of length "length"
 * provided as input.
 * - November 3rd 2005: first version.
 */
Value * cloog_matrix_vector_copy(Value * vector, int length)
{ int i ;
  Value * copy ;
  
  /* We allocate the memory space for the new vector, and we fill it with
   * the original coefficients.
   */
  copy = (Value *)malloc(length * sizeof(Value)) ;
  for (i=0;i<length;i++)
  { value_init_c(copy[i]) ;
    value_assign(copy[i],vector[i]) ;
  }
  
  return copy ;
}


/**
 * cloog_matrix_vector_simplify function:
 * this function simplify an affine expression with its coefficients in
 * "vector" of length "length" thanks to an equality matrix "equal" that gives
 * for some elements of the affine expression an equality with other elements,
 * preferably constants. For instance, if the vector contains i+j+3 and the
 * equality matrix gives i=n and j=2, the vector is simplified to n+3 and is
 * returned in a new vector.
 * - vector is the array of affine expression coefficients
 * - equal is the matrix of equalities,
 * - length is the vector length,
 * - level is a level we don't want to simplify (-1 if none),
 * - nb_par is the number of parameters of the program.
 **
 * - September 20th 2005: first version.
 * - November   2nd 2005: (debug) we are simplifying inequalities, thus we are
 *                        not allowed to multiply the vector by a negative
 *                        constant.Problem found after a report of Michael
 *                        Classen.
 */
Value * cloog_matrix_vector_simplify(vector, equal, length, level, nb_par)
Value * vector ;
CloogMatrix * equal ;
int length, level, nb_par ;
{ int i, j ;
  Value gcd, factor_vector, factor_equal, temp_vector, temp_equal, * simplified;
  
  simplified = cloog_matrix_vector_copy(vector,length) ;
  
  value_init_c(gcd) ;
  value_init_c(temp_vector) ;
  value_init_c(temp_equal) ;
  value_init_c(factor_vector) ;
  value_init_c(factor_equal) ;
    
  /* For each non-null coefficient in the vector, */
  for (i=length-nb_par-2;i>0;i--)
  if (i != level)
  { /* if the coefficient in not null, and there exists a useful equality */
    if ((value_notzero_p(simplified[i])) &&
        (value_notzero_p(equal->p[i-1][0])))
    { /* Compute the Greatest Common Divisor. */ 
      Gcd(simplified[i],equal->p[i-1][i],&gcd) ;
      
      /* Compute the factors to apply to each row vector element. */
      value_division(factor_vector,equal->p[i-1][i],gcd) ;
      value_division(factor_equal,simplified[i],gcd) ;
      
      /* We are simplifying an inequality: factor_vector must not be <0. */
      if (value_neg_p(factor_vector))
      { value_absolute(factor_vector,factor_vector) ;
        value_oppose(factor_equal,factor_equal) ;
      }
      
      /* Now update the vector. */
      /* - the iterators, up to the current level, */
      for (j=1;j<=length-nb_par-2;j++)
      { value_multiply(temp_vector,factor_vector,simplified[j]) ;
        value_multiply(temp_equal,factor_equal,equal->p[i-1][j]) ;
        value_substract(simplified[j],temp_vector,temp_equal) ;
      }
      /* - between last useful iterator (i) and the first parameter, the equal
       *   matrix is sparse (full of zeroes), we just do nothing there. 
       * - the parameters and the scalar.
       */
      for (j=0;j<nb_par+1;j++)
      { value_multiply(temp_vector,factor_vector,simplified[length-1-j]) ;
        value_multiply(temp_equal,factor_equal,
                       equal->p[i-1][equal->NbColumns-j-1]) ;
        value_substract(simplified[length-1-j],temp_vector,temp_equal) ;
      }
    }
  }
  
  /* Normalize (divide by GCD of all elements) the updated vector. */
  Vector_Normalize(&(simplified[1]),length-1) ;

  value_clear_c(gcd) ;
  value_clear_c(temp_vector) ;
  value_clear_c(temp_equal) ;
  value_clear_c(factor_vector) ;
  value_clear_c(factor_equal) ;
  
  return simplified ;
}


/**
 * cloog_matrix_simplify function:
 * this function simplify all constraints inside the matrix "matrix" thanks to
 * an equality matrix "equal" that gives for some elements of the affine
 * constraint an equality with other elements, preferably constants.
 * For instance, if a row of the matrix contains i+j+3>=0 and the equality
 * matrix gives i=n and j=2, the constraint is simplified to n+3>=0. The
 * simplified constraints are returned back inside a new simplified matrix.
 * - matrix is the set of constraints to simplify,
 * - equal is the matrix of equalities,
 * - level is a level we don't want to simplify (-1 if none),
 * - nb_par is the number of parameters of the program.
 **
 * - November 4th 2005: first version.
 */
CloogMatrix * cloog_matrix_simplify(matrix, equal, level, nb_par)
CloogMatrix * matrix, * equal ;
int level, nb_par ;
{ int i, j, k ;
  Value * vector ;
  CloogMatrix * simplified ;
  
  if (matrix == NULL)
  return NULL ;
  
  /* The simplified matrix is such that each row has been simplified thanks
   * tho the "equal" matrix. We allocate the memory for the simplified matrix,
   * then for each row of the original matrix, we compute the simplified
   * vector and we copy its content into the according simplified row.
   */
  simplified = cloog_matrix_alloc(matrix->NbRows,matrix->NbColumns) ;
  for (i=0;i<matrix->NbRows;i++)
  { vector = cloog_matrix_vector_simplify(matrix->p[i],equal,matrix->NbColumns,
                                          level,nb_par) ;
    for (j=0;j<matrix->NbColumns;j++)
    value_assign(simplified->p[i][j],vector[j]) ;
    
    cloog_matrix_vector_free(vector,matrix->NbColumns) ;
  }
  
  /* After simplification, it may happen that few constraints are the same,
   * we remove them here by replacing them with 0=0 constraints.
   */
  for (i=0;i<simplified->NbRows;i++)
  for (j=i+1;j<simplified->NbRows;j++)
  { for (k=0;k<simplified->NbColumns;k++)
    if (value_ne(simplified->p[i][k],simplified->p[j][k]))
    break ;
    
    if (k == matrix->NbColumns)
    { for (k=0;k<matrix->NbColumns;k++)
      value_set_si(simplified->p[j][k],0) ;
    }
  }
  
  return simplified ;
}


/**
 * cloog_matrix_vector_free function:
 * this function clears the elements of a vector "vector" of length "length",
 * then frees the vector itself this is useful for the GMP version of CLooG
 * which has to clear all elements.
 * - October 29th 2005: first version.
 */
void cloog_matrix_vector_free(Value * vector, int length)
{ int i ;
  
  for (i=0;i<length;i++)
  value_clear_c(vector[i]) ;
  free(vector) ;
}
