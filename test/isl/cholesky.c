/* Generated from ../../../git/cloog/test/cholesky.cloog by CLooG 0.14.0-117-g7c6f653 gmp bits in 0.16s. */
if (n >= 1) {
  if (n >= 2) {
    S1(i = 1) ;
    S3(i = 1) ;
    for (c3=2;c3<=n;c3++) {
      S4(i = 1,j = c3) ;
      S6(i = 1,j = c3) ;
    }
  }
  if (n == 1) {
    S1(i = 1) ;
    S3(i = 1) ;
  }
  for (c1=2;c1<=n-1;c1++) {
    S1(i = c1) ;
    for (c3=1;c3<=c1-1;c3++) {
      S2(i = c1,j = c3) ;
    }
    S3(i = c1) ;
    for (c3=c1+1;c3<=n;c3++) {
      S4(i = c1,j = c3) ;
      for (c5=1;c5<=c1-1;c5++) {
        S5(i = c1,j = c3,k = c5) ;
      }
      S6(i = c1,j = c3) ;
    }
  }
  if (n >= 2) {
    S1(i = n) ;
    for (c3=1;c3<=n-1;c3++) {
      S2(i = n,j = c3) ;
    }
    S3(i = n) ;
  }
}
