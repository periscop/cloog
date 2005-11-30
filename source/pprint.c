
   /**-------------------------------------------------------------------**
    **                              CLooG                                **
    **-------------------------------------------------------------------**
    **                             pprint.c                              **
    **-------------------------------------------------------------------**
    **                  First version: october 26th 2001                 **
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
/* CAUTION: the english used for comments is probably the worst you ever read,
 *          please feel free to correct and improve it !
 */

/* June    22nd 2005: General adaptation for GMP.
 * October 26th 2005: General adaptation from CloogDomain to CloogMatrix data 
 *                    structure for all constraint systems.
 * October 27th 2005: General adaptation from CloogEqual to CloogMatrix data 
 *                    structure for equality spreading.
 */

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../include/cloog/cloog.h"


/******************************************************************************
 *                             Memory leaks hunting                           *
 ******************************************************************************/

/**
 * These global variables are devoted to memory leaks hunting: we
 * want to know at each moment how many Value variables have been allocated
 * since in GMP mode they have to be freed (see domain.c for the declaration).
 * - July 3rd->11th 2003: first version (memory leaks hunt and correction).
 */

extern int cloog_value_allocated ;
extern int cloog_value_freed ;
extern int cloog_value_max ;


/******************************************************************************
 *                        Equalities spreading functions                      *
 ******************************************************************************/


/* Equalities are stored inside a CloogMatrix data structure called "equal".
 * This matrix has (nb_scattering + nb_iterators + 1) rows (i.e. total
 * dimensions + 1, the "+ 1" is because a statement can be included inside an
 * external loop without iteration domain), and (nb_scattering + nb_iterators +
 * nb_parameters + 2) columns (all unknowns plus the scalar plus the equality
 * type). The ith row corresponds to the equality "= 0" for the ith dimension
 * iterator. The first column gives the equality type (0: no equality, then
 * EQTYPE_* -see pprint.h-). At each recursion of pprint, if an equality for
 * the current level is found, the corresponding row is updated. Then the
 * equality if it exists is used to simplify expressions (e.g. if we have 
 * "i+1" while we know that "i=2", we simplify it in "3"). At the end of
 * the pprint call, the corresponding row is reset to zero.
 */


/**
 * pprint_equal_type function :
 * This function returns the type of the equality in the constraint (line) of
 * (equal) for the element (level). An equality is 'constant' iff all other
 * factors are null except the constant one. It is a 'pure item' iff one and
 * only one factor is non null and is 1 or -1. Otherwise it is an 'affine
 * expression'.
 * For instance:
 *   i = -13 is constant, i = j, j = -M are pure items,
 *   j = 2*M, i = j+1 are affine expressions.
 * When the equality comes from a 'one time loop', (line) is ONE_TIME_LOOP.
 * This case require a specific treatment since we have to study all the
 * constraints.
 * - equal is the matrix of equalities,
 * - level is the column number in equal of the element which is 'equal to',
 * - line is the line number in equal of the constraint we want to study;
 *   if it is -1, all lines must be studied.
 **
 * - July     3rd 2002: first version, called pprint_equal_isconstant. 
 * - July     6th 2002: adaptation for the 3 types. 
 * - June    15th 2005: (debug) expr = domain->Constraint[line] was evaluated
 *                      before checking if line != ONE_TIME_LOOP. Since
 *                      ONE_TIME_LOOP is -1, an invalid read was possible.
 * - October 19th 2005: Removal of the once-time-loop specific processing.
 */
int pprint_equal_type(equal, level, line)
CloogMatrix * equal ;
int level, line ;
{ int i, one=0 ;
  Value * expr ;
    
  expr = equal->p[line] ;
  
  /* There is only one non null factor, and it must be +1 or -1 for
   * iterators or parameters.
   */ 
  for (i=1;i<=equal->NbColumns-2;i++)
  if (value_notzero_p(expr[i]) && (i != level))
  { if ((value_notone_p(expr[i]) && value_notmone_p(expr[i])) || (one != 0))
    return EQTYPE_EXAFFINE ;
    else
    one = 1 ;
  }
  /* if the constant factor is non null, it must be alone. */
  if (one != 0)
  { if (value_notzero_p(expr[equal->NbColumns-1]))
    return EQTYPE_EXAFFINE ;
  }
  else
  return EQTYPE_CONSTANT ;
  
  return EQTYPE_PUREITEM ;
}


/**
 * pprint_equal_allow function:
 * This function checks whether the options allow us to spread the equality or
 * not. It returns 1 if so, 0 otherwise.
 * - equal is the matrix of equalities,
 * - level is the column number in equal of the element which is 'equal to',
 * - line is the line number in equal of the constraint we want to study,
 * - the infos structure gives the user all options on code printing and more.
 **
 * - October 27th 2005: first version (extracted from old pprint_equal_add).
 */
int pprint_equal_allow(equal, level, line, infos)
CloogMatrix * equal ;
int level, line ;
CloogInfos * infos ;
{ if ((!infos->options->csp && !infos->options->esp) ||
      (level < infos->options->fsp))
  return 0 ;
  
  if (infos->options->csp &&
      (pprint_equal_type(equal,level,line) == EQTYPE_EXAFFINE) &&
      !infos->options->esp)
  return 0 ;

  return 1 ;
}


/**
 * pprint_equal function:
 * This function returns the content an equality matrix (equal) into a string.
 * - equal is the matrix of equalities,
 * - the infos structure gives the user all options on code printing and more. 
 **
 * - July   2nd 2002: first version. 
 * - March 16th 2003: return now a string instead of printing directly and do
 *                    not write 'Sx()' if there is no spreading, but only 'Sx'. 
 */
char * pprint_equal(equal, infos)
CloogMatrix * equal ;
CloogInfos * infos ;
{ int i, first=1, iterator ;
  char * body, * temp, * seq, * sline ;
  Value type ;

  temp = (char *)malloc(MAX_STRING*sizeof(char)) ;
  body = (char *)malloc(MAX_STRING*sizeof(char)) ;
  body[0] = '\0' ;
  seq = (char *)malloc(MAX_STRING*sizeof(char)) ;
  value_init_c(type) ;
  
  /* It is not necessary to print here the scattering iterators since they
   * never appear in the statement bodies.
   */
  for (i=infos->names->nb_scattering;i<equal->NbRows;i++)
  { if (value_notzero_p(equal->p[i][0])&&pprint_equal_allow(equal,i+1,i,infos))
    { if (!first)
      strcat(body,",") ;
      
      iterator = i - infos->names->nb_scattering ;
      sprintf(temp,"%s = ",infos->names->iterators[iterator]) ;
      strcat(body,temp) ;
    
      /* pprint_line needs to know that the current line is an equality, so
       * we temporary remove the equality type and set it to zero (the equality
       * tag in PolyLib.
       */
      value_assign(type,equal->p[i][0]) ;
      value_set_si(equal->p[i][0],0) ;
      sline = pprint_line(equal,equal,i,i+1,infos) ;
      value_assign(equal->p[i][0],type) ;
      
      strcat(body,sline) ;    
      free(sline) ;
      first = 0 ;
    }
  }
  free(temp) ;
  value_clear_c(type) ;

  if (!first)
  sprintf(seq,"(%s)",body) ;
  else
  sprintf(seq,"%s",body) ;

  free(body) ;

  return(seq) ;
}


