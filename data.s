.data
txt1:  .asciiz   "Please enter a integer : "
txt2:  .asciiz   "Please enter the power of the integer : "
txt3:  .asciiz   "The result is : "

.text
.globl main
main:
la $a0, txt1
li $v0, 4
syscall

li $v0, 5
syscall

move $t0, $v0

la $a0, txt2
li $v0, 4
syscall

li $v0, 5
syscall 

move $t1, $v0
add $t2, $t2, 1

loop:
beqz $t1, print
mul $t2, $t2, $t0
add $t1, $t1, -1
j loop

print:
la $a0, txt3
li $v0, 4
syscall

move $a0, $t2
li $v0, 1
syscall

exit: 
li $v0, 10
syscall
