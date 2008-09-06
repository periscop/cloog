/* Generated from ../../../git/cloog/test/4-param.cloog by CLooG 0.14.0-107-g04a31aa gmp bits in 0.00s. */
for (i=m;i<=min(n,p-1);i++) {
  S1 ;
}
for (i=p;i<=min(q,m-1);i++) {
  S2 ;
}
for (i=max(m,p);i<=min(n,q);i++) {
  S1 ;
  S2 ;
}
for (i=max(max(m,p),q+1);i<=n;i++) {
  S1 ;
}
for (i=max(max(m,p),n+1);i<=q;i++) {
  S2 ;
}
