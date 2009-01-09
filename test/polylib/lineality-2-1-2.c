/* Generated from ../../../git/cloog/test/lineality-2-1-2.cloog by CLooG 0.14.0-135-g7671e98 gmp bits in 0.01s. */
for (i=1;i<=M-3;i++) {
  for (j=1;j<=i+1;j++) {
    S1 ;
  }
  S1(j = i+2) ;
  S2(j = i+2) ;
  for (j=i+3;j<=M;j++) {
    S1 ;
  }
}
if (M >= 3) {
  for (j=1;j<=M-1;j++) {
    S1(i = M-2) ;
  }
  S1(i = M-2,j = M) ;
  S2(i = M-2,j = M) ;
}
for (i=M-1;i<=M;i++) {
  for (j=1;j<=M;j++) {
    S1 ;
  }
  S2(j = i+2) ;
}
