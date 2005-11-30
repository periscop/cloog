/* Generated from ./test/vasilache.cloog by CLooG v0.14.0 64 bits in 0.08s. */
/* CLooG asked for 168 KBytes. */
S1 ;
S2 ;
for (p1=0;p1<=N-1;p1++) {
  for (p3=0;p3<=N-1;p3++) {
    S4(i = p1,j = p3) ;
    S5(i = p1,j = p3) ;
  }
}
for (p1=0;p1<=N-1;p1++) {
  for (p3=0;p3<=N-1;p3++) {
    for (p5=0;p5<=floord(N-1,32);p5++) {
      if (p5 >= 0) {
        p7 = 32*p5 ;
        l = 32*p5 ;
        S7(i = p1,j = p3,k = p5) ;
      }
      if (p5 <= -1) {
        S7(i = p1,j = p3,k = p5,l = 0) ;
      }
      for (p7=max(32*p5+1,1);p7<=min(N-1,32*p5+31);p7++) {
        l = p7-1 ;
        S6(i = p1,j = p3,k = p5) ;
        S7(i = p1,j = p3,k = p5,l = p7) ;
      }
      if (p5 >= ceild(N-32,32)) {
        l = N-1 ;
        S6(i = p1,j = p3,k = p5) ;
      }
      if (p5 <= floord(N-33,32)) {
        p7 = 32*p5+32 ;
        l = 32*p5+31 ;
        S6(i = p1,j = p3,k = p5) ;
      }
    }
  }
}
S8 ;
