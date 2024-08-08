#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
  srand(time(NULL));
  int rickChegouNaSaida = 0; //quando != 0 o jogo acaba
  char cenario[10][10];
  int xRick;
  int yRick;
  int xSaida, xObstaculo;
  int ySaida, yObstaculo;
  int quantidadeDeObstaculosAlocados, quantidadeDeZumbisAlocados;
  int bullets = 0;

  //cria o cenario
  for(int linha = 0; linha < 10; linha++){
    printf("\n");
    for(int coluna = 0; coluna < 10; coluna++){
      cenario[linha][coluna] = '.';
    }
  }

  do{ //cria um rick em uma posicao disponivel no mapa
    xRick = rand() % 10;
    yRick = rand() % 10;
    if(cenario[yRick][xRick] == '.'){
      cenario[yRick][xRick] = 'R';
    }
  }while(cenario[yRick][xRick] == '.');

  do{ //cria uma saida em uma posicao disponivel no mapa
      xSaida = rand() % 10;
      ySaida = rand() % 10;
      if(cenario[ySaida][xSaida] == '.'){
        cenario[ySaida][xSaida] = 'S';
      }
    }while(cenario[ySaida][xSaida] == '.');

  //cria 15 obstaculos no mapa
  quantidadeDeObstaculosAlocados = 0;
  while(quantidadeDeObstaculosAlocados < 15){
    xObstaculo = rand() % 10;
    yObstaculo = rand() % 10;
    if(cenario[yObstaculo][xObstaculo] == '.'){
      if(quantidadeDeObstaculosAlocados < 4){
        cenario[yObstaculo][xObstaculo] = 'c';
      }
      if(quantidadeDeObstaculosAlocados < 11 && quantidadeDeObstaculosAlocados >= 4){
        cenario[yObstaculo][xObstaculo] = 'a';
      }
      if(quantidadeDeObstaculosAlocados < 19 && quantidadeDeObstaculosAlocados >= 11){
        cenario[yObstaculo][xObstaculo] = 'p';
      }
      quantidadeDeObstaculosAlocados++;
    }
  }

  //cria 15 zumbis no mapa
  quantidadeDeZumbisAlocados = 0;
  while(quantidadeDeZumbisAlocados < 15){
    xObstaculo = rand() % 10;
    yObstaculo = rand() % 10;
    if(cenario[yObstaculo][xObstaculo] == '.'){
        cenario[yObstaculo][xObstaculo] = 'Z';      
      quantidadeDeZumbisAlocados++;
    }
  }
  //gambiarra pra por as balas no mapa
  quantidadeDeObstaculosAlocados = 0;
  while(quantidadeDeObstaculosAlocados < 5){
    xObstaculo = rand() % 10;
    yObstaculo = rand() % 10;
    if(cenario[yObstaculo][xObstaculo] == '.'){
        cenario[yObstaculo][xObstaculo] = 'b';
        quantidadeDeObstaculosAlocados++;
    }
  }

  //printa o estado do cenario
  for(int linha = 0; linha < 10; linha++){
    printf("\n");
    for(int coluna = 0; coluna < 10; coluna++){
      printf("%c", cenario[linha][coluna]);
    }
  }
  printf("\nUse WASD para mover Rick: ");

  //verifica se a saida esta bloquada por obstaculos
  if(ySaida > 0 && cenario[ySaida - 1][xSaida] != '.' && cenario[ySaida - 1][xSaida] != 'b' && cenario[ySaida - 1][xSaida] != 'Z' && cenario[ySaida - 1][xSaida] != 'R'){
    if(ySaida < 9 && cenario[ySaida + 1][xSaida] != '.' && cenario[ySaida + 1][xSaida] != 'b' && cenario[ySaida + 1][xSaida] != 'Z' && cenario[ySaida + 1][xSaida] != 'R'){
      if(xSaida > 0 && cenario[ySaida][xSaida - 1] != '.' && cenario[ySaida ][xSaida - 1] != 'b' && cenario[ySaida ][xSaida - 1] != 'Z' && cenario[ySaida ][xSaida - 1] != 'R'){
        if(xSaida < 9 && cenario[ySaida][xSaida + 1] != '.' && cenario[ySaida ][xSaida + 1] != 'b' && cenario[ySaida ][xSaida + 1] != 'Z' && cenario[ySaida ][xSaida + 1] != 'R'){
          printf("A saida esta bloqueada por obstaculos, rick nao pode escapar\n");
          rickChegouNaSaida = 1;
        }
      }
    }
  }

  do{
    char letra;
    scanf("%c", &letra);
    switch(letra){
      case 'w':
        if(yRick > 0){
          if(cenario[yRick - 1][xRick] != 'a' && cenario[yRick - 1][xRick] != 'c' && cenario[yRick - 1][xRick] != 'p'){
            if(cenario[yRick - 1][xRick] == 'b'){
              bullets++;
              printf("\nRick agora tem %d bala(s)", bullets);
            }
            if(cenario[yRick - 1][xRick] == 'S'){
              printf("\nRick encontrou a saida, fim de jogo");
              rickChegouNaSaida = 1;
            }
            if(cenario[yRick - 1][xRick] == 'Z'){
              if(bullets == 0){
                printf("\nRick se deparou com um zumbi, mas nao tinha balas, fim de jogo");
                rickChegouNaSaida = 1;
              } else{
                bullets--;
                printf("\nRick gastou uma bala no zumbi, agora possui %d balas" , bullets);
              }
            }
            cenario[yRick][xRick] = '.';
            yRick--;
            cenario[yRick][xRick] = 'R';
          }
        }
        for(int linha = 0; linha < 10; linha++){
          printf("\n");
          for(int coluna = 0; coluna < 10; coluna++){
            printf("%c", cenario[linha][coluna]);
          }
        }
      break;

      case 's':
        if(yRick < 9){
          if(cenario[yRick + 1][xRick] != 'a' && cenario[yRick + 1][xRick] != 'c' && cenario[yRick + 1][xRick] != 'p'){
            if(cenario[yRick + 1][xRick] == 'b'){
              bullets++;
              printf("Rick agora tem %d bala(s)", bullets);
            }
            if(cenario[yRick + 1][xRick] == 'S'){
              printf("Rick encontrou a saida, fim de jogo");
              rickChegouNaSaida = 1;
            }
            if(cenario[yRick + 1][xRick] == 'Z'){
              if(bullets == 0){
                printf("\nRick se deparou com um zumbi, mas nao tinha balas, fim de jogo");
                rickChegouNaSaida = 1;
              } else{
                bullets--;
                printf("\nRick gastou uma bala no zumbi, agora possui %d balas" , bullets);
              }
            }
            cenario[yRick][xRick] = '.';
            yRick++;
            cenario[yRick][xRick] = 'R';
          }
        }
        for(int linha = 0; linha < 10; linha++){
          printf("\n");
          for(int coluna = 0; coluna < 10; coluna++){
            printf("%c", cenario[linha][coluna]);
          }
        }
      break;

      case 'd':
        if(yRick < 9){
          if(cenario[yRick][xRick + 1] != 'a' && cenario[yRick][xRick + 1] != 'c' && cenario[yRick][xRick + 1] != 'p'){
            if(cenario[yRick][xRick + 1] == 'b'){
              bullets++;
              printf("Rick agora tem %d bala(s)", bullets);
            }
            if(cenario[yRick][xRick + 1] == 'S'){
              printf("Rick encontrou a saida, fim de jogo");
              rickChegouNaSaida = 1;
            }
            if(cenario[yRick][xRick + 1] == 'Z'){
              if(bullets == 0){
                printf("\nRick se deparou com um zumbi, mas nao tinha balas, fim de jogo");
                rickChegouNaSaida = 1;
              } else{
                bullets--;
                printf("\nRick gastou uma bala no zumbi, agora possui %d balas" , bullets);
              }
            }
            cenario[yRick][xRick] = '.';
            xRick++;
            cenario[yRick][xRick] = 'R';
          }
        }
        for(int linha = 0; linha < 10; linha++){
          printf("\n");
          for(int coluna = 0; coluna < 10; coluna++){
            printf("%c", cenario[linha][coluna]);
          }
        }
      break;

      case 'a':
        if(yRick > 0){
          if(cenario[yRick][xRick - 1] != 'a' && cenario[yRick][xRick - 1] != 'c' && cenario[yRick][xRick - 1] != 'p'){
            if(cenario[yRick][xRick - 1] == 'b'){
              bullets++;
              printf("Rick agora tem %d bala(s)", bullets);
            }
            if(cenario[yRick][xRick - 1] == 'S'){
              printf("Rick encontrou a saida, fim de jogo");
              rickChegouNaSaida = 1;
            }
            if(cenario[yRick][xRick - 1] == 'Z'){
              if(bullets == 0){
                printf("\nRick se deparou com um zumbi, mas nao tinha balas, fim de jogo");
                rickChegouNaSaida = 1;
              } else{
                bullets--;
                printf("\nRick gastou uma bala no zumbi, agora possui %d balas" , bullets);
              }
            }
            cenario[yRick][xRick] = '.';
            xRick--;
            cenario[yRick][xRick] = 'R';
          }
        }
        for(int linha = 0; linha < 10; linha++){
          printf("\n");
          for(int coluna = 0; coluna < 10; coluna++){
            printf("%c", cenario[linha][coluna]);
          }
        }
      break;
    }
  }while(rickChegouNaSaida == 0);
}
