/* Generated from ./reservoir/loechner4.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
if (M >= 1) {
  for (c2=2;c2<=2*M;c2++) {
    for (c4=1;c4<=M;c4++) {
      for (c6=1;c6<=M;c6++) {
        for (c8=max(1,c2-M);c8<=min(M,c2-1);c8++) {
          S1(c6,c4,c8,c2-c8);
        }
      }
    }
  }
}
/* </scop_0_code_end> */
