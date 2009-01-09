/* Generated from ../../../git/cloog/test/./non_optimal/nul_complex1.cloog by CLooG 0.14.0-135-g7671e98 gmp bits in 0.01s. */
if (n >= 0) {
  for (c1=0;c1<=5*n;c1++) {
    for (c2=max(ceild(2*c1,3),c1-n);c2<=min(floord(2*c1+2*n,3),c1);c2++) {
      if (c2%2 == 0) {
        S1(i = (-2*c1+3*c2)/2,j = c1-c2) ;
      }
    }
  }
}
