/* Generated from ./infinite3.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
for (;i<=0;i++) {
  S1(i);
}
for (i=1;i<=min(M,N);i++) {
  S1(i);
  for (j=1;j<=M;j++) {
    S2(i,j);
  }
}
for (i=N+1;i<=M;i++) {
  S1(i);
}
for (i=M+1;i<=N;i++) {
  for (j=1;j<=M;j++) {
    S2(i,j);
  }
}
/* </scop_0_code_end> */
