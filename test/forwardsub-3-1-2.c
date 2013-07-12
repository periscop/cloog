/* Generated from ./forwardsub-3-1-2.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
S3(2,1);
S1(3,1);
S1(4,1);
S4(4,2);
for (i=5;i<=M+1;i++) {
  S1(i,1);
  for (j=2;j<=floord(i-1,2);j++) {
    S2(i,j);
  }
  if (i%2 == 0) {
    S4(i,i/2);
  }
}
for (i=M+2;i<=2*M-1;i++) {
  for (j=i-M;j<=floord(i-1,2);j++) {
    S2(i,j);
  }
  if (i%2 == 0) {
    S4(i,i/2);
  }
}
S4(2*M,M);
/* </scop_0_code_end> */
