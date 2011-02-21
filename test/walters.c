/* Generated from ../../../git/cloog/test/walters.cloog by CLooG 0.16.1-3-g354eed5 gmp bits in 0.01s. */
S2(1,0,1,0);
S4(1,0,1,0);
S3(2,0,1,1);
S4(2,0,1,1);
for (i=3;i<=10;i++) {
  if ((i+1)%3 == 0) {
    S3(i,(i-2)/3,(i+1)/3,(i+1)/3);
  }
  if ((i+2)%3 == 0) {
    S2(i,(i-1)/3,(i+2)/3,(i-1)/3);
  }
  if (i%3 == 0) {
    S1(i,i/3,i/3,i/3);
  }
  div36 = floord(i,3);
  div37 = ceild(2*i-3*div36-1,3);
  if (div37 <= floord(i+2,3)) {
    S4(i,div36,div37,i-div36-div37);
  }
}
