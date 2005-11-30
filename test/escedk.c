/* Generated from ./test/escedk.cloog by CLooG v0.14.0 64 bits in 0.01s. */
/* CLooG asked for 168 KBytes. */
if ((n <= m) && (n >= max(m+1,2))) {
  S1(i = n) ;
}
if ((n <= min(m,1)) && (n >= 0) && (m <= -1)) {
  S1(i = n) ;
}
if ((n == 1) && (m >= 1) && (m >= 0)) {
  S2(i = 0) ;
  for (j=0;j<=m;j++) {
    S3(i = 0) ;
  }
}
if ((n <= m) && (n >= 2)) {
  for (i=0;i<=min(m,n-1);i++) {
    S2 ;
  }
}
if ((n == 1) && (m == 0) && (m >= 0)) {
  S3(i = 0,j = 0) ;
}
if ((n <= min(min(1,m),m)) && (n >= 0)) {
  S1(i = n) ;
  S2(i = n) ;
  for (j=0;j<=m;j++) {
    S3(i = n) ;
  }
}
if ((n <= min(m,m)) && (n >= 2)) {
  S1(i = n) ;
  S2(i = n) ;
}
if ((n == 1) && (m == 0) && (m >= 1)) {
  S1(i = 1) ;
  S3(i = 1,j = 0) ;
}
if ((n <= min(1,m)) && (n >= 0)) {
  for (i=n+1;i<=m;i++) {
    S2 ;
    for (j=0;j<=m;j++) {
      S3 ;
    }
  }
}
if ((n <= m) && (n >= 2)) {
  for (i=n+1;i<=m;i++) {
    S2 ;
  }
}
if ((n == 1) && (m == 0)) {
  for (i=2;i<=m;i++) {
    S3(j = 0) ;
  }
}
