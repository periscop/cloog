/* Generated from pingali5.cloog by CLooG v0.14.0 64 bits in 0.00s. */
/* CLooG asked for 160 KBytes. */
for (c2=3;c2<=2*M-3;c2++) {
  for (c4=ceild(c2+3,2);c4<=M;c4++) {
    for (i=ceild(c2+1,2);i<=min(c4-1,c2-1);i++) {
      j = c2-i ;
      S1(k = c4) ;
    }
  }
  for (c4=max(1,c2-M);c4<=floord(c2-1,2);c4++) {
    i = c2-c4 ;
    S2(j = c4) ;
  }
  for (c4=ceild(c2+3,2);c4<=M;c4++) {
    for (i=ceild(c2+1,2);i<=min(c4-1,c2-1);i++) {
      j = c2-i ;
      S3(k = c4) ;
    }
  }
}
for (c2=max(2*M-2,3);c2<=2*M-1;c2++) {
  for (c4=max(1,c2-M);c4<=floord(c2-1,2);c4++) {
    i = c2-c4 ;
    S2(j = c4) ;
  }
}