/**
 * pprint_equal_cpp function:
 * This function prints the substitution data of a statement into a string.
 * Using this function instead of pprint_equal is useful for generating
 * a compilable pseudo-code by using preprocessor macro for each statement.
 * By opposition to pprint_equal, the result is less human-readable. For
 * instance this function will print (i,i+3,k,3) where pprint_equal would
 * return (j=i+3,l=3).
 * - equal is the matrix of equalities,
 * - level is the number of loops enclosing the statement,
 * - the infos structure gives the user all options on code printing and more.
 **
 * - March    12th 2004: first version. 
 * - November 21th 2005: (debug) now works well with GMP version. 
 */
char * pprint_equal_cpp(equal, level, infos)
CloogMatrix * equal ;
int level ;
CloogInfos * infos ;
{ int i ;
  char * temp, * seq, * sline ;
  Value type ;

  temp = (char *)malloc(MAX_STRING*sizeof(char)) ;
  seq = (char *)malloc(MAX_STRING*sizeof(char)) ;
  seq[0] = '\0' ;
  value_init_c(type) ;
  
  strcat(seq,"(") ;
  for (i=infos->names->nb_scattering;i<level-1;i++)
  { if (value_notzero_p(equal->p[i][0]))
    { /* pprint_line needs to know that the current line is an equality, so
       * we temporary remove the equality type and set it to zero (the equality
       * tag in PolyLib.
       */
      value_assign(type,equal->p[i][0]) ;
      value_set_si(equal->p[i][0],0) ;
      sline = pprint_line(equal,equal,i,i+1,infos) ;
      value_assign(equal->p[i][0],type) ;
      
      strcat(seq,sline) ;    
      free(sline) ;
    }
    else
    { sprintf(temp,"%s",infos->names->iterators[i-infos->names->nb_scattering]);
      strcat(seq,temp) ;
    }
    
    if (i != level-2)
    strcat(seq,",") ;
  }
  free(temp) ;
  value_clear_c(type) ;
  strcat(seq,")") ;

  return(seq) ;
}

 
/**
 * pprint_equal_add function:
 * This function updates the row (level-1) of the equality matrix (equal) with
 * the row that corresponds to the row (line) of the matrix (matrix). It returns
 * 1 if the row can be updated, 0 otherwise.
 * - equal is the matrix of equalities,
 * - matrix is the matrix of constraints,
 * - level is the column number in matrix of the element which is 'equal to',
 * - line is the line number in matrix of the constraint we want to study,
 * - the infos structure gives the user all options on code printing and more.
 **
 * - July     2nd 2002: first version. 
 * - October 19th 2005: Addition of the once-time-loop specific processing.
 */
int pprint_equal_add(equal, matrix, level, line, infos)
CloogMatrix * equal, * matrix ;
int level, line ;
CloogInfos * infos ;
{ int i ;
  Value numerator, denominator, division, modulo ;

  /* If we are in the case of a loop running once, this means that the equality
   * comes from an inequality. Here we find this inequality.
   */
  if (line == ONE_TIME_LOOP)
  { for (i=0;i<matrix->NbRows;i++)
    if ((value_notzero_p(matrix->p[i][0]))&&
        (value_notzero_p(matrix->p[i][level])))
    { line = i ;
      
      /* Since in once-time-loops, equalities derive from inequalities, we
       * may have to offset the values. For instance if we have 2i>=3, the
       * equality is in fact i=2. This may happen when the level coefficient is
       * not 1 or -1 and the scalar value is not zero. In any other case (e.g.,
       * if the inequality is an expression including outer loop counters or
       * parameters) the once time loop would not have been detected
       * because of floord and ceild functions.
       */
      if (value_ne_si(matrix->p[i][level],1) &&
          value_ne_si(matrix->p[i][level],-1) &&
	  value_notzero_p(matrix->p[i][matrix->NbColumns-1]))
      { value_init_c(numerator) ;
        value_init_c(denominator) ;
        value_init_c(division) ;
        value_init_c(modulo) ;
        
	value_assign(denominator,matrix->p[i][level]) ;
	value_absolute(denominator,denominator) ; 
        value_assign(numerator,matrix->p[i][matrix->NbColumns-1]) ;   
        value_modulus(modulo,numerator,denominator) ;
        value_division(division,numerator,denominator) ;
	
	/* There are 4 scenarios:
	 *  di +n >= 0  -->  i + (n div d) >= 0
	 * -di +n >= 0  --> -i + (n div d) >= 0
	 *  di -n >= 0  -->  if (n%d == 0)  i + ((-n div d)+1) >= 0
	 *                   else           i +  (-n div d)    >= 0
	 * -di -n >= 0  -->  if (n%d == 0) -i + ((-n div d)-1) >= 0
	 *                   else          -i +  (-n div d)    >= 0
	 * In the following we distinct the scalar value setting and the
	 * level coefficient.
	 */
	if (value_pos_p(numerator) || value_zero_p(modulo))
	value_assign(matrix->p[i][matrix->NbColumns-1],division) ;
	else
	{ if (value_pos_p(matrix->p[i][level]))
	  value_increment(matrix->p[i][matrix->NbColumns-1],division) ;
	  else
	  value_decrement(matrix->p[i][matrix->NbColumns-1],division) ;
	}
        
	if (value_pos_p(matrix->p[i][level]))
	value_set_si(matrix->p[i][level],1) ;
	else
	value_set_si(matrix->p[i][level],-1) ;
	
	value_clear_c(numerator) ;
        value_clear_c(denominator) ;
        value_clear_c(division) ;
        value_clear_c(modulo) ;
      }
            
      break ;
    }
  }
  
  /* We update the line of equal corresponding to level:
   * - the first element gives the equality type,
   */
  value_set_si(equal->p[level-1][0],pprint_equal_type(matrix,level,line)) ;
  /* - the other elements corresponding to the equality itself
   *   (the iterators up to level, then the parameters and the scalar).
   */
  for (i=1;i<=level;i++)
  value_assign(equal->p[level-1][i],matrix->p[line][i]) ;
  for (i=0;i<infos->names->nb_parameters+1;i++)
  value_assign(equal->p[level-1][equal->NbColumns-i-1],
               matrix->p[line][matrix->NbColumns-i-1]) ;
  
  cloog_matrix_equality_update(equal,level,infos->names->nb_parameters) ;
  
  return (pprint_equal_allow(equal,level,level-1,infos)) ;
}
  

