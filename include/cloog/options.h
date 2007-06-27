
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


struct cloogoptions
{ /* OPTIONS FOR LOOP GENERATION */
  int l ;         /* Last level to optimize. */
  int f ;         /* First level to optimize. */
  int stop ;      /* Level to stop code generation. */
  int strides ;   /* 1 if user wants to handle non-unit strides (then loop
                   * increment can be something else than one), 0 otherwise.
		   */
  int sh;	  /* 1 for computing simple hulls */

  /* OPTIONS FOR PRETTY PRINTING */
  int esp ;       /* 1 if user wants to spread all equalities, i.e. when there
                   * is something like "i = 3*j + 1 ; A[i] = 0 ;" the generator
                   * will write "A[3*j + 1] = 0 ;", 0 otherwise.
                   */
  int csp ;       /* 1 if user wants to spread the constant equalities,
                   * i.e. the simple equalities like "i = M ;", "i = j ;"...
                   * It is for performance saving with a spreading, 0 otherwise.
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
  int cpp ;       /* 1 to generate a pseudo-code easily compilable by using
                   * preprocessing, 0 otherwise.
                   */
  int compilable; /* 1 to generate a compilable code by using
                   * preprocessing, 0 otherwise.
                   */
  int language;   /* 1 to generate FORTRAN, 0 for C otherwise. */

  /* MISC OPTIONS */
  char * name ;   /* Name of the input file. */
  float time ;    /* Time spent for code generation in seconds. */
#ifdef CLOOG_MEMORY
  int memory ;    /* Memory spent for code generation in kilobytes. */
#endif
  /* UNDOCUMENTED OPTIONS FOR THE AUTHOR ONLY */
  int leaks ;     /* 1 if I want to print the allocation statistics,
                   * 0 otherwise.
		   */
  int nobacktrack;/* 1 if I don't want to achieve backtracking in 
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
} ;
typedef struct cloogoptions CloogOptions ;


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
void cloog_options_read(int, char **, FILE **, FILE **, CloogOptions **) ;


/******************************************************************************
 *                            Processing functions                            *
 ******************************************************************************/
CloogOptions * cloog_options_malloc(void) ;


#if defined(__cplusplus)
  }
#endif 
#endif /* define _H */
