#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cloog/isl/cloog.h>
#include <isl_map.h>
#include <isl_set.h>
#include <isl_list.h>


/******************************************************************************
 *                             Memory leaks hunting                           *
 ******************************************************************************/


/**
 * These global variables are devoted to memory leaks hunting in the PolyLib
 * backend.  The isl backend has it's own memory leak detection facilities.
 */
int cloog_domain_allocated = 0;
int cloog_domain_freed = 0;
int cloog_domain_max = 0;



/**
 * Returns true if each scattering dimension is defined in terms
 * of the original iterators.
 */
int cloog_scattering_fully_specified(CloogScattering *scattering,
				      CloogDomain *domain)
{
	int i;
	int scattering_dim = cloog_scattering_dimension(scattering, domain);
	for (i = 0; i < scattering->n; ++i)
		if (scattering->p[i]->n_eq < scattering_dim)
			return 0;
	return 1;
}


CloogConstraintSet *cloog_domain_constraints(CloogDomain *domain)
{
	assert(domain->n == 1);
	return isl_basic_set_copy(domain->p[0]);
}


void cloog_domain_print_constraints(FILE *foo, CloogDomain *domain,
					int print_number)
{
	if (print_number)
		isl_set_print(domain, foo, 0, ISL_FORMAT_POLYLIB);
	else {
		assert(domain->n == 1);
		isl_basic_set_print(domain->p[0], foo,
					0, NULL, NULL, ISL_FORMAT_POLYLIB);
	}
}


void cloog_domain_free(CloogDomain * domain)
{
	isl_set_free(domain);
}


void cloog_scattering_free(CloogScattering * domain)
{
	isl_map_free(domain);
}


CloogDomain * cloog_domain_copy(CloogDomain * domain)
{
	return isl_set_copy(domain);
}


/**
 * cloog_domain_convex function:
 * Computes the convex hull of domain.
 */ 
CloogDomain *cloog_domain_convex(CloogDomain *domain)
{
	return isl_set_from_basic_set(isl_set_convex_hull(isl_set_copy(domain)));
}


/**
 * set_bounds:
 * Given a list (union) of polyhedra "set", this function returns a basic
 * set with constraints that reflect the (parametric) lower and
 * upper bound on dimension "dim".
 */
static struct isl_basic_set *set_bounds(struct isl_set *set, int dim)
{
	set = isl_set_copy(set);
	set = isl_set_eliminate_dims(set, dim + 1, set->dim - (dim + 1));
	set = isl_set_eliminate_dims(set, 0, dim);
	return isl_set_convex_hull(set);
}


/**
 * cloog_domain_simple_convex:
 * Given a list (union) of polyhedra, this function returns a "simple"
 * convex hull of this union.  In particular, the constraints of the
 * the returned polyhedron consist of (parametric) lower and upper
 * bounds on individual variables and constraints that appear in the
 * original polyhedra.
 *
 * nb_par is the number of parameters of the domain.
 */
CloogDomain *cloog_domain_simple_convex(CloogDomain *domain, int nb_par)
{
	int i;
	struct isl_basic_set *hull;

	if (cloog_domain_isconvex(domain))
		return cloog_domain_copy(domain);

	if (domain->dim == 0)
		return cloog_domain_convex(domain);

	for (i = 0; i < domain->dim; ++i) {
		struct isl_basic_set *bounds;
		bounds = set_bounds(domain, i);
		if (!i)
			hull = bounds;
		else
			hull = isl_basic_set_intersect(hull, bounds);
	}
	if (domain->dim == 1)
		return isl_set_from_basic_set(hull);

	hull = isl_basic_set_intersect(hull,
				isl_set_simple_hull(isl_set_copy(domain)));
	return isl_set_from_basic_set(hull);
}


/**
 * cloog_domain_simplify function:
 * Given two polyhedral domains (dom1) and (dom2),
 * this function finds the largest domain set (or the smallest list
 * of non-redundant constraints), that when intersected with polyhedral
 * domain (dom2) equals (dom1)intersect(dom2). The output is a new CloogDomain
 * structure with a polyhedral domain with the "redundant" constraints removed.
 * NB: the second domain is required not to be a union.
 */ 
CloogDomain *cloog_domain_simplify(CloogDomain *dom1, CloogDomain *dom2)
{
	assert(dom2->n == 1);
	return isl_set_gist(isl_set_copy(dom1),
				isl_basic_set_copy(dom2->p[0]));
}


