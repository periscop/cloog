#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/cloog/cloog.h"

#define ALLOC(type) (type*)malloc(sizeof(type))

static char *next_line(FILE *input, char *line, unsigned len)
{
	char *p;

	do {
		if (!(p = fgets(line, len, input)))
			return NULL;
		while (isspace(*p) && *p != '\n')
			++p;
	} while (*p == '#' || *p == '\n');

	return p;
}

/**
 * Read input from a .cloog file, putting most of the information
 * in the returned CloogInput.  The chosen language is put in
 * options->language.
 */
CloogInput *cloog_input_read(FILE *file, CloogOptions *options)
{
	char line[MAX_STRING];
	char language;
	CloogDomain *context;
	CloogUnionDomain *ud;
	int nb_par;

	/* First of all, we read the language to use. */
	if (!next_line(file, line, sizeof(line)))
		cloog_die("Input error.\n");
	if (sscanf(line, "%c", &language) != 1)
		cloog_die("Input error.\n");
   
	if (language == 'f')
		options->language = LANGUAGE_FORTRAN;
	else
		options->language = LANGUAGE_C;

	/* We then read the context data. */
	context = cloog_domain_read_context(options->state, file);
	nb_par = cloog_domain_parameter_dimension(context);

	ud = cloog_union_domain_read(file, nb_par, options);

	return cloog_input_alloc(context, ud);
}

/**
 * Create a CloogInput from a CloogDomain context and a CloogUnionDomain.
 */
CloogInput *cloog_input_alloc(CloogDomain *context, CloogUnionDomain *ud)
{
	CloogInput *input;

	input = ALLOC(CloogInput);
	if (!input)
		cloog_die("memory overflow.\n");

	input->context = context;
	input->ud = ud;

	return input;
}

void cloog_input_free(CloogInput *input)
{
	cloog_domain_free(input->context);
	cloog_union_domain_free(input->ud);
	free(input);
}
