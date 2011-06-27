#ifndef CLOOG_ISL_CONSTRAINTSET_H
#define CLOOG_ISL_CONSTRAINTSET_H

#include <cloog/isl/backend.h>

#if defined(__cplusplus)
extern "C" 
  {
#endif 

struct cloogconstraintset {
	int dummy;	/* Solaris cc doesn't like zero-sized structs */
};

struct cloogequalities {
	int			  n;
	unsigned		  total_dim;
	isl_constraint		**constraints;
	int			 *types;
};

struct cloogconstraint {
	int dummy;	/* Solaris cc doesn't like zero-sized structs */
};

CloogConstraintSet *cloog_constraint_set_from_isl_basic_set(struct isl_basic_set *bset);
CloogConstraint *cloog_constraint_from_isl_constraint(struct isl_constraint *constraint);
isl_constraint *cloog_constraint_to_isl(CloogConstraint *constraint);

#if defined(__cplusplus)
  }
#endif 
#endif /* define _H */
