// FILE DA MODIFICARE
#include <string>
#include <iostream>
#include "ASD-aritexpr.h"
#include "ASD-token.h"
#include "ASD-stack.h"

using namespace my_stack;
using namespace std;

/*Calcula il valore intero dell'espressione aritmetica st*/
/*se st non corrisponde ad un expression aritmetica*/
/*solleva un eccezione di tipo string*/
/*con valore: "Lexical error" se st non è composta da tokens*/
/*e valore: "Syntactical error" se st è ben formata*/
int compute_arithmetic_expr(const string& st){
	token tok;
	Stack stack = createEmpty();
	string str = "";
	for(char c: st)
		str += c;
	try{
		while(nextToken(str, tok)){
			push(tok, stack);
			if(tok.k == PARENTESI_CHIUSA){
				if(pop(stack).k != PARENTESI_CHIUSA)
					throw string("Syntactical error");
				token a = pop(stack);
				if(a.k != NUMERO)
					throw string("Syntactical error");
				token op = pop(stack);
				if(op.k != OP_MOLTIPLICAZIONE && op.k != OP_SOMMA && op.k != OP_SOTTRAZIONE)
					throw string("Syntactical error");
				token b = pop(stack);
				if(b.k != NUMERO)
					throw string("Syntactical error");
				if(pop(stack).k != PARENTESI_APERTA)
					throw string("Syntactical error");
				if(op.k == OP_MOLTIPLICAZIONE){
					token t;
					t.k = NUMERO;
					t.val = b.val * a.val;
					push(t, stack);
				}
				if(op.k == OP_SOMMA){
					token t;
					t.k = NUMERO;
					t.val = b.val + a.val;
					push(t, stack);
				}
				if(op.k == OP_SOTTRAZIONE){
					token t;
					t.k = NUMERO;
					t.val = b.val - a.val;
					push(t, stack);
				}
			}
		}
		token ris = pop(stack);
		if(!isEmpty(stack) or ris.k != NUMERO)
			throw string("Syntactical error");
	
		return ris.val;
	}catch(string e){
		throw e;
	}		
}

