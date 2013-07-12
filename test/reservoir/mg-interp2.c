/* Generated from ./reservoir/mg-interp2.cloog by CLooG  gmp bits in 0.03s. */
/* <scop_0_code_start> */
if (O >= 2) {
  if ((M >= P+1) && (N >= Q+1)) {
    for (c2=1;c2<=O-1;c2++) {
      for (c4=Q;c4<=N-1;c4++) {
        for (c6=P;c6<=M-1;c6++) {
          S1(c2,c4,c6);
        }
      }
    }
  }
  if ((M >= 2) && (N >= Q+1)) {
    for (c2=1;c2<=O-1;c2++) {
      for (c4=Q;c4<=N-1;c4++) {
        for (c6=1;c6<=M-1;c6++) {
          S2(c2,c4,c6);
        }
      }
    }
  }
  if ((M >= P+1) && (N >= 2)) {
    for (c2=1;c2<=O-1;c2++) {
      for (c4=1;c4<=N-1;c4++) {
        for (c6=P;c6<=M-1;c6++) {
          S3(c2,c4,c6);
        }
      }
    }
  }
  if ((M >= 2) && (N >= 2)) {
    for (c2=1;c2<=O-1;c2++) {
      for (c4=1;c4<=N-1;c4++) {
        for (c6=1;c6<=M-1;c6++) {
          S4(c2,c4,c6);
        }
      }
    }
  }
}
/* </scop_0_code_end> */
