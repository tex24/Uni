.data
	min: .string "N < M"
	magg: .string "N > M"
	ug: .string "N = M"
	stampaN: .string "Inserisci N: "
	stampaM: .string "Inserisci M: "

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
	printStr(stampaN)
	leggiInt(t0)
	printStr(stampaM)
	leggiInt(t1)
	bge t0, t1, maggioreUguale
	printStr(min)
	beq zero, zero, END
maggioreUguale:
	beq t0, t1, uguale
	printStr(magg)
	beq zero, zero, END
uguale:
	printStr(ug)
END:
	
