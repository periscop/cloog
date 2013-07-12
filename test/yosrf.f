! Generated from ./yosrf.cloog by CLooG  gmp bits in 0.01s.
/* <scop_0_code_start> */
IF (n >= 2) THEN
  DO j=2, n
    S1(1,j)
  END DO
  DO proc=2, n-1
    DO i=1, proc-1
      DO j=i+1, n
        S2(i,j,proc)
      END DO
    END DO
    DO j=proc+1, n
      S1(proc,j)
    END DO
  END DO
  DO i=1, n-1
    DO j=i+1, n
      S2(i,j,n)
    END DO
  END DO
END IF
/* </scop_0_code_end> */
