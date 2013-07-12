/* Generated from ./4-param.cloog by CLooG  gmp bits in 0.00s. */
/* <scop_0_code_start> */
for (i=m;i<=min(n,p-1);i++) {
  S1(i);
}
for (i=p;i<=min(q,m-1);i++) {
  S2(i);
}
for (i=max(m,p);i<=min(n,q);i++) {
  S1(i);
  S2(i);
}
for (i=max(max(m,p),q+1);i<=n;i++) {
  S1(i);
}
for (i=max(max(m,p),n+1);i<=q;i++) {
  S2(i);
}
/* </scop_0_code_end> */
