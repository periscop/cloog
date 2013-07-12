/* Generated from ./gauss.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
if (M >= 2) {
  for (c2=2;c2<=M;c2++) {
    for (j=2;j<=M;j++) {
      S2(1,j,c2);
    }
  }
  for (c1=2;c1<=M-1;c1++) {
    for (c2=c1+1;c2<=M;c2++) {
      for (j=1;j<=c1-1;j++) {
        S1(c1,j,c2);
      }
      for (j=c1+1;j<=M;j++) {
        S2(c1,j,c2);
      }
    }
  }
}
/* </scop_0_code_end> */