/**
 * cloog_domain_union function:
 * This function returns a new polyhedral domain which is the union of
 * two polyhedral domains (dom1) U (dom2).
 */
CloogDomain *cloog_domain_union(CloogDomain *dom1, CloogDomain *dom2)
{
	return isl_set_union(isl_set_copy(dom1), isl_set_copy(dom2));
}



/**
 * cloog_domain_intersection function:
 * This function returns a new polyhedral domain which is the intersection of
 * two polyhedral domains (dom1) \cap (dom2).
 */ 
CloogDomain *cloog_domain_intersection(CloogDomain *dom1, CloogDomain *dom2)
{
	return isl_set_intersect(isl_set_copy(dom1), isl_set_copy(dom2));
}


/**
 * cloog_domain_difference function:
 * Returns the set difference domain \ minus.
 */ 
CloogDomain *cloog_domain_difference(CloogDomain *domain, CloogDomain *minus)
{
	return isl_set_subtract(isl_set_copy(domain), isl_set_copy(minus));
}


/**
 * cloog_domain_sort function:
 * This function topologically sorts (nb_doms) domains. Here (doms) is a an
 * array of pointers to CloogDomains, (nb_doms) is the number of domains,
 * (level) is the level to consider for partial ordering (nb_par) is the
 * parameter space dimension, (permut) if not NULL, is an array of (nb_doms)
 * integers that contains a permutation specification after call in order to
 * apply the topological sorting. 
 */
void cloog_domain_sort(CloogDomain **doms, unsigned nb_doms, unsigned level,
			unsigned nb_par, int *permut)
{
	int i, j, k, cmp;
	struct isl_ctx *ctx;
	unsigned char **follows;

	if (!nb_doms)
		return;
	ctx = doms[0]->ctx;
	for (i = 0; i < nb_doms; i++)
		assert(doms[i]->n == 1);

	follows = isl_alloc_array(ctx, unsigned char *, nb_doms);
	assert(follows);
	for (i = 0; i < nb_doms; ++i) {
		follows[i] = isl_alloc_array(ctx, unsigned char, nb_doms);
		assert(follows[i]);
		for (j = 0; j < nb_doms; ++j)
			follows[i][j] = 0;
	}

	for (i = 1; i < nb_doms; ++i) {
		for (j = 0; j < i; ++j) {
			if (follows[i][j] || follows[j][i])
				continue;
			cmp = isl_basic_set_compare_at(doms[i]->p[0],
					doms[j]->p[0], level-1);
			if (!cmp)
				continue;
			if (cmp > 0) {
				follows[i][j] = 1;
				for (k = 0; k < i; ++k)
					follows[i][k] |= follows[j][k];
			} else {
				follows[j][i] = 1;
				for (k = 0; k < i; ++k)
					follows[k][i] |= follows[k][j];
			}
		}
	}

	for (i = 0, j = 0; i < nb_doms; j = (j + 1) % nb_doms) {
		for (k = 0; k < nb_doms; ++k)
			if (follows[j][k])
				break;
		if (k < nb_doms)
			continue;
		for (k = 0; k < nb_doms; ++k)
			follows[k][j] = 0;
		follows[j][j] = 1;
		permut[i] = 1 + j;
		++i;
	}

	for (i = 0; i < nb_doms; ++i)
		free(follows[i]);
	free(follows);
}


/**
 * cloog_domain_empty function:
 * Returns an empty domain of the same dimensions as template.
 */
CloogDomain *cloog_domain_empty(CloogDomain *template)
{
	return isl_set_empty(template->ctx, template->nparam, template->dim);
}


/******************************************************************************
 *                          Structure display function                        *
 ******************************************************************************/


/**
 * cloog_domain_print_structure :
 * this function is a more human-friendly way to display the CloogDomain data
 * structure, it only shows the constraint system and includes an indentation
 * level (level) in order to work with others print_structure functions.
 */
