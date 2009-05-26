#include <stdlib.h>
#include "../include/cloog/cloog.h"

/**
 * Allocate state and initialize backend independent part.
 */
CloogState *cloog_core_state_malloc(void)
{
  CloogState *state;

  state = (CloogState *)malloc(sizeof(CloogState));
  if (!state) 
    cloog_die("memory overflow.\n");

  state->backend = NULL;

  state->block_allocated = 0;
  state->block_freed = 0;
  state->block_max = 0;

  state->domain_allocated = 0;
  state->domain_freed = 0;
  state->domain_max = 0;

  state->loop_allocated = 0;
  state->loop_freed = 0;
  state->loop_max = 0;

  state->statement_allocated = 0;
  state->statement_freed = 0;
  state->statement_max = 0;

  return state;
}

/**
 * Free state.
 */
void cloog_core_state_free(CloogState *state)
{
  free(state);
}
