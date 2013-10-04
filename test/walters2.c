/* Generated from ./walters2.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
for (i=0;i<=51;i++) {
  S2(0,i);
}
for (j=1;j<=24;j++) {
  S2(j,0);
  for (i=1;i<=50;i++) {
    S1(j,i);
  }
  S2(j,51);
}
for (i=0;i<=51;i++) {
  S2(25,i);
}
/* </scop_0_code_end> */
