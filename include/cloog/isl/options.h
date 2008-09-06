#ifndef CLOOG_ISL_OPTIONS_H
#define CLOOG_ISL_OPTIONS_H

struct cloogbackendoptions {
	struct isl_ctx	*ctx;
	unsigned	ctx_allocated : 1;
};

CloogOptions *cloog_isl_options_malloc(struct isl_ctx *ctx);

#endif
