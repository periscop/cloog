/* Generated from loops.scop by CLooG 0.20.0-bb9d408 gmp bits in 0.05s. */
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

#define S1(i,j,k,l) { hash(1); hash(i); hash(j); hash(k); hash(l); }
#define S2(i,j,k,l,m,n) { hash(2); hash(i); hash(j); hash(k); hash(l); hash(m); hash(n); }

void test(int N)
{
  /* Scattering iterators. */
  int t2, t3, t4, t5, t6, t9;
  /* Original iterators. */
  int i, j, k, l, m, n;
  if (N >= 1) {
    for (t2=0;t2<=floord(N-1,32);t2++) {
      for (t3=0;t3<=floord(N-1,32);t3++) {
        for (t4=32*t2;t4<=min(N-1,32*t2+31);t4++) {
          for (t9=32*t3;t9<=min(N-1,32*t3+31);t9++) {
            S1(t3,t2,t4,t9);
          }
        }
      }
    }
    for (t2=0;t2<=floord(N-1,32);t2++) {
      for (t3=0;t3<=floord(N-1,32);t3++) {
        for (t4=0;t4<=floord(N-1,32);t4++) {
          for (t5=32*t2;t5<=min(N-1,32*t2+31);t5++) {
            for (t6=32*t4;t6<=min(N-1,32*t4+31);t6++) {
              for (t9=32*t3;t9<=min(N-1,32*t3+31);t9++) {
                S2(t4,t3,t2,t5,t9,t6);
              }
            }
          }
        }
      }
    }
  }
}
