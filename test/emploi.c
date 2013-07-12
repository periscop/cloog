/* Generated from ./emploi.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
if (n >= 1) {
  if (m >= 1) {
    for (i=1;i<=n;i++) {
      S1(i);
      for (j=1;j<=m;j++) {
        S2(i,j);
      }
    }
  }
  if (m <= 0) {
    for (i=1;i<=n;i++) {
      S1(i);
    }
  }
}
/* </scop_0_code_end> */
