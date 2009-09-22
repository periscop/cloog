#ifndef CLOOG_POLYLIB_CONSTRAINTSET_H
#define CLOOG_POLYLIB_CONSTRAINTSET_H

#include <cloog/polylib/backend.h>

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

typedef Matrix CloogConstraintSet;

struct cloogequalities {
	CloogConstraintSet	*constraints;
	int			*types;
};
typedef struct cloogequalities CloogEqualities;

struct cloogconstraint {
	CloogConstraintSet	*set;
	Value			**line;
};
typedef struct cloogconstraint CloogConstraint;


/******************************************************************************
 *                              PolyLib interface                             *
 ******************************************************************************/
void          cloog_matrix_print(FILE *, Matrix *) ;
void          cloog_matrix_free(Matrix *) ;
Matrix * cloog_matrix_alloc(unsigned, unsigned) ;
Matrix * cloog_matrix_matrix(Matrix *);

/******************************************************************************
 *                          Structure display function                        *
 ******************************************************************************/
void          cloog_matrix_print_structure(FILE *, Matrix *, int) ;

/******************************************************************************
 *                               Reading function                             *
 ******************************************************************************/
Matrix * cloog_matrix_read(FILE *) ;


#if defined(__cplusplus)
  }
#endif 
#endif /* define _H */
