/* Generated from ./reservoir/lim-lam3.cloog by CLooG v0.14.0 gmp bits in 0.04s. */
/* CLooG asked for 304 KBytes. */
for (c2=5;c2<=min(5*M,8);c2++) {
  if (c2%5 == 0) {
    S4(i = c2/5) ;
  }
}
for (c2=9;c2<=min(13,5*M-1);c2++) {
  for (c4=max(1,ceild(c2-M-3,4));c4<=floord(c2-4,5);c4++) {
    i = c2-4*c4-3 ;
    S2(j = c4) ;
  }
  if (c2%5 == 0) {
    S4(i = c2/5) ;
  }
  for (c4=max(1,ceild(c2-3*M-1,2));c4<=floord(c2-4,5);c4++) {
    if ((c2+c4+2)%3 == 0) {
      i = (c2-2*c4-1)/3 ;
      S3(j = c4) ;
    }
  }
}
for (c2=14;c2<=5*M-1;c2++) {
  for (c4=max(2,ceild(c2-M-3,4));c4<=min(M-1,floord(c2-8,3));c4++) {
    for (c6=max(1,ceild(c2-2*c4-M-5,2));c6<=min(c4-1,floord(c2-3*c4-6,2));c6++) {
      i = c2-2*c4-2*c6-5 ;
      S1(j = c4,k = c6) ;
    }
  }
  for (c4=max(ceild(c2-M-3,4),1);c4<=floord(c2-4,5);c4++) {
    i = c2-4*c4-3 ;
    S2(j = c4) ;
  }
  if (c2%5 == 0) {
    S4(i = c2/5) ;
  }
  for (c4=max(ceild(c2-3*M-1,2),1);c4<=floord(c2-4,5);c4++) {
    if ((c2+c4+2)%3 == 0) {
      i = (c2-2*c4-1)/3 ;
      S3(j = c4) ;
    }
  }
}
if (M >= 2) {
  c2 = 5*M ;
  S4(i = M) ;
}