void cloog_domain_print_structure(FILE *file, CloogDomain *domain, int level,
				  const char *name)
{
	int i ;
	char *suffix = " ]";
	char *prefix;

	/* Go to the right level. */
	for (i = 0; i < level; i++)
		fprintf(file, "|\t");
  
	if (!domain) {
		fprintf(file, "+-- Null CloogDomain\n");
		return;
	}
	fprintf(file, "+-- %s\n", name);
	prefix = isl_alloc_array(domain->ctx, char, 2*(level+1)+3);
	assert(prefix);
	for (i = 0; i < level+1; ++i)
		memcpy(prefix+2*i, "|\t", 2);
	strcpy(prefix+2*(level+1), "[ ");

	for (i = 0; i < domain->n; ++i) {
		isl_basic_set_print(domain->p[i], file, 0, prefix, suffix,
					ISL_FORMAT_POLYLIB_CONSTRAINTS);
		prefix[2*(level+1)] = '\0';
		fprintf(file, "%s\n", prefix);
		prefix[2*(level+1)] = '[';
	}
	free(prefix);
}


/******************************************************************************
 *                         Memory deallocation function                       *
 ******************************************************************************/


/**
 * cloog_scattering_list_free function:
 * This function frees the allocated memory for a CloogScatteringList structure.
 */
void cloog_scattering_list_free(CloogScatteringList *list)
{
	while (list != NULL) {
		CloogScatteringList *temp = list->next;
		isl_map_free(list->domain);
		free(list);
		list = temp;
	}
}


/******************************************************************************
 *                               Reading function                             *
 ******************************************************************************/


/**
 * cloog_domain_read_context function:
 * Read parameter domain.
 */
CloogDomain *cloog_domain_read_context(FILE *input, CloogOptions *options)
{
	struct isl_ctx *ctx = options->backend->ctx;
	struct isl_basic_set *bset;
	struct isl_basic_set *model;

	bset = isl_basic_set_read_from_file(ctx, input, 0, ISL_FORMAT_POLYLIB);
	assert(bset);
	model = isl_basic_set_empty(ctx, bset->dim, 0);
	bset = isl_basic_set_from_underlying_set(bset, model);

	return isl_set_from_basic_set(bset);
}


/**
 * cloog_domain_from_context
 * Reinterpret context by turning parameters into variables.
 */
CloogDomain *cloog_domain_from_context(CloogDomain *context)
{
	struct isl_basic_set *model;
	model = isl_basic_set_empty(context->ctx, 0, context->nparam);
	context = isl_set_to_underlying_set(context);
	return isl_set_from_underlying_set(context, model);
}


/**
 * cloog_domain_union_read function:
 * This function reads a union of polyhedra into a file (input) and
 * returns a pointer to a CloogDomain containing the read information. 
 */
CloogDomain *cloog_domain_union_read(FILE *input, int nb_parameters,
					CloogOptions *options)
{
	struct isl_ctx *ctx = options->backend->ctx;
	struct isl_set *set;

	set = isl_set_read_from_file(ctx, input, nb_parameters,
					ISL_FORMAT_POLYLIB);
	return set;
}


/**
 * cloog_scattering_list_read function:
 * This function reads in a scattering function from the file input.
 */
CloogScattering *cloog_scattering_read(FILE *input,
				    CloogDomain *domain, CloogOptions *options)
{
	struct isl_ctx *ctx = options->backend->ctx;
	struct isl_basic_set *bset;
	struct isl_basic_map *scat;

	bset = isl_basic_set_read_from_file(ctx, input, domain->nparam,
						ISL_FORMAT_POLYLIB);
	scat = isl_basic_map_from_basic_set(bset,
					bset->dim - domain->dim, domain->dim);
	return isl_map_from_basic_map(scat);
}


/******************************************************************************
 *                            Processing functions                            *
 ******************************************************************************/



/**
 * cloog_domain_isempty function:
 */ 
int cloog_domain_isempty(CloogDomain *domain)
{
	return isl_set_is_empty(domain);
}


/**
 * cloog_domain_universe function:
 * This function returns the complete dim-dimensional space.
 */
CloogDomain *cloog_domain_universe(unsigned dim, CloogOptions *options)
{
	struct isl_basic_set *bset;

	bset = isl_basic_set_universe(options->backend->ctx, 0, dim);
	return isl_set_from_basic_set(bset);
}


/**
 * cloog_domain_project function:
 * This function returns the projection of
 * (domain) on the (level) first dimensions (i.e. outer loops).
 */ 
CloogDomain *cloog_domain_project(CloogDomain *domain, int level, int nb_par)
{
	return isl_set_remove_dims(isl_set_copy(domain),
					level, domain->dim - level);
}