/**
 * pprint_equal_del function :
 * This function reset the equality corresponding to the iterator (level)
 * in the equality matrix (equal).
 * - July 2nd 2002: first version. 
 */
void pprint_equal_del(CloogMatrix * equal, int level)
{ int i ;
  
  for (i=0;i<equal->NbColumns;i++)
  value_set_si(equal->p[level-1][i],0) ;
}


/******************************************************************************
 *                       Pretty Printing (dirty) functions                    *
 ******************************************************************************/


/**
 * pprint_val function:
 * This function returns a string containing the printing of a value (possibly
 * an iterator or a parameter with its coefficient or a constant).
 * - val is the coefficient or constant value,
 * - first is a pointer to a boolean set to 1 if the current value is the first
 *   of an expresion, 0 otherwise (this function can change it),
 * - cst is a boolean set to 1 if the value is a constant, 0 otherwise,
 * - name is a string containing the name of the iterator or of the parameter,
 * - the infos structure gives the user some options about code printing,
 *   the number of parameters in domain (nb_par), and the arrays of iterator
 *   names and parameters (iters and params). 
 **
 * - November 2nd 2001: first version. 
 * - November 8th 2001: complete rewriting. 
 * - July 6th 2002: integration of the equality spreading.
 * - October 10th 2002: (debug) sline was sometimes freed twice (hard to find !)
 *                      and equality spreading gives no more (for instance) --2
 *                      but -(-2). (November 2005: now it's 2 !).
 * - June 27th 2003: 64 bits version ready.
 */
char * pprint_val(val, level, first, cst, name, infos)
Value val ;
int level, * first, cst ;
char * name ;
CloogInfos * infos ;
{ char * sval, * body, * temp ;

  temp = (char *)malloc(MAX_STRING_VAL*sizeof(char)) ;
  body = (char *)malloc(MAX_STRING_VAL*sizeof(char)) ;
  sval = (char *)malloc(MAX_STRING_VAL*sizeof(char)) ;
  body[0] = '\0' ;
  sval[0] = '\0' ;

  /* statements for the 'normal' processing. */
  if (value_notzero_p(val) && (!cst))
  { if ((*first) || value_neg_p(val))
    { if (value_one_p(val))          /* case 1 */
      sprintf(sval,"%s",name) ;
      else
      { if (value_mone_p(val))       /* case -1 */
        sprintf(sval,"-%s",name) ;
	else                         /* default case */
	{ value_sprint(sval,VALUE_FMT,val) ;
	  sprintf(temp,"*%s",name) ;
	  strcat(sval,temp) ;
        }
      }
      *first = 0 ;
    }
    else
    { if (value_one_p(val))
      sprintf(sval,"+%s",name) ;
      else
      { sprintf(sval,"+") ;
	value_sprint(temp,VALUE_FMT,val) ;
	strcat(sval,temp) ;
	sprintf(temp,"*%s",name) ;
	strcat(sval,temp) ;
      }
    }
  }
  else
  { if (cst)
    { if ((value_zero_p(val) && (*first)) || value_neg_p(val))
      value_sprint(sval,VALUE_FMT,val) ;
      if (value_pos_p(val))
      { if (!(*first))
        { value_sprint(sval,"+"VALUE_FMT,val) ; /* Block macro ! */
	}
	else
        value_sprint(sval,VALUE_FMT,val) ;
      }
    }
  }
  free(temp) ;
  free(body) ;
  
  return(sval) ;
}
 

/**
 * pprint_line function:
 * This function returns a string containing the printing of the 'right part'
 * of a constraint according to an element.
 * For instance, for the constraint -3*i + 2*j - M >=0 and the element j,
 * we have j >= (3*i + M)/2. As we are looking for integral solutions, this
 * function should return 'ceild(3*i+M,2)'.
 * - matrix is the polyhedron containing all the constraints,
 * - line_num is the line number in domain of the constraint we want to print,
 * - level is the column number in domain of the element we want to use,
 * - the infos structure gives the user some options about code printing,
 *   the number of parameters in domain (nb_par), and the arrays of iterator
 *   names and parameters (iters and params). 
 **
 * - November 2nd 2001: first version. 
 * - June    27th 2003: 64 bits version ready.
 */
