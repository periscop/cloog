/* Generated from ../../../git/cloog/test/thomasset.cloog by CLooG 0.14.0-117-g7c6f653 gmp bits in 0.68s. */
if (n >= 1) {
  for (c1=0;c1<=floord(n-4,3);c1++) {
    for (i=3*c1+1;i<=3*c1+3;i++) {
      S1(j = c1) ;
    }
  }
  if ((n >= 2) && (n <= 3)) {
    S1(i = 1,j = 0) ;
    for (j=1;j<=-n+4;j++) {
      for (p=ceild(n-2,3);p<=floord(-j+2,3);p++) {
        S2(i = 1,k = 0,q = -p) ;
      }
    }
    for (i=2;i<=n;i++) {
      S1(j = 0) ;
    }
    for (c2=1;c2<=n-1;c2++) {
      i = c2+1 ;
      for (j=1;j<=-n+4;j++) {
        for (p=ceild(n-2,3);p<=floord(-j+2,3);p++) {
          S2(k = 0,q = -p) ;
        }
      }
    }
  }
  if (n == 1) {
    S1(i = 1,j = 0) ;
    S2(i = 1,j = 1,k = 0,p = 0,q = 0) ;
  }
  for (c1=max(1,ceild(n-3,3));c1<=floord(n-1,3);c1++) {
    for (j=1;j<=3*c1-n+4;j++) {
      for (p=ceild(n-2,3);p<=floord(3*c1-j+2,3);p++) {
        q = c1-p ;
        S2(i = 1,k = 0) ;
      }
    }
    for (i=3*c1+1;i<=n;i++) {
      S1(j = c1) ;
    }
    for (c2=1;c2<=n-1;c2++) {
      i = c2+1 ;
      for (j=1;j<=3*c1-n+4;j++) {
        for (p=ceild(n-2,3);p<=floord(3*c1-j+2,3);p++) {
          q = c1-p ;
          S2(k = 0) ;
        }
      }
    }
  }
  for (c1=ceild(n,3);c1<=floord(2*n,3);c1++) {
    for (c2=0;c2<=n-1;c2++) {
      i = c2+1 ;
      for (j=max(1,3*c1-n);j<=min(n,3*c1-n+4);j++) {
        for (p=max(ceild(3*c1-j,3),ceild(n-2,3));p<=min(floord(n,3),floord(3*c1-j+2,3));p++) {
          q = c1-p ;
          S2(k = 0) ;
        }
      }
    }
  }
}
