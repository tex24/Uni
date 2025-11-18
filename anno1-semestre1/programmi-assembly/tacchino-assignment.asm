.macro printInt(%x)
	li a7, 1
	mv a0, %x
	ecall
.end_macro

.macro end
	li a7, 93
	li a0, 0
	ecall
.end_macro

.data
	l: .word 8
	H: .space 256
	
.text

#Per controllare il funzionamendo di questo codice ho avviato il progrmma in c++ fornito,
#e ho controllato tutto il contenuto di H e il valore di u al termine del programma
#verificando che combaciasse tutto.

####################### main
jal funzione
mv t1, a0 #s = risultato della funzione
printInt(t1)
end #return 0
#######################

funzione:
	la t4, l #metto in t4 l'indirizzo di l
	lw t4, (t4) #carico il valore di l dalla memoria ovvero 8 (fuori dal ciclo tanto l non cambia nella funzione, per questo posso anche non tenermi piu in un registro l indirizzo di memoria di l)
	la t5, H #metto in t5 l'indirizzo di memoria di H
	li t0, 2 #m
	li t1, 0 #i
loop:	
	li t3, 0 #j
	
loop2:
	bnez t1, nonuguali
	bnez t3, nonuguali
	#se sono entrambi uguali a 0:
	mul t2, t1, t4 #moltiplicazione fra i e l
	add t2, t2, t3 #somma fra i*l e j
	slli t2, t2, 2 #moltiplico l indice per accedere ad H di 4 per l'offset
	add t6, t5, t2 #aggiungo all'indirizzo iniziale di H l'offset
	lw t2, (t6) #carico l elemendo di H con posizione i*l+j
	li t2, 10 #lo setto a 10
	sw t2, (t6)#lo riscrivo in memoria
	j uguali
	
nonuguali:
	li t2, 0 #k=0
	li t6, 5 #numero da mettere nella condizione di termine ciclo
ciclo3:
	li a6, 1 #carico 1 in a6
	sll a1, a6, t2 #t = shift del numero 1 di k posizioni
	blt t1, a1, noif
	bge t3, a1, noif
	mul a2, t1, t4 #i*l
	add a2, a2, t3 #i*l+j
	slli a2, a2, 2
	add a2, a2, t5 #sommo l indirizzo di H con l offset
	sub a3, t1, a1 #i-t
	mul a3, a3, t4 #(i-t)*l
	add a3, a3, t3 #(i-t)*l+j
	slli a3, a3, 2 #moltiplico per 4 (per l offset delle word)
	add a3, t5, a3 #sommo all offset totale l indirizzo di partenza di H
	lw a3, (a3)
	sw a3, (a2)
noif:
	addi t2, t2, 1 #aggiungo 1 a k
	ble t2, t6, ciclo3 #fine terzo ciclo annidato
	##################################
	
	
uguali:
	addi t3, t3, 1 #aggiungo 1 a j
	blt t3, t4, loop2 #fine secondo ciclo annidato
	################################################
	
	addi t1, t1, 1 #aggiungiamo 1 a i
	blt t1, t4, loop #fine primo ciclo
	################################################
	
	mv t0, zero #u
	mv t1, zero #k
	li t3, 16
for:
	slli t4, t1, 2
	add t4, t5, t4
	lw t6, (t4)
	add t0, t0, t6
	addi t1, t1, 1 #aggiungo 1 a k
	blt t1, t3, for #fine for
	####################
	mv a0, t1
	ret
	
	
	
