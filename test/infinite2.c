/* Generated from ./infinite2.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
for (i=1;i<=N;i++) {
  S1(i);
  for (j=1;j<=M;j++) {
    S2(i,j);
  }
}
for (i=N+1;;i++) {
  S1(i);
}
/* </scop_0_code_end> */
