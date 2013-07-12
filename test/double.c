/* Generated from ./double.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
if (M >= 0) {
  for (i=0;i<=M;i++) {
    S1(i);
    for (j=0;j<=N;j++) {
      S2(i,j);
      S3(i,j);
    }
    S4(i);
  }
}
/* </scop_0_code_end> */
