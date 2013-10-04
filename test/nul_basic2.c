/* Generated from ./nul_basic2.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
for (i=2;i<=n;i+=2) {
  if (i%4 == 0) {
    S2(i,i/4);
  }
  S1(i,i/2);
}
/* </scop_0_code_end> */
