/* Generated from ./ex1.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
for (i=0;i<=14;i++) {
  for (j=0;j<=n-15;j++) {
    S1(i,j);
  }
}
for (i=15;i<=n;i++) {
  for (j=0;j<=9;j++) {
    S1(i,j);
  }
  for (j=10;j<=n-15;j++) {
    S1(i,j);
    S2(i,j);
  }
  for (j=n-14;j<=n;j++) {
    S2(i,j);
  }
}
/* </scop_0_code_end> */
