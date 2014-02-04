#ifndef CLOOG_INPUT_H
#define CLOOG_INPUT_H

#if defined(__cplusplus)
extern "C" {
#endif 

struct osl_scop;
struct clooginput;

struct clooginput {
	CloogDomain *context;
	CloogUnionDomain *ud;
  struct clooginput* next;
};
typedef struct clooginput CloogInput;

CloogInput *cloog_input_from_osl_scop(CloogState *state, struct osl_scop *scop);
CloogInput *cloog_input_read(FILE *file, CloogOptions **options);
CloogInput *cloog_input_alloc(CloogDomain *context, CloogUnionDomain *ud);
void cloog_input_free(CloogInput *input);

void cloog_input_dump_cloog(FILE *file, CloogInput *input, CloogOptions *opt);

#if defined(__cplusplus)
}
#endif 

#endif
