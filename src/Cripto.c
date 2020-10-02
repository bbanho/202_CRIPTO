#include "Cripto.h"
#include <stdio.h>
#include <stdlib.h>

Palavra *criaPalavra(){
  
  Palavra *P =(Palavra*) malloc(sizeof(Palavra));
  if(P!=NULL)
    *P=NULL;

  return P;
}

int addLetra(Palavra *P, char c){

  if(P==NULL) return 0;

  Letra *Ln = (Letra *) malloc(sizeof(Letra));
  if(Ln==NULL) return 0;
  Ln->c=c;
  Ln->prox=NULL;

  if(*P==NULL){ // vazia
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
    putchar(Ln->c);
    Ln=Ln->prox;
  } 
  puts("\n");
  return 1;
}

int trCesar(Palavra *P, int n){

  if (P==NULL) return 0;

  Letra *Li = (Letra *) malloc(sizeof(Letra));
  if(Li==NULL) return 0;

  Li=*P;
  while(Li!=NULL){
    Li->c+=n;
    Li=Li->prox;
  }

  return 1;
}

int trChave(Palavra *P, int v[5], int modo){

  if(P==NULL) return 0;

  Letra *Li = (Letra *) malloc(sizeof(Letra));
  if(Li==NULL) return 0;

  int i=0;
  Li=*P;
  while(Li->prox!=NULL){
    if(i>5) i=0;
    if(modo==1){
      Li->c+=v[i];
    } else {
      Li->c-=v[i];
    }
    Li=Li->prox;
    i++;
  }

  return 1;
}


int trChaveChar(Palavra *P, int v[5], int modo){

  if(P==NULL) return 0;

  Letra *Li = (Letra *) malloc(sizeof(Letra));
  if(Li==NULL) return 0;

  int i=0;
  Li=*P;
  while(Li->prox!=NULL){
    if(modo==1){
      if((i+1)%3==0) {
        addLetra(&Li, '*');
        Li=Li->prox;
      }
      Li->c+=v[i];
    } else {
      if((i+1)%3==0)
        Li=Li->prox;
      Li->c-=v[i];
    }
    Li=Li->prox;
    i++;
  }

  return 1;
}
