#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cripto.h"

int main(){

	// 1  c cesdar
	// -1 d cesar
	// 2  c cesar+3
  // -2 d cesar+3
  //
  Palavra *P = criaPalavra();

  char *w = "abcdefghij\0";
    
  for(int i=0;i<(int)strlen(w);i++){
    if(addLetra(P,w[i])==0) return 0;
  }

  puts("Mensagem");
  printPalavra(P);

  puts("Encript cesar 1");
  trCesar(P,1);
  printPalavra(P);

  puts("Decript cesar 1");
  trCesar(P,-1);
  printPalavra(P);

  int chave[5] = {1,2,3,4,5};
  puts("Encript chave");
  trChave(P,chave,1);
  printPalavra(P);

  puts("decript Chave");
  trChave(P,chave,0);
  printPalavra(P);

  puts("encript + char");
  trChaveChar(P,chave,1);
  printPalavra(P);

  puts("decrypt + char");
  trChaveChar(P,chave,0);
  printPalavra(P);

  return 0;
}

