/* Generated from ./gesced.cloog by CLooG  gmp bits in 0.01s. */
/* <scop_0_code_start> */
for (c1=1;c1<=N;c1++) {
  S1(c1);
}
for (c1=N+1;c1<=2*N;c1++) {
  for (i=1;i<=N;i++) {
    S2(i,c1-N);
  }
}
for (c1=2*N+1;c1<=M+N;c1++) {
  for (i=1;i<=N;i++) {
    S3(i,c1-2*N);
    S2(i,c1-N);
  }
}
for (c1=M+N+1;c1<=M+2*N;c1++) {
  for (i=1;i<=N;i++) {
    S3(i,c1-2*N);
  }
}
/* </scop_0_code_end> */
