/* Generated from ./test/openscop/matmult.scop by CLooG 0.14.0-416-g013422c gmp bits in 0.51s. */
for (c2=0;c2<=N-1;c2++) {
  for (c4=0;c4<=N-1;c4++) {
    S1(c2,c4);
    for (c6=0;c6<=N-1;c6++) {
      S2(c2,c4,c6);
    }
  }
}
