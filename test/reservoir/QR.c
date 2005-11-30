/* Generated from QR.cloog by CLooG v0.14.0 64 bits in 0.06s. */
/* CLooG asked for 288 KBytes. */
if ((M <= -1) && (N >= 1)) {
  S1(i = 0) ;
}
if ((M >= 0) && (N >= 1)) {
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
for (c2=2;c2<=min(N-1,M);c2++) {
  for (c4=c2-1;c4<=N-1;c4++) {
    i = c2-2 ;
    S6(j = c4) ;
    for (c6=c2-2;c6<=M-1;c6++) {
      i = c2-2 ;
      S7(j = c4,k = c6) ;
    }
    i = c2-2 ;
    S8(j = c4) ;
    for (c6=c2-2;c6<=M-1;c6++) {
      i = c2-2 ;
      S9(j = c4,k = c6) ;
    }
  }
  for (c4=c2-1;c4<=M-1;c4++) {
    i = c2-1 ;
    S2(j = c4) ;
  }
  i = c2-1 ;
  S3 ;
  for (c4=c2-1;c4<=M-1;c4++) {
    i = c2-1 ;
    S4(j = c4) ;
  }
  i = c2-1 ;
  S10 ;
  S1(i = c2) ;
  i = c2-1 ;
  S5 ;
}
if ((M >= 1) && (M <= N-2)) {
  c2 = M+1 ;
  for (c4=M;c4<=N-1;c4++) {
    i = M-1 ;
    S6(j = c4) ;
    c6 = M-1 ;
    i = M-1 ;
    k = M-1 ;
    S7(j = c4) ;
    i = M-1 ;
    S8(j = c4) ;
    c6 = M-1 ;
    i = M-1 ;
    k = M-1 ;
    S9(j = c4) ;
  }
  S3(i = M) ;
  S10(i = M) ;
  i = M+1 ;
  S1 ;
  S5(i = M) ;
}
if ((M >= N) && (N >= 2)) {
  c4 = N-1 ;
  i = N-2 ;
  j = N-1 ;
  S6 ;
  for (c6=N-2;c6<=M-1;c6++) {
    i = N-2 ;
    j = N-1 ;
    S7(k = c6) ;
  }
  i = N-2 ;
  j = N-1 ;
  S8 ;
  for (c6=N-2;c6<=M-1;c6++) {
    i = N-2 ;
    j = N-1 ;
    S9(k = c6) ;
  }
  for (c4=N-1;c4<=M-1;c4++) {
    i = N-1 ;
    S2(j = c4) ;
  }
  i = N-1 ;
  S3 ;
  for (c4=N-1;c4<=M-1;c4++) {
    i = N-1 ;
    S4(j = c4) ;
  }
  i = N-1 ;
  S10 ;
  i = N-1 ;
  S5 ;
}
if ((M == N-1) && (N >= 2)) {
  c4 = N-1 ;
  i = N-2 ;
  j = N-1 ;
  S6 ;
  c6 = N-2 ;
  i = N-2 ;
  j = N-1 ;
  k = N-2 ;
  S7 ;
  i = N-2 ;
  j = N-1 ;
  S8 ;
  c6 = N-2 ;
  i = N-2 ;
  j = N-1 ;
  k = N-2 ;
  S9 ;
  i = N-1 ;
  S3 ;
  i = N-1 ;
  S10 ;
  i = N-1 ;
  S5 ;
}
for (c2=max(M+2,2);c2<=N-1;c2++) {
  for (c4=c2-1;c4<=N-1;c4++) {
    i = c2-2 ;
    S6(j = c4) ;
    i = c2-2 ;
    S8(j = c4) ;
  }
  i = c2-1 ;
  S3 ;
  i = c2-1 ;
  S10 ;
  S1(i = c2) ;
  i = c2-1 ;
  S5 ;
}
if ((M <= N-2) && (N >= 2)) {
  c4 = N-1 ;
  i = N-2 ;
  j = N-1 ;
  S6 ;
  i = N-2 ;
  j = N-1 ;
  S8 ;
  i = N-1 ;
  S3 ;
  i = N-1 ;
  S10 ;
  i = N-1 ;
  S5 ;
}
