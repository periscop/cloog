/* Generated from ../../../git/cloog/test/gesced.cloog by CLooG 0.14.0-135-g7671e98 gmp bits in 0.02s. */
for (c1=1;c1<=N;c1++) {
  S1(i = c1) ;
}
for (c1=N+1;c1<=2*N;c1++) {
  for (i=1;i<=N;i++) {
    S2(j = c1-N) ;
  }
}
for (c1=2*N+1;c1<=M+N;c1++) {
  for (i=1;i<=N;i++) {
    S3(j = c1-2*N) ;
    S2(j = c1-N) ;
  }
}
for (c1=M+N+1;c1<=M+2*N;c1++) {
  for (i=1;i<=N;i++) {
    S3(j = c1-2*N) ;
  }
}
