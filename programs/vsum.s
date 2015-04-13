vsum:
      li    $v0, 0        # sum = 0;
      li    $t0, 0        # i = 0;
      beq   $a1, $zero, _L2   # (7) if (n == 0) goto _L2;
_L1:
      sll     $t1, $t0, 2     # (8)  $t1 = $t0 << 2; ($t1 = $t0 * 4;)
      add     $t1, $a0, $t1   # (9)  $t1はデータのアドレス
      lw      $t2, 0($t1)     # (10) データをロードし、$t2に格納
      add     $v0, $v0, $t2   # 加算
      addi    $t0, $t0, 1     # i++;
      bne     $t0, $a1, _L1   # (7) if ($t3 == 0) goto _L1;
_L2:
      jal     $ra             # return