char * pprint_line(matrix, equal, line_num, level, infos)
CloogMatrix * matrix, * equal ;
int line_num, level ;
CloogInfos * infos ;
{ int i, nb_iter, sign, first=1, nb_elts=0 ;
  char * sval, * body, * sline, * name, * stemp ;
  Value * line, numerator, denominator, temp, division ;

  line = matrix->p[line_num] ;
  value_init_c(temp) ;
  value_init_c(numerator) ;
  value_init_c(denominator) ;

  stemp = (char *)malloc(MAX_STRING*sizeof(char)) ;
  body = (char *)malloc(MAX_STRING*sizeof(char)) ;
  body[0] = '\0' ;
  sline = (char *)malloc(MAX_STRING*sizeof(char)) ;
  sline[0] = '\0' ;

  if (value_notzero_p(line[level]))
  { /* Maybe we need to invert signs in such a way that the element sign is>0.*/
    sign = value_pos_p(line[level]) ? -1 : 1 ;

    /* First, we have to print the iterators. */
    nb_iter = matrix->NbColumns - 2 - infos->names->nb_parameters ;
    for (i=1;i<=nb_iter;i++)
    if ((i != level) && value_notzero_p(line[i]))
    { if (i <= infos->names->nb_scattering)
      name = infos->names->scattering[i-1] ;
      else
      name = infos->names->iterators[i-infos->names->nb_scattering-1] ;
      
      if (sign == -1)
      value_oppose(temp,line[i]) ;
      else
      value_assign(temp,line[i]) ;
      
      sval = pprint_val(temp,i,&first,0,name,infos) ;
      strcat(body,sval) ;
      free(sval) ;
      nb_elts ++ ;
    }    

    /* Next, the parameters. */
    for (i=nb_iter+1;i<=matrix->NbColumns-2;i++)
    if ((i != level) && value_notzero_p(line[i]))
    { name = infos->names->parameters[i-nb_iter-1] ;
      
      if (sign == -1)
      value_oppose(temp,line[i]) ;
      else
      value_assign(temp,line[i]) ;
      
      sval=pprint_val(temp,-1,&first,0,name,infos) ;
      strcat(body,sval) ;
      free(sval) ;
      nb_elts ++ ;
    }    

    if (sign == -1)
    { value_oppose(numerator,line[matrix->NbColumns - 1]) ;
      value_assign(denominator,line[level]) ;
    }
    else
    { value_assign(numerator,line[matrix->NbColumns - 1]) ;
      value_oppose(denominator,line[level]) ;
    }
        
    /* Finally, the constant, and the final printing. */
    if (!first)
    { sval = pprint_val(numerator,-1,&first,1,"",infos) ;
      strcat(body,sval) ;
      if (strlen(sval)>0)
      nb_elts ++ ;
      free(sval) ;
    
      if (value_notone_p(line[level]) && value_notmone_p(line[level]))
      { if (value_one_p(line[0]))
        { if (value_pos_p(line[level]))
          { if (infos->language == LANGUAGE_FORTRAN)
            { sprintf(sline,"CEILING(REAL(%s)/REAL(",body) ;
              value_sprint(stemp,VALUE_FMT"))",denominator) ;
	    }
	    else
            { sprintf(sline,"ceild(%s,",body) ;
	      value_sprint(stemp,VALUE_FMT")",denominator) ;
	    }
          }
          else
          { if (infos->language == LANGUAGE_FORTRAN)
            { sprintf(sline,"FLOOR(REAL(%s)/REAL(",body) ;
	      value_sprint(stemp,VALUE_FMT"))",denominator) ;
	    }
            else
            { sprintf(sline,"floord(%s,",body) ;
	      value_sprint(stemp,VALUE_FMT")",denominator) ;
	    }
          }
        }
        else
        { if (nb_elts > 1)
          sprintf(sline,"(%s)/",body) ;
          else
          sprintf(sline,"%s/",body) ;

	  value_sprint(stemp,VALUE_FMT,denominator) ;
        }  
	strcat(sline,stemp) ;
      }
      else
      sprintf(sline,"%s",body) ;
    }
    else
    { if (value_zero_p(numerator))
      sprintf(sline,"0") ;
      else
      { if (value_notone_p(denominator))
        { if (value_one_p(line[0])) /* useful? */
          { value_modulus(temp,numerator,denominator) ;
            if (value_zero_p(temp))
            { value_division(temp,numerator,denominator) ;
              value_sprint(sline,VALUE_FMT,temp) ;
            }
            else
            { value_init_c(division) ;
	      value_division(division,numerator,denominator) ;
	      if (value_neg_p(numerator))
              { if (value_pos_p(line[level]))
                /* nb<0 need max */
                { value_sprint(sline,VALUE_FMT,division) ; /* Block macro ! */
		}
                else
                { /* nb<0 need min */
                  value_decrement(temp,division) ;
		  value_sprint(sline,VALUE_FMT,temp) ;
                }
	      }
              else
              { if (value_pos_p(line[level]))
	        { /* nb>0 need max */
                  value_increment(temp,division) ;
		  value_sprint(sline,VALUE_FMT,temp) ;
                }
		else
		/* nb>0 need min */
                value_sprint(sline,VALUE_FMT,division) ;
              }
	      value_clear_c(division) ;
            }
          }
          else
          { value_sprint(sline,VALUE_FMT"/",numerator) ;
	    value_sprint(stemp,VALUE_FMT,denominator) ;
	    strcat(sline,stemp) ;
	  }
        }
        else
        value_sprint(sline,VALUE_FMT,numerator) ;      
      }
    }
  }

  free(stemp) ;
  free(body) ;
  value_clear_c(temp) ;
  value_clear_c(numerator) ;
  value_clear_c(denominator) ;
    
  return(sline) ;
}


/**
 * pprint_minmax function:
 * This function returns a string containing the printing of a minimum or a
 * maximum of the 'right parts' of all constraints according to an element.
 * For instance consider the constraints:
 * -3*i  +2*j   -M >= 0
 *  2*i    +j      >= 0
 *   -i    -j +2*M >= 0
 * if we are looking for the minimum for the element j, the function should
 * return 'max(ceild(3*i+M,2),-2*i)'.
 * - matrix is the polyhedron containing all the constraints,
 * - level is the column number in domain of the element we want to use,
 * - max is a boolean set to 1 if we are looking for a maximum, 0 for a minimum,
 * - guard is set to 0 if there is no guard, and set to the level of the element
 *   with a guard otherwise (then the function gives the max or the min only
 *   for the constraint where the guarded coefficient is 0), 
 * - the infos structure gives the user some options about code printing,
 *   the number of parameters in domain (nb_par), and the arrays of iterator
 *   names and parameters (iters and params). 
 **
 * - November 2nd 2001: first version. 
 */
char * pprint_minmax(matrix, equal, level, max, guard, infos)
CloogMatrix * matrix, * equal ;
int level, max, guard ;
CloogInfos * infos ;
{ int i, first=1 ;
  char * sline, * body, * sminmax ;
  
  body = (char *)malloc(MAX_STRING*sizeof(char)) ;
  body[0] = '\0' ;
  sminmax = (char *)malloc(MAX_STRING*sizeof(char)) ;
  sminmax[0] = '\0' ;

  for (i=0;i<matrix->NbRows;i++)
  if (((max && value_pos_p(matrix->p[i][level])) ||
       (!max && value_neg_p(matrix->p[i][level]))) &&
      (!guard || value_zero_p(matrix->p[i][guard])) &&
      (value_notzero_p(matrix->p[i][0])))
  { sline = pprint_line(matrix,equal,i,level,infos) ;
    strcat(sminmax,sline) ;
    free(sline) ;
    break ;
  }
  /* We begin after the first found element. */
  for (i++;i<matrix->NbRows;i++)
  if (((max && value_pos_p(matrix->p[i][level])) ||
       (!max && value_neg_p(matrix->p[i][level]))) &&
      (!guard || value_zero_p(matrix->p[i][guard])) &&
      (value_notzero_p(matrix->p[i][0])))
  { sline = pprint_line(matrix,equal,i,level,infos) ;
    
    if (infos->language == LANGUAGE_FORTRAN)
    { if (first)
      { if (max)
        sprintf(body,"MAX(%s,%s",sminmax,sline) ;
        else
        sprintf(body,"MIN(%s,%s",sminmax,sline) ;
        
        first = 0 ;
        sprintf(sminmax,"%s",body) ;
      }
      else
      { sprintf(body,",%s",sline) ;
        strcat(sminmax,body) ;
      }
    }
    else
    { if (max)
      sprintf(body,"max(%s,%s)",sminmax,sline) ;
      else
      sprintf(body,"min(%s,%s)",sminmax,sline) ;
  
      sprintf(sminmax,"%s",body) ;
    } 
    
    free(sline) ;
  }
  free(body) ;
  
  if ((infos->language == LANGUAGE_FORTRAN) && (!first))
  strcat(sminmax,")") ;
  
  return(sminmax) ;
}


