
   /**-------------------------------------------------------------------**
    **                              CLooG                                **
    **-------------------------------------------------------------------**
    **                            program.h                              **
    **-------------------------------------------------------------------**
    **                 First version: october 25th 2001                  **
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


#ifndef CLOOG_PROGRAM_H
#define CLOOG_PROGRAM_H
#if defined(__cplusplus)
extern "C" 
  {
#endif 


# define MAX_STRING 1024
# define MEGA 1000000  /* One million. */


/**
 * CloogProgram structure:
 * this structure contains all the informations of a program generated or to be
 * generated.
 */
struct cloogprogram
{ /* Basic program description fields. */
  char language ;              /**< The language of the program. */
  int  nb_scattdims ;          /**< Scattering dimension number. */
  CloogDomain    * context ;   /**< The context of the program. */
  CloogLoop      * loop ;      /**< The loops of the program. */
  CloogNames     * names ;     /**< Iterators and parameters names. */
  CloogBlockList * blocklist ; /**< The statement block list. */
  
  /* Internal service fields, filled up by cloog_program_scatter function. */
  int * scaldims ;             /**< Boolean array saying whether a given
                                *   scattering dimension is scalar or not.
				*/
} ;
typedef struct cloogprogram CloogProgram ;


/******************************************************************************
 *                          Structure display function                        *
 ******************************************************************************/
void cloog_program_print_structure(FILE *, CloogProgram *, int) ;
void cloog_program_print(FILE *, CloogProgram *) ;
void cloog_program_pprint(FILE *, CloogProgram *, CloogOptions *) ;
void cloog_program_dump_cloog(FILE *, CloogProgram *) ;


/******************************************************************************
 *                         Memory deallocation function                       *
 ******************************************************************************/
void cloog_program_free(CloogProgram *) ;


/******************************************************************************
 *                               Reading function                             *
 ******************************************************************************/
CloogProgram * cloog_program_read(FILE *, CloogOptions *) ;


/******************************************************************************
 *                            Processing functions                            *
 ******************************************************************************/
CloogProgram * cloog_program_malloc() ;
CloogProgram * cloog_program_generate(CloogProgram *, CloogOptions *) ;
void cloog_program_block(CloogProgram *, CloogDomainList *) ;
void cloog_program_extract_scalars(CloogProgram *program, CloogDomainList *) ;
void cloog_program_scatter(CloogProgram *, CloogDomainList *) ;

#if defined(__cplusplus)
  }
#endif 
#endif /* define _H */

