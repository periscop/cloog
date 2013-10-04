/* Generated from ./forwardsub-2-1-2-3.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
S3(1,0);
for (k=2;k<=M;k++) {
  S1(1,1,k);
}
for (i=2;i<=M-1;i++) {
  S4(i,0);
  for (k=i+1;k<=M;k++) {
    S2(i,1,k);
  }
}
S4(M,0);
/* </scop_0_code_end> */
