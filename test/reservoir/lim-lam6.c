/* Generated from ./reservoir/lim-lam6.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
if (M >= 1) {
  for (c2=0;c2<=M;c2++) {
    for (c4=1;c4<=M;c4++) {
      S1(c2,c4);
    }
  }
  for (c2=0;c2<=M;c2++) {
    for (c4=1;c4<=M;c4++) {
      S2(c4,c2);
    }
  }
}
/* </scop_0_code_end> */
