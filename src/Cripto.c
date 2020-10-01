#include "Cripto.h"
#include <stdio.h>
#include <stdlib.h>

Letra *criaPalavra(){
  
  Letra *Li;

  Li =(Letra*) malloc(sizeof(Letra));
  if(Li!=NULL)
    Li=NULL;

  return Li;
}

int addLetra(Letra *Li, char c){

  Letra *Ln = (Letra *) malloc(sizeof(Letra));
  if(Ln==NULL) return 0;

  Ln->c=c;
  Ln->prox=NULL;

  if(Li==NULL){
    Li=Ln;
  } else {
    Letra *aux;
    aux=Li;
    while(aux->prox!=NULL){
      aux=aux->prox;
    }
    aux->prox=Li;
  }

  return 1; // sucesso=1 p/ while(add..)
}

int printPalavra(Letra *Li){

  if(Li==NULL) return 0;

  Letra *Ln=Li;
  while(Ln!=NULL) printf("%c",Ln->c);

  return 1;
}
