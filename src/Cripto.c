#include "Cripto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Palavra *criaPalavra(){
  
  Palavra *P =(Palavra*) malloc(sizeof(Palavra));
  if(P!=NULL)
    *P=NULL;

  return P;
}

int addLetra(Palavra *P, char c){

  if(P==NULL) return 1;

  Letra *Ln = (Letra *) malloc(sizeof(Letra));
  if(Ln==NULL) return 1;
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
  return 0; 
}

int rmLetra(Palavra *P, int pos){

  if(P==NULL) return 1;

  Letra *Li,*La;
  Li=*P;

  for(int i=1;i<=pos;i++){
    if(Li->prox==NULL) return 1;
    La=Li;
    Li=Li->prox;
  }
  La->prox=Li->prox;
  Li->prox=La;
  
  return 0; 
}


int printPalavra(Palavra *P){

  if(P==NULL) return 1;

  char p[1024];
  int i=0;

  Letra *Ln=*P;
  while(Ln!=NULL&&Ln->c>0){
    if(i>1024) return 1;
    p[i]=Ln->c;
//    printf("%c",Ln->c);
    Ln=Ln->prox;i++;

  }
//  printf("%s\n",p);
  for(int i=0;i<tamPalavra(P);i++){
    printf("%c",p[i]);
  }
  puts("");
  return 0;
}


int trCesar(Palavra *P, int n){

  if (P==NULL) return 1;

  Letra *Li = (Letra *) malloc(sizeof(Letra));
  if(Li==NULL) return 1;

  Li=*P;
  while(Li!=NULL){
    Li->c+=n;
    Li=Li->prox;
  }

  return 0;
}

int trChave(Palavra *P, int *v, int v_l, int modo){

  if(P==NULL || v==NULL) return 1;

  Letra *Li;
  Li=*P;

  int i=0;
  while(Li->prox!=NULL){
    if(i>=v_l) i=0;
    if(modo==1){
      Li->c+=v[i];
    } else {
      Li->c-=v[i];
    }
    Li=Li->prox;
    i++;
  }

  return 0;
}

int trChaveChar(Palavra *P, int *v, int v_l, int modo){


  Letra *Li = (Letra *) malloc(sizeof(Letra));
  if(Li==NULL) return 1;

  Palavra *Lo;
  Lo=criaPalavra();
  if(Lo==NULL) return 1;
  
  int i=0,j=1;
  Li=*P;
  while(Li->prox!=NULL){
    if(i>=v_l) i=0;
    if(modo==1){
      addLetra(Lo,Li->c+v[i]);
      if(j%3==0&&Li->prox->prox!=NULL)
        addLetra(Lo,'*');
    } else {
      addLetra(Lo,Li->c-v[i]);
      if(j%3==0&&Li->prox->prox!=NULL){
        Li=Li->prox;
      }
    }
    Li=Li->prox;
    i++;j++;
  }
  *P=*Lo;

 return 0;
}


int traduz(int *outp, char *inp){

  for(int i=0;i<5;i++){
    outp[i]=inp[i]-'0';
  }

  return 0;
}

int tamPalavra(Palavra *P){

  if(P==NULL||*P==NULL) return 0;

  Letra *Li=*P;
  int c=1;
  while(Li->prox!=NULL){
    c++;
    Li=Li->prox;
  }

  return c;
}
