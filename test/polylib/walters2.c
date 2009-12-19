/* Generated from /home/skimo/git/cloog/test/walters2.cloog by CLooG 0.14.0-227-g08f253a gmp bits in 0.00s. */
for (i=0;i<=51;i++) {
  S2(0,i);
}
for (j=1;j<=24;j++) {
  S2(j,0);
  for (i=1;i<=50;i++) {
    S1(j,i);
  }
  S2(j,51);
}
for (i=0;i<=51;i++) {
  if (i >= 0) {
    S2(25,i);
  }
}
