.macro leggiInt(%x)
	li a7, 5
	ecall
	mv %x, a0
.end_macro

.macro printStr(%x)
	li a7, 4
	la a0, %x
	ecall
.end_macro

.macro printInt(%x)
	li a7, 1
	mv a0, %x
	ecall
.end_macro


.text
	li a0, 5
	jal fattoriale
	printInt(a0)
	j fine
	
fattoriale:
	addi sp, sp, -8
	sw ra, 4(sp)
	sw a0, 0(sp)
	li t0, 1
	bne t0, a0, diversi
	addi sp, sp, 8
	ret
diversi:
	addi a0, a0, -1
	jal fattoriale
	lw ra, 4(sp)
	lw t0, 0(sp)
	addi t1, zero, -1
	sw t1, 4(sp)
	sw t1, 0(sp)
	addi sp, sp, 8
	mul a0, a0, t0
	ret
	
fine:
	

	
