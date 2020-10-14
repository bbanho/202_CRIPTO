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

int rmLetra(Palavra *P, int pos){

  if(P==NULL) return 0;

  Letra *Li,*La;
  Li=*P;

  for(int i=1;i<=pos;i++){
    if(Li->prox==NULL) return 0;
    La=Li;
    Li=Li->prox;
  }
  La->prox=Li->prox;
  Li->prox=La;
  
  return 1; // sucesso=1 p/ while(add..)
}


int printPalavra(Palavra *P){

  if(P==NULL) return 0;

  Letra *Ln=*P;
  while(Ln!=NULL){
    printf("%c",Ln->c);
    Ln=Ln->prox;
  } 
  printf("\n");
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

int trChave(Palavra *P, int *v, int v_l, int modo){

  if(P==NULL || v==NULL) return 0;

  Letra *Li = (Letra *) malloc(sizeof(Letra));
  if(Li==NULL) return 0;
  Li=*P;

  int i=0;
  while(Li!=NULL){
    if(i>=v_l) i=0;
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

int trChaveChar(Palavra *P, int *v, int v_l, int modo){


  Letra *Li = (Letra *) malloc(sizeof(Letra));
  if(Li==NULL) return 0;

  Palavra *Lo;
  Lo=criaPalavra();
  if(Lo==NULL) return 0;
  
  int i=0,j=1;
  Li=*P;
  while(Li->prox!=NULL){
    if(i>=v_l) i=0;
    if(modo==1){
      addLetra(Lo,Li->c+v[i]);
      if(j%3==0&&Li->prox->prox!=NULL)
        addLetra(Lo,'*');
    } else {
      if(j%3==0){
        rmLetra(&Li,j);
        Li=Li->prox;
      }
      addLetra(Lo,Li->c-v[i]);
    }
    Li=Li->prox;
    i++;j++;
  }
  *P=*Lo;

 return 1;
}


int traduz(int *outp, char *inp){

  for(int i=0;i<5;i++){
    outp[i]=inp[i]-'0';
  }

  return 1;
}
