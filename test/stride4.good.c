/* Generated from stride4.cloog by CLooG 0.20.0-5e05a27 gmp bits in 0.00s. */
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

#define S1(i0,i1) { hash(1); hash(i0); hash(i1); }

void test(int t)
{
  /* Original iterators. */
  int i0, i1;
  if ((t >= 0) && (t <= 15)) {
    for (i0=0;i0<=99;i0++) {
      if ((15*i0+t)%16 == 0) {
        S1(i0,t);
      }
    }
  }
}
