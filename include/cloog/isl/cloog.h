#ifndef CLOOG_ISL_H
#define CLOOG_ISL_H

#ifndef CLOOG_INT_GMP
#define CLOOG_INT_GMP
#endif

#include <cloog/cloog.h>
#include <cloog/isl/constraintset.h>
#include <cloog/isl/domain.h>

#if defined(__cplusplus)
extern "C" {
#endif 

CloogState *cloog_isl_state_malloc(struct isl_ctx *ctx);

#if defined(__cplusplus)
}
#endif 

#endif /* define _H */
