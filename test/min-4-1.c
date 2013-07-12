/* Generated from ./min-4-1.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
if ((M >= -N) && (M >= -O) && (N >= 0) && (N >= -O)) {
  for (i=max(-M,-N);i<=min(N,O);i++) {
    S1(i);
  }
}
/* </scop_0_code_end> */