/**
 * pprint_guard function:
 * This function returns a string containing the printing of a guard.
 * A guard on an element (level) is :
 * -> the conjunction of all the existing constraints where the coefficient of
 *    this element is 0 if the element is an iterator,
 * -> the conjunction of all the existing constraints if the element isn't an
 *    iterator.
 * For instance, considering these constraints and the element j:
 * -3*i +2*j -M >= 0
 *  2*i      +M >= 0
 * this function should return 'if (2*i+M>=0) {'.
 * - matrix is the polyhedron containing all the constraints,
 * - level is the column number of the element in matrix we want to use,
 * - guard is a pointer to a boolean set to 0 if there is no guard, 1 otherwise,
 *   this function can set this boolean to 1 if there is a guard,
 * - indent is a pointer to an integer giving the indent level, this function
 *   can increase indent if there is a guard,
 * - the infos structure gives the user some options about code printing,
 *   the number of parameters in matrix (nb_par), and the arrays of iterator
 *   names and parameters (iters and params). 
 **
 * - November  3rd 2001: first version. 
 * - November 14th 2001: a lot of 'purifications'. 
 * - July     31th 2002: (debug) some guard parts are no more redundants. 
 * - August   12th 2002: polyhedra union ('or' conditions) are now supported.
 * - October  27th 2005: polyhedra union ('or' conditions) are no more supported
 *                       (the need came from loop_simplify that may result in
 *                       domain unions, now it should be fixed directly in
 *                       cloog_loop_simplify).
 */
char * pprint_guard(matrix, equal, level, guard, indent, infos)
CloogMatrix * matrix, * equal ;
int level, * guard, * indent ;
CloogInfos * infos ;
{ int i, j, k, l, guarded, minmax=-1, nb_and = 0, nb_iter ;
  char * name, * sline, * body, * temp, * sguard ;
  CloogMatrix * copy ;

  temp = (char *)malloc(MAX_STRING*sizeof(char)) ;
  body = (char *)malloc(MAX_STRING*sizeof(char)) ;
  sguard = (char *)malloc(MAX_STRING*sizeof(char)) ;
  sguard[0] = '\0' ;
  
  if (matrix != NULL)
  { /* Well, it looks complicated because I wanted to have a particular, more
     * readable, ordering, obviously this function may be far much simpler !
     */
    copy = cloog_matrix_copy(matrix) ;
    
    nb_iter = copy->NbColumns - 2 - infos->names->nb_parameters ;
 
    nb_and = 0 ;
    body[0] = '\0' ;
    /* We search for guard parts. */
    for (i=1;i<=copy->NbColumns-2;i++)
    for (j=0;j<copy->NbRows;j++)
    if (value_notzero_p(copy->p[j][i]) &&
        (value_zero_p(copy->p[j][level]) || (nb_iter < level)))
    { if (i <= nb_iter)
      { if (i <= infos->names->nb_scattering)
        name = infos->names->scattering[i-1] ;
        else
        name = infos->names->iterators[i-infos->names->nb_scattering-1] ;
      }
      else
      name = infos->names->parameters[i-(nb_iter+1)] ;
      
      if (nb_and)
      { if (infos->language == LANGUAGE_FORTRAN)
        strcat(body," .AND. ") ;
        else
        strcat(body," && ") ;
      }
      
      if (value_zero_p(copy->p[j][0]))
      { sprintf(temp,"(%s == ",name) ;
        sline = pprint_line(copy,equal,j,i,infos) ;
      }
      else
      { if (value_pos_p(copy->p[j][i]))
        { sprintf(temp,"(%s >= ",name) ;
          minmax = 1 ;
        }
        else
        { sprintf(temp,"(%s <= ",name) ;
          minmax = 0 ;
        }
      
        guarded = (nb_iter >= level) ? level : 0 ;
        sline = pprint_minmax(copy,equal,i,minmax,guarded,infos) ;
      }
      
      strcat(body,temp) ;
      strcat(body,sline) ;
      strcat(body,")") ;
      nb_and ++ ;
      free(sline) ;

      /* 'elimination' of the current constraint, this avoid to use one
       * constraint more than once. The current line is always eliminated,
       * and the next lines if they are in a min or a max.
       */
      for (k=i;k<=copy->NbColumns-2;k++)
      value_set_si(copy->p[j][k],0) ;
    
      if (minmax != -1)
      for (l=j+1;l<copy->NbRows;l++)
      if (((minmax == 1) && value_pos_p(copy->p[l][i])) ||
          ((minmax == 0) && value_neg_p(copy->p[l][i])))
      for (k=i;k<=copy->NbColumns-2;k++)
      value_set_si(copy->p[l][k],0) ;
    }
    cloog_matrix_free(copy) ;
  }
  free(temp) ;
  
  if (nb_and)
  { for (k=0;k<(*indent);k++)
    strcat(sguard," ") ;
    
    if (infos->language == LANGUAGE_FORTRAN)
    strcat(sguard,"IF ") ;
    else
    strcat(sguard,"if ") ;
    
    if (nb_and > 1)
    { strcat(sguard,"(") ;
      strcat(sguard,body) ;
      strcat(sguard,")") ;
    }
    else
    strcat(sguard,body) ;
    
    if (infos->language == LANGUAGE_FORTRAN)
    strcat(sguard," THEN\n") ;
    else
    strcat(sguard," {\n") ;
    *guard = 1 ;
    *indent += INDENT_STEP ;
  }
  free(body) ;
  
  return(sguard) ;
}
 
  
/**
 * pprint_equality function:
 * This function returns a string containing the printing of an equality 
 * constraint according to an element.
 * An equality can be preceded by a 'modulo guard'.
 * For instance, consider the constraint i -2*j = 0 and the
 * element j: pprint_equality should return 'if(i%2==0) { j = i/2 ;'.
 * - matrix is the polyhedron containing all the constraints,
 * - num is the line number of the constraint in matrix we want to print,
 * - level is the column number of the element in matrix we want to use,
 * - modulo_guard is a pointer to a boolean set to 0 if there is no modulo
 *   guard, 1 otherwise, this function can set this boolean to 1,
 * - indent is a pointer to an integer giving the indent level, this function
 *   can increase indent if there is a modulo guard,
 * - the infos structure gives the user some options about code printing,
 * - the infos structure gives the user some options about code printing,
 *   the number of parameters in matrix (nb_par), and the arrays of iterator
 *   names and parameters (iters and params). 
 **
 * - November 13th 2001: first version.
 * - June 26th 2003: simplification of the modulo guards (remove parts such as
 *                   modulo is 0, compare vivien or vivien2 with a previous
 *                   version for an idea).
 * - June 29th 2003: non-unit strides support.
 * - July 14th 2003: (debug) no more print the constant in the modulo guard when
 *                   it was previously included in a stride calculation.
 */
 char * pprint_equality(matrix, equal, num, level, modulo_guard, indent, infos)
