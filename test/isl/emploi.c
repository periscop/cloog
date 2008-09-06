/* Generated from ../../../git/cloog/test/emploi.cloog by CLooG 0.14.0-117-g7c6f653 gmp bits in 0.07s. */
if (n >= 1) {
  if (m >= 1) {
    for (i=1;i<=n;i++) {
      if (i <= min(2*m,m-1)) {
        S1 ;
      }
      if (i >= m) {
        S1 ;
      }
      for (j=1;j<=m;j++) {
        S2 ;
      }
    }
  }
  if (m <= 0) {
    for (i=1;i<=n;i++) {
      S1 ;
    }
  }
}
