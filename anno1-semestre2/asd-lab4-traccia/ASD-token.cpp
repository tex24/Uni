//FILE DA MODIFICARE
#include <iostream>
#include "ASD-token.h"

using namespace std;

/**************************************************/
/*      funzioni da implementare                  */
/**************************************************/

//funzione che estrae il prossimo token della string st
//lo mette in tok e modifica st,
//ritorna true se c'era un token da estrarre,
//ritorna false se non c'era niente da estrarre e si e arrivato alla fine di st,
//solleva una eccezione di tipo string se legge un token di tipo sconosciuto
bool nextToken(string &st, token &tok) {
  if(st.size() == 0)
    return false;
  unsigned int k;
  for(k=0; k<st.size(); k++){
    if(st[k] != ' ')
      break;
  }
  if(k != 0)
    st.erase(0, k);

  unsigned int i;
  for(i=0; i < st.size() && st[i] != ' '; i++);
  string s = st.substr(0, i);
  if(s.size() == 1){
    if(s[0] == '(')
      tok.k = PARENTESI_APERTA;
    else if(s[0] == ')')
      tok.k = PARENTESI_CHIUSA;
    else if(s[0] == '+')
      tok.k = OP_SOMMA;
    else if(s[0] == '-')
      tok.k = OP_SOTTRAZIONE;
    else if(s[0] == '*')
      tok.k = OP_MOLTIPLICAZIONE;
    else if(s[0] >= '0' && s[0] <= '9'){
      tok.k = NUMERO;
      tok.val = stoi(s);
    }
    else
      throw string("Lexical error");
  }else{
    for(unsigned int j = 0; j<s.size(); j++){
      if(s[j] < '0' || s[j] > '9'){
        throw string("Lexical error");
      }
    }
    tok.k = NUMERO;
    tok.val = stoi(s);
  }
  st.erase(0, i+1);
  return true;
}

