/* Generated from ./stride.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
for (c1=3;c1<=100;c1++) {
  if (c1 == 25) {
    S1(25);
  }
  if (c1%3 == 0) {
    S2(c1,c1/3);
  }
}
/* </scop_0_code_end> */
