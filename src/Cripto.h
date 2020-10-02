#include <stdlib.h>

typedef struct letra {
  char c;
  struct letra *prox;
} Letra;

typedef Letra *Palavra;

Palavra *criaPalavra();
int addLetra(Palavra *P, char c);
char pickLetra(Palavra *P, int pos);
int printPalavra(Palavra *P);

// modo 1 encrypt, 0 decrypt

int trCesar(Palavra *P, int n);
int trChave(Palavra *P, int v[5], int modo);

int trChaveChar(Palavra *P, int v[5], int modo);

