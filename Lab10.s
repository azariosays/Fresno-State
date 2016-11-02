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

jal RCpower

addu $t0, $v0, $0

li $v0, 4
la $a0, msg3
syscall

li $v0, 1
addu $a0, $t0, $0
syscall

addu $ra, $0, $s0
jr $ra

RCpower:                    #begin function

bgt $a1, $0, else           # if a1 is my y: y is > then
li $v0, 1                   # = +
jr $ra                      # jump to after jal RCpower

else:
    addi $sp, $sp, -4       #Allocate 4 bytes from the stack
sw $ra, 0($sp)              #This writes to the stack

    addi $a1, $a1, -1       #  decrement y
    jal  RCpower            #
    mul $v0, $v0, $a0       # multiply X into the equation because a0 is my X and v0 is my return value
lw $ra, 0($sp)              # 
    addi $sp, $sp, 4        # POP I took from the stack and now I have to put back
    jr $ra                  # jump back to the main code. RA returns the address of the current instruction