/**
 * cloog_domain_extend function:
 * This function returns the (domain) given as input with (dim)
 * dimensions and (nb_par) parameters.
 * This function does not free (domain), and returns a new CloogDomain.
 */ 
CloogDomain *cloog_domain_extend(CloogDomain *domain, int dim, int nb_par)
{
	return isl_set_extend(isl_set_copy(domain), nb_par, dim);
}


/**
 * cloog_domain_never_integral function:
 * For us, an equality like 3*i -4 = 0 is always false since 4%3 != 0.
 * There is no need to check for such constraints explicitly for the isl
 * backend.
 */
int cloog_domain_never_integral(CloogDomain * domain)
{
	return isl_set_is_empty(domain);
}


/**
 * cloog_domain_stride function:
 * This function finds the stride imposed to unknown with the column number
 * 'strided_level' in order to be integral. For instance, if we have a
 * constraint like -i - 2j + 2k = 0, and we consider k, then k can be integral
 * only if (i + 2j)%2 = 0. Then only if i%2 = 0. Then k imposes a stride 2 to
 * the unknown i. The function returns the imposed stride in a parameter field.
 * - domain is the set of constraint we have to consider,
 * - strided_level is the column number of the unknown for which a stride have
 *   to be found,
 * - looking_level is the column number of the unknown that impose a stride to
 *   the first unknown.
 * - stride is the stride that is returned back as a function parameter. 
 * - offset is the value of the constant c if the condition is of the shape
 *   (i + c)%s = 0, s being the stride.
 */
void cloog_domain_stride(CloogDomain *domain, int strided_level, int nb_par,
	cloog_int_t *stride, cloog_int_t *offset)
{
	assert(domain->n == 1);
	isl_basic_set_dim_residue_class(domain->p[0], strided_level-1,
					stride, offset);
	if (!isl_int_is_zero(*offset))
		isl_int_sub(*offset, *stride, *offset);
	return;
}


/**
 * cloog_domain_integral_lowerbound function:
 * This function returns 1 if the lower bound of an iterator (such as its
 * column rank in the constraint set 'domain' is 'level') is integral,
 * 0 otherwise. If the lower bound is actually integral, the function fills
 * the 'lower' field with the lower bound value.
 */
int cloog_domain_integral_lowerbound(CloogDomain *domain, int level,
					cloog_int_t *lower)
{
	return isl_set_fast_dim_has_fixed_lower_bound(domain, level-1, lower);
}


/**
 * cloog_domain_lowerbound_update function:
 * This function updates the integral lower bound of an iterator (such as its
 * column rank in the constraint set 'domain' is 'level') into  'lower'
 * and returns the updated domain.
 */
CloogDomain *cloog_domain_lowerbound_update(CloogDomain *domain, int level,
						cloog_int_t lower)
{
	return isl_set_lower_bound_dim(domain, level-1, lower);
}


/**
 * cloog_domain_lazy_equal function:
 * This function returns 1 if the domains given as input are the same, 0 if it
 * is unable to decide.
 */
int cloog_domain_lazy_equal(CloogDomain *d1, CloogDomain *d2)
{
	return isl_set_fast_is_equal(d1, d2);
}


/**
 * cloog_scattering_lazy_block function:
 * This function returns 1 if the two scattering functions s1 and s2 given
 * as input are the same (except possibly for the final dimension, where we
 * allow a difference of 1), assuming that the domains on which this
 * scatterings are applied are the same.
 * In fact this function answers the question "can I
 * safely consider the two domains as only one with two statements (a block) ?".
 * - s1 and s2 are the two domains to check for blocking,
 * - scattering is the linked list of all domains,
 * - scattdims is the total number of scattering dimentions.
 */
int cloog_scattering_lazy_block(CloogScattering *s1, CloogScattering *s2,
			    CloogScatteringList *scattering, int scattdims)
{
	int i;
	struct isl_map *rel;
	struct isl_set *delta;
	int fixed, block;
	isl_int cst;

	if (s1->n_in != s2->n_in)
		return 0;

	rel = isl_map_identity(s1->ctx, s1->nparam, s1->n_out);
	rel = isl_map_apply_range(isl_map_copy(s2), rel);
	rel = isl_map_reverse(rel);
	rel = isl_map_apply_range(isl_map_copy(s1), rel);
	delta = isl_map_deltas(rel);
	isl_int_init(cst);
	for (i = 0; i < s1->n_in; ++i) {
		fixed = isl_set_fast_dim_is_fixed(delta, i, &cst);
		if (fixed != 1)
			break;
		if (i+1 < s1->n_in && !isl_int_is_zero(cst))
			break;
		if (!isl_int_is_zero(cst) && !isl_int_is_one(cst))
			break;
	}
	block = i >= s1->n_in;
	isl_int_clear(cst);
	isl_set_free(delta);
	return block;
}


