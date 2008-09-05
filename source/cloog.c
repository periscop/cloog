
   /**-------------------------------------------------------------------**
    **                              CLooG                                **
    **-------------------------------------------------------------------**
    **                             cloog.c                               **
    **-------------------------------------------------------------------**
    **       First version: october 25th 2001, CLooG's birth date !      **
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
 * version.							              *
 *                                                                            *
 * This software is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY *
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License   *
 * for more details.							      *
 *                                                                            *
 * You should have received a copy of the GNU General Public License along    *
 * with software; if not, write to the Free Software Foundation, Inc.,        *
 * 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA                     *
 *                                                                            *
 * CLooG, the Chunky Loop Generator                                           *
 * Written by Cedric Bastoul, Cedric.Bastoul@inria.fr                         *
 *                                                                            *
 ******************************************************************************/


# include <stdlib.h>
# include <stdio.h>
# include "../include/cloog/cloog.h"

/** Extern global variables for memory leak hunt. */
extern int cloog_domain_allocated ;
extern int cloog_domain_freed ;
extern int cloog_domain_max ;
extern int cloog_loop_allocated ;
extern int cloog_loop_freed ;
extern int cloog_loop_max ;
extern int cloog_statement_allocated ;
extern int cloog_statement_freed ;
extern int cloog_statement_max ;
extern int cloog_matrix_allocated ;
extern int cloog_matrix_freed ;
extern int cloog_matrix_max ;
extern int cloog_block_allocated ;
extern int cloog_block_freed ;
extern int cloog_block_max ;
extern int cloog_int_allocated;
extern int cloog_int_freed;
extern int cloog_int_max;


int main(int argv, char * argc[])
{ CloogProgram * program ;
  CloogOptions * options ;
  FILE * input, * output ;
   
  /* Options and input/output file setting. */
  cloog_options_read(argv,argc,&input,&output,&options) ;

  /* Reading the program informations. */
  program = cloog_program_read(input,options) ;
  fclose(input) ;
  
  /* Generating and printing the code. */
  program = cloog_program_generate(program,options) ;
  if (options->structure)
  cloog_program_print(stdout,program) ;
  cloog_program_pprint(output,program,options) ;
  cloog_program_free(program) ;

  /* Printing the allocation statistics if asked. */
  if (options->leaks)
  { fprintf(output,"/* Matrices   : allocated=%5d, freed=%5d, max=%5d. */\n",
           cloog_matrix_allocated,cloog_matrix_freed,cloog_matrix_max) ;
    fprintf(output,"/* Domains    : allocated=%5d, freed=%5d, max=%5d. */\n",
           cloog_domain_allocated,cloog_domain_freed,cloog_domain_max);
    fprintf(output,"/* Loops      : allocated=%5d, freed=%5d, max=%5d. */\n",
           cloog_loop_allocated,cloog_loop_freed,cloog_loop_max) ;
    fprintf(output,"/* Statements : allocated=%5d, freed=%5d, max=%5d. */\n",
           cloog_statement_allocated,cloog_statement_freed,cloog_statement_max);
    fprintf(output,"/* Blocks     : allocated=%5d, freed=%5d, max=%5d. */\n",
           cloog_block_allocated,cloog_block_freed,cloog_block_max) ;
    fprintf(output,"/* Int (GMP)  : allocated=%5d, freed=%5d, max=%5d. */\n",
           cloog_int_allocated, cloog_int_freed, cloog_int_max);
  }

  /* Inform the user in case of a problem with the allocation statistics. */
  if ((cloog_matrix_allocated    != cloog_matrix_freed)    ||
      (cloog_domain_allocated    != cloog_domain_freed)    ||
      (cloog_loop_allocated      != cloog_loop_freed)      ||
      (cloog_statement_allocated != cloog_statement_freed) ||
      (cloog_block_allocated     != cloog_block_freed)     ||
      (cloog_int_allocated       != cloog_int_freed))
  { fprintf(stderr,
            "[CLooG]INFO: an internal problem has been detected (it should have"
	    " no\n             consequence on the correctness of the output)."
	    " Please send (if\n	     you can) your input file, the first line "
	    "given by typing 'cloog -v'\n	     and your full command ") ;
    fprintf(stderr,
            "line call to CLooG including options to\n	     <cedric.bastoul"
	    "@inria.fr>. Thank you for your participation to get\n"
	    "	     CLooG better and safer.\n") ;
  }

  cloog_options_free(options) ;
  fclose(output) ;
  return 0;
}

