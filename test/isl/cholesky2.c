/* Generated from ../../../git/cloog/test/cholesky2.cloog by CLooG 0.14.0-135-g7671e98 gmp bits in 0.12s. */
if (M >= 1) {
  if (M >= 2) {
    for (c2=1;c2<=M-1;c2++) {
      S1(i = c2) ;
      for (c3=c2+1;c3<=M;c3++) {
        S4(i = c2,j = c3) ;
      }
    }
    S1(i = M) ;
  }
  if (M == 1) {
    S1(i = 1) ;
  }
  S3(i = 1) ;
  if (M >= 3) {
    S6(i = 1,j = 2) ;
    for (c2=3;c2<=M;c2++) {
      S6(i = 1,j = c2) ;
      for (i=2;i<=c2-1;i++) {
        S5(j = c2,k = 1) ;
      }
    }
  }
  if (M == 2) {
    S6(i = 1,j = 2) ;
  }
  for (c1=3;c1<=3*M-7;c1++) {
    if ((c1+2)%3 == 0) {
      S3(i = (c1+2)/3) ;
    }
    if (c1%3 == 0) {
      S2(i = (c1+3)/3,j = c1/3) ;
    }
    c2 = floord(c1+6,3) ;
    if ((c1+1)%3 == 0) {
      S6(i = (c1+1)/3,j = c2) ;
    }
    if (c1%3 == 0) {
      S2(i = c2,j = c1/3) ;
    }
    for (c2=ceild(c1+7,3);c2<=M;c2++) {
      if ((c1+1)%3 == 0) {
        S6(i = (c1+1)/3,j = c2) ;
      }
      if (c1%3 == 0) {
        S2(i = c2,j = c1/3) ;
      }
      if ((c1+1)%3 == 0) {
        for (i=ceild(c1+4,3);i<=c2-1;i++) {
          S5(j = c2,k = (c1+1)/3) ;
        }
      }
    }
  }
  if (M >= 3) {
    S2(i = M-1,j = M-2) ;
    S2(i = M,j = M-2) ;
  }
  for (c1=max(3,3*M-5);c1<=3*M-4;c1++) {
    if ((c1+2)%3 == 0) {
      S3(i = (c1+2)/3) ;
    }
    if ((c1+1)%3 == 0) {
      S6(i = (c1+1)/3,j = M) ;
    }
  }
  if (M >= 2) {
    S2(i = M,j = M-1) ;
  }
  if (M >= 2) {
    S3(i = M) ;
  }
}
