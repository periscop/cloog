/* Generated from ./reservoir/loechner3.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
if (M >= 1) {
  for (c2=1;c2<=M;c2++) {
    for (c4=2;c4<=c2+M;c4++) {
      for (c6=max(1,-c2+c4);c6<=min(M,c4-1);c6++) {
        S1(c2,c6,c4-c6);
      }
    }
  }
}
/* </scop_0_code_end> */
