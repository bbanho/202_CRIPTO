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

int addLetra(Palavra *P, char c){

  if(P==NULL) return 0;

  Letra *Ln = (Letra *) malloc(sizeof(Letra));
  if(Ln==NULL) return 0;
  Ln->c=c;
  Ln->prox=NULL;

  if((*P)==NULL){
    *P=Ln;
  } else {
    Letra *aux;
    aux=*P;
    while(aux->prox!=NULL){
      aux=aux->prox;
    }
    aux->prox=Ln;
  }
  

  return 1; // sucesso=1 p/ while(add..)
}

int printPalavra(Palavra *P){

  if(P==NULL) return 0;

  Letra *Ln=*P;
  while(Ln!=NULL){
    printf("%c",Ln->c);
    Ln=Ln->prox;
  } 
  return 1;
}
