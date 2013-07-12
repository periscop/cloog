/* Generated from ./isl/mxm-shared.cloog by CLooG  gmp bits in 0.29s. */
/* <scop_0_code_start> */
if (g4%4 == 0) {
  if ((N >= g0+t1+1) && (N >= g1+t0+1) && (t1 <= 7)) {
    for (c0=t0;c0<=min(127,N-g1-1);c0+=16) {
      S1(g0+t1,c0+g1);
    }
  }
}
/* </scop_0_code_end> */
