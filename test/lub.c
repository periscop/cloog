/* Generated from ./lub.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
if (M >= 2) {
  for (i=1;i<=M-1;i++) {
    for (j=i+1;j<=M;j++) {
      S1(i,j);
      for (k=i+1;k<=M;k++) {
        S2(i,j,k);
        S3(i,j,k);
      }
      S4(i,j);
    }
  }
}
/* </scop_0_code_end> */
