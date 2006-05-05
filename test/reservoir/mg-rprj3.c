/* Generated from ./reservoir/mg-rprj3.cloog by CLooG v0.14.0 gmp bits in 0.35s. */
/* CLooG asked for 1128 KBytes. */
if ((M >= 4) && (N >= 4)) {
  for (c2=2;c2<=O-1;c2++) {
    for (c6=2;c6<=M;c6++) {
      S1(i = c2,j = 2,k = c6) ;
    }
    for (c4=3;c4<=N-1;c4++) {
      for (c6=2;c6<=M;c6++) {
        j = c4-1 ;
        S2(i = c2,k = c6) ;
      }
      j = c4-1 ;
      S4(i = c2,k = 2) ;
      for (c6=2;c6<=M-2;c6++) {
        j = c4-1 ;
        S3(i = c2,k = c6) ;
        j = c4-1 ;
        S5(i = c2,k = c6) ;
        j = c4-1 ;
        k = c6+1 ;
        S4(i = c2) ;
      }
      c6 = M-1 ;
      j = c4-1 ;
      k = M-1 ;
      S3(i = c2) ;
      j = c4-1 ;
      k = M-1 ;
      S5(i = c2) ;
      for (c6=2;c6<=M;c6++) {
        S1(i = c2,j = c4,k = c6) ;
      }
    }
    for (c6=2;c6<=M;c6++) {
      j = N-1 ;
      S2(i = c2,k = c6) ;
    }
    j = N-1 ;
    S4(i = c2,k = 2) ;
    for (c6=2;c6<=M-2;c6++) {
      j = N-1 ;
      S3(i = c2,k = c6) ;
      j = N-1 ;
      S5(i = c2,k = c6) ;
      j = N-1 ;
      k = c6+1 ;
      S4(i = c2) ;
    }
    c6 = M-1 ;
    j = N-1 ;
    k = M-1 ;
    S3(i = c2) ;
    j = N-1 ;
    k = M-1 ;
    S5(i = c2) ;
  }
}
if ((M >= 4) && (N == 3)) {
  for (c2=2;c2<=O-1;c2++) {
    for (c6=2;c6<=M;c6++) {
      S1(i = c2,j = 2,k = c6) ;
    }
    for (c6=2;c6<=M;c6++) {
      S2(i = c2,j = 2,k = c6) ;
    }
    S4(i = c2,j = 2,k = 2) ;
    for (c6=2;c6<=M-2;c6++) {
      S3(i = c2,j = 2,k = c6) ;
      S5(i = c2,j = 2,k = c6) ;
      k = c6+1 ;
      S4(i = c2,j = 2) ;
    }
    c6 = M-1 ;
    k = M-1 ;
    S3(i = c2,j = 2) ;
    k = M-1 ;
    S5(i = c2,j = 2) ;
  }
}
if ((M == 3) && (N == 3)) {
  for (c2=2;c2<=O-1;c2++) {
    for (c6=2;c6<=3;c6++) {
      S1(i = c2,j = 2,k = c6) ;
    }
    for (c6=2;c6<=3;c6++) {
      S2(i = c2,j = 2,k = c6) ;
    }
    S4(i = c2,j = 2,k = 2) ;
    S3(i = c2,j = 2,k = 2) ;
    S5(i = c2,j = 2,k = 2) ;
  }
}
if ((M == 3) && (N >= 4)) {
  for (c2=2;c2<=O-1;c2++) {
    for (c6=2;c6<=3;c6++) {
      S1(i = c2,j = 2,k = c6) ;
    }
    for (c4=3;c4<=N-1;c4++) {
      for (c6=2;c6<=3;c6++) {
        j = c4-1 ;
        S2(i = c2,k = c6) ;
      }
      j = c4-1 ;
      S4(i = c2,k = 2) ;
      j = c4-1 ;
      S3(i = c2,k = 2) ;
      j = c4-1 ;
      S5(i = c2,k = 2) ;
      for (c6=2;c6<=3;c6++) {
        S1(i = c2,j = c4,k = c6) ;
      }
    }
    for (c6=2;c6<=3;c6++) {
      j = N-1 ;
      S2(i = c2,k = c6) ;
    }
    j = N-1 ;
    S4(i = c2,k = 2) ;
    j = N-1 ;
    S3(i = c2,k = 2) ;
    j = N-1 ;
    S5(i = c2,k = 2) ;
  }
}
if ((M == 2) && (N >= 4)) {
  for (c2=2;c2<=O-1;c2++) {
    S1(i = c2,j = 2,k = 2) ;
    for (c4=3;c4<=N-1;c4++) {
      j = c4-1 ;
      S2(i = c2,k = 2) ;
      S1(i = c2,j = c4,k = 2) ;
    }
    j = N-1 ;
    S2(i = c2,k = 2) ;
  }
}
if ((M == 2) && (N == 3)) {
  for (c2=2;c2<=O-1;c2++) {
    S1(i = c2,j = 2,k = 2) ;
    S2(i = c2,j = 2,k = 2) ;
  }
}
