/* Generated from mod4.cloog by CLooG 0.20.0-5e05a27 gmp bits in 0.01s. */
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

#define S1(j,div41,div42,mod6,mod6_a) { hash(1); hash(j); hash(div41); hash(div42); hash(mod6); hash(mod6_a); }
#define S2(j,div41,div42,mod6,mod6_a) { hash(2); hash(j); hash(div41); hash(div42); hash(mod6); hash(mod6_a); }
#define S3(j,div41,div42,mod6,mod6_a) { hash(3); hash(j); hash(div41); hash(div42); hash(mod6); hash(mod6_a); }

void test()
{
  /* Original iterators. */
  int j, div41, div42, mod6, mod6_a;
  for (j=1;j<=10;j++) {
    if ((j+1)%3 == 0) {
      S1(j,((j+1)/3),((j+1)/3),2,((j-2)/3));
      S2(j,((j+1)/3),((j+1)/3),2,((j-2)/3));
      S3(j,((j+1)/3),((j+1)/3),2,((j-2)/3));
    }
  }
}
