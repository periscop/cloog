/* Generated from ./tiling.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
for (ii=0;ii<=floord(n,10);ii++) {
  for (i=10*ii;i<=min(n,10*ii+9);i++) {
    S1(ii,i);
  }
}
/* </scop_0_code_end> */
