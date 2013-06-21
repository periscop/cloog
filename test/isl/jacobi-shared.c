/* Generated from ../../../git/cloog/test/isl/jacobi-shared.cloog by CLooG 0.16.3-2-g5511bef gmp bits in 1.82s. */
if ((h0+1)%2 == 0) {
  if ((16*floord(t0-1,16) >= -N+g1+t0+1) && (16*floord(g1+t0-3,16) >= -N+g1+t0+1) && (32*floord(t1-1,32) >= -N+g2+t1+1) && (32*floord(g2+t1-3,32) >= t1-32)) {
    for (c0=max(-16*floord(t0-1,16)+t0,-16*floord(g1+t0-3,16)+t0);c0<=min(32,N-g1-1);c0+=16) {
      for (c1=-32*floord(t1-1,32)+t1;c1<=min(32,N-g2-1);c1+=32) {
        if ((c1 >= 1) && (c1 <= 32)) {
          S1(c0+g1-1,c1+g2-1);
        }
      }
    }
  }
}
