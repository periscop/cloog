/* Generated from ./reservoir/lim-lam1.cloog by CLooG  gmp bits in 0.01s. */
/* <scop_0_code_start> */
S1(1,100);
for (c2=-98;c2<=99;c2++) {
  if (c2 <= 0) {
    S1(1,-c2+1);
  }
  if (c2 >= 1) {
    S2(c2,1);
  }
  for (c4=max(2,-2*c2+3);c4<=min(199,-2*c2+200);c4++) {
    if (c4%2 == 0) {
      S1((2*c2+c4)/2,c4/2);
    }
    if ((c4+1)%2 == 0) {
      S2((2*c2+c4-1)/2,(c4+1)/2);
    }
  }
  if (c2 <= 0) {
    S1(c2+100,100);
  }
  if (c2 >= 1) {
    S2(100,-c2+101);
  }
}
S2(100,1);
/* </scop_0_code_end> */
