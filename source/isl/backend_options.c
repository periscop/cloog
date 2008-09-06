#include <cloog/isl/cloog.h>

CloogOptions *cloog_options_malloc(void)
{
	return cloog_isl_options_malloc(NULL);
}

CloogOptions *cloog_isl_options_malloc(struct isl_ctx *ctx)
{
	CloogOptions *options;
	int allocated = !ctx;

	options = cloog_core_options_malloc();
	if (!ctx)
		ctx = isl_ctx_alloc();
	options->backend = isl_alloc_type(ctx, CloogBackendOptions);
	options->backend->ctx = ctx;
	options->backend->ctx_allocated = allocated;
	return options;
}

void cloog_options_free(CloogOptions *options)
{
	if (options->backend->ctx_allocated)
		isl_ctx_free(options->backend->ctx);
	free(options->backend);
	cloog_core_options_free(options);
}
