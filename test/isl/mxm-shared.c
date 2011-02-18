/* Generated from ../../../git/cloog/test/isl/mxm-shared.cloog by CLooG 0.16.1-5-gcba2a9f gmp bits in 0.34s. */
if (g4%4 == 0) {
  if ((N >= g0+t1+1) && (N >= g1+t0+1) && (t1 <= 7)) {
    for (c0=t0;c0<=min(127,N-g1-1);c0+=16) {
      S1(g0+t1,c0+g1);
    }
  }
}
