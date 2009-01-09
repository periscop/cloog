/* Generated from ../../../git/cloog/test/./reservoir/fusion2.cloog by CLooG 0.14.0-135-g7671e98 gmp bits in 0.01s. */
if ((M >= 1) && (N >= 1)) {
  for (c4=1;c4<=M;c4++) {
    S1(i = 1,j = c4) ;
  }
  for (c2=2;c2<=N;c2++) {
    for (c4=1;c4<=M;c4++) {
      S2(i = c2-1,j = c4) ;
    }
    for (c4=1;c4<=M;c4++) {
      S1(i = c2,j = c4) ;
    }
  }
  for (c4=1;c4<=M;c4++) {
    S2(i = N,j = c4) ;
  }
}
