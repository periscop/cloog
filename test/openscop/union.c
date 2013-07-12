/* Generated from ./openscop/union.scop by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
if (N >= 1) {
  for (c2=0;c2<=N-1;c2++) {
    for (c4=0;c4<=min(10,N-1);c4++) {
      C[c2+c4]+=A[c2]*B[c4];
    }
    for (c4=20;c4<=N-1;c4++) {
      C[c2+c4]+=A[c2]*B[c4];
    }
  }
}
/* </scop_0_code_end> */
