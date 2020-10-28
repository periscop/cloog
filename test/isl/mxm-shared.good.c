/* Generated from mxm-shared.cloog by CLooG 0.20.0-5e05a27 gmp bits in 0.11s. */
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

void test(int N, int b0, int b1, int g0, int g1, int g2, int g3, int g4, int t0, int t1)
{
  /* Scattering iterators. */
  int c0, c1, c2, c3;
  /* Original iterators. */
  int i, j;
  if (g4%4 == 0) {
    if ((N >= g0+t1+1) && (t1 <= 7) && (16*floord(N-t0-1,16) >= g1-t0)) {
      for (c0=0;c0<=min(127,N-g1-1);c0++) {
        if ((c0+15*t0)%16 == 0) {
          S1((g0+t1),(c0+g1));
        }
      }
    }
  }
}
