/* Generated from ./reservoir/lim-lam1.cloog by CLooG v0.14.0 gmp bits in 0.02s. */
/* CLooG asked for 188 KBytes. */
S1(i = 1,j = 100) ;
for (c2=-98;c2<=0;c2++) {
  c4 = -2*c2+2 ;
  j = -c2+1 ;
  S1(i = 1) ;
  for (c4=-2*c2+3;c4<=199;c4++) {
    if (c4%2 == 0) {
      i = (2*c2+c4)/2 ;
      S1(j = c4/2) ;
    }
    if ((c4+1)%2 == 0) {
      i = (2*c2+c4-1)/2 ;
      j = (c4+1)/2 ;
      S2 ;
    }
  }
  i = c2+100 ;
  S1(j = 100) ;
}
for (c2=1;c2<=99;c2++) {
  S2(i = c2,j = 1) ;
  for (c4=2;c4<=-2*c2+200;c4++) {
    if (c4%2 == 0) {
      i = (2*c2+c4)/2 ;
      S1(j = c4/2) ;
    }
    if ((c4+1)%2 == 0) {
      i = (2*c2+c4-1)/2 ;
      j = (c4+1)/2 ;
      S2 ;
    }
  }
  c4 = -2*c2+201 ;
  j = -c2+101 ;
  S2(i = 100) ;
}
S2(i = 100,j = 1) ;
