/* Generated from ../../../git/cloog/test/lux.cloog by CLooG 0.14.0-117-g7c6f653 gmp bits in 0.09s. */
if (M >= 2) {
  for (l=2;l<=M;l++) {
    S1(i = 1,j = 1,k = M) ;
  }
  for (i=2;i<=M-1;i++) {
    for (j=1;j<=i-1;j++) {
      for (k=j+1;k<=M;k++) {
        S2(l = k,m = i) ;
      }
    }
    for (l=i+1;l<=M;l++) {
      S1(j = i,k = M) ;
    }
  }
  for (j=1;j<=M-1;j++) {
    for (k=j+1;k<=M;k++) {
      S2(i = M,l = k,m = M) ;
    }
  }
}
