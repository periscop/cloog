/* Generated from bastoul3.cloog by CLooG 0.20.0-5e05a27 gmp bits in 0.00s. */
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

#define S1(i,j,k) { hash(1); hash(i); hash(j); hash(k); }

void test()
{
  /* Original iterators. */
  int i, j, k;
  for (i=3;i<=9;i++) {
    for (j=max(1,i-6);j<=min(3,i-2);j++) {
      if ((i+j)%2 == 0) {
        S1(i,j,((i-j)/2));
      }
    }
  }
}
