/* Generated from ./lineality-1-2.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
for (i=1;i<=M;i++) {
  for (j=1;j<=i-1;j++) {
    S1(i,j);
  }
  S1(i,i);
  S2(i,i);
  for (j=i+1;j<=M;j++) {
    S1(i,j);
  }
}
/* </scop_0_code_end> */