CloogMatrix * matrix, * equal ;
int num, level, * modulo_guard, * indent ;
CloogInfos * infos ;
{ int i, sign, first=1, nb_elts=0, nb_iter=0, guarded=0, in_stride=0 ;
  char * body, * seq, * sval, * sline, * name ;
  Value * line, val ;

  value_init_c(val) ;

  body = (char *)malloc(MAX_STRING*sizeof(char)) ;
  body[0] = '\0' ;
  seq = (char *)malloc(MAX_STRING*sizeof(char)) ;
  seq[0] = '\0' ;
    
  line = matrix->p[num] ;
  sign = value_pos_p(line[level]) ? -1 : 1 ;
  nb_iter = matrix->NbColumns - 2 - infos->names->nb_parameters ;

  /* First, the modulo guard : the iterators... */
  for (i=1;i<=nb_iter;i++)
  { value_modulus(val,line[i],line[level]) ;
    if ((i != level) && value_notzero_p(line[i]) && value_notzero_p(val))
    { value_modulus(val,infos->stride[i-1],line[level]) ;
      if (value_notzero_p(val))
      { if (sign == -1)
	value_oppose(val,line[i]) ;
	else
	value_assign(val,line[i]) ;
	
	if (i <= infos->names->nb_scattering)
        name = infos->names->scattering[i-1] ;
        else
        name = infos->names->iterators[i-infos->names->nb_scattering-1] ;
      
        sval = pprint_val(val,i,&first,0,name,infos) ;
        strcat(body,sval) ;
        free(sval) ;
        nb_elts ++ ;
      }
      else
      /* We need to know if an element of the equality has not to be printed
       * because of a stride that guarantees that this element can be divided by
       * the current coefficient. Because when there is a constant element, it
       * is included in the stride calculation (more exactly in the strided
       * iterator new lower bound: the 'offset') and we have not to print it.
       */
      if (value_notone_p(infos->stride[i-1]))
      in_stride = 1 ;
    }
  }

  /* ...the parameters... */
  for (i=nb_iter+1;i<=matrix->NbColumns-2;i++)
  { value_modulus(val,line[i],line[level]) ;
    if (value_notzero_p(line[i]) && value_notzero_p(val))
    { if (sign == -1)
      value_oppose(val,line[i]) ;
      else
      value_assign(val,line[i]) ;
	
      name = infos->names->parameters[i-nb_iter-1] ;
      sval = pprint_val(val,-1,&first,0,name,infos) ;
      strcat(body,sval) ;
      free(sval) ;
      nb_elts ++ ;
    }
  }    

  /* ...the constant. */
  value_modulus(val,line[matrix->NbColumns-1],line[level]) ;
  if ((nb_elts || (value_notzero_p(val) && (!in_stride))) &&
      value_notone_p(line[level]) && value_notmone_p(line[level]))
  { if (sign == -1)
    value_oppose(val,line[matrix->NbColumns-1]) ;
    else
    value_assign(val,line[matrix->NbColumns-1]) ;
    
    sval = pprint_val(val,-1,&first,1,"",infos) ;
    strcat(body,sval) ;
    if (strlen(sval)>0)
    nb_elts ++ ;
    free(sval) ;
  
    for (i=0;i<(*indent);i++)
    strcat(seq," ") ;
    
    if (infos->language == LANGUAGE_FORTRAN)
    strcat(seq,"IF (") ;
    else
    strcat(seq,"if (") ;
    
    if ((-1 * sign) == -1)
    value_oppose(val,line[level]) ;
    else
    value_assign(val,line[level]) ;
    
    if (infos->language == LANGUAGE_FORTRAN)
    { strcat(seq,"MOD(") ;
      strcat(seq,body) ;
      value_sprint(body,","VALUE_FMT") == 0) THEN\n",val) ;
    }  
    else
    { if (nb_elts > 1)
      { strcat(seq,"(") ;
        strcat(seq,body) ;
        strcat(seq,")") ;
      }
      else
      strcat(seq,body) ;
    
      strcat(seq,"\%") ;
      value_sprint(body,VALUE_FMT" == 0) {\n",val) ;
    }
        
    strcat(seq,body) ;
    *modulo_guard = 1 ;
    *indent += INDENT_STEP ;
    guarded = 1 ;
  }       
 
  if (!pprint_equal_add(equal,matrix,level,num,infos))
  { /* Finally, the equality. */
    for (i=0;i<(*indent);i++)
    strcat(seq," ") ;
		
    /* If we have to make a block by dimension, we start the block. Function
     * pprint knows if there is an equality, if this is the case, it checks
     * for the same following condition to close the brace.
     */
    if (infos->options->block && (infos->language==LANGUAGE_C))
    { strcat(seq,"{ ") ;
      *indent += INDENT_STEP ;
    }
		
    if (level <= infos->names->nb_scattering)
    sprintf(body,"%s = ",infos->names->scattering[level-1]) ;
    else
    sprintf(body,"%s = ",
            infos->names->iterators[level-infos->names->nb_scattering-1]) ;

    strcat(seq,body) ;
    sline = pprint_line(matrix,equal,num,level,infos) ;
    if (infos->language == LANGUAGE_FORTRAN)
    sprintf(body,"%s\n",sline) ;
    else
    sprintf(body,"%s ;\n",sline) ;
    strcat(seq,body) ;
    free(sline) ;
  }

  free(body) ;
  value_clear_c(val) ;
  
  return(seq) ;
}


/**
 * pprint_for function:
 * This function returns a string containing the printing of a loop header
 * according to an element.
 * A loop header according to an element is the conjonction of a minimum and a
 * maximum on the element (they give the loop bounds).
 * For instance, considering these constraints and the element j:
 * i + j -9*M >= 0
 *    -j +5*M >= 0
 *     j -4*M >= 0
 * this function should return 'for (j=max(-i+9*M,4*M),j<=5*M;j++) {'.
 * - matrix is the polyhedron containing all the constraints,
 * - level is the column number of the element in matrix we want to use,
 * - accol is a pointer to a boolean set to 0 if there is no 'if', 1 otherwise,
 *   this function can set this boolean to 1 if there is a 'if',
 * - indent is a pointer to an integer giving the indent level, this function
 *   can increase indent if there is a 'if',
 * - the infos structure gives the user some options about code printing,
 *   the number of parameters in matrix (nb_par), and the arrays of iterator
 *   names and parameters (iters and params). 
 **
 * - July 2nd 2002: first version (pick from pprint function). 
 * - March 6th 2003: infinite domain support. 
 * - June 29th 2003: non-unit strides support.
 */
