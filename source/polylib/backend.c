#include <cloog/polylib/cloog.h>

/**
 * Allocate complete state.
 */
CloogState *cloog_state_malloc(void)
{
	return cloog_core_state_malloc();
}

/**
 * Free state and backend independent parts.
 */
void cloog_state_free(CloogState *state)
{
	cloog_core_state_free(state);
}
