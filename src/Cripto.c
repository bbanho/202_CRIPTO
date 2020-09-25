#include "Cripto.h"
#include <stdlib.h>

Palavra *criaPalavra(){
  
  Palavra *Pi;

  Pi = (Palavra*) malloc(sizeof(Palavra));
  if(Pi!=NULL)
    Pi=NULL;

  return Pi;
}

int addLetra(Palavra *P, char c){

  if(P==NULL) return 0; // erro
  Letra *Li = (Letra *) malloc(sizeof(Letra));
  if(Li==NULL) return 0;

  Li->c=c;
  Li->prox=NULL;

  if(*P==NULL){
    *P=Li;
  } else {
    Letra *aux;
    aux=*P;
    while(aux->prox!=NULL){
      aux=aux->prox;
    }
    aux->prox=Li;
  }

  return 1; // sucesso=1 p/ while(add..)
}

int printPalavra(Palavra *P){


  return 0;
}
