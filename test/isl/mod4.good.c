/* Generated from mod4.cloog by CLooG 0.20.0-5e05a27 gmp bits in 0.00s. */
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

void test(int M, int N)
{
  /* Original iterators. */
  int i;
  if (M%11 <= 6) {
    if (N%5 <= 2) {
      if (M >= -N) {
        for (i=0;i<=M+N;i++) {
          S1(i);
        }
      }
    }
  }
}
