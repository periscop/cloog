/* Generated from ../../../git/cloog/test/forwardsub-2-1-2-3.cloog by CLooG 0.14.0-91-g5d3da4b gmp bits in 0.01s. */
S3(i = 1,j = 0) ;
for (k=2;k<=M;k++) {
  S1(i = 1,j = 1) ;
}
for (i=2;i<=M-1;i++) {
  S4(j = 0) ;
  for (k=i+1;k<=M;k++) {
    S2(j = 1) ;
  }
}
S4(i = M,j = 0) ;
