! Generated from ../../../git/cloog/test/iftestf.cloog by CLooG 0.14.0-135-g7671e98 gmp bits in 0.00s.
IF (n >= 1) THEN
  DO i=1, n
    IF (i <= 2*m) THEN
      S1
    END IF
    IF (i >= MAX(m,2*m+1)) THEN
      S1
    END IF
  END DO
END IF
