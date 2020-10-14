#include <string.h>
#include "Cripto.h"

int main(){

	// 1  c cesdar
	// -1 d cesar
	// 2  c cesar+3
  // -2 d cesar+3
  //
  Palavra *P;
  P = criaPalavra();

  int menu,chave3[3]={1,2,3},chaved[5];
  char buf[1025],chavec[6];

  menu = 9;

  while(menu){
    scanf("%d",&menu);
    fflush(stdin);
    strcpy(buf,"");
    P=criaPalavra();
    switch(menu){
      // cesar
      case 1:
       scanf("%*[^\n]"); scanf("%*c");
       scanf("%[^\n]",buf);
        for(int i=0;i<(int)strlen(buf);i++){
          if(addLetra(P,buf[i])==0) return 0;
        }
        trCesar(P,1);
        printPalavra(P);
      break;

      case -1:
        scanf("%*[^\n]"); scanf("%*c");
        scanf("%[^\n]",buf);
        for(int i=0;i<(int)strlen(buf);i++){
          if(addLetra(P,buf[i])==0) return 0;
        }
        trCesar(P,-1);
        printPalavra(P);
      break;

      // cesar 3
      case 2:
        scanf("%*[^\n]"); scanf("%*c");
        scanf("%[^\n]",buf);
        for(int i=0;i<(int)strlen(buf);i++){
          if(addLetra(P,buf[i])==0) return 0;
        }
        trCesar(P,3);
        printPalavra(P);
      break;

      case -2:
        scanf("%*[^\n]"); scanf("%*c");
        scanf("%[^\n]",buf);
        for(int i=0;i<(int)strlen(buf);i++){
          if(addLetra(P,buf[i])==0) return 0;
        }
        trCesar(P,-3);
        printPalavra(P);
      break;

      // cesar 1,2,3 (chave 1,2,3)
      case 3:
        scanf("%*[^\n]"); scanf("%*c");
        scanf("%[^\n]",buf);
        for(int i=0;i<(int)strlen(buf);i++){
          if(addLetra(P,buf[i])==0) return 0;
        }
        trChave(P,chave3,3,1);
        printPalavra(P);
      break;

      case -3:
        scanf("%*[^\n]"); scanf("%*c");
        scanf("%[^\n]",buf);
        for(int i=0;i<(int)strlen(buf);i++){
          if(addLetra(P,buf[i])==0) return 0;
        }
        trChave(P,chave3,3,0);
        printPalavra(P);
      break;
      
      case 4:
        scanf("%*[^\n]"); scanf("%*c");
        scanf("%[^\n]",chavec);
        if(traduz(chaved,chavec)==0) return 0;
        scanf("%*[^\n]"); scanf("%*c");
        scanf("%[^\n]",buf);
        buf[strlen(buf)]='\0';
        for(int i=0;i<=(int)strlen(buf);i++){
          if(addLetra(P,buf[i])==0) return 0;
        }
        trChave(P,chaved,5,1);
        printPalavra(P);       
      break;

      case -4:
        scanf("%*[^\n]"); scanf("%*c");
        scanf("%[^\n]",chavec);
        if(traduz(chaved,chavec)==0) return 0;
        scanf("%*[^\n]"); scanf("%*c");
        scanf("%[^\n]",buf);
        buf[strlen(buf)]='\0';
        for(int i=0;i<=(int)strlen(buf);i++){
          if(addLetra(P,buf[i])==0) return 0;
        }
        trChave(P,chaved,5,0);
        printPalavra(P);       
      break;

      case 5:
        scanf("%*[^\n]"); scanf("%*c");
        scanf("%[^\n]",chavec);
        if(traduz(chaved,chavec)==0) return 0;
        fflush(stdin);
        scanf("%*[^\n]"); scanf("%*c");
        scanf("%[^\n]",buf);
        for(int i=0;i<=(int)strlen(buf);i++){
          if(addLetra(P,buf[i])==0) return 0;
        }
        trChaveChar(P,chaved,5,1);
        printPalavra(P);       
      break;

      case -5:
        scanf("%*[^\n]"); scanf("%*c");
        scanf("%[^\n]",chavec);
        if(traduz(chaved,chavec)==0) return 0;
        scanf("%*[^\n]"); scanf("%*c");
        scanf("%[^\n]",buf);
        for(int i=0;i<=(int)strlen(buf);i++){
          if(addLetra(P,buf[i])==0) return 0;
        }
        trChaveChar(P,chaved,5,0);
        printPalavra(P);       
      break;
    }

  }
  return 1;
}

