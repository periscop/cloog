/* Generated from ./multi-mm-1.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
for (i=0;i<=M;i++) {
  for (j=0;j<=min(N,i);j++) {
    S1(i,j);
    S2(i,j);
  }
  for (j=N+1;j<=i;j++) {
    S1(i,j);
  }
}
/* </scop_0_code_end> */
