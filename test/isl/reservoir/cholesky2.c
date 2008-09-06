/* Generated from ../../../git/cloog/test/./reservoir/cholesky2.cloog by CLooG 0.14.0-117-g7c6f653 gmp bits in 0.20s. */
if (M >= 1) {
  for (c2=2;c2<=min(3,3*M-4);c2++) {
    if ((c2+1)%3 == 0) {
      i = (c2+1)/3 ;
      S1 ;
    }
    for (c4=ceild(c2+4,3);c4<=c2;c4++) {
      if ((c2+c4)%2 == 0) {
        i = (c2-c4+2)/2 ;
        S2(j = c4) ;
      }
    }
  }
  for (c2=4;c2<=3*M-4;c2++) {
    if ((c2+1)%3 == 0) {
      i = (c2+1)/3 ;
      S1 ;
    }
    for (c4=ceild(c2+2,3);c4<=min(M,c2-2);c4++) {
      for (c6=ceild(c2-c4+2,2);c6<=min(c4,c2-c4);c6++) {
        i = c2-c4-c6+1 ;
        S3(j = c4,k = c6) ;
      }
    }
    for (c4=ceild(c2+4,3);c4<=min(M,c2);c4++) {
      if ((c2+c4)%2 == 0) {
        i = (c2-c4+2)/2 ;
        S2(j = c4) ;
      }
    }
  }
  for (c2=max(M+2,3*M-3);c2<=3*M-2;c2++) {
    for (c6=ceild(c2-M+2,2);c6<=M;c6++) {
      i = c2-c6-M+1 ;
      S3(j = M,k = c6) ;
    }
  }
  c2 = 3*M-1 ;
  S1(i = M) ;
}
