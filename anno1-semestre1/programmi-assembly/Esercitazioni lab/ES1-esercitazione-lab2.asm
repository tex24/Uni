.data
	V: .space 120 # Riserva 120 byte per un array di 30 interi (4 byte ciascuno)
	S1: .string "Inserici la lunghezza dell array: "
	S2: .string "Inserisci un elemento: "
	capo: .string "\n"
	somma: .string "la somma e: "
	media: .string "la media e: "
	
.macro readInt(%x)
	li a7, 5
	ecall #salva il risultato della ecall 5 in a0 (SEMPRE!)
	mv %x,a0 #salvo nel registro che daro in output (%x) il valore salvato in a0
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
	printStr(S1)
	readInt(t0)#lunghezza del vettore inserita dall utente
	la t1, V # salviamo in t1 l indirizzo del primo elemento dell array
	mv t2, zero #creaiamo il contatore a 0
	mv t6, zero #la somma
	
while:
	printStr(S2)
	readInt(s1) #il valore che inseriamo ogni volta per popolare il vettore
	slli t3, t2, 2 #salviamo in t3 il valore del cotatore moltiplicato per 4 (2 alla 2) (l'ultimo numnero =2 starebbe  a signifcare l'esponente che ci serve per avere 4 come risultato (4 = word, 2 alla 2 perche siamo in base 2)
	add t4, t1, t3 # sommimao la moltiplicazione (nel primo ciclo 0*4) a l indirizzo iniziale dell array 
	sw s1, 0(t4) #scriviamo nella memoria il valore letto in input in t4 ovvero la somma fra l indirizzo iniziale piu lo spostamento
	addi t2, t2, 1 #una sorta di i++
	bne t2, t0, while#condizione del ciclo

	mv t2, zero #rimettiamo il contatore a 0 fuori dal ciclo
whileSomma:	
	slli t3, t2, 2
	add t4, t1, t3
	lw s1, 0(t4)
	add t6, t6, s1 #somma = somma + elemento dell array
	addi t2, t2, 1 #i++
	bne t2, t0, whileSomma

	printStr(somma)
	printInt(t6)
	
	printStr(capo)
	
	printStr(media)
	div t0, t6, t0
	printInt(t0)
	
	
	

	
	
	