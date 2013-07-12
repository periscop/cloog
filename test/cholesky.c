/* Generated from ./cholesky.cloog by CLooG  gmp bits in 0.02s. */
/* <scop_0_code_start> */
if (n >= 1) {
  if (n >= 2) {
    S1(1);
    S3(1);
    for (c3=2;c3<=n;c3++) {
      S4(1,c3);
      S6(1,c3);
    }
  }
  if (n == 1) {
    S1(1);
    S3(1);
  }
  for (c1=2;c1<=n-1;c1++) {
    S1(c1);
    for (c3=1;c3<=c1-1;c3++) {
      S2(c1,c3);
    }
    S3(c1);
    for (c3=c1+1;c3<=n;c3++) {
      S4(c1,c3);
      for (c5=1;c5<=c1-1;c5++) {
        S5(c1,c3,c5);
      }
      S6(c1,c3);
    }
  }
  if (n >= 2) {
    S1(n);
    for (c3=1;c3<=n-1;c3++) {
      S2(n,c3);
    }
    S3(n);
  }
}
/* </scop_0_code_end> */
