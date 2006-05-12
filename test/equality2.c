/* Generated from equality2.cloog by CLooG v0.14.0 gmp bits in 0.06s. */
/* CLooG asked for 308 KBytes. */
for (i0=1;i0<=10000;i0++) {
  for (i1=1000;i1<=1016;i1++) {
    for (i2=1;i2<=min(-2*i1+2033,2*i1-1999);i2++) {
      if (2*i1 == i2+1999) {
        S2(i3 = 1,i4 = i0,i5 = 2*i1-1000,i6 = 1,i7 = 2,i8 = i0,i9 = i1-499,i10 = 2*i1-1999,i11 = i0,i12 = 2*i1-1999,i13 = i1-999,i14 = i1-999) ;
      }
      if (i2 == 1) {
        if (i1%2 == 0) {
          S1(i3 = 2,i4 = i0,i5 = (i1+2)/2,i6 = i1-999,i7 = i0,i8 = i1-999,i9 = (i1-998)/2,i10 = (i1-998)/2) ;
        }
      }
    }
  }
}
