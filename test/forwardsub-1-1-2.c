/* Generated from ./forwardsub-1-1-2.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
S3(1,1);
S1(2,1);
S4(2,2);
for (i=3;i<=M;i++) {
  S1(i,1);
  for (j=2;j<=i-1;j++) {
    S2(i,j);
  }
  S4(i,i);
}
/* </scop_0_code_end> */
