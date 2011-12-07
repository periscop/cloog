/* Generated from ./test/openscop/union.scop by CLooG 0.14.0-432-g5cf921d gmp bits in 0.01s. */
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
