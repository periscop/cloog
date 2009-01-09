/* Generated from ../../../git/cloog/test/iftest.cloog by CLooG 0.14.0-136-gb91ef26 gmp bits in 0.02s. */
if (n >= 1) {
  for (i=1;i<=n;i++) {
    if (i <= min(2*m,m-1)) {
      S1(i) ;
    }
    if (i >= m) {
      S1(i) ;
    }
  }
}
