/* Generated from ./otl.cloog by CLooG  gmp bits in 0.30s. */
/* <scop_0_code_start> */
if ((M >= 3) && (N >= 4)) {
  for (outerTimeTileScatter=1;outerTimeTileScatter<=floord(2*M+2*N-7,5);outerTimeTileScatter++) {
    for (outerProcTileScatter1=max(ceild(outerTimeTileScatter,2),ceild(5*outerTimeTileScatter-M-2,5));outerProcTileScatter1<=min(min(floord(M+2*N-5,5),floord(5*outerTimeTileScatter+2*N+1,10)),outerTimeTileScatter);outerProcTileScatter1++) {
      for (outerProcTileScatter2=max(max(max(max(ceild(outerTimeTileScatter-outerProcTileScatter1-1,2),ceild(5*outerProcTileScatter1-N-1,5)),ceild(5*outerTimeTileScatter-M-N+1,5)),ceild(5*outerTimeTileScatter-N-2,10)),outerTimeTileScatter-outerProcTileScatter1-1);outerProcTileScatter2<=min(min(min(floord(M+N-2,5),floord(5*outerTimeTileScatter-5*outerProcTileScatter1+N+4,5)),floord(5*outerTimeTileScatter+N+3,10)),outerProcTileScatter1);outerProcTileScatter2++) {
        for (innerTimeTileScatter=max(max(max(ceild(10*outerProcTileScatter1-2*N,5),ceild(10*outerProcTileScatter2-N-2,5)),ceild(5*outerProcTileScatter1+5*outerProcTileScatter2-N-3,5)),outerTimeTileScatter);innerTimeTileScatter<=min(min(min(min(min(floord(2*M+2*N-6,5),floord(5*outerProcTileScatter1+M+3,5)),floord(5*outerProcTileScatter2+M+N,5)),floord(10*outerProcTileScatter2+N+3,5)),outerTimeTileScatter+1),outerProcTileScatter1+outerProcTileScatter2+1);innerTimeTileScatter++) {
          for (innerProcTileScatter1=max(max(max(max(ceild(innerTimeTileScatter,2),ceild(5*innerTimeTileScatter-M-2,5)),ceild(5*outerTimeTileScatter-M-1,5)),outerProcTileScatter1),outerTimeTileScatter-outerProcTileScatter2);innerProcTileScatter1<=min(min(min(min(min(min(min(floord(M+2*N-4,5),floord(5*outerProcTileScatter2+N+2,5)),floord(-5*outerProcTileScatter2+5*innerTimeTileScatter+N+4,5)),floord(5*outerTimeTileScatter-5*outerProcTileScatter2+N+5,5)),floord(5*innerTimeTileScatter+2*N+2,10)),floord(5*outerTimeTileScatter+2*N+3,10)),outerTimeTileScatter),outerProcTileScatter1+1);innerProcTileScatter1++) {
            for (innerProcTileScatter2=outerProcTileScatter2;innerProcTileScatter2<=outerProcTileScatter2;innerProcTileScatter2++) {
              for (outerTimeTileIter=outerTimeTileScatter;outerTimeTileIter<=outerTimeTileScatter;outerTimeTileIter++) {
                for (outerProcTileIter1=outerProcTileScatter1;outerProcTileIter1<=outerProcTileScatter1;outerProcTileIter1++) {
                  for (outerProcTileIter2=outerProcTileScatter2;outerProcTileIter2<=outerProcTileScatter2;outerProcTileIter2++) {
                    for (innerTimeTileIter=innerTimeTileScatter;innerTimeTileIter<=innerTimeTileScatter;innerTimeTileIter++) {
                      for (innerProcTileIter1=innerProcTileScatter1;innerProcTileIter1<=innerProcTileScatter1;innerProcTileIter1++) {
                        for (innerProcTileIter2=outerProcTileScatter2;innerProcTileIter2<=outerProcTileScatter2;innerProcTileIter2++) {
                          S1(outerTimeTileIter,outerProcTileIter1,outerProcTileIter2,innerTimeTileIter,innerProcTileIter1,innerProcTileIter2);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
/* </scop_0_code_end> */
