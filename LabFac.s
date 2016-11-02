.data
msg1: .asciiz "Please enter first integer number: "
msg2: .asciiz "\nPlease enter second integer number: "
msg3: .asciiz "\nResult: "

.text
.globl main

main:
addu $s0, $ra, $0

li $v0, 4
la $a0, msg1
syscall

li $v0, 5
syscall

addu $s1, $v0, $0

li $v0, 4
la $a0, msg2
syscall

li $v0, 5
syscall

addu $s2, $v0, $0

addu $a0, $s1, $0
addu $a1, $s2, $0

jal fact

addu $t0, $v0, $0

li $v0, 4
la $a0, msg3
syscall

li $v0, 1
addu $a0, $t0, $0
syscall

addu $ra, $0, $s0
jr $ra

fact:
addi $sp, $sp, -8     # adjust stack for 2 items
sw   $ra, 4($sp)      # save return address
sw   $a0, 0($sp)      # save argument
slti $t0, $a0, 2      # test for n < 2
beq  $t0, $zero, L1
addi $v0, $zero, 1    # if so, result is 1
addi $sp, $sp, 8      #   pop 2 items from stack
jr   $ra              #   and return
L1: addi $a0, $a0, -1     # else decrement n  
jal  fact             # recursive call
lw   $a0, 0($sp)      # restore original n
lw   $ra, 4($sp)      #   and return address
addi $sp, $sp, 8      # pop 2 items from stack
mul  $v0, $a0, $v0    # multiply to get result
jr   $ra              # and return
