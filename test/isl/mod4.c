/* Generated from ./isl/mod4.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
if (M%11 <= 6) {
  if (N%5 <= 2) {
    if (M >= -N) {
      for (i=0;i<=M+N;i++) {
        S1(i);
      }
    }
  }
}
/* </scop_0_code_end> */
