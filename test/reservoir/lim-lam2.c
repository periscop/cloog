/* Generated from ./reservoir/lim-lam2.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
for (c2=1;c2<=M;c2++) {
  S1(c2);
}
if (N >= 2) {
  for (c2=1;c2<=M;c2++) {
    for (c4=2;c4<=N;c4++) {
      S2(c2,c4);
    }
  }
}
if (N >= 2) {
  for (c2=1;c2<=M;c2++) {
    for (c4=1;c4<=N-1;c4++) {
      S3(c2,c4);
    }
  }
}
/* </scop_0_code_end> */
