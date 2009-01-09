/* Generated from ../../../git/cloog/test/levenshtein-1-2-3.cloog by CLooG 0.14.0-135-g7671e98 gmp bits in 0.04s. */
S1(i = 0,j = 0) ;
S2(i = 1,j = 0) ;
S3(i = 1,j = 1) ;
for (i=2;i<=N;i++) {
  S2(j = 0) ;
  for (j=1;j<=i-1;j++) {
    S6 ;
  }
  S3(j = i) ;
}
S7(i = N+1,j = 0) ;
for (j=1;j<=N;j++) {
  S6(i = N+1) ;
  S8(i = N+1) ;
}
for (i=N+2;i<=2*M-N-2;i++) {
  j = floord(i-N-1,2) ;
  S7 ;
  if ((i+N)%2 == 0) {
    S5(j = (i-N)/2) ;
    S8(j = (i-N)/2) ;
  }
  for (j=ceild(i-N+1,2);j<=floord(i+N-1,2);j++) {
    S6 ;
    S8 ;
  }
  if ((i+N)%2 == 0) {
    S4(j = (i+N)/2) ;
    S8(j = (i+N)/2) ;
  }
}
for (i=2*M-N-1;i<=2*M-2;i++) {
  for (j=i-M+1;j<=M-1;j++) {
    S6 ;
  }
}
