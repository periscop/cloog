/* Generated from ../../../git/cloog/test/forwardsub-1-1-2.cloog by CLooG 0.14.0-91-g5d3da4b gmp bits in 0.00s. */
S3(i = 1,j = 1) ;
S1(i = 2,j = 1) ;
S4(i = 2,j = 2) ;
for (i=3;i<=M;i++) {
  S1(j = 1) ;
  for (j=2;j<=i-1;j++) {
    S2 ;
  }
  S4(j = i) ;
}
