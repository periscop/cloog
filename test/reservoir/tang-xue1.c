/* Generated from ./reservoir/tang-xue1.cloog by CLooG  gmp bits in 0.02s. */
/* <scop_0_code_start> */
for (c2=0;c2<=9;c2++) {
  for (c4=max(-1,c2-9);c4<=min(4,c2+3);c4++) {
    for (c6=max(max(1,c2),c2-c4);c6<=min(min(9,c2+1),c2-c4+4);c6++) {
      for (c8=max(1,-c2+c4+c6);c8<=min(4,-c2+c4+c6+1);c8++) {
        if (c2%2 == 0) {
          if (c4%2 == 0) {
            S1(c2/2,(-c2+c4)/2,-c2+c6,-c4+c8);
          }
        }
      }
    }
  }
}
/* </scop_0_code_end> */
