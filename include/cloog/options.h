
   /**-------------------------------------------------------------------**
    **                               CLooG                               **
    **-------------------------------------------------------------------**
    **                             options.h                             **
    **-------------------------------------------------------------------**
    **                  First version: april 19th 2003                   **
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

#include <stdio.h>

#ifndef CLOOG_OPTIONS_H
#define CLOOG_OPTIONS_H
#if defined(__cplusplus)
extern "C" 
  {
#endif 


/* Uncomment the following line if you want some information about
 * maximum total allocated memory for code generation.
#define CLOOG_MEMORY 
 */
#define CLOOG_SCALARS

struct cloogoptions;
typedef struct cloogoptions CloogOptions;
struct osl_scop;

struct cloogoptions
{
  CloogState *state; /* State. */
  /* OPTIONS FOR LOOP GENERATION */
  int l ;           /* Last level to optimize. */
  int f ;           /* First level to optimize. */

  int *ls;         /* Last level to optimize (statement-wise). */
  int *fs;         /* First level to optimize (statement-wise). */
  int fs_ls_size;  /* Size of the fs and ls arrays (same size) */
  int stop ;        /* Level to stop code generation. */
  int strides ;     /* 1 if user wants to handle non-unit strides (then loop
                     * increment can be something else than one), 0 otherwise.
                     */
  int sh;	    /* 1 for computing simple hulls */
  int first_unroll; /* The first dimension to unroll */

  /* OPTIONS FOR PRETTY PRINTING */
  int esp ;       /* 1 if user wants to spread all equalities, i.e. when there
                   * is something like "i = 3*j + 1 ; A[i] = 0 ;" the generator
                   * will write "A[3*j + 1] = 0 ;", 0 otherwise.
                   */
  int fsp ;       /* The iteration level where equalities spreading can begin
                   * (it might happen that the user wants not to spread values
                   * of scattering iterators).
                   */
  int otl ;       /* 1 for eliminate loops running just one time and write them
                   * as an affectation of the iterator, 0 otherwise.
                   */
  int block ;     /* 1 to make one new block {...} per new dimension,
                   * 0 otherwise.
                   */
  int compilable; /* 1 to generate a compilable code by using
                   * preprocessing, 0 otherwise.
                   */
  int callable;   /* 1 to generate callable code by using
                   * preprocessing, 0 otherwise.
                   */
  int language;   /* 1 to generate FORTRAN, 0 for C otherwise. */

  int save_domains;/* Save unsimplified copy of domain. */

  /* MISC OPTIONS */
  char * name ;   /* Name of the input file. */
  float time ;    /* Time spent for code generation in seconds. */
  int openscop;   /* 1 if the input file has OpenScop format, 0 otherwise. */
  struct osl_scop *scop; /* Input OpenScop scop if any, NULL otherwise. */
#ifdef CLOOG_MEMORY
  int memory ;    /* Memory spent for code generation in kilobytes. */
#endif
  int quiet;      /* Don't print any informational messages. */
  /* UNDOCUMENTED OPTIONS FOR THE AUTHOR ONLY */
  int leaks ;     /* 1 if I want to print the allocation statistics,
                   * 0 otherwise.
		   */
  int backtrack;  /* 1 to perform backtracking in 
                   * Quillere's algorithm, 0 otherwise.
		   */
  int override ;  /* 1 if I want to bypass CLooG decisions on option correctness
                   * (generated code may be incorrect), 0 otherwise.
		   */
  int structure ; /* 1 if I want to print the CloogProgram structure before the
                   * pretty printed code, 0 otherwise.
		   */
  int noblocks ;  /* 1 if I don't want to make statement blocks, 0 otherwise. */
  int noscalars ; /* 1 if I don't want to use scalar dimensions, 0 otherwise. */
  int nosimplify; /* 1 if I don't want to simplify polyhedra, 0 otherwise. */
  int osl_options;/* 1 if osl_cloogoptions are to be used */
} ;


/******************************************************************************
 *                          Error reporting functions                         *
 ******************************************************************************/

enum cloog_msg_type { CLOOG_ERROR, CLOOG_WARNING, CLOOG_INFO };

void cloog_msg(CloogOptions *options, enum cloog_msg_type type,
		const char *msg, ...);
void cloog_die(const char *msg, ...);


/******************************************************************************
 *                          Structure display function                        *
 ******************************************************************************/
void cloog_options_print(FILE *, CloogOptions *) ;


/******************************************************************************
 *                         Memory deallocation function                       *
 ******************************************************************************/
void cloog_options_free(CloogOptions *) ;


/******************************************************************************
 *                               Reading function                             *
 ******************************************************************************/
void cloog_options_read(CloogState *state, int argc, char **argv,
			FILE **input, FILE **output, CloogOptions **options);


/******************************************************************************
 *                            Processing functions                            *
 ******************************************************************************/
CloogOptions *cloog_options_malloc(CloogState *state);
CloogOptions *cloog_options_copy_from_osl_scop(struct osl_scop *scop,
                                               CloogOptions *options);
CloogOptions* cloog_options_extract_from_scop(struct osl_scop *scop,
                                              CloogOptions *options);
CloogOptions* cloog_options_clone(CloogOptions *options) ;


#if defined(__cplusplus)
  }
#endif 
#endif /* define _H */
