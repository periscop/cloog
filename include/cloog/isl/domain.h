#ifndef CLOOG_ISL_DOMAIN_H
#define CLOOG_ISL_DOMAIN_H

#include <isl_map.h>
#include <isl_set.h>
#include <isl_union_map.h>

#if defined(__cplusplus)
extern "C" 
  {
#endif 


struct cloogdomain {
	struct isl_set set;
};

struct cloogscattering {
	struct isl_map map;
};

CloogDomain *cloog_domain_from_isl_set(struct isl_set *set);
CloogScattering *cloog_scattering_from_isl_map(struct isl_map *map);
CloogUnionDomain *cloog_union_domain_from_isl_union_map(
	__isl_take isl_union_map *umap);


#if defined(__cplusplus)
  }
#endif 
#endif /* define _H */
