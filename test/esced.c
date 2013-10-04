/* Generated from ./esced.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
if (m >= 1) {
  if (n >= 1) {
    for (i=1;i<=m;i++) {
      S1(i);
      for (j=1;j<=n;j++) {
        S2(i,j);
      }
    }
  }
  if (n <= 0) {
    for (i=1;i<=m;i++) {
      S1(i);
    }
  }
}
/* </scop_0_code_end> */
