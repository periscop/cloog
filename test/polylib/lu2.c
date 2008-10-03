/* Generated from ../../../git/cloog/test/lu2.cloog by CLooG 0.14.0-117-g5444fca gmp bits in 0.02s. */
if (n >= 2) {
  for (l=2;l<=n;l++) {
    S1(i = 1,j = n,k = 1) ;
  }
  for (i=2;i<=n-1;i++) {
    for (j=2;j<=n-1;j++) {
      for (k=1;k<=min(i-1,j-1);k++) {
        S2(l = j,m = i) ;
      }
    }
    for (k=1;k<=i-1;k++) {
      S2(j = n,l = n,m = i) ;
    }
    for (l=i+1;l<=n;l++) {
      S1(j = n,k = i) ;
    }
  }
  for (j=2;j<=n;j++) {
    for (k=1;k<=j-1;k++) {
      S2(i = n,l = j,m = n) ;
    }
  }
}
