#ifndef CLOOG_ISL_CONSTRAINTSET_H
#define CLOOG_ISL_CONSTRAINTSET_H

#include <cloog/isl/backend.h>

#if defined(__cplusplus)
extern "C" 
  {
#endif 

struct cloogconstraintset {
};

struct cloogequalities {
	int			  n;
	unsigned		  total_dim;
	CloogConstraintSet	**constraints;
	int			 *types;
};

struct cloogconstraint {
	struct isl_constraint isl;
};

CloogConstraintSet *cloog_constraint_set_from_isl_basic_set(struct isl_basic_set *bset);
CloogConstraint *cloog_constraint_from_isl_constraint(struct isl_constraint *constraint);

#if defined(__cplusplus)
  }
#endif 
#endif /* define _H */
