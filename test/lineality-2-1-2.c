/* Generated from /home/skimo/git/cloog/test/lineality-2-1-2.cloog by CLooG 0.14.0-284-ga90f184 gmp bits in 0.00s. */
for (i=1;i<=M;i++) {
  for (j=1;j<=min(M,i+1);j++) {
    S1(i,j);
  }
  if (i >= M-1) {
    S2(i,i+2);
  }
  if (i <= M-2) {
    S1(i,i+2);
    S2(i,i+2);
  }
  for (j=i+3;j<=M;j++) {
    S1(i,j);
  }
}
