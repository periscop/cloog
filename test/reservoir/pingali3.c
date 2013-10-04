/* Generated from ./reservoir/pingali3.cloog by CLooG  gmp bits in 0.01s. */
/* <scop_0_code_start> */
if (M >= 1) {
  for (c2=1;c2<=M;c2++) {
    for (c4=1;c4<=M;c4++) {
      S1(c2,c4);
    }
  }
  for (c2=1;c2<=M;c2++) {
    for (c4=1;c4<=M;c4++) {
      for (c6=1;c6<=M;c6++) {
        S2(c2,c4,c6);
      }
    }
  }
}
/* </scop_0_code_end> */
