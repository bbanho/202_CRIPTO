#include <stdio.h>
#include <stdlib.h>

typedef struct letra {
  char c;
  struct letra *prox;
} Letra;

typedef Letra *Palavra;

Palavra *criaPalavra();
int addLetra(Palavra *P, char c);
int rmLetra(Palavra *P, int pos);
char pickLetra(Palavra *P, int pos);
int printPalavra(Palavra *P);

// modo 1 encrypt, 0 decrypt

int trCesar(Palavra *P, int n);
int trChave(Palavra *P, int *v, int v_l, int modo);
int trChaveChar(Palavra *P, int *v, int v_l, int modo);

int traduz(int *u, char *inp);
int tamPalavra(Palavra *P);
