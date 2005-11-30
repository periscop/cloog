/* Generated from ./test/wavefront.cloog by CLooG v0.14.0 64 bits in 0.00s. */
/* CLooG asked for 168 KBytes. */
if ((n >= 1) && (m >= 1)) {
  for (c1=2;c1<=n+m;c1++) {
    for (c2=max(1,c1-m);c2<=min(n,c1-1);c2++) {
      j = c1-c2 ;
      S1(i = c2) ;
    }
  }
}
