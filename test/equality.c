/* Generated from ./equality.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
for (i0=0;i0<=5;i0++) {
  for (i1=ceild(4*i0,5);i1<=floord(6*i0+20,5);i1++) {
    if (2*i0 == i1) {
      S1(i0,i1);
    }
    if (i1 == 4) {
      S2(i0,i1);
    }
  }
}
/* </scop_0_code_end> */
