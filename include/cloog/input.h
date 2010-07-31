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

#if defined(__cplusplus)
}
#endif 

#endif
