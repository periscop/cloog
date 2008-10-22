/* Generated from ../../git/cloog/test/wavefront.cloog by CLooG 0.14.0-121-gb84d25f gmp bits in 0.00s. */
if ((m >= 1) && (n >= 1)) {
  for (c1=2;c1<=n+m;c1++) {
    for (c2=max(1,c1-m);c2<=min(n,c1-1);c2++) {
      j = c1-c2 ;
      S1(i = c2) ;
    }
  }
}
