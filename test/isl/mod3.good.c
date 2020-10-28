/* Generated from mod3.cloog by CLooG 0.20.0-5e05a27 gmp bits in 0.01s. */
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

void test(int h0)
{
  /* Original iterators. */
  int i, j;
  for (i=max(0,32*h0-1991);i<=min(999,32*h0+31);i++) {
    if ((63*i+32*h0+31)%64 <= 62) {
      for (j=0;j<=999;j++) {
        S1(i,j);
      }
    }
  }
}
