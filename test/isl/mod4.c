/* Generated from /home/skimo/git/cloog/test/mod4.cloog by CLooG 0.14.0-223-gad1f0a0 gmp bits in 0.01s. */
for (j=2;j<=10;j+=3) {
  div41 = floord(j+2,3);
  S1(j,div41,(j+1)/3,2,(j-2)/3);
  S2(j,div41,(j+1)/3,2,(j-2)/3);
  S3(j,div41,(j+1)/3,2,(j-2)/3);
}
