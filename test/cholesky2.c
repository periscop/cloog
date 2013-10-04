/* Generated from ./cholesky2.cloog by CLooG  gmp bits in 0.04s. */
/* <scop_0_code_start> */
if (M >= 1) {
  for (c2=1;c2<=M-1;c2++) {
    S1(c2);
    for (c3=c2+1;c3<=M;c3++) {
      S4(c2,c3);
    }
  }
  S1(M);
  S3(1);
  if (M >= 3) {
    S6(1,2);
    for (c2=3;c2<=M;c2++) {
      S6(1,c2);
      for (i=2;i<=c2-1;i++) {
        S5(i,c2,1);
      }
    }
  }
  if (M == 2) {
    S6(1,2);
  }
  for (c1=3;c1<=3*M-7;c1++) {
    if ((c1+2)%3 == 0) {
      S3((c1+2)/3);
    }
    if (c1%3 == 0) {
      S2((c1+3)/3,c1/3);
    }
    if ((c1+1)%3 == 0) {
      S6((c1+1)/3,(c1+4)/3);
    }
    if (c1%3 == 0) {
      S2((c1+6)/3,c1/3);
    }
    for (c2=ceild(c1+7,3);c2<=M;c2++) {
      if ((c1+1)%3 == 0) {
        S6((c1+1)/3,c2);
      }
      if (c1%3 == 0) {
        S2(c2,c1/3);
      }
      if ((c1+1)%3 == 0) {
        for (i=ceild(c1+4,3);i<=c2-1;i++) {
          S5(i,c2,(c1+1)/3);
        }
      }
    }
  }
  if (M >= 3) {
    for (c2=M-1;c2<=M;c2++) {
      S2(c2,M-2);
    }
  }
  if (M >= 3) {
    S3(M-1);
  }
  if (M >= 3) {
    S6(M-1,M);
  }
  if (M >= 2) {
    S2(M,M-1);
  }
  if (M >= 2) {
    S3(M);
  }
}
/* </scop_0_code_end> */
