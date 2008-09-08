! Generated from ../../../git/cloog/test/levenshtein-1-2-3f.cloog by CLooG 0.14.0-91-g5d3da4b gmp bits in 0.04s.
S1(i = 0,j = 0)
S2(i = 1,j = 0)
S3(i = 1,j = 1)
DO i=2, N
  S2(j = 0)
  DO j=1, i-1
    S6
  END DO
  S3(j = i)
END DO
i = N+1
S7(j = 0)
DO j=1, N
  S6
  S8
END DO
DO i=N+2, 2*M-N-2
  j = FLOOR(REAL(i-N-1)/REAL(2))
  S7
  IF (MOD(i+N, 2) == 0) THEN
    j = (i-N)/2
    S5
    S8
  END IF
  DO j=CEILING(REAL(i-N+1)/REAL(2)), FLOOR(REAL(i+N-1)/REAL(2))
    S6
    S8
  END DO
  IF (MOD(i+N, 2) == 0) THEN
    j = (i+N)/2
    S4
    S8
  END IF
END DO
DO i=2*M-N-1, 2*M-2
  DO j=i-M+1, M-1
    S6
  END DO
END DO
