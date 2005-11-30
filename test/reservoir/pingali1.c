/* Generated from pingali1.cloog by CLooG v0.14.0 64 bits in 0.01s. */
/* CLooG asked for 160 KBytes. */
if (N >= 2) {
  for (c2=1;c2<=M;c2++) {
    for (c4=1;c4<=2;c4++) {
      if ((c4+1)%2 == 0) {
        j = (c4+1)/2 ;
        S2(i = c2) ;
      }
    }
    for (c4=3;c4<=2*N-1;c4++) {
      for (c6=max(1,c4-N);c6<=floord(c4-1,2);c6++) {
        j = c4-c6 ;
        S1(i = c2,k = c6) ;
      }
      if ((c4+1)%2 == 0) {
        j = (c4+1)/2 ;
        S2(i = c2) ;
      }
    }
  }
}
if (N == 1) {
  for (c2=1;c2<=M;c2++) {
    S2(i = c2,j = 1) ;
  }
}
