/* Generated from stride3.cloog by CLooG 0.20.0-5e05a27 gmp bits in 0.00s. */
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

#define S1(i) { hash(1); hash(i); }

void test(int m, int n)
{
  /* Scattering iterators. */
  int p1;
  /* Original iterators. */
  int i;
  if ((m <= n) && (n >= 1)) {
    for (p1=max(50,50*m);p1<=50*n;p1++) {
      if (p1%50 == 0) {
        S1((p1/50));
      }
    }
  }
}
