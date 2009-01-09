/* Generated from ../../../git/cloog/test/./reservoir/pingali5.cloog by CLooG 0.14.0-135-g7671e98 gmp bits in 0.02s. */
if (M >= 2) {
  for (c2=3;c2<=2*M-3;c2++) {
    for (c4=ceild(c2+3,2);c4<=M;c4++) {
      for (i=ceild(c2+1,2);i<=min(c2-1,c4-1);i++) {
        S1(j = c2-i,k = c4) ;
      }
    }
    for (c4=max(1,c2-M);c4<=floord(c2-1,2);c4++) {
      S2(i = c2-c4,j = c4) ;
    }
    for (c4=ceild(c2+3,2);c4<=M;c4++) {
      for (i=ceild(c2+1,2);i<=min(c2-1,c4-1);i++) {
        S3(j = c2-i,k = c4) ;
      }
    }
  }
  for (c2=max(3,2*M-2);c2<=2*M-1;c2++) {
    for (c4=max(1,c2-M);c4<=floord(c2-1,2);c4++) {
      S2(i = c2-c4,j = c4) ;
    }
  }
}