char * pprint_for(matrix, equal, level, accol, indent, infos)
CloogMatrix * matrix, * equal ;
int level, * accol, * indent ;
CloogInfos * infos ;
{ int i ;
  char * sfor, * sline1, *sline2, * temp, * iterator ;
  
  if (level <= infos->names->nb_scattering)
  iterator = infos->names->scattering[level-1] ;
  else
  iterator = infos->names->iterators[level-infos->names->nb_scattering-1] ;
  
  temp = (char *)malloc(MAX_STRING*sizeof(char)) ;
  sfor = (char *)malloc(MAX_STRING*sizeof(char)) ;
  sfor[0] = '\0' ;
        
  sline1 = pprint_minmax(matrix,equal,level,1,0,infos) ;
  sline2 = pprint_minmax(matrix,equal,level,0,0,infos) ;

  /* If min and max are not equal there is a 'for' else, there is a '='.
   * In the special case sline1 = sline2 = '\0', this is an infinite loop
   * so this is not a '='.
   */
  if ((strcmp(sline1,sline2) != 0) || !infos->options->otl ||
      ((strlen(sline1) == 0) && (strlen(sline2) == 0)))
  { for (i=0;i<(*indent);i++)
    strcat(sfor," ") ;
    
    if (infos->language == LANGUAGE_FORTRAN)
    sprintf(temp,"DO ") ;
    else
    sprintf(temp,"for (") ;
    
    strcat(sfor,temp) ;
    if (strlen(sline1) != 0)
    { sprintf(temp,"%s=%s",iterator,sline1) ;
      strcat(sfor,temp) ;
    }
    else
    if (infos->language == LANGUAGE_FORTRAN)
    { fprintf(stderr,"[CLooG]ERROR: unbounded loops not allowed in FORTRAN.\n");
      exit(1) ;
    }

    if (infos->language == LANGUAGE_FORTRAN)
    sprintf(temp,", ") ;
    else
    sprintf(temp,";") ;

    strcat(sfor,temp) ;
    if (strlen(sline2) != 0)
    { if (infos->language == LANGUAGE_FORTRAN)
      sprintf(temp,"%s",sline2) ;
      else
      sprintf(temp,"%s<=%s",iterator,sline2) ;
      
      strcat(sfor,temp) ;
    }
    else
    if (infos->language == LANGUAGE_FORTRAN)
    { fprintf(stderr,"[CLooG]ERROR: unbounded loops not allowed in FORTRAN.\n");
      exit(1) ;
    }
    
    if (infos->language == LANGUAGE_FORTRAN)
    { if (value_gt_si(infos->stride[level-1],1))
      { value_sprint(temp,", "VALUE_FMT"\n",infos->stride[level-1]) ;
      }
      else
      sprintf(temp,"\n") ;
    }
    else
    { if (value_gt_si(infos->stride[level-1],1))
      { sprintf(temp,";%s+=",iterator) ; /* sline2 may be reused safely here. */
        value_sprint(sline2,VALUE_FMT") {\n",infos->stride[level-1]) ;
	strcat(temp,sline2) ;
      }
      else
      sprintf(temp,";%s++) {\n",iterator) ;
    }
    
    *accol = 1 ;
    strcat(sfor,temp) ;
  }
  else
  if (!pprint_equal_add(equal,matrix,level,ONE_TIME_LOOP,infos))
  { for (i=0;i<(*indent);i++)
    strcat(sfor," ") ;
    if (infos->language == LANGUAGE_FORTRAN)
    sprintf(temp,"%s = %s\n",iterator,sline1);
    else
    { /* If the option block is set, build the block. */
      if (infos->options->block)
      { strcat(sfor,"{ ") ;
        *accol = 1 ;
      }
       sprintf(temp,"%s = %s ;\n",iterator,sline1);
    }
    strcat(sfor,temp) ;
  }

  free(temp) ;
  free(sline1) ;
  free(sline2) ;

  return(sfor) ;    
}


/**
 * pprint_scalar function:
 * This function returns a string containing the printing of the scalar values
 * that follows the level (level). It finds by scanning (loop) by inner level,
 * the first CloogBlock data structure (at this step, all blocks has the same
 * scalar vector information after (level)), and prints all the adjacent
 * scalar values following (level), if it is required by options in (info).
 * - loop is the loop structure to begin the search for a block,
 * - level is the current loop level,
 * - scalar points to the number of scalar values already visited,
 * - scalbraces points to the number of braces to close for scalar dimensions,
 * - indent points to the number of space required for indentation,
 * - the infos structure gives the user options about code printing and more.
 **
 * - September 12th 2005: first version.
 */
char * pprint_scalar(loop, level, scalar, scalbraces, indent, infos)
CloogLoop * loop ;
int level, * scalar, * scalbraces, * indent ;
CloogInfos * infos ;
{ int i ;
  char * sscalar, * temp ;
  
  sscalar = (char *)malloc(MAX_STRING*sizeof(char)) ;
  sscalar[0] = '\0' ;

  if ((!infos->options->csp) &&
      (level+(*scalar) <= infos->nb_scattdims) &&
      (infos->scaldims[level+(*scalar)-1]))
  { while (loop->block == NULL)
    loop = loop->inner ;

    temp = (char *)malloc(MAX_STRING*sizeof(char)) ;
    while ((level+(*scalar) <= infos->nb_scattdims) &&
           (infos->scaldims[level+(*scalar)-1]))
    { for (i=0;i<(*indent);i++)
      strcat(sscalar," ") ;
      
      if (infos->options->block)
      { strcat(sscalar,"{ ") ;
        (*scalbraces) ++ ;
      }
      
      sprintf(temp,"%s = ",infos->names->scalars[(*scalar)]) ;
      strcat(sscalar,temp) ;
      value_sprint(temp,VALUE_FMT" ;\n",loop->block->scaldims[(*scalar)]) ;
      strcat(sscalar,temp) ;
      (*scalar) ++ ;
      
      if (infos->options->block)
      *indent += INDENT_STEP ;
    }
    free(temp) ;
  }
  
  return(sscalar) ;
}


/**
 * pprint_block function:
 * This function returns a string containing the printing of a statement block
 * structure.
 * - block is the statement block,
 * - level is the number of loops enclosing the statement,
 * - accol is a pointer to a boolean set to 0 if there is no 'if' before the
 *   statement, 1 otherwise,
 * - indent is a pointer to an integer giving the indentation level,
 * - the infos structure gives the user some options about code printing,
 *   the number of parameters in domain (nb_par), and the arrays of iterator
 *   names and parameters (iters and params). 
 **
 * - September 21th 2003: first version (pick from pprint function). 
 */
char * pprint_block(block, equal, level, accol, indent, infos)
CloogBlock * block ;
CloogMatrix * equal ;
int level, accol, indent ;
CloogInfos * infos ;
{ int i, new_indent ;
  char * sstatement, * sline, * temp ;
  CloogStatement * statement ;
   
  sstatement = (char *)malloc(MAX_STRING*sizeof(char)) ;
  sstatement[0] = '\0' ;
          
  if (block != NULL)
  { temp = (char *)malloc(MAX_STRING*sizeof(char)) ;
    
    statement = block->statement ;
 
    while (statement != NULL)
    { new_indent = (accol == 1) ? indent + INDENT_STEP : indent ;
  
      /* Printing of one statement. */
      for (i=0;i<new_indent;i++)
      strcat(sstatement," ") ;
      
      if (infos->options->cpp == 0)
      sline = pprint_equal(equal,infos) ;
      else
      sline = pprint_equal_cpp(equal,level,infos) ;
      
      sprintf(temp,"S%d%s",statement->number+1,sline) ;
      strcat(sstatement,temp) ;
      free(sline) ;     
      
      if (infos->language != LANGUAGE_FORTRAN)
      strcat(sstatement," ;") ;
      strcat(sstatement,"\n") ;
       
      statement = statement->next ;
    }
    free(temp) ;
  }
  
  return(sstatement) ;
}


