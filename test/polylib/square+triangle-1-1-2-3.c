/* Generated from ../../../git/cloog/test/square+triangle-1-1-2-3.cloog by CLooG 0.14.0-135-g7671e98 gmp bits in 0.01s. */
for (j=1;j<=M;j++) {
  S1(i = 1) ;
}
for (i=2;i<=M-1;i++) {
  S1(j = 1) ;
  for (j=2;j<=i;j++) {
    S1 ;
    S2 ;
  }
  for (j=i+1;j<=M;j++) {
    S1 ;
  }
}
if (M >= 2) {
  S1(i = M,j = 1) ;
  for (j=2;j<=M;j++) {
    S1(i = M) ;
    S2(i = M) ;
  }
}
