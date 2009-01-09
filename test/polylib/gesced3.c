/* Generated from ../../../git/cloog/test/gesced3.cloog by CLooG 0.14.0-135-g7671e98 gmp bits in 0.01s. */
for (c1=M+1;c1<=2*M;c1++) {
  S1(i = c1-M) ;
}
for (c1=2*M+1;c1<=M+N;c1++) {
  S2(i = c1-2*M) ;
  S1(i = c1-M) ;
}
for (c1=M+N+1;c1<=2*M+N;c1++) {
  S2(i = c1-2*M) ;
}
