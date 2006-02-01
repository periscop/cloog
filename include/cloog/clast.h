#ifndef CLOOG_CLAST_H
#define CLOOG_CLAST_H
#if defined(__cplusplus)
extern "C" 
  {
#endif 

/**
 * CloogInfos structure:
 * this structure contains all the informations necessary for pretty printing,
 * they come from the original CloogProgram structure (language, names), from
 * genereral options (options) or are built only for pretty printing (stride).
 * This structure is mainly there to reduce the number of function parameters,
 * since most pprint.c functions need most of its field.
 */
struct clooginfos
{ Value * stride ;           /**< The stride for each iterator. */
  int language ;             /**< 1 to generate FORTRAN, 0 for C otherwise. */
  int  nb_scattdims ;        /**< Scattering dimension number. */
  int * scaldims ;           /**< Boolean array saying whether a given
                              *   scattering dimension is scalar or not.
                              */
  CloogNames * names ;       /**< Names of iterators and parameters. */
  CloogOptions * options ;   /**< Options on CLooG's behaviour. */
} ;

typedef struct clooginfos CloogInfos ;

struct clast_expr {
    enum { expr_term, expr_bin, expr_red } type;
};

struct clast_term {
    struct clast_expr	expr;
    Value		val;
    char *		var;
};

struct clast_reduction {
    struct clast_expr	expr;
    enum red_type { red_sum, red_min, red_max } type;
    int			n;
    struct clast_expr*	elts[1];
};

struct clast_binary {
    struct clast_expr	expr;
    enum bin_type { bin_fdiv, bin_cdiv, bin_div, bin_mod } type;
    struct clast_expr*	LHS;
    Value		RHS;
};

struct clast_stmt {
    enum { stmt_ass, stmt_block, stmt_for, stmt_guard, stmt_user } type;
    struct clast_stmt	*next;
};

struct clast_assignment {
    struct clast_stmt	stmt;
    const char *	LHS;
    struct clast_expr *	RHS;
};

struct clast_block {
    struct clast_stmt	stmt;
    struct clast_stmt *	body;
};

struct clast_user_stmt {
    struct clast_stmt	stmt;
    CloogStatement *	statement;
    struct clast_stmt *	substitutions;
};

struct clast_for {
    struct clast_stmt	stmt;
    const char *	iterator;
    struct clast_expr *	LB;
    struct clast_expr *	UB;
    Value		stride;
    struct clast_stmt *	body;
};

struct clast_equation {
    struct clast_expr *	LHS;
    struct clast_expr *	RHS;
    int			sign;
};

struct clast_guard {
    struct clast_stmt	stmt;
    struct clast_stmt *	then;
    int			n;
    struct clast_equation	eq[1];
};


struct clast_stmt *cloog_clast_create(CloogLoop * loop, CloogMatrix * equal, 
				      CloogInfos *infos);
void cloog_clast_free(struct clast_stmt *s);

#if defined(__cplusplus)
  }
#endif 
#endif /* define _H */
