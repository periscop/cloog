! Generated from ../../../git/cloog/test/dartef.cloog by CLooG 0.14.0-117-g7c6f653 gmp bits in 2.89s.
IF (n >= 1) THEN
  t1 = -n+1
  t2 = n+1
  DO t3=n+3, 3*n+1
    IF (MOD(t3+n+1, 2) == 0) THEN
      k = (t3-n-1)/2
      S1(i = 1,j = n)
    END IF
  END DO
  IF (n == 2) THEN
    DO t3=4, 6
      IF (MOD(t3, 2) == 0) THEN
        k = (t3-2)/2
        S1(i = 1,j = 1)
      END IF
    END DO
    DO t2=3, 4
      DO t3=t2+2, t2+4
        IF (MOD(t2, 2) == 0) THEN
          IF (MOD(t3, 2) == 0) THEN
            k = (t3-4)/2
            S1(i = t2/2,j = 2)
          END IF
        END IF
      END DO
    END DO
    DO t3=1, 2
      S2(i = 1,j = 2,k = t3)
    END DO
  END IF
  IF (n == 2) THEN
    DO t3=5, 7
      IF (MOD(t3+1, 2) == 0) THEN
        k = (t3-3)/2
        S1(i = 2,j = 1)
      END IF
    END DO
    DO t2=4, 5
      DO t3=1, 2
        IF (MOD(t2, 2) == 0) THEN
          i = (t2-2)/2
          S2(j = 1,k = t3)
        END IF
      END DO
    END DO
    DO t3=1, 2
      S2(i = 2,j = 2,k = t3)
    END DO
  END IF
  IF (n >= 3) THEN
    t1 = -n+2
    DO t2=n, n+2
      DO t3=t2+2, t2+2*n
        IF (MOD(t2+n, 2) == 0) THEN
          i = (t2-n+2)/2
          j = (t2+n-2)/2
          IF (MOD(t3+n, 2) == 0) THEN
            k = (-t2+t3)/2
            S1
          END IF
        END IF
      END DO
    END DO
    t2 = n+3
    DO t3=1, n
      S2(i = 1,j = n,k = t3)
    END DO
  END IF
  DO t1=-n+3, MIN(-1,-n+6)
    DO t2=-t1+2, -t1+4
      DO t3=t2+2, t2+2*n
        IF (MOD(t1+t2, 2) == 0) THEN
          i = (t1+t2)/2
          j = (-t1+t2)/2
          IF (MOD(t1+t3, 2) == 0) THEN
            k = (-t2+t3)/2
            S1
          END IF
        END IF
      END DO
    END DO
    DO t2=-t1+5, t1+2*n
      DO t3=1, n
        IF (MOD(t1+t2+1, 2) == 0) THEN
          i = (t1+t2-3)/2
          j = (-t1+t2-1)/2
          S2(k = t3)
        END IF
      END DO
      DO t3=t2+2, t2+2*n
        IF (MOD(t1+t2, 2) == 0) THEN
          i = (t1+t2)/2
          j = (-t1+t2)/2
          IF (MOD(t1+t3, 2) == 0) THEN
            k = (-t2+t3)/2
            S1
          END IF
        END IF
      END DO
    END DO
    t2 = t1+2*n+1
    DO t3=1, n
      i = t1+n-1
      S2(j = n,k = t3)
    END DO
  END DO
  IF ((n >= 3) .AND. (n <= 6)) THEN
    DO t3=4, 2*n+2
      IF (MOD(t3, 2) == 0) THEN
        k = (t3-2)/2
        S1(i = 1,j = 1)
      END IF
    END DO
    DO t2=3, 4
      DO t3=t2+2, t2+2*n
        IF (MOD(t2, 2) == 0) THEN
          IF (MOD(t3, 2) == 0) THEN
            k = (t3-4)/2
            S1(i = t2/2,j = 2)
          END IF
        END IF
      END DO
    END DO
    DO t2=5, 2*n
      DO t3=1, n
        IF (MOD(t2+1, 2) == 0) THEN
          i = (t2-3)/2
          j = (t2-1)/2
          S2(k = t3)
        END IF
      END DO
      DO t3=t2+2, t2+2*n
        IF (MOD(t2, 2) == 0) THEN
          IF (MOD(t2, 2) == 0) THEN
            IF (MOD(t2+t3, 2) == 0) THEN
              k = (-t2+t3)/2
              S1(i = t2/2,j = t2/2)
            END IF
          END IF
        END IF
      END DO
    END DO
    t2 = 2*n+1
    DO t3=1, n
      i = n-1
      S2(j = n,k = t3)
    END DO
  END IF
  IF ((n >= 3) .AND. (n <= 5)) THEN
    DO t3=5, 2*n+3
      IF (MOD(t3+1, 2) == 0) THEN
        k = (t3-3)/2
        S1(i = 2,j = 1)
      END IF
    END DO
    DO t2=4, 2*n-1
      DO t3=1, n
        IF (MOD(t2, 2) == 0) THEN
          i = (t2-2)/2
          j = (t2-2)/2
          S2(k = t3)
        END IF
      END DO
      DO t3=t2+2, t2+2*n
        IF (MOD(t2+1, 2) == 0) THEN
          i = (t2+1)/2
          j = (t2-1)/2
          IF (MOD(t3+1, 2) == 0) THEN
            k = (-t2+t3)/2
            S1
          END IF
        END IF
      END DO
    END DO
    DO t2=2*n, 2*n+1
      DO t3=1, n
        IF (MOD(t2, 2) == 0) THEN
          i = (t2-2)/2
          j = n-1
          S2(k = t3)
        END IF
      END DO
    END DO
    t2 = 2*n+2
    DO t3=1, n
      S2(i = n,j = n,k = t3)
    END DO
  END IF
  DO t1=-n+7, -1
    DO t2=-t1+2, -t1+4
      DO t3=t2+2, t2+2*n
        IF (MOD(t1+t2, 2) == 0) THEN
          i = (t1+t2)/2
          j = (-t1+t2)/2
          IF (MOD(t1+t3, 2) == 0) THEN
            k = (-t2+t3)/2
            S1
          END IF
        END IF
      END DO
    END DO
    DO t2=-t1+5, n-2
      DO t3=1, t2+1
        IF (MOD(t1+t2+1, 2) == 0) THEN
          i = (t1+t2-3)/2
          j = (-t1+t2-1)/2
          S2(k = t3)
        END IF
      END DO
      DO t3=t2+2, n
        IF (MOD(t1+t2+1, 2) == 0) THEN
          i = (t1+t2-3)/2
          j = (-t1+t2-1)/2
          S2(k = t3)
        END IF
        IF (MOD(t1+t2, 2) == 0) THEN
          i = (t1+t2)/2
          j = (-t1+t2)/2
          IF (MOD(t1+t3, 2) == 0) THEN
            k = (-t2+t3)/2
            S1
          END IF
        END IF
      END DO
      DO t3=n+1, t2+2*n
        IF (MOD(t1+t2, 2) == 0) THEN
          i = (t1+t2)/2
          j = (-t1+t2)/2
          IF (MOD(t1+t3, 2) == 0) THEN
            k = (-t2+t3)/2
            S1
          END IF
        END IF
      END DO
    END DO
    DO t2=n-1, t1+2*n
      DO t3=1, n
        IF (MOD(t1+t2+1, 2) == 0) THEN
          i = (t1+t2-3)/2
          j = (-t1+t2-1)/2
          S2(k = t3)
        END IF
      END DO
      DO t3=t2+2, t2+2*n
        IF (MOD(t1+t2, 2) == 0) THEN
          i = (t1+t2)/2
          j = (-t1+t2)/2
          IF (MOD(t1+t3, 2) == 0) THEN
            k = (-t2+t3)/2
            S1
          END IF
        END IF
      END DO
    END DO
    t2 = t1+2*n+1
    DO t3=1, n
      i = t1+n-1
      S2(j = n,k = t3)
    END DO
  END DO
  IF (n >= 7) THEN
    DO t3=4, 2*n+2
      IF (MOD(t3, 2) == 0) THEN
        k = (t3-2)/2
        S1(i = 1,j = 1)
      END IF
    END DO
    DO t2=3, 4
      DO t3=t2+2, t2+2*n
        IF (MOD(t2, 2) == 0) THEN
          IF (MOD(t3, 2) == 0) THEN
            k = (t3-4)/2
            S1(i = t2/2,j = 2)
          END IF
        END IF
      END DO
    END DO
    DO t2=5, n-2
      DO t3=1, t2+1
        IF (MOD(t2+1, 2) == 0) THEN
          i = (t2-3)/2
          j = (t2-1)/2
          S2(k = t3)
        END IF
      END DO
      DO t3=t2+2, n
        IF (MOD(t2+1, 2) == 0) THEN
          i = (t2-3)/2
          j = (t2-1)/2
          S2(k = t3)
        END IF
        IF (MOD(t2, 2) == 0) THEN
          IF (MOD(t2, 2) == 0) THEN
            IF (MOD(t2+t3, 2) == 0) THEN
              k = (-t2+t3)/2
              S1(i = t2/2,j = t2/2)
            END IF
          END IF
        END IF
      END DO
      DO t3=n+1, t2+2*n
        IF (MOD(t2, 2) == 0) THEN
          IF (MOD(t2, 2) == 0) THEN
            IF (MOD(t2+t3, 2) == 0) THEN
              k = (-t2+t3)/2
              S1(i = t2/2,j = t2/2)
            END IF
          END IF
        END IF
      END DO
    END DO
    DO t2=n-1, 2*n
      DO t3=1, n
        IF (MOD(t2+1, 2) == 0) THEN
          i = (t2-3)/2
          j = (t2-1)/2
          S2(k = t3)
        END IF
      END DO
      DO t3=t2+2, t2+2*n
        IF (MOD(t2, 2) == 0) THEN
          IF (MOD(t2, 2) == 0) THEN
            IF (MOD(t2+t3, 2) == 0) THEN
              k = (-t2+t3)/2
              S1(i = t2/2,j = t2/2)
            END IF
          END IF
        END IF
      END DO
    END DO
    t2 = 2*n+1
    DO t3=1, n
      i = n-1
      S2(j = n,k = t3)
    END DO
  END IF
  IF (n >= 6) THEN
    DO t3=5, 2*n+3
      IF (MOD(t3+1, 2) == 0) THEN
        k = (t3-3)/2
        S1(i = 2,j = 1)
      END IF
    END DO
    DO t2=4, n-2
      DO t3=1, t2+1
        IF (MOD(t2, 2) == 0) THEN
          i = (t2-2)/2
          j = (t2-2)/2
          S2(k = t3)
        END IF
      END DO
      DO t3=t2+2, n
        IF (MOD(t2, 2) == 0) THEN
          i = (t2-2)/2
          j = (t2-2)/2
          S2(k = t3)
        END IF
        IF (MOD(t2+1, 2) == 0) THEN
          i = (t2+1)/2
          j = (t2-1)/2
          IF (MOD(t3+1, 2) == 0) THEN
            k = (-t2+t3)/2
            S1
          END IF
        END IF
      END DO
      DO t3=n+1, t2+2*n
        IF (MOD(t2+1, 2) == 0) THEN
          i = (t2+1)/2
          j = (t2-1)/2
          IF (MOD(t3+1, 2) == 0) THEN
            k = (-t2+t3)/2
            S1
          END IF
        END IF
      END DO
    END DO
    DO t2=n-1, 2*n-1
      DO t3=1, n
        IF (MOD(t2, 2) == 0) THEN
          i = (t2-2)/2
          j = (t2-2)/2
          S2(k = t3)
        END IF
      END DO
      DO t3=t2+2, t2+2*n
        IF (MOD(t2+1, 2) == 0) THEN
          i = (t2+1)/2
          j = (t2-1)/2
          IF (MOD(t3+1, 2) == 0) THEN
            k = (-t2+t3)/2
            S1
          END IF
        END IF
      END DO
    END DO
    DO t2=2*n, 2*n+1
      DO t3=1, n
        IF (MOD(t2, 2) == 0) THEN
          i = (t2-2)/2
          j = n-1
          S2(k = t3)
        END IF
      END DO
    END DO
    t2 = 2*n+2
    DO t3=1, n
      S2(i = n,j = n,k = t3)
    END DO
  END IF
  DO t1=2, n-5
    t2 = t1+2
    DO t3=t1+4, t1+2*n+2
      i = t1+1
      IF (MOD(t1+t3, 2) == 0) THEN
        k = (-t1+t3-2)/2
        S1(j = 1)
      END IF
    END DO
    DO t2=t1+3, n-2
      DO t3=1, t2+1
        IF (MOD(t1+t2+1, 2) == 0) THEN
          i = (t1+t2-3)/2
          j = (-t1+t2-1)/2
          S2(k = t3)
        END IF
      END DO
      DO t3=t2+2, n
        IF (MOD(t1+t2+1, 2) == 0) THEN
          i = (t1+t2-3)/2
          j = (-t1+t2-1)/2
          S2(k = t3)
        END IF
        IF (MOD(t1+t2, 2) == 0) THEN
          i = (t1+t2)/2
          j = (-t1+t2)/2
          IF (MOD(t1+t3, 2) == 0) THEN
            k = (-t2+t3)/2
            S1
          END IF
        END IF
      END DO
      DO t3=n+1, t2+2*n
        IF (MOD(t1+t2, 2) == 0) THEN
          i = (t1+t2)/2
          j = (-t1+t2)/2
          IF (MOD(t1+t3, 2) == 0) THEN
            k = (-t2+t3)/2
            S1
          END IF
        END IF
      END DO
    END DO
    DO t2=n-1, -t1+2*n
      DO t3=1, n
        IF (MOD(t1+t2+1, 2) == 0) THEN
          i = (t1+t2-3)/2
          j = (-t1+t2-1)/2
          S2(k = t3)
        END IF
      END DO
      DO t3=t2+2, t2+2*n
        IF (MOD(t1+t2, 2) == 0) THEN
          i = (t1+t2)/2
          j = (-t1+t2)/2
          IF (MOD(t1+t3, 2) == 0) THEN
            k = (-t2+t3)/2
            S1
          END IF
        END IF
      END DO
    END DO
    DO t2=-t1+2*n+1, -t1+2*n+3
      DO t3=1, n
        IF (MOD(t1+t2+1, 2) == 0) THEN
          i = (t1+t2-3)/2
          j = (-t1+t2-1)/2
          S2(k = t3)
        END IF
      END DO
    END DO
  END DO
  DO t1=MAX(2,n-4), n-2
    t2 = t1+2
    DO t3=t1+4, t1+2*n+2
      i = t1+1
      IF (MOD(t1+t3, 2) == 0) THEN
        k = (-t1+t3-2)/2
        S1(j = 1)
      END IF
    END DO
    DO t2=t1+3, -t1+2*n
      DO t3=1, n
        IF (MOD(t1+t2+1, 2) == 0) THEN
          i = (t1+t2-3)/2
          j = (-t1+t2-1)/2
          S2(k = t3)
        END IF
      END DO
      DO t3=t2+2, t2+2*n
        IF (MOD(t1+t2, 2) == 0) THEN
          i = (t1+t2)/2
          j = (-t1+t2)/2
          IF (MOD(t1+t3, 2) == 0) THEN
            k = (-t2+t3)/2
            S1
          END IF
        END IF
      END DO
    END DO
    DO t2=-t1+2*n+1, -t1+2*n+3
      DO t3=1, n
        IF (MOD(t1+t2+1, 2) == 0) THEN
          i = (t1+t2-3)/2
          j = (-t1+t2-1)/2
          S2(k = t3)
        END IF
      END DO
    END DO
  END DO
  IF (n >= 3) THEN
    t1 = n-1
    t2 = n+1
    DO t3=n+3, 3*n+1
      IF (MOD(t3+n+1, 2) == 0) THEN
        k = (t3-n-1)/2
        S1(i = n,j = 1)
      END IF
    END DO
    DO t2=n+2, n+4
      DO t3=1, n
        IF (MOD(t2+n, 2) == 0) THEN
          i = (t2+n-4)/2
          j = (t2-n)/2
          S2(k = t3)
        END IF
      END DO
    END DO
  END IF
  t2 = n+3
  DO t3=1, n
    S2(i = n,j = 1,k = t3)
  END DO
END IF
