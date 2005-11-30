/* Generated from fusion2.cloog by CLooG v0.14.0 64 bits in 0.00s. */
/* CLooG asked for 160 KBytes. */
if ((M >= 1) && (N >= 1)) {
  for (c4=1;c4<=M;c4++) {
    S1(i = 1,j = c4) ;
  }
}
if (M >= 1) {
  for (c2=2;c2<=N;c2++) {
    for (c4=1;c4<=M;c4++) {
      i = c2-1 ;
      S2(j = c4) ;
    }
    for (c4=1;c4<=M;c4++) {
      S1(i = c2,j = c4) ;
    }
  }
}
if ((M >= 1) && (N >= 1)) {
  c2 = N+1 ;
  for (c4=1;c4<=M;c4++) {
    S2(i = N,j = c4) ;
  }
}
