/* Generated from ./reservoir/bastoul3.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
for (i=3;i<=9;i++) {
  for (j=max(i-6,i-2*floord(i+1,2)+2);j<=min(3,i-2);j+=2) {
    S1(i,j,(i-j)/2);
  }
}
/* </scop_0_code_end> */
