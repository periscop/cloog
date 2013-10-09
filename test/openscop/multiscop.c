/* Generated from test/openscop/multiscop.scop by CLooG 0.18.0-2-gdf6919a gmp bits in 0.00s. */
if (N >= 1) {
  for (i=0;i<=N-1;i++) {
    for (j=0;j<=N-1;j++) {
      c[i][j] = 0.0;
      for (k=0;k<=N-1;k++) {
        c[i][j] = c[i][j] + a[i][k]*b[k][j];
      }
    }
  }
}
/* Generated from test/openscop/multiscop.scop by CLooG 0.18.0-2-gdf6919a gmp bits in 0.01s. */
if (N >= 1) {
  for (i=0;i<=N-1;i++) {
    for (j=0;j<=N-1;j++) {
      c[i][j] = 0.0;
      for (k=0;k<=N-1;k++) {
        c[i][j] = c[i][j] + a[i][k]*b[k][j];
      }
    }
  }
}
/* Generated from test/openscop/multiscop.scop by CLooG 0.18.0-2-gdf6919a gmp bits in 0.00s. */
i = 0;
