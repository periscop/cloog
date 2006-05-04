/* Generated from ./reservoir/pingali6.cloog by CLooG v0.14.0 gmp bits in 0.04s. */
/* CLooG asked for 212 KBytes. */
if (N >= 3) {
  for (c4=2;c4<=N-1;c4++) {
    for (c6=2;c6<=N-1;c6++) {
      S1(i = 1,j = c4,k = c6) ;
    }
  }
}
if (N >= 3) {
  for (c2=3;c2<=2*M;c2++) {
    for (c4=2;c4<=N-1;c4++) {
      for (c6=2;c6<=N-1;c6++) {
        if (c2%2 == 0) {
          S1(i = c2/2,j = c4,k = c6) ;
        }
      }
    }
    for (c4=2;c4<=N-1;c4++) {
      for (c6=2;c6<=N-1;c6++) {
        if ((c2+1)%2 == 0) {
          i = (c2-1)/2 ;
          S2(j = c4,k = c6) ;
        }
      }
    }
  }
}
if (N >= 3) {
  c2 = 2*M+1 ;
  for (c4=2;c4<=N-1;c4++) {
    for (c6=2;c6<=N-1;c6++) {
      S2(i = M,j = c4,k = c6) ;
    }
  }
}
