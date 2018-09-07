/* Generated from ../test/isl/jacobi-shared.cloog by CLooG 0.19.0-6faa51a gmp bits in 0.26s. */
if ((h0+1)%2 == 0) {
  if ((16*floord(N-t0-1,16) >= -t0+3) && (16*floord(N-t0-1,16) >= g1-t0+1) && (32*floord(t1-1,32) <= g2+t1-3) && (32*floord(t1-1,32) >= -N+g2+t1+1)) {
    for (c0=max(-16*floord(t0-1,16)+t0,-16*floord(g1+t0-3,16)+t0);c0<=min(32,N-g1-1);c0+=16) {
      for (c1=-32*floord(t1-1,32)+t1;c1<=min(32,N-g2-1);c1+=32) {
        S1((c0+g1-1),(c1+g2-1));
      }
    }
  }
}
