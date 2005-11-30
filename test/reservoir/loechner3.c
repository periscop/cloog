/* Generated from loechner3.cloog by CLooG v0.14.0 64 bits in 0.00s. */
/* CLooG asked for 160 KBytes. */
for (c2=1;c2<=M;c2++) {
  for (c4=2;c4<=c2+M;c4++) {
    for (c6=max(1,-c2+c4);c6<=min(M,c4-1);c6++) {
      k = c4-c6 ;
      S1(i = c2,j = c6) ;
    }
  }
}
