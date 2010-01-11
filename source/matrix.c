   /**-------------------------------------------------------------------**
    **                              CLooG                                **
    **-------------------------------------------------------------------**
    **                           cloogmatrix.c                           **
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

#include <stdlib.h>
#include <stdio.h>
#include "../include/cloog/cloog.h"

/**
 * cloog_matrix_alloc:
 * Allocate a CloogMatrix data structure with NbRows rows and NbColumns columns.
 * All values are initialized to 0.
 * This method returns a pointer to the data structure if successful or a NULL
 * pointer otherwise.
 */
CloogMatrix *cloog_matrix_alloc(unsigned NbRows, unsigned NbColumns)
{
  CloogMatrix *matrix;
  cloog_int_t **p, *q;
  int i, j;

  matrix = (CloogMatrix *)malloc(sizeof(CloogMatrix));

  if (!matrix)
    return NULL;

  matrix->NbRows = NbRows;
  matrix->NbColumns = NbColumns;

  if (!NbRows || !NbColumns) {
    matrix->p = NULL;
    matrix->p_Init = NULL;
    return matrix;
  }

  p = (cloog_int_t **)malloc(NbRows * sizeof(cloog_int_t *));

  if (p == NULL) {
    free (matrix);
    return NULL;
  }

  q = (cloog_int_t *)malloc(NbRows * NbColumns * sizeof(cloog_int_t));

  if (q == NULL) {
    free (matrix);
    free (p);
    return NULL;
  }

  matrix->p = p;
  matrix->p_Init = q;

  for (i = 0; i < NbRows; i++) {
    *p++ = q;
    for (j = 0; j < NbColumns; j++) {
      cloog_int_init(*(q+j));
      cloog_int_set_si(*(q+j), 0);
    }
    q += NbColumns;
  }

  return matrix;
}

/**
 * cloog_matrix_free:
 * Free matrix.
 */
void cloog_matrix_free(CloogMatrix * matrix)
{
  int i;
  cloog_int_t *p;
  int size = matrix->NbRows * matrix->NbColumns;

  p = matrix->p_Init;

  for (i = 0; i < size; i++)
    cloog_int_clear(*p++);

  if (matrix) {
    free(matrix->p_Init);
    free(matrix->p);
    free(matrix);
  }
}

/**
 * cloog_matrix_print function:
 * This function prints the content of a CloogMatrix structure (matrix) into a
 * file (foo, possibly stdout).
 */
void cloog_matrix_print(FILE* foo, CloogMatrix* m)
{
  int i, j;

  if (!m)
    fprintf(foo, "(null)\n");

  fprintf(foo, "%d %d\n", m->NbRows, m->NbColumns);
  for (i = 0; i < m->NbRows; ++i) {
    for (j = 0; j < m->NbColumns; ++j) {
      cloog_int_print(foo, m->p[i][j]);
      fprintf(foo, " ");
    }
    fprintf(foo, "\n");
  }
  fflush(foo);
}
