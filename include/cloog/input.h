#ifndef CLOOG_INPUT_H
#define CLOOG_INPUT_H

#if defined(__cplusplus)
extern "C" {
#endif 

struct clooginput {
	CloogDomain *context;
	CloogUnionDomain *ud;
};
typedef struct clooginput CloogInput;

CloogInput *cloog_input_read(FILE *file, CloogOptions *options);
CloogInput *cloog_input_alloc(CloogDomain *context, CloogUnionDomain *ud);
void cloog_input_free(CloogInput *input);

#if defined(__cplusplus)
}
#endif 

#endif
