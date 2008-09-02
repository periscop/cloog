#include <stdio.h>
#include <cloog/cloog.h>

/* Generate code that scans part of the parameter domain of
 * a given cloog problem, running both a function called "good"
 * and a function called "test" for each value of the parameters.
 * These functions are assumed to call the "hash" function,
 * which is also generated by this program.
 * If for any given value of the parameters, the final hash
 * value computed by test is different from that computed by
 * good, then an error is reported.
 */

CloogDomain *get_param_domain(CloogOptions *options)
{
	CloogDomain *domain;
	CloogProgram *program;
  
	program = cloog_program_read(stdin, options);

	domain = cloog_domain_copy(program->context);

	cloog_program_free(program);

	return domain;
}

static const char preamble[] =
"#include <assert.h>\n"
"#include <stdio.h>\n"
"\n"
"static unsigned h;\n"
"\n"
"void hash(int v)\n"
"{\n"
"	int i;\n"
"	union u {\n"
"		int v;\n"
"		unsigned char c[1];\n"
"	} u;\n"
"	u.v = v;\n"
"	for (i = 0; i < sizeof(int); ++i) {\n"
" 		h *= 16777619;\n"
"		h ^= u.c[i];\n"
"	}\n"
"}\n"
"\n"
"int main()\n"
"{\n"
"	unsigned h_good, h_test;\n";
;

static const char postamble[] =
"	return 0;\n"
"}\n"
;

static const char *call[] = {"good", "test"};

int main()
{
	int dim;
	int range;
	int i, j;
	CloogOptions *options = cloog_options_malloc();
	CloogDomain *domain = get_param_domain(options);
	CloogDomain *cube, *tmp;
	CloogProgram *p;
	CloogStatement *statement;
	cloog_int_t m, M;

	dim = cloog_domain_dimension(domain);

	if (dim >= 8)
		range = 4;
	else if (dim >= 5)
		range = 6;
	else
		range = 30;

	cloog_int_init(m);
	cloog_int_init(M);
	cloog_int_set_si(m, 0);
	cloog_int_set_si(M, range);
	cube = cloog_domain_cube(dim, m, M, options);
	domain = cloog_domain_intersection(tmp = domain, cube);
	cloog_domain_free(tmp);
	cloog_domain_free(cube);

	p = cloog_program_malloc();
	assert(p);
	p->names = cloog_names_malloc();
	assert(p->names);
	p->names->nb_iterators = dim;
	p->names->iterators = cloog_names_generate_items(dim, "p", 0);
	p->language = 'c';
	p->context = cloog_domain_universe(0, options);
	statement = cloog_statement_alloc(1);
	p->loop = cloog_loop_malloc();
	p->loop->domain = domain;
	p->loop->block = cloog_block_alloc(statement, 0, NULL, dim);
	p->blocklist = cloog_block_list_alloc(p->loop->block);

	printf("%s", preamble);
	for (i = 0; i < dim; ++i)
		printf("\tint %s;\n", p->names->iterators[i]);
	printf("#define S1(");
	for (i = 0; i < dim; ++i) {
		if (i)
			printf(",");
		printf("p%d", i);
	}
	printf(") do {");
	for (j = 0; j < 2; ++j) {
		printf(" h = 2166136261u;");
		printf(" %s(", call[j]);
		for (i = 0; i < dim; ++i) {
			if (i)
				printf(", ");
			printf("p%d", i);
		}
		printf(");");
		printf(" h_%s = h;", call[j]);
	}
	printf(" assert(h_good == h_test);");
	printf(" } while (0)\n");
	/* ClooG currently doesn't handle 0D problems very well. */
	if (dim == 0)
		printf("S1();\n");
	else {
		p = cloog_program_generate(p, options);
		options->cpp = 1;
		cloog_program_pprint(stdout, p, options);
	}
	printf("%s", postamble);

	cloog_int_clear(m);
	cloog_int_clear(M);
	cloog_program_free(p);
	cloog_options_free(options);

	return 0;
}
