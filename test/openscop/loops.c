  if (N >= 1) {
    lbp=0;
    ubp=floord(N-1,32);
#pragma omp parallel for private(lbv,ubv,t3,t4,t5,t6,t7,t8,t9)
    for (t2=lbp;t2<=ubp;t2++) {
      for (t3=0;t3<=floord(N-1,32);t3++) {
        for (t4=32*t2;t4<=min(N-1,32*t2+31);t4++) {
          lbv=32*t3;
          ubv=min(N-1,32*t3+31);
          #pragma ivdep
          #pragma vector always
          for (t9=lbv;t9<=ubv;t9++) {
            c[t4][t9] = 0.0;
          }
        }
      }
    }
    lbp=0;
    ubp=floord(N-1,32);
#pragma omp parallel for private(lbv,ubv,t3,t4,t5,t6,t7,t8,t9)
    for (t2=lbp;t2<=ubp;t2++) {
      for (t3=0;t3<=floord(N-1,32);t3++) {
        for (t4=0;t4<=floord(N-1,32);t4++) {
          for (t5=32*t2;t5<=min(N-1,32*t2+31);t5++) {
            for (t6=32*t4;t6<=min(N-1,32*t4+31);t6++) {
              lbv=32*t3;
              ubv=min(N-1,32*t3+31);
              #pragma ivdep
              #pragma vector always
              for (t9=lbv;t9<=ubv;t9++) {
                c[t5][t9] = c[t5][t9] + a[t5][t6]*b[t6][t9];
              }
            }
          }
        }
      }
    }
  }
