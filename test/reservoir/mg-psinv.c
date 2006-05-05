/* Generated from ./reservoir/mg-psinv.cloog by CLooG v0.14.0 gmp bits in 0.06s. */
/* CLooG asked for 300 KBytes. */
if ((M >= 3) && (N >= 4)) {
  for (c2=2;c2<=O-1;c2++) {
    for (c6=1;c6<=M;c6++) {
      S1(i = c2,j = 2,k = c6) ;
      S2(i = c2,j = 2,k = c6) ;
    }
    for (c4=4;c4<=2*N-3;c4++) {
      for (c6=1;c6<=M;c6++) {
        if ((c4+1)%2 == 0) {
          j = (c4+1)/2 ;
          S1(i = c2,k = c6) ;
          S2(i = c2,k = c6) ;
        }
      }
      for (c6=2;c6<=M-1;c6++) {
        if (c4%2 == 0) {
          S3(i = c2,j = c4/2,k = c6) ;
        }
      }
    }
    c4 = 2*N-2 ;
    for (c6=2;c6<=M-1;c6++) {
      j = N-1 ;
      S3(i = c2,k = c6) ;
    }
  }
}
if ((M >= 3) && (N == 3)) {
  for (c2=2;c2<=O-1;c2++) {
    for (c6=1;c6<=M;c6++) {
      S1(i = c2,j = 2,k = c6) ;
      S2(i = c2,j = 2,k = c6) ;
    }
    for (c6=2;c6<=M-1;c6++) {
      S3(i = c2,j = 2,k = c6) ;
    }
  }
}
if ((M >= 1) && (M <= 2) && (N >= 3)) {
  for (c2=2;c2<=O-1;c2++) {
    for (c4=3;c4<=2*N-3;c4++) {
      for (c6=1;c6<=M;c6++) {
        if ((c4+1)%2 == 0) {
          j = (c4+1)/2 ;
          S1(i = c2,k = c6) ;
          S2(i = c2,k = c6) ;
        }
      }
    }
  }
}
