/* Generated from ../../../git/cloog/test/./reservoir/QR.cloog by CLooG 0.14.0-135-g7671e98 gmp bits in 0.30s. */
if (N >= 1) {
  if (M <= -1) {
    S1(i = 0) ;
  }
  if (M >= 0) {
    S1(i = 0) ;
  }
  if ((M >= 1) && (N >= 2)) {
    for (c4=0;c4<=M-1;c4++) {
      S2(i = 0,j = c4) ;
    }
    S3(i = 0) ;
    for (c4=0;c4<=M-1;c4++) {
      S4(i = 0,j = c4) ;
    }
    S10(i = 0) ;
    S1(i = 1) ;
    S5(i = 0) ;
  }
  if ((M <= 0) && (N >= 2)) {
    S3(i = 0) ;
    S10(i = 0) ;
    S1(i = 1) ;
    S5(i = 0) ;
  }
  if ((M >= 1) && (N == 1)) {
    for (c4=0;c4<=M-1;c4++) {
      S2(i = 0,j = c4) ;
    }
    S3(i = 0) ;
    for (c4=0;c4<=M-1;c4++) {
      S4(i = 0,j = c4) ;
    }
    S10(i = 0) ;
    S5(i = 0) ;
  }
  if ((M <= 0) && (N == 1)) {
    S3(i = 0) ;
    S10(i = 0) ;
    S5(i = 0) ;
  }
  for (c2=2;c2<=min(M,N-1);c2++) {
    for (c4=c2-1;c4<=N-1;c4++) {
      S6(i = c2-2,j = c4) ;
      for (c6=c2-2;c6<=M-1;c6++) {
        S7(i = c2-2,j = c4,k = c6) ;
      }
      S8(i = c2-2,j = c4) ;
      for (c6=c2-2;c6<=M-1;c6++) {
        S9(i = c2-2,j = c4,k = c6) ;
      }
    }
    for (c4=c2-1;c4<=M-1;c4++) {
      S2(i = c2-1,j = c4) ;
    }
    S3(i = c2-1) ;
    for (c4=c2-1;c4<=M-1;c4++) {
      S4(i = c2-1,j = c4) ;
    }
    S10(i = c2-1) ;
    S1(i = c2) ;
    S5(i = c2-1) ;
  }
  if ((M >= 1) && (M <= N-2)) {
    for (c4=M;c4<=N-1;c4++) {
      S6(i = M-1,j = c4) ;
      S7(i = M-1,j = c4,k = M-1) ;
      S8(i = M-1,j = c4) ;
      S9(i = M-1,j = c4,k = M-1) ;
    }
    S3(i = M) ;
    S10(i = M) ;
    S1(i = M+1) ;
    S5(i = M) ;
  }
  if ((M >= N) && (N >= 2)) {
    S6(i = N-2,j = N-1) ;
    for (c6=N-2;c6<=M-1;c6++) {
      S7(i = N-2,j = N-1,k = c6) ;
    }
    S8(i = N-2,j = N-1) ;
    for (c6=N-2;c6<=M-1;c6++) {
      S9(i = N-2,j = N-1,k = c6) ;
    }
    for (c4=N-1;c4<=M-1;c4++) {
      S2(i = N-1,j = c4) ;
    }
    S3(i = N-1) ;
    for (c4=N-1;c4<=M-1;c4++) {
      S4(i = N-1,j = c4) ;
    }
    S10(i = N-1) ;
    S5(i = N-1) ;
  }
  if ((M == N-1) && (N >= 2)) {
    S6(i = N-2,j = N-1) ;
    S7(i = N-2,j = N-1,k = N-2) ;
    S8(i = N-2,j = N-1) ;
    S9(i = N-2,j = N-1,k = N-2) ;
    S3(i = N-1) ;
    S10(i = N-1) ;
    S5(i = N-1) ;
  }
  for (c2=max(2,M+2);c2<=N-1;c2++) {
    for (c4=c2-1;c4<=N-1;c4++) {
      S6(i = c2-2,j = c4) ;
      S8(i = c2-2,j = c4) ;
    }
    S3(i = c2-1) ;
    S10(i = c2-1) ;
    S1(i = c2) ;
    S5(i = c2-1) ;
  }
  if ((M <= N-2) && (N >= 2)) {
    S6(i = N-2,j = N-1) ;
    S8(i = N-2,j = N-1) ;
    S3(i = N-1) ;
    S10(i = N-1) ;
    S5(i = N-1) ;
  }
}
