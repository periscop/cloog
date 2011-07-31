/* Generated from ../../../git/cloog/test/reservoir/bastoul3.cloog by CLooG 0.16.3 gmp bits in 0.01s. */
for (i=3;i<=9;i++) {
  for (j=max(i-6,i-2*floord(i+1,2)+2);j<=min(3,i-2);j+=2) {
    S1(i,j,(i-j)/2);
  }
}
