.data
	n: .string "il numero "
	incluso: .string " e' incluso fra 1 e 10"
	escluso: .string " non e' incluso fra 1 e 10"
	input: .string "inserisci un numero: "

.macro readInt(%x)
	li a7, 5
	ecall
	mv %x, a0
.end_macro

.macro printInt(%x)
	li a7, 1
	mv a0, %x
	ecall
.end_macro

.macro printStr(%x)
	li a7, 4
	la a0, %x
	ecall
.end_macro



.text
	printStr(input)
	readInt(t0)
	li t1, 1
	li t2, 11
	printStr(n)
	printInt(t0)
	bge t0, t1, maggiore
minore:
	printStr(escluso)
	beq zero, zero, exit
maggiore:
	bge t0, t2, minore
	printStr(incluso)
exit:
