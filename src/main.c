#include <stdio.h>
#include <stdlib.h>
#include "Cripto.h"
int main(){

	// 1  c cesdar
	// -1 d cesar
	// 2  c cesar+3
	// -2 d cesar+3
  //
  Letra *P = criaPalavra();

  char *w = "Teste\0";
    
  for(int i=0;i<(int)sizeof(w)-1;i++){
    if(addLetra(P,w[i])==0) return 0;
  }

  printPalavra(P);

    return 0;
}

