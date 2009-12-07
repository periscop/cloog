/* Generated from /home/skimo/git/cloog/test/walters.cloog by CLooG 0.14.0-225-g6e2d019 gmp bits in 0.01s. */
S2(1,0,1,0);
S4(1,0,1,0);
S3(2,0,1,1);
S4(2,0,1,1);
for (i=3;i<=10;i++) {
  if ((i+1)%3 == 0) {
    S3(i,(i-2)/3,(i+1)/3,(i+1)/3);
    S4(i,(i-2)/3,(i+1)/3,(i+1)/3);
  }
  if ((i+2)%3 == 0) {
    S2(i,(i-1)/3,(i+2)/3,(i-1)/3);
    S4(i,(i-1)/3,(i+2)/3,(i-1)/3);
  }
  if (i%3 == 0) {
    S1(i,i/3,i/3,i/3);
    S4(i,i/3,i/3,i/3);
  }
}
