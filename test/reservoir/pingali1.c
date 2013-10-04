/* Generated from ./reservoir/pingali1.cloog by CLooG  gmp bits in 0.01s. */
/* <scop_0_code_start> */
if ((M >= 1) && (N >= 1)) {
  if (N >= 2) {
    for (c2=1;c2<=M;c2++) {
      S2(c2,1);
      for (c4=3;c4<=2*N-1;c4++) {
        for (c6=max(1,c4-N);c6<=floord(c4-1,2);c6++) {
          S1(c2,c4-c6,c6);
        }
        if ((c4+1)%2 == 0) {
          S2(c2,(c4+1)/2);
        }
      }
    }
  }
  if (N == 1) {
    for (c2=1;c2<=M;c2++) {
      S2(c2,1);
    }
  }
}
/* </scop_0_code_end> */
