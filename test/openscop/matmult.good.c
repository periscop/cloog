/* Generated from matmult.scop by CLooG 0.20.0-bb9d408 gmp bits in 0.01s. */
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
#define S2(i,j,k) { hash(2); hash(i); hash(j); hash(k); }

void test(int N)
{
  /* Scattering iterators. */
  int c2, c4, c6;
  /* Original iterators. */
  int i, j, k;
  for (c2=0;c2<=N-1;c2++) {
    for (c4=0;c4<=N-1;c4++) {
      S1(c2,c4);
      for (c6=0;c6<=N-1;c6++) {
        S2(c2,c4,c6);
      }
    }
  }
}
