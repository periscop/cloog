/* Generated from ./openscop/multiscop.scop by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
if (N >= 1) {
  for (i=0;i<=N-1;i++) {
    for (j=0;j<=N-1;j++) {
      c[i][j] = 0.0;
      for (k=0;k<=N-1;k++) {
        c[i][j] = c[i][j] + a[i][k]*b[k][j];
      }
    }
  }
}
/* </scop_0_code_end> */
/* Generated from ./openscop/multiscop.scop by CLooG  gmp bits in 0.00s. */
/* <scop_1_code_start> */
if (N >= 1) {
  for (i=0;i<=N-1;i++) {
    for (j=0;j<=N-1;j++) {
      c[i][j] = 0.0;
      for (k=0;k<=N-1;k++) {
        c[i][j] = c[i][j] + a[i][k]*b[k][j];
      }
    }
  }
}
/* </scop_1_code_end> */
/* Generated from ./openscop/multiscop.scop by CLooG  gmp bits in 0.00s. */
/* <scop_2_code_start> */
i = 0;
/* </scop_2_code_end> */