/**
 * cloog_domain_lazy_disjoint function:
 * This function returns 1 if the domains given as input are disjoint, 0 if it
 * is unable to decide.
 */
int cloog_domain_lazy_disjoint(CloogDomain *d1, CloogDomain *d2)
{
	return isl_set_fast_is_disjoint(d1, d2);
} 
 
 
/**
 * cloog_scattering_list_lazy_same function:
 * This function returns 1 if two domains in the list are the same, 0 if it
 * is unable to decide.
 */
int cloog_scattering_list_lazy_same(CloogScatteringList *list)
{
	CloogScatteringList *one, *other;

	for (one = list; one; one = one->next)
		for (other = one->next; other; other = other->next)
			if (isl_map_fast_is_equal(one->domain, other->domain))
				return 1;
	return 0;
}

int cloog_domain_dimension(CloogDomain * domain)
{
	return domain->dim + domain->nparam;
}

int cloog_scattering_dimension(CloogScattering *scatt, CloogDomain *domain)
{
	return scatt->n_in;
}

int cloog_domain_isconvex(CloogDomain * domain)
{
	return domain->n <= 1;
}


/**
 * cloog_domain_cut_first function:
 * This function splits off and returns the first convex set in the
 * union "domain".  The remainder of the union is returned in rest.
 * The original "domain" itself is destroyed and may not be used
 * after a call to this function.
 */
CloogDomain *cloog_domain_cut_first(CloogDomain *domain, CloogDomain **rest)
{
	struct isl_basic_set *first;

	first = isl_set_copy_basic_set(domain);
	domain = isl_set_drop_basic_set(domain, first);
	*rest = domain;

	return isl_set_from_basic_set(first);
}


/**
 * cloog_scattering_lazy_isscalar function:
 * this function returns 1 if the scattering dimension 'dimension' in the
 * scattering 'scatt' is constant.
 * If value is not NULL, then it is set to the constant value of dimension.
 */
int cloog_scattering_lazy_isscalar(CloogScattering *scatt, int dimension,
					cloog_int_t *value)
{
	return isl_map_fast_input_is_fixed(scatt, dimension, value);
}


/**
 * cloog_scattering_erase_dimension function:
 * this function returns a CloogDomain structure builds from 'domain' where
 * we removed the dimension 'dimension' and every constraint involving this
 * dimension.
 */
CloogScattering *cloog_scattering_erase_dimension(CloogScattering *domain,
						int dimension)
{
	return isl_map_remove_inputs(isl_map_copy(domain), dimension, 1);
}

/**
 * cloog_domain_cube:
 * Construct and return a dim-dimensional cube, with values ranging
 * between min and max in each dimension.
 */
CloogDomain *cloog_domain_cube(int dim, cloog_int_t min, cloog_int_t max,
				CloogOptions *options)
{
	int i;
	struct isl_basic_set *cube;
	struct isl_basic_set *interval;
	struct isl_basic_set_list *list;

	if (dim == 0)
		return cloog_domain_universe(dim, options);

	interval = isl_basic_set_interval(options->backend->ctx, min, max);
	list = isl_basic_set_list_alloc(options->backend->ctx, dim);
	for (i = 0; i < dim; ++i)
		list = isl_basic_set_list_add(list, isl_basic_set_copy(interval));
	isl_basic_set_free(interval);
	cube = isl_basic_set_product(list);
	return isl_set_from_basic_set(cube);
}


/**
 * cloog_domain_scatter function:
 * This function add the scattering (scheduling) informations to a domain.
 */
CloogDomain *cloog_domain_scatter(CloogDomain *domain, CloogScattering *scatt)
{
	struct isl_map *map;

	map = isl_map_intersect_range(isl_map_copy(scatt), domain);
	return isl_set_from_map(map);
}
