/* Generated from ./reservoir/fusion2.cloog by CLooG  gmp bits in 0.01s. */
/* <scop_0_code_start> */
if ((M >= 1) && (N >= 1)) {
  for (c4=1;c4<=M;c4++) {
    S1(1,c4);
  }
  for (c2=2;c2<=N;c2++) {
    for (c4=1;c4<=M;c4++) {
      S2(c2-1,c4);
    }
    for (c4=1;c4<=M;c4++) {
      S1(c2,c4);
    }
  }
  for (c4=1;c4<=M;c4++) {
    S2(N,c4);
  }
}
/* </scop_0_code_end> */
