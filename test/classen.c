/* Generated from classen.cloog by CLooG v0.14.0 gmp bits in 1.54s. */
/* CLooG asked for 3980 KBytes. */
if (m >= 2) {
  S1(coordT1 = 0,coordP1 = 1,other1 = 1,other2 = 1) ;
  S2(coordT1 = 0,coordP1 = 1,other1 = 1,other2 = 1,other3 = 1,other4 = 1,other5 = 2,other6 = 1) ;
  S3(coordT1 = 0,coordP1 = 1,other1 = 1,other2 = 2,other3 = 1,other4 = 1,other5 = 1,other6 = 2) ;
  S4(coordT1 = 0,coordP1 = 1,other1 = 2,other2 = 2,other3 = 1,other4 = 1,other5 = 2,other6 = 2) ;
  S8(coordT1 = 0,coordP1 = 1) ;
}
if (m == 1) {
  S1(coordT1 = 0,coordP1 = 1,other1 = 1,other2 = 1) ;
  S8(coordT1 = 0,coordP1 = 1) ;
}
if (m >= 3) {
  S5(coordT1 = 0,coordP1 = 1,other1 = 1,other2 = 1,other3 = 1,other4 = 1,other5 = 2,other6 = 1) ;
  S1(coordT1 = 1,coordP1 = 1,other1 = 2,other2 = 1) ;
  S2(coordT1 = 1,coordP1 = 1,other1 = 2,other2 = 1,other3 = 2,other4 = 1,other5 = 3,other6 = 1) ;
  S3(coordT1 = 1,coordP1 = 1,other1 = 2,other2 = 2,other3 = 2,other4 = 1,other5 = 2,other6 = 2) ;
  S4(coordT1 = 1,coordP1 = 1,other1 = 3,other2 = 2,other3 = 2,other4 = 1,other5 = 3,other6 = 2) ;
  S6(coordT1 = 0,coordP1 = 1,other1 = 1,other2 = 2,other3 = 1,other4 = 1,other5 = 1,other6 = 2) ;
  S7(coordT1 = 0,coordP1 = 1,other1 = 2,other2 = 2,other3 = 1,other4 = 1,other5 = 2,other6 = 2) ;
  S1(coordT1 = 1,coordP1 = 2,other1 = 1,other2 = 2) ;
  S2(coordT1 = 1,coordP1 = 2,other1 = 2,other2 = 2,other3 = 1,other4 = 2,other5 = 2,other6 = 2) ;
  S3(coordT1 = 1,coordP1 = 2,other1 = 2,other2 = 3,other3 = 1,other4 = 2,other5 = 1,other6 = 3) ;
  S4(coordT1 = 1,coordP1 = 2,other1 = 3,other2 = 3,other3 = 1,other4 = 2,other5 = 2,other6 = 3) ;
  for (coordP1=1;coordP1<=2;coordP1++) {
    S8(coordT1 = 1) ;
  }
}
for (glT1=2;glT1<=m-2;glT1++) {
  coordT1 = glT1-1 ;
  other5 = glT1+1 ;
  S5(coordP1 = 1,other1 = glT1,other2 = 1,other3 = glT1,other4 = 1,other6 = 1) ;
  other1 = glT1+1 ;
  S1(coordT1 = glT1,coordP1 = 1,other2 = 1) ;
  local1 = glT1+1 ;
  other1 = glT1+1 ;
  other3 = glT1+1 ;
  other5 = glT1+2 ;
  S2(coordT1 = glT1,coordP1 = 1,other2 = 1,other4 = 1,other6 = 1) ;
  other3 = glT1+1 ;
  other5 = glT1+1 ;
  S3(coordT1 = glT1,coordP1 = 1,other2 = 2,other4 = 1,other6 = 2) ;
  other1 = glT1+2 ;
  other3 = glT1+1 ;
  other5 = glT1+2 ;
  S4(coordT1 = glT1,coordP1 = 1,other2 = 2,other4 = 1,other6 = 2) ;
  for (rp1=2;rp1<=glT1;rp1++) {
    local1 = glT1-rp1+1 ;
    coordT1 = glT1-1 ;
    other3 = glT1-rp1+1 ;
    other5 = glT1-rp1+2 ;
    S5(coordP1 = rp1,other1 = glT1,other2 = rp1,other4 = rp1,other6 = rp1) ;
    local1 = glT1-rp1+2 ;
    local2 = rp1-1 ;
    coordT1 = glT1-1 ;
    coordP1 = rp1-1 ;
    other3 = glT1-rp1+2 ;
    other4 = rp1-1 ;
    other5 = glT1-rp1+2 ;
    S6(other1 = glT1,other2 = rp1,other6 = rp1) ;
    other1 = glT1+1 ;
    other3 = glT1-rp1+2 ;
    other4 = rp1-1 ;
    other5 = glT1-rp1+3 ;
    S7(other2 = rp1,other6 = rp1) ;
    other1 = glT1-rp1+2 ;
    S1(coordT1 = glT1,coordP1 = rp1,other2 = rp1) ;
    local1 = glT1-rp1+2 ;
    other1 = glT1+1 ;
    other3 = glT1-rp1+2 ;
    other5 = glT1-rp1+3 ;
    S2(coordT1 = glT1,coordP1 = rp1,other2 = rp1,other4 = rp1,other6 = rp1) ;
    other2 = rp1+1 ;
    other3 = glT1-rp1+2 ;
    other5 = glT1-rp1+2 ;
    other6 = rp1+1 ;
    S3(coordT1 = glT1,coordP1 = rp1,other4 = rp1) ;
    other1 = glT1+2 ;
    other2 = rp1+1 ;
    other3 = glT1-rp1+2 ;
    other5 = glT1-rp1+3 ;
    other6 = rp1+1 ;
    S4(coordT1 = glT1,coordP1 = rp1,other4 = rp1) ;
  }
  rp1 = glT1+1 ;
  coordT1 = glT1-1 ;
  other2 = glT1+1 ;
  other6 = glT1+1 ;
  S6(coordP1 = glT1,other1 = glT1,other3 = 1,other4 = glT1,other5 = 1) ;
  other1 = glT1+1 ;
  other2 = glT1+1 ;
  other6 = glT1+1 ;
  S7(coordP1 = glT1,other3 = 1,other4 = glT1,other5 = 2) ;
  coordP1 = glT1+1 ;
  other2 = glT1+1 ;
  S1(coordT1 = glT1,other1 = 1) ;
  local2 = glT1+1 ;
  coordP1 = glT1+1 ;
  other1 = glT1+1 ;
  other2 = glT1+1 ;
  other4 = glT1+1 ;
  other6 = glT1+1 ;
  S2(coordT1 = glT1,other3 = 1,other5 = 2) ;
  other2 = glT1+2 ;
  other4 = glT1+1 ;
  other6 = glT1+2 ;
  S3(coordT1 = glT1,other3 = 1,other5 = 1) ;
  other1 = glT1+2 ;
  other2 = glT1+2 ;
  other4 = glT1+1 ;
  other6 = glT1+2 ;
  S4(coordT1 = glT1,other3 = 1,other5 = 2) ;
  for (coordP1=1;coordP1<=glT1+1;coordP1++) {
    S8(coordT1 = glT1) ;
  }
}
if (m >= 3) {
  glT1 = m-1 ;
  local1 = m-1 ;
  coordT1 = m-2 ;
  other1 = m-1 ;
  other3 = m-1 ;
  S5(coordP1 = 1,other2 = 1,other4 = 1,other5 = m,other6 = 1) ;
  coordT1 = m-1 ;
  S1(coordP1 = 1,other1 = m,other2 = 1) ;
  coordT1 = m-1 ;
  S3(coordP1 = 1,other1 = m,other2 = 2,other3 = m,other4 = 1,other5 = m,other6 = 2) ;
  for (rp1=2;rp1<=m-1;rp1++) {
    local1 = -rp1+m ;
    coordT1 = m-2 ;
    other1 = m-1 ;
    other3 = -rp1+m ;
    other5 = -rp1+m+1 ;
    S5(coordP1 = rp1,other2 = rp1,other4 = rp1,other6 = rp1) ;
    local1 = -rp1+m+1 ;
    local2 = rp1-1 ;
    coordT1 = m-2 ;
    coordP1 = rp1-1 ;
    other1 = m-1 ;
    other3 = -rp1+m+1 ;
    other4 = rp1-1 ;
    other5 = -rp1+m+1 ;
    S6(other2 = rp1,other6 = rp1) ;
    other3 = -rp1+m+1 ;
    other4 = rp1-1 ;
    other5 = -rp1+m+2 ;
    S7(other1 = m,other2 = rp1,other6 = rp1) ;
    coordT1 = m-1 ;
    other1 = -rp1+m+1 ;
    S1(coordP1 = rp1,other2 = rp1) ;
    local1 = -rp1+m+1 ;
    coordT1 = m-1 ;
    other3 = -rp1+m+1 ;
    other5 = -rp1+m+2 ;
    S2(coordP1 = rp1,other1 = m,other2 = rp1,other4 = rp1,other6 = rp1) ;
    other2 = rp1+1 ;
    other3 = -rp1+m+1 ;
    other5 = -rp1+m+1 ;
    other6 = rp1+1 ;
    S3(coordP1 = rp1,other1 = m,other4 = rp1) ;
    other1 = m+1 ;
    other2 = rp1+1 ;
    other3 = -rp1+m+1 ;
    other5 = -rp1+m+2 ;
    other6 = rp1+1 ;
    S4(coordP1 = rp1,other4 = rp1) ;
  }
  local2 = m-1 ;
  coordT1 = m-2 ;
  coordP1 = m-1 ;
  other1 = m-1 ;
  other4 = m-1 ;
  S6(other2 = m,other3 = 1,other5 = 1,other6 = m) ;
  other4 = m-1 ;
  S7(other1 = m,other2 = m,other3 = 1,other5 = 2,other6 = m) ;
  coordT1 = m-1 ;
  S1(coordP1 = m,other1 = 1,other2 = m) ;
  coordT1 = m-1 ;
  S2(coordP1 = m,other1 = m,other2 = m,other3 = 1,other4 = m,other5 = 2,other6 = m) ;
  coordT1 = m-1 ;
  for (coordP1=1;coordP1<=m;coordP1++) {
    S8 ;
  }
}
for (glT1=m;glT1<=2*m-4;glT1++) {
  rp1 = glT1-m+2 ;
  local1 = m-1 ;
  local2 = glT1-m+2 ;
  coordT1 = glT1-1 ;
  coordP1 = glT1-m+2 ;
  other2 = glT1-m+2 ;
  other3 = m-1 ;
  other4 = glT1-m+2 ;
  other6 = glT1-m+2 ;
  S5(other1 = glT1,other5 = m) ;
  local2 = glT1-m+1 ;
  coordT1 = glT1-1 ;
  coordP1 = glT1-m+1 ;
  other2 = glT1-m+2 ;
  other4 = glT1-m+1 ;
  other6 = glT1-m+2 ;
  S6(other1 = glT1,other3 = m,other5 = m) ;
  coordP1 = glT1-m+2 ;
  other2 = glT1-m+2 ;
  S1(coordT1 = glT1,other1 = m) ;
  local2 = glT1-m+2 ;
  coordP1 = glT1-m+2 ;
  other1 = glT1+1 ;
  other2 = glT1-m+3 ;
  other4 = glT1-m+2 ;
  other6 = glT1-m+3 ;
  S3(coordT1 = glT1,other3 = m,other5 = m) ;
  for (rp1=glT1-m+3;rp1<=m-1;rp1++) {
    local1 = glT1-rp1+1 ;
    coordT1 = glT1-1 ;
    other3 = glT1-rp1+1 ;
    other5 = glT1-rp1+2 ;
    S5(coordP1 = rp1,other1 = glT1,other2 = rp1,other4 = rp1,other6 = rp1) ;
    local1 = glT1-rp1+2 ;
    local2 = rp1-1 ;
    coordT1 = glT1-1 ;
    coordP1 = rp1-1 ;
    other3 = glT1-rp1+2 ;
    other4 = rp1-1 ;
    other5 = glT1-rp1+2 ;
    S6(other1 = glT1,other2 = rp1,other6 = rp1) ;
    other1 = glT1+1 ;
    other3 = glT1-rp1+2 ;
    other4 = rp1-1 ;
    other5 = glT1-rp1+3 ;
    S7(other2 = rp1,other6 = rp1) ;
    other1 = glT1-rp1+2 ;
    S1(coordT1 = glT1,coordP1 = rp1,other2 = rp1) ;
    local1 = glT1-rp1+2 ;
    other1 = glT1+1 ;
    other3 = glT1-rp1+2 ;
    other5 = glT1-rp1+3 ;
    S2(coordT1 = glT1,coordP1 = rp1,other2 = rp1,other4 = rp1,other6 = rp1) ;
    other2 = rp1+1 ;
    other3 = glT1-rp1+2 ;
    other5 = glT1-rp1+2 ;
    other6 = rp1+1 ;
    S3(coordT1 = glT1,coordP1 = rp1,other4 = rp1) ;
    other1 = glT1+2 ;
    other2 = rp1+1 ;
    other3 = glT1-rp1+2 ;
    other5 = glT1-rp1+3 ;
    other6 = rp1+1 ;
    S4(coordT1 = glT1,coordP1 = rp1,other4 = rp1) ;
  }
  local1 = glT1-m+1 ;
  coordT1 = glT1-1 ;
  other3 = glT1-m+1 ;
  other5 = glT1-m+2 ;
  S5(coordP1 = m,other1 = glT1,other2 = m,other4 = m,other6 = m) ;
  local1 = glT1-m+2 ;
  local2 = m-1 ;
  coordT1 = glT1-1 ;
  coordP1 = m-1 ;
  other3 = glT1-m+2 ;
  other4 = m-1 ;
  other5 = glT1-m+2 ;
  S6(other1 = glT1,other2 = m,other6 = m) ;
  other1 = glT1+1 ;
  other3 = glT1-m+2 ;
  other4 = m-1 ;
  other5 = glT1-m+3 ;
  S7(other2 = m,other6 = m) ;
  other1 = glT1-m+2 ;
  S1(coordT1 = glT1,coordP1 = m,other2 = m) ;
  local1 = glT1-m+2 ;
  other1 = glT1+1 ;
  other3 = glT1-m+2 ;
  other5 = glT1-m+3 ;
  S2(coordT1 = glT1,coordP1 = m,other2 = m,other4 = m,other6 = m) ;
  for (coordP1=glT1-m+2;coordP1<=m;coordP1++) {
    S8(coordT1 = glT1) ;
  }
}
if (m >= 3) {
  glT1 = 2*m-3 ;
  rp1 = m-1 ;
  local1 = m-1 ;
  local2 = m-1 ;
  coordT1 = 2*m-4 ;
  coordP1 = m-1 ;
  other1 = 2*m-3 ;
  other2 = m-1 ;
  other3 = m-1 ;
  other4 = m-1 ;
  other6 = m-1 ;
  S5(other5 = m) ;
  local2 = m-2 ;
  coordT1 = 2*m-4 ;
  coordP1 = m-2 ;
  other1 = 2*m-3 ;
  other2 = m-1 ;
  other4 = m-2 ;
  other6 = m-1 ;
  S6(other3 = m,other5 = m) ;
  coordT1 = 2*m-3 ;
  coordP1 = m-1 ;
  other2 = m-1 ;
  S1(other1 = m) ;
  local2 = m-1 ;
  coordT1 = 2*m-3 ;
  coordP1 = m-1 ;
  other1 = 2*m-2 ;
  other4 = m-1 ;
  S3(other2 = m,other3 = m,other5 = m,other6 = m) ;
  local1 = m-2 ;
  coordT1 = 2*m-4 ;
  other1 = 2*m-3 ;
  other3 = m-2 ;
  other5 = m-1 ;
  S5(coordP1 = m,other2 = m,other4 = m,other6 = m) ;
  local1 = m-1 ;
  local2 = m-1 ;
  coordT1 = 2*m-4 ;
  coordP1 = m-1 ;
  other1 = 2*m-3 ;
  other3 = m-1 ;
  other4 = m-1 ;
  other5 = m-1 ;
  S6(other2 = m,other6 = m) ;
  other1 = 2*m-2 ;
  other3 = m-1 ;
  other4 = m-1 ;
  S7(other2 = m,other5 = m,other6 = m) ;
  coordT1 = 2*m-3 ;
  other1 = m-1 ;
  S1(coordP1 = m,other2 = m) ;
  local1 = m-1 ;
  coordT1 = 2*m-3 ;
  other1 = 2*m-2 ;
  other3 = m-1 ;
  S2(coordP1 = m,other2 = m,other4 = m,other5 = m,other6 = m) ;
  coordT1 = 2*m-3 ;
  for (coordP1=m-1;coordP1<=m;coordP1++) {
    S8 ;
  }
}
if (m == 2) {
  S5(coordT1 = 0,coordP1 = 1,other1 = 1,other2 = 1,other3 = 1,other4 = 1,other5 = 2,other6 = 1) ;
  S1(coordT1 = 1,coordP1 = 1,other1 = 2,other2 = 1) ;
  S3(coordT1 = 1,coordP1 = 1,other1 = 2,other2 = 2,other3 = 2,other4 = 1,other5 = 2,other6 = 2) ;
  S1(coordT1 = 1,coordP1 = 2,other1 = 1,other2 = 2) ;
  S2(coordT1 = 1,coordP1 = 2,other1 = 2,other2 = 2,other3 = 1,other4 = 2,other5 = 2,other6 = 2) ;
}
if (m >= 2) {
  glT1 = 2*m-2 ;
  local1 = m-1 ;
  coordT1 = 2*m-3 ;
  other1 = 2*m-2 ;
  other3 = m-1 ;
  S5(coordP1 = m,other2 = m,other4 = m,other5 = m,other6 = m) ;
  local2 = m-1 ;
  coordT1 = 2*m-3 ;
  coordP1 = m-1 ;
  other1 = 2*m-2 ;
  other4 = m-1 ;
  S6(other2 = m,other3 = m,other5 = m,other6 = m) ;
  coordT1 = 2*m-2 ;
  S1(coordP1 = m,other1 = m,other2 = m) ;
  coordT1 = 2*m-2 ;
  S8(coordP1 = m) ;
}
