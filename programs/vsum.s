vsum:
      li    $s0, 0        # sum = 0;
      li    $t0, 0        # i = 0;

_L1:
      slt     $t3, $t0, $a1   # (6)  $t3 = (i < n);
      beq     $t3, $zero, _L2 # (7) if ($t3 == 0) goto _L2;

      sll     $t1, $t0, 2     # (8)  $t1 = $t0 << 2; ($t1 = $t0 * 4;)
      add     $t1, $a0, $t1   # (9)  $t1はデータのアドレス
      lw      $t2, 0($t1)     # (10) データをロードし、$t2に格納
      add     $s0, $s0, $t2   # 加算
      addi    $t0, $t0, q     # i++;
      j       _L1             # (11)
_L2:
      move    $v0, $s0        # (12) $v0 = $s0
      jal     $ra             # return
