/* Generated from multi-stride2.cloog by CLooG 0.20.0-5e05a27 gmp bits in 0.00s. */
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
  for (i=0;i<=100;i++) {
    if ((i+1)%2 == 0) {
      if ((i+1)%3 == 0) {
        S1(i,((i-1)/2),((i-2)/3));
      }
    }
  }
}
