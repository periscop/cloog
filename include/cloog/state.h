#ifndef CLOOG_STATE_H
#define CLOOG_STATE_H

#if defined(CLOOG_POLYLIB)
#include <cloog/polylib/backend.h>
#elif defined(CLOOG_ISL)
#include <cloog/isl/backend.h>
#else
struct cloogbackend;
#endif
typedef struct cloogbackend CloogBackend;

#if defined(__cplusplus)
extern "C" {
#endif 

struct cloogstate {
  CloogBackend *backend;
};
typedef struct cloogstate CloogState;

CloogState *cloog_core_state_malloc(void);
CloogState *cloog_state_malloc(void);

void cloog_core_state_free(CloogState *state);
void cloog_state_free(CloogState *state);

#if defined(__cplusplus)
}
#endif 

#endif
