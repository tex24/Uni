.macro printInt
	li a7, 1
	ecall
.end_macro

.text
	li a0, 10
	addi sp, sp, -4
	sw ra, -4(sp)
	jal fibonacci
	printInt
	beq zero, zero, fine
	
	
fibonacci:
	addi t1, zero, 1
	bne a0, zero, nozero
	mv a0, zero
	ret
nozero:
	bne a0, t1, nouno
	mv a0, t1
	ret
	
nouno:
	addi sp, sp, -12
	sw a0, -8(sp)
	sw ra, -4(sp)
	addi a0, a0, -1
	jal fibonacci
	sw a0, -12(sp)
	lw a0, -8(sp)
	lw ra, -4(sp)
	addi a0, a0, -2
	jal fibonacci
	lw t2, -12(sp)
	add a0, a0, t2
	lw ra, -4(sp)
	addi t6, zero, -1
	sw t6, -8(sp)
	sw t6, -4(sp)
	sw t6, -12(sp)
	addi sp, sp, 12
	ret
	
fine:
	lw ra, -4(sp)