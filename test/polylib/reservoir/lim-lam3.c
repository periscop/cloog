/* Generated from ../../../git/cloog/test/./reservoir/lim-lam3.cloog by CLooG 0.14.0-135-g7671e98 gmp bits in 0.05s. */
for (c2=5;c2<=min(8,5*M);c2++) {
  if (c2%5 == 0) {
    S4(i = c2/5) ;
  }
}
for (c2=9;c2<=min(13,5*M-1);c2++) {
  for (c4=max(1,ceild(c2-M-3,4));c4<=floord(c2-4,5);c4++) {
    S2(i = c2-4*c4-3,j = c4) ;
  }
  if (c2%5 == 0) {
    S4(i = c2/5) ;
  }
  for (c4=max(1,ceild(c2-3*M-1,2));c4<=floord(c2-4,5);c4++) {
    if ((c2+c4+2)%3 == 0) {
      S3(i = (c2-2*c4-1)/3,j = c4) ;
    }
  }
}
for (c2=14;c2<=5*M-1;c2++) {
  for (c4=max(2,ceild(c2-M-3,4));c4<=min(floord(c2-8,3),M-1);c4++) {
    for (c6=max(1,ceild(c2-2*c4-M-5,2));c6<=min(floord(c2-3*c4-6,2),c4-1);c6++) {
      S1(i = c2-2*c4-2*c6-5,j = c4,k = c6) ;
    }
  }
  for (c4=max(1,ceild(c2-M-3,4));c4<=floord(c2-4,5);c4++) {
    S2(i = c2-4*c4-3,j = c4) ;
  }
  if (c2%5 == 0) {
    S4(i = c2/5) ;
  }
  for (c4=max(1,ceild(c2-3*M-1,2));c4<=floord(c2-4,5);c4++) {
    if ((c2+c4+2)%3 == 0) {
      S3(i = (c2-2*c4-1)/3,j = c4) ;
    }
  }
}
if (M >= 2) {
  S4(i = M) ;
}
