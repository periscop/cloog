/* Generated from ../../../git/cloog/test/./reservoir/lim-lam4.cloog by CLooG 0.14.0-117-g5444fca gmp bits in 0.02s. */
if (M >= 2) {
  S1(i = 1,j = 0,k = 0) ;
  for (c2=2;c2<=2*M-2;c2++) {
    for (c4=max(-M+1,-c2+1);c4<=-1;c4++) {
      for (i=max(1,c2-M+1);i<=min(M-1,c2+c4);i++) {
        j = c2+c4-i ;
        S1(k = -c4) ;
      }
      for (c6=max(-c4,c2-M+1);c6<=min(M-1,c2-1);c6++) {
        i = c2-c6 ;
        j = c4+c6 ;
        S2(k = c6) ;
      }
    }
    for (i=max(1,c2-M+1);i<=min(c2,M-1);i++) {
      j = c2-i ;
      S1(k = 0) ;
    }
  }
}
