
   /**-------------------------------------------------------------------**
    **                              CLooG                                **
    **-------------------------------------------------------------------**
    **                           statement.h                             **
    **-------------------------------------------------------------------**
    **                  First version: november 4th 2001                 **
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


#ifndef CLOOG_STATEMENT_H
#define CLOOG_STATEMENT_H
#if defined(__cplusplus)
extern "C" 
  {
#endif 


struct cloogstatement
{ int number ;                   /* The statement unique number. */
  void * usr ;                   /* A pointer for library users convenience. */
  struct cloogstatement * next ; /* Pointer to the next statement with the
                                  * same original domain and the same
				  * scattering function.
				  */
} ;
typedef struct cloogstatement CloogStatement ;


/******************************************************************************
 *                          Structure display function                        *
 ******************************************************************************/
void cloog_statement_print_structure(FILE *, CloogStatement *, int) ;
void cloog_statement_print(FILE *, CloogStatement *) ;


/******************************************************************************
 *                         Memory deallocation function                       *
 ******************************************************************************/
void cloog_statement_free(CloogStatement *) ;


/******************************************************************************
 *                            Processing functions                            *
 ******************************************************************************/
CloogStatement * cloog_statement_malloc(void);
CloogStatement * cloog_statement_alloc(int) ;
CloogStatement * cloog_statement_copy(CloogStatement *) ;
void cloog_statement_add(CloogStatement**, CloogStatement**, CloogStatement*) ;

#if defined(__cplusplus)
  }
#endif 
#endif /* define _H */

