/* Generated from nul_lcpc.cloog by CLooG 0.20.0-5e05a27 gmp bits in 0.01s. */
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

#define S1(i,k,j) { hash(1); hash(i); hash(k); hash(j); }
#define S2(i,k,j) { hash(2); hash(i); hash(k); hash(j); }

void test(int m, int n, int p)
{
  /* Original iterators. */
  int i, k, j;
  for (i=1;i<=6;i++) {
    if ((i+1)%2 == 0) {
      for (j=1;j<=i;j++) {
        S1(i,((i-1)/2),j);
        S2(i,((i-1)/2),j);
      }
      for (j=i+1;j<=p;j++) {
        S1(i,((i-1)/2),j);
      }
    }
  }
  for (i=7;i<=m;i++) {
    if ((i+1)%2 == 0) {
      for (j=1;j<=p;j++) {
        S1(i,((i-1)/2),j);
      }
    }
  }
}
