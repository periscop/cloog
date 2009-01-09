/* Generated from ../../../git/cloog/test/yosr2.cloog by CLooG 0.14.0-135-g7671e98 gmp bits in 0.03s. */
for (i=1;i<=M;i++) {
  S2 ;
}
for (proc=2;proc<=M-1;proc++) {
  for (i=1;i<=proc-1;i++) {
    S4(j = proc) ;
  }
  for (j=1;j<=proc-1;j++) {
    S1(i = proc) ;
  }
  for (j=proc+1;j<=M;j++) {
    for (k=1;k<=proc-1;k++) {
      S3(i = proc) ;
    }
  }
}
for (i=1;i<=M-1;i++) {
  S4(j = M) ;
}
for (j=1;j<=M-1;j++) {
  S1(i = M) ;
}
