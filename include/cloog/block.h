
   /**-------------------------------------------------------------------**
    **                              CLooG                                **
    **-------------------------------------------------------------------**
    **                             block.h                               **
    **-------------------------------------------------------------------**
    **                    First version: June 11th 2005                  **
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


#ifndef CLOOG_BLOCK_H
#define CLOOG_BLOCK_H
#if defined(__cplusplus)
extern "C" 
  {
#endif 


/**
 * CloogBlock structure:
 * this structure contains the informations of a statement block. It may happen
 * that users are lazy enough to ask CLooG to generate the code for statements
 * with exactly the same domain/scattering pair (possibly differing by only one
 * constant) instead of giving only one pair. CLooG provides them a last chance
 * to save time and memory by trying to find these blocks itself. The block
 * contains the statement list and the common informations of the statements.
 * This structure contains also the number of existing active references to it:
 * because CLooG uses many copies of blocks there is no need to actually copy
 * these blocks but just to return a pointer to them and to increment the number
 * of active references. Each time a CloogBlock will be freed, we will decrement
 * the active reference counter and actually free it if its value is zero.
 */
struct cloogblock
{ CloogStatement * statement ;  /**< The list of statements in the block. */
  CloogMatrix * scattering ;    /**< The scattering function for the block. */
  int  nb_scaldims ;            /**< Number of scalar dimensions. */
  Value * scaldims ;            /**< Scalar dimension values. */
  int depth ;                   /**< Original block depth (outer loop number).*/
  int references ;              /**< Number of references to this structure. */
} ;
typedef struct cloogblock CloogBlock ;


/**
 * CloogBlockList structure:
 * this structure reprensents a node of a linked list of CloogBlock structures.
 */
struct cloogblocklist
{ CloogBlock * block ;          /**< An element of the list. */
  struct cloogblocklist * next ;/**< Pointer to the next element of the list.*/
} ;
typedef struct cloogblocklist CloogBlockList ;


/******************************************************************************
 *                          Structure display function                        *
 ******************************************************************************/
void cloog_block_print_structure(FILE *, CloogBlock *, int) ;
void cloog_block_print(FILE *, CloogBlock *) ;
void cloog_block_list_print(FILE *, CloogBlockList *) ;


/******************************************************************************
 *                         Memory deallocation function                       *
 ******************************************************************************/
void cloog_block_free(CloogBlock *) ;
void cloog_block_list_free(CloogBlockList *) ;


/******************************************************************************
 *                            Processing functions                            *
 ******************************************************************************/
CloogBlock     * cloog_block_malloc() ;
CloogBlock     * cloog_block_alloc(CloogStatement*,CloogMatrix*,int,Value*,int);
CloogBlockList * cloog_block_list_malloc() ;
CloogBlockList * cloog_block_list_alloc(CloogBlock *) ;
CloogBlock     * cloog_block_copy(CloogBlock * block) ;
void             cloog_block_merge(CloogBlock *, CloogBlock *) ;

#if defined(__cplusplus)
  }
#endif 
#endif /* define _H */

