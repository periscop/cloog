/* Generated from infinite4.cloog by CLooG 0.20.0-0e868c5 gmp bits in 0.00s. */
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

void test()
{
  /* Original iterators. */
  int i;
  for (i=-1000;i<=1000;i++) {
    S1(i);
  }
}
