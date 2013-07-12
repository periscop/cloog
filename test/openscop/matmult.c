/* Generated from ./openscop/matmult.scop by CLooG  gmp bits in 0.01s. */
/* <scop_0_code_start> */
for (c2=0;c2<=N-1;c2++) {
  for (c4=0;c4<=N-1;c4++) {
    C[c2][c4] = 0.0;
    for (c6=0;c6<=N-1;c6++) {
      C[c2][c4] = C[c2][c4] + A[c2][c6] * B[c6][c4];
    }
  }
}
/* </scop_0_code_end> */
