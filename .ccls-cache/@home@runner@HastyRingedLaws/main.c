#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//variaveis
char cenario[10][10];
int linhaRick = 0;
int colunaRick = 0;

//Printa na tela a posicao atual dos objetos no mapa
static void print(){
  for(int linha = 0; linha < 10; linha++){
    printf("\n");
    for(int coluna = 0; coluna < 10; coluna++){
        printf("%c", cenario[linha][coluna]);
    }
  }
}

//Cria um rick em uma posicao aleatoria no mapa
static void geraRick(){
  srand(time(NULL));
  do{
    linhaRick = rand() % 9;
    colunaRick = rand() % 9;
  }while(cenario[linhaRick][colunaRick] != '.');
  cenario[linhaRick][colunaRick] = 'R';
  print();
}

int main(void){
  //inicializando o cenario
  for(int linha = 0; linha < 10; linha++){
    for(int coluna = 0; coluna < 10; coluna++){
        cenario[linha][coluna] = '.';
    }
  }

  geraRick();
}

