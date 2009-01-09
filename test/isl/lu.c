/* Generated from ../../../git/cloog/test/lu.cloog by CLooG 0.14.0-135-g7671e98 gmp bits in 0.03s. */
if (n >= 2) {
  for (j=2;j<=n;j++) {
    S1(i = 1) ;
  }
  for (c1=2;c1<=n-1;c1++) {
    for (c2=2;c2<=n-1;c2++) {
      for (i=1;i<=min(c1-1,c2-1);i++) {
        S2(j = c2,k = c1) ;
      }
    }
    for (i=1;i<=c1-1;i++) {
      S2(j = n,k = c1) ;
    }
    for (j=c1+1;j<=n;j++) {
      S1(i = c1) ;
    }
  }
  for (c2=2;c2<=n;c2++) {
    for (i=1;i<=c2-1;i++) {
      S2(j = c2,k = n) ;
    }
  }
}
