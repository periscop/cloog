#include <cloog/polylib/cloog.h>

CloogOptions *cloog_options_malloc(void)
{
	return cloog_core_options_malloc();
}

void cloog_options_free(CloogOptions *options)
{
	cloog_core_options_free(options);
}
