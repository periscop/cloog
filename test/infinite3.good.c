/* Generated from infinite3.cloog by CLooG 0.20.0-0e868c5 gmp bits in 0.01s. */
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

#define S0 { hash(0); }
#define S1(i) { hash(1); hash(i); }
#define S2(i,j) { hash(2); hash(i); hash(j); }

void test(int M, int N)
{
  /* Original iterators. */
  int i, j;
  for (i=-1000+0;i<=0;i++) {
    S1(i);
  }
  for (i=1;i<=min(M,N);i++) {
    S1(i);
    for (j=1;j<=M;j++) {
      S2(i,j);
    }
  }
  for (i=N+1;i<=M;i++) {
    S1(i);
  }
  for (i=M+1;i<=N;i++) {
    for (j=1;j<=M;j++) {
      S2(i,j);
    }
  }
}
