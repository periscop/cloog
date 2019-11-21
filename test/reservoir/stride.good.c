/* Generated from stride.cloog by CLooG 0.20.0-5e05a27 gmp bits in 0.00s. */
extern void hash(int);

/* Useful macros. */
#define floord(n,d) (((n)<0) ? -((-(n)+(d)-1)/(d)) : (n)/(d))
#define ceild(n,d)  (((n)<0) ? -((-(n))/(d)) : ((n)+(d)-1)/(d))
#define max(x,y)    ((x) > (y) ? (x) : (y))
#define min(x,y)    ((x) < (y) ? (x) : (y))

#ifdef TIME 
#define IF_TIME(foo) foo; 
#else
#define IF_TIME(foo)
#endif

#define S1(i,j) { hash(1); hash(i); hash(j); }

void test(int M)
{
  /* Scattering iterators. */
  int c2;
  /* Original iterators. */
  int i, j;
  if (M >= 2) {
    for (c2=2;c2<=M;c2++) {
      if ((c2+5)%7 == 0) {
        S1(c2,((c2-2)/7));
      }
    }
  }
}
