/* Generated from ./classen2.cloog by CLooG  gmp bits in 0.15s. */
/* <scop_0_code_start> */
if ((M >= 2) && (N >= 3) && (outerProcTileScatter1 >= outerProcTileScatter2) && (5*outerProcTileScatter1 <= M+2*N-4) && (5*outerProcTileScatter1 <= 5*outerProcTileScatter2+N+2) && (outerProcTileScatter2 >= 0) && (5*outerProcTileScatter2 <= M+N-2) && (outerTimeTileScatter >= outerProcTileScatter1) && (outerTimeTileScatter <= 2*outerProcTileScatter1) && (outerTimeTileScatter <= outerProcTileScatter1+outerProcTileScatter2+1) && (5*outerTimeTileScatter <= 2*M+2*N-6) && (5*outerTimeTileScatter <= 5*outerProcTileScatter1+M+2) && (5*outerTimeTileScatter >= 10*outerProcTileScatter1-2*N-2) && (5*outerTimeTileScatter <= 5*outerProcTileScatter2+M+N) && (5*outerTimeTileScatter >= 10*outerProcTileScatter2-N-3) && (5*outerTimeTileScatter <= 10*outerProcTileScatter2+N+3) && (5*outerTimeTileScatter >= 5*outerProcTileScatter1+5*outerProcTileScatter2-N-4)) {
  for (compScatter1=max(max(max(max(max(4,5*outerTimeTileScatter),5*outerProcTileScatter2+1),5*outerProcTileScatter1+5*outerProcTileScatter2-N),10*outerProcTileScatter1-2*N+2),10*outerProcTileScatter2-N+1);compScatter1<=min(min(min(min(min(5*outerTimeTileScatter+4,2*M+2*N-6),5*outerProcTileScatter1+M+2),5*outerProcTileScatter1+5*outerProcTileScatter2+5),5*outerProcTileScatter2+M+N),10*outerProcTileScatter2+N+3);compScatter1++) {
    for (compScatter2=max(max(max(max(ceild(compScatter1+4,2),5*outerProcTileScatter1),5*outerProcTileScatter2+1),compScatter1-M+2),compScatter1-5*outerProcTileScatter2-1);compScatter2<=min(min(min(min(floord(compScatter1+2*N-2,2),compScatter1),5*outerProcTileScatter1+4),compScatter1-5*outerProcTileScatter2+N),5*outerProcTileScatter2+N+2);compScatter2++) {
      for (compScatter3=max(max(5*outerProcTileScatter2,compScatter1-compScatter2+3),compScatter2-N+2);compScatter3<=min(min(compScatter2-1,5*outerProcTileScatter2+4),compScatter1-compScatter2+N);compScatter3++) {
        S1(compScatter1-compScatter2+1,-compScatter1+compScatter2+compScatter3-2,compScatter2-compScatter3,compScatter1,compScatter2,compScatter3);
      }
    }
  }
}
/* </scop_0_code_end> */
