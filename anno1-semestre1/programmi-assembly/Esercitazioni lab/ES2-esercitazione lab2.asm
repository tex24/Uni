#Esercizio 2
#
#Assemblare il seguente programma C++ 
#
#int A[48]={...} //inizializzato con valori a scelta tra 0 e 50
#int H[20]={0,0,...0}
#
#int main(){
#
# for (int i = 0; i < 48; i++){
#   if(A[i] < 20) {
#      H[A[i]]++; 
#    }
#  } 
#
# for (int i = 0; i < 20; i++){
#    print_int(H[i]);
#  }

.data
	A:  .word 0, 0, 0, 0, 0, 15, 20, 32, 48, 11, 25, 7, 42, 10, 6, 3,
	     1, 8, 50, 17, 27, 9, 14, 28, 31, 23, 36, 2, 44, 45, 4, 49,
	     13, 33, 21, 16, 18, 29, 35, 24, 39, 1, 40, 22, 26, 38, 34, 37
	     
	H:  .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

.macro printInt(%x)
	li a7, 1
	mv a0, %x
	ecall
.end_macro

.text	
	la a2, A #salvo in a3 l indirizzo iniziale di A
	la a3, H #salvo in a3 l indirizzo iniziale di H
	li a4, 48
	li a5, 20
	mv t0, zero #i=0
while:
	slli t1, t0, 2 #salvo la moltiplicazione di i*4, per via dell offset
	add t2, t1, a2 #t2 ora contiene la posizione dell elemento con indice attuale nell array A
	lw t3, 0(t2) #leggiamo A[i]
	bge t3, a5, ipp #se A[i] e maggiore uguale a 20 salta ad i++
	slli t4, t3, 2 #moltiplichiamo A[i] per 4
	add t5, t4, a3 #sommiamo A[i] moltiplicato per 4 all indirizzo iniziale di H
	lw t6, (t5)#leggiamo H[A[i]]
	addi t6, t6, 1 #H[A[i]]++
	sw t6, (t5) #riscriviamo in memoria H[A[i]] piu grande di uno
ipp:
	addi t0, t0, 1	#i++
	blt t0, a4, while #se i<48 rinizia il ciclo
	mv t0, zero #se i >= 20 rimetti i a 0 per iniziare il secondo ciclo su H
while2:
	slli t1, t0, 2 #t1 = i*4
	add t2, t1, a3 #t2 = i*4 + H
	lw t3, 0(t2) #leggiamo H[i]
	printInt(t3)	
	addi t0, t0, 1	#i++
	blt t0, a5, while2 #se i < 20 rinizia il ciclo