! Generated from ../../../git/cloog/test/iftestf.cloog by CLooG 0.14.0-91-g5d3da4b gmp bits in 0.00s.
DO i=1, n
  IF (i <= 2*m) THEN
    S1
  END IF
  IF (i >= MAX(m,2*m+1)) THEN
    S1
  END IF
END DO