/**
 * pprint function:
 * This function prints the content of a CloogLoop structure (loop) into a
 * file (foo, possibly stdout), in a C-like or FORTRAN-like language.
 * This function pretty-prints the data of a loop. The iterator (level) of
 * the current loop is given by 'level': this is the column number of the
 * domain corresponding to the current loop iterator. The data of a loop are
 * written in this order:
 * 1. The guard of the loop, i.e. each constraint in the domain that do not
 *    depend on the iterator (when the entry in the column 'level' is 0).
 * 2. The iteration domain of the iterator, given by the constraints in the
 *    domain depending on the iterator, i.e.:
 *    * an equality if the iterator has only one value (possibly preceded by
 *      a guard verifying if this value is integral), *OR*
 *    * a loop from the minimum possible value of the iterator to the maximum
 *      possible value.
 * 3. The included statement block.
 * 4. The inner loops (recursive call).
 * 5. The following loops (recursive call).
 * - level is the recursion level or the iteration level that we are printing,
 * - indent is the indent level, the number of spaces to print before writing,
 * - the infos structure gives the user some options about code printing,
 *   the number of parameters in domain (nb_par), and the arrays of iterator
 *   names and parameters (iters and params). 
 **
 * - November   2nd 2001: first version. 
 * - March      6th 2003: infinite domain support. 
 * - April     19th 2003: (debug) NULL loop support. 
 * - June      29th 2003: non-unit strides support.
 * - April     28th 2005: (debug) level is level+equality when print statement!
 * - June      16th 2005: (debug) the N. Vasilache normalization step has been
 *                        added to avoid iteration duplication (see DaeGon Kim
 *                        bug in cloog_program_generate). Try vasilache.cloog
 *                        with and without the call to cloog_matrix_normalize,
 *                        using -f 8 -l 9 options for an idea.
 * - September 15th 2005: (debug) don't close equality braces when unnecessary.
 * - October   16th 2005: (debug) scalar value is saved for next loops.
 */
void pprint(foo, loop, equal, level, scalar, indent, infos)
FILE * foo ;
CloogLoop * loop ;
CloogMatrix * equal ;
int level, scalar, indent ;
CloogInfos * infos ;
{ int i, new_indent, stride, equality=0, accol=0, scalbraces=0, guard=0,
      modulo_guard=0, scalar_level ;
  char * sline ;
  CloogMatrix * matrix, * temp ;
  
  /* It can happen that loop be NULL when an input polyhedron is empty. */
  if (loop == NULL)
  return ;
  
  /* The matrix has not always a shape that allows us to generate code from it,
   * thus we normalize it, we also simplify it with the matrix of equalities.
   */ 
  temp = cloog_domain_domain2matrix(loop->domain) ;
  cloog_matrix_normalize(temp,level) ;
  matrix = cloog_matrix_simplify(temp,equal,level,infos->names->nb_parameters) ;
  cloog_matrix_free(temp) ;
  value_assign(infos->stride[level-1],loop->stride) ;

  /* First of all we have to print the guard. */
  sline = pprint_guard(matrix,equal,level,&guard,&indent,infos) ;
  fprintf(foo,"%s",sline) ;
  free(sline) ;
   
  /* Then we print scalar dimensions. */ 
  scalar_level = scalar ;
  sline = pprint_scalar(loop,level,&scalar,&scalbraces,&indent,infos) ;
  fprintf(foo,"%s",sline) ;
  free(sline) ;
        
  if ((matrix->NbColumns - 2 - infos->names->nb_parameters >= level))
  { /* We scan all the constraints to know in which case we are :
     * [[if] equality] or [for].
     */
    for (i=0;i<matrix->NbRows;i++)
    if (value_zero_p(matrix->p[i][0]) &&
        value_notzero_p(matrix->p[i][level]))
    { /* If there is an equality, we can print it directly -no ambiguity-.
       * PolyLib can give more than one equality, we use just the first one
       * (this is a PolyLib problem, but all equalities are equivalent).
       */
      sline=pprint_equality(matrix,equal,i,level,&modulo_guard,&indent,infos) ;
      equality = 1 ;   
      break ;
    }
  
    if (!equality)
    { stride = 0 ;
      sline = pprint_for(matrix,equal,level,&accol,&indent,infos);
    }
    else
    { /* If no equality have been printed out (e.g. because of a spreading), we
       * have to specify that there is no open brace to close.
       */
      if ((sline == NULL) || (!strcmp(sline,"\0")))
      equality = 0 ;
    }
    fprintf(foo,"%s",sline) ;
    free(sline) ;
  }
  
  /* Finally, if there is an included statement block, print it. */
  sline = pprint_block(loop->block,equal,level+equality,accol,indent,infos) ;
  fprintf(foo,"%s",sline) ;
  free(sline) ;

  /* Go to the next level. */
  if (loop->inner != NULL)
  { new_indent = (accol == 1) ? indent + INDENT_STEP : indent ;
    pprint(foo,loop->inner,equal,level+1,scalar,new_indent,infos) ;
  }
  
  /* Close the open braces. */
  /* Close the for (or do) loop brace if any. */
  if (accol)
  { for (i=0;i<indent;i++) fprintf(foo," ") ;
  
    if (infos->language == LANGUAGE_FORTRAN)
    fprintf(foo,"END DO\n") ; 
    else
    fprintf(foo,"}\n") ; 
  }
  else
  { /* Close the equality brace if any. */
    if (equality && infos->options->block && (infos->language == LANGUAGE_C))
    { indent = indent - INDENT_STEP ;
      for (i=0;i<indent;i++) fprintf(foo," ") ;
      
      fprintf(foo,"}\n") ;
    }
    /* Close the modulo guard brace that may precede an equality if any. */
    if (modulo_guard)
    { indent = indent - INDENT_STEP ;
      for (i=0;i<indent;i++) fprintf(foo," ") ;
    
      if (infos->language == LANGUAGE_FORTRAN)
      fprintf(foo,"END IF\n") ; 
      else
      fprintf(foo,"}\n") ;
    }
  }
  /* Close the scalar dimension braces if any. */
  if (infos->language == LANGUAGE_C)
  { for (i=0;i<scalbraces;i++)
    { indent = indent - INDENT_STEP ;
      for (i=0;i<indent;i++) fprintf(foo," ") ;
      
      fprintf(foo,"}\n") ;
    }
  }
  /* Close the general guard brace if any. */
  if (guard)
  { indent = indent - INDENT_STEP ;
    for (i=0;i<indent;i++) fprintf(foo," ") ;
    
    if (infos->language == LANGUAGE_FORTRAN)
    fprintf(foo,"END IF\n") ; 
    else
    fprintf(foo,"}\n") ; 
  }
  
  pprint_equal_del(equal,level) ;
  cloog_matrix_free(matrix) ;
  /* Go to the next loop on the same level. */
  if (loop->next != NULL)
  pprint(foo,loop->next,equal,level,scalar_level,indent,infos) ;
}
