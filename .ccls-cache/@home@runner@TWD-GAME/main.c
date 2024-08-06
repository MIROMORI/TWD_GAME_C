#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>

//variaveis
char cenario[10][10];
int linhaRick, colunaRick, cordenadaXSaida, cordenadaYSaida;
bool condicaoDeParada = true;
int bullets;

//Cria uma saida "S" em uma posicao aleatoria da matriz
static void geraSaida(){
  srand(time(NULL));
  int cordenadasSaida[2];
  cordenadaXSaida = rand() % 10;
  cordenadaYSaida= rand() % 10;
  cordenadasSaida[0] = cordenadaXSaida;
  cordenadasSaida[1] = cordenadaYSaida;
  cenario[cordenadasSaida[0]][cordenadasSaida[1]] = 'S';
}

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
    linhaRick = rand() % 10;
    colunaRick = rand() % 10;
  }while(cenario[linhaRick][colunaRick] != '.');
  cenario[linhaRick][colunaRick] = 'R';
  print();
}

//verifica se a posicao do rick coincide com a posicao da saida
static void verificaParada(){
  if(linhaRick == cordenadaXSaida && colunaRick == cordenadaYSaida){
    condicaoDeParada = false;
  }
}

static void movimentaRick(){
  char movimentoRick;  
  do{
    printf("\n\nDigite WASD para movimentar Rick: ");
    scanf("%c", &movimentoRick);
    cenario[linhaRick][colunaRick] = '.';

    switch(movimentoRick){
      break;
      case 'w':
        if(linhaRick != 0){
          linhaRick--;
        }
        break;
      case 's':
        if(linhaRick != 9){
          linhaRick++;
        }
        break;
      case 'a':
        if(colunaRick != 0){
          colunaRick--;
        }
        break;
      case 'd':
        if(colunaRick != 9){
          colunaRick++;
        }
      break;
    }
    verificaParada();
    cenario[linhaRick][colunaRick] = 'R';
    print();
  }while(condicaoDeParada);
  printf("\nRick chegou à saida, fim de jogo");
}

int main(void){
  //inicializando o cenario
  for(int linha = 0; linha < 10; linha++){
    for(int coluna = 0; coluna < 10; coluna++){
        cenario[linha][coluna] = '.';
    }
  }

  geraSaida();
  geraRick();
  movimentaRick();
  
}

