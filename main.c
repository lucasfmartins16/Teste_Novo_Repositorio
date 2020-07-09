#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tabuleiro.h"
#include "interface.h"





int main(void) {
  int num_jog;
  printf("Numero de jogadores: ");
  scanf("%d",&num_jog);
  
  char **nomes =(char **) malloc(sizeof(char *)*num_jog);

  int i = 0;
  
  for( i = 0; i < num_jog; i++){
    nomes[i] = (char *) malloc(sizeof(char)*20);
  }

  setbuf(stdin, NULL);
  for(int i=0;i<num_jog;i++){
    printf("Nome do jogador %d: ", i+1);
    fgets(nomes[i], 20, stdin);
    for(int k=0;k<20;k++){
      if(nomes[i][k]=='\n'){
        nomes[i][k]='\0';
      }
    }
  }
  

  int cheatmode;
  printf("Cheat mode (Sim=1/Nao=0): ");
  scanf("%d",&cheatmode);

  int n_linhas = 1;
  int n_colunas = 1;
  int *m = &n_linhas;
  int *n = &n_colunas;

  Peca **matriz = aloca_tabuleiro(n_linhas, n_colunas);
  fill_tabuleiros(matriz, n_linhas, n_colunas, ' ');
  print_tabuleiro(matriz, n_linhas, n_colunas);
  
  while(1){
      menu(matriz, m, n, num_jog, nomes, cheatmode);
      //matriz_ = jogada(matriz_, m, n);
      break;
  }
  
  return 0;
}