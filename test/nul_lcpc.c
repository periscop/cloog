/* Generated from ./nul_lcpc.cloog by CLooG  gmp bits in 0.01s. */
/* <scop_0_code_start> */
for (i=1;i<=6;i+=2) {
  for (j=1;j<=i;j++) {
    S1(i,(i-1)/2,j);
    S2(i,(i-1)/2,j);
  }
  for (j=i+1;j<=p;j++) {
    S1(i,(i-1)/2,j);
  }
}
for (i=7;i<=m;i+=2) {
  for (j=1;j<=p;j++) {
    S1(i,(i-1)/2,j);
  }
}
/* </scop_0_code_end> */
