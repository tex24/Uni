.data
	s: .string "ecco i numeri che hai inserito: "
	c: .string " "

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
	leggiInt(t0)
	leggiInt(t1)
	printStr(s)
	printInt(t0)
	printStr(c)
	printInt(t1)
	