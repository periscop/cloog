/* Generated from ./reservoir/loechner5.cloog by CLooG  gmp bits in 0.01s. */
/* <scop_0_code_start> */
if (M >= 1) {
  for (c2=1;c2<=M;c2++) {
    for (c4=1;c4<=M;c4++) {
      for (c6=1;c6<=M;c6++) {
        for (c8=1;c8<=M;c8++) {
          S1(c4,c6,c2,c8);
        }
      }
    }
  }
}
/* </scop_0_code_end> */
