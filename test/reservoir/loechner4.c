/* Generated from loechner4.cloog by CLooG v0.14.0 64 bits in 0.01s. */
/* CLooG asked for 160 KBytes. */
for (c2=2;c2<=2*M;c2++) {
  for (c4=1;c4<=M;c4++) {
    for (c6=1;c6<=M;c6++) {
      for (c8=max(1,c2-M);c8<=min(c2-1,M);c8++) {
        l = c2-c8 ;
        S1(i = c6,j = c4,k = c8) ;
      }
    }
  }
}
