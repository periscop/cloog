! Generated from ./test/iftestf.cloog by CLooG v0.14.0 64 bits in 0.00s.
! CLooG asked for 168 KBytes.
DO i=1, n
  IF (i <= 2*m) THEN
    S1
  END IF
  IF (i >= MAX(m,2*m+1)) THEN
    S1
  END IF
END DO
