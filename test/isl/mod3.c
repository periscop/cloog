/* Generated from ./isl/mod3.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
for (i=max(0,32*h0-1991);i<=min(999,32*h0+31);i++) {
  if ((63*i+32*h0+31)%64 <= 62) {
    for (j=0;j<=999;j++) {
      S1(i,j);
    }
  }
}
/* </scop_0_code_end> */
