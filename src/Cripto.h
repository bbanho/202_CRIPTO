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

int trCesar(Palavra *P);
int trChave(Palavra *P);
