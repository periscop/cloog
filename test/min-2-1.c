/* Generated from ./min-2-1.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
if ((M >= 0) && (N >= 1)) {
  for (i=1;i<=N;i++) {
    for (j=0;j<=min(min(M,i),-i+N);j++) {
      for (k=0;k<=min(min(M,i),-i+N);k++) {
        S1(i,j,k);
      }
    }
  }
}
/* </scop_0_code_end> */
