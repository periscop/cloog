/* Generated from cholesky2.cloog by CLooG v0.14.0 gmp bits in 0.11s. */
/* CLooG asked for 616 KBytes. */
if (M >= 2) {
  for (c2=1;c2<=M-1;c2++) {
    S1(i = c2) ;
    for (c3=c2+1;c3<=M;c3++) {
      S4(i = c2,j = c3) ;
    }
  }
  S1(i = M) ;
}
if (M == 1) {
  S1(i = 1) ;
}
if (M >= 2) {
  S3(i = 1) ;
}
if (M >= 3) {
  S6(i = 1,j = 2) ;
  for (c2=3;c2<=M;c2++) {
    S6(i = 1,j = c2) ;
    for (i=2;i<=c2-1;i++) {
      S5(j = c2,k = 1) ;
    }
  }
}
if (M == 2) {
  S6(i = 1,j = 2) ;
}
for (c1=3;c1<=3*M-7;c1++) {
  if ((c1+2)%3 == 0) {
    i = (c1+2)/3 ;
    S3 ;
  }
  if (c1%3 == 0) {
    c2 = (c1+3)/3 ;
    i = (c1+3)/3 ;
    S2(j = c1/3) ;
  }
  for (c2=ceild(c1+4,3);c2<=floord(c1+6,3);c2++) {
    if ((c1+1)%3 == 0) {
      i = (c1+1)/3 ;
      S6(j = c2) ;
    }
    if (c1%3 == 0) {
      S2(i = c2,j = c1/3) ;
    }
  }
  for (c2=ceild(c1+7,3);c2<=M;c2++) {
    if ((c1+1)%3 == 0) {
      i = (c1+1)/3 ;
      S6(j = c2) ;
    }
    if (c1%3 == 0) {
      S2(i = c2,j = c1/3) ;
    }
    if ((c1+1)%3 == 0) {
      c3 = (c1+1)/3 ;
      for (i=ceild(c1+4,3);i<=c2-1;i++) {
        k = (c1+1)/3 ;
        S5(j = c2) ;
      }
    }
  }
}
for (c1=max(3*M-6,3);c1<=3*M-4;c1++) {
  if ((c1+2)%3 == 0) {
    i = (c1+2)/3 ;
    S3 ;
  }
  if (c1%3 == 0) {
    c2 = (c1+3)/3 ;
    i = (c1+3)/3 ;
    S2(j = c1/3) ;
  }
  for (c2=ceild(c1+4,3);c2<=M;c2++) {
    if ((c1+1)%3 == 0) {
      i = (c1+1)/3 ;
      S6(j = c2) ;
    }
    if (c1%3 == 0) {
      S2(i = c2,j = c1/3) ;
    }
  }
}
if (M >= 2) {
  c1 = 3*M-3 ;
  j = M-1 ;
  S2(i = M) ;
}
if (M >= 1) {
  c1 = 3*M-2 ;
  S3(i = M) ;
}
