/* Generated from ./byu98-1-2-3.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
for (i=2;i<=3;i++) {
  for (j=-i+6;j<=6;j++) {
    S1(i,j);
  }
}
for (i=4;i<=7;i++) {
  if (i == 4) {
    for (j=3;j<=4;j++) {
      S1(i,j);
    }
  }
  if (i >= 6) {
    S2(i,-i+9);
  }
  if (i <= 5) {
    S1(i,-i+9);
    S2(i,-i+9);
  }
  for (j=max(-i+10,i-1);j<=6;j++) {
    S1(i,j);
  }
}
S2(8,1);
/* </scop_0_code_end> */
