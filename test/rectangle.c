/* Generated from ./rectangle.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
for (c1=0;c1<=2*n;c1++) {
  for (i=max(0,c1-n);i<=min(c1,n);i++) {
    S1(i,c1-i);
  }
}
/* </scop_0_code_end> */
