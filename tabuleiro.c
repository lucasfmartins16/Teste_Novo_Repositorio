#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tabuleiro.h"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

Peca** aloca_tabuleiro(int m, int n){

    Peca **matriz = (Peca **) malloc(sizeof(Peca *)*m);

    int i;

    for(i = 0; i < m; i++){
        matriz[i] = (Peca *) malloc(sizeof(Peca)*n);
    }

    return matriz;
}

void cores(char c, char d){

    switch(c){
      case '1':
        printf(ANSI_COLOR_BLUE "%c" ANSI_COLOR_RESET, d);
        printf(ANSI_COLOR_BLUE "%c" ANSI_COLOR_RESET, c);
        break;
      case '2':
        printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET, d);
        printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET, c);
        break;
      case '3':
        printf(ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET, d);
        printf(ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET, c);
        break;
      case '4':
        printf(ANSI_COLOR_YELLOW "%c" ANSI_COLOR_RESET, d);
        printf(ANSI_COLOR_YELLOW "%c" ANSI_COLOR_RESET, c);
        break;
      case '5':
        printf(ANSI_COLOR_MAGENTA "%c" ANSI_COLOR_RESET, d);
        printf(ANSI_COLOR_MAGENTA "%c" ANSI_COLOR_RESET, c);
        break;
      case '6':
        printf(ANSI_COLOR_CYAN "%c" ANSI_COLOR_RESET, d);
        printf(ANSI_COLOR_CYAN "%c" ANSI_COLOR_RESET, c);
        break;
      default:
        printf(" ");
        printf(" ");
        break;
    }
}

void print_tabuleiro(Peca **matriz, int m, int n){
	printf("\n");
	
	int i, j, k;
	
	printf("   ");
	for(k = 0; k < n; k++){
		
		  if(k+1 < 10){
		    printf("  %d  ", k);	
		  }else{
		  	printf("  %d  ", k);
		  }
	}
	
	printf("\n");
	
	for(i = 0; i < m; i++){
		
		if(i+1 < 10){
		  	printf("%d - ", i);
		  }else{
		  	printf("%d- ", i);
		  }
		
		for(j = 0; j < n; j++){
			
			//printf("%c", matriz[i][j].forma);
      cores(matriz[i][j].cor, matriz[i][j].forma);
      //printf("%c", matriz[i][j].cor);
			printf(" | ");
				
		}
		
		printf("\n");
		
		if(j == 1){
			printf("    ");
		}
		for(k = 0; k <= n; k++){
		  printf("-----");
		}
		printf("\n");
	}
}

void fill_tabuleiros(Peca **matriz, int m, int n, char c){
    int i, j;

    for(i = 0; i < m; i++){
      for(j = 0; j < n; j++){
            matriz[i][j].forma = c;
            
            matriz[i][j].cor = c;
      }
    }
}

Peca ** resize_tabuleiro(Peca **matriz, int *n_linhas, int *n_colunas, int **track, int pos){
  int x = track[pos][0];
  int y = track[pos][1];
  int m = *n_linhas;
  int n = *n_colunas;
  int i, j;

  int a = 0, b = 0;

  int expand[4] = {0, 0, 0, 0};

  if(y == 0){
    expand[2] = 1;
    b++;
    int k;
    for(k = 0; k <= pos; k++){
      (track[k][1])++;
    }
  }
  if(y == n-1){
    b++;
  }
  if(x == 0){
    expand[0] = 1;
    a++;
    int k;
    for(k = 0; k <= pos; k++){
      (track[k][0])++;
    }
  }
  if(x == m-1){
    a++;
  }

  Peca **matriz_ = aloca_tabuleiro(m + a, n + b);

      int k = 0, l = 0;

      if(expand[0] == 1){
        k = 1;
      }
    
      fill_tabuleiros(matriz_, m + a, n + b, ' ');

      for(i = 0; i < m; i++){
        if(expand[2] == 1){
          l = 1;
        }else{
          l = 0;
        }
        for(j = 0; j < n; j++){
            matriz_[k][l].forma = matriz[i][j].forma;
            matriz_[k][l].cor = matriz[i][j].cor;

            l++;
        }
        k++;
      }

      m+= a;

      n += b;

      *n_linhas = m;

      *n_colunas = n;

      return matriz_;


}

void update_tabuleiro(Peca **matriz, int *n_linhas, int *n_colunas, int **track, int pos){

  int x = track[pos][0];
  int y = track[pos][1];
  int m = *n_linhas;  
  int n = *n_colunas;
  int i, j;

  int a = 0, b = 0;

  int expand_cima=0;
  int expand_esquerda=0;

  if(y == 0){
    expand_esquerda= 1;
    b++;
    int k;
    for(k = 0; k <= pos; k++){
      (track[k][1])++;
    }
  }
  
  if(x == 0){
    expand_cima=1;
    a++;
    int k;
    for(k = 0; k <= pos; k++){
      (track[k][0])++;
    }
  }
  if(x == m-1){
    a++;
  }
  if(y == n-1){
    b++;
  }
  
  //adiciona linha
  if(x == 0 || x == m-1){
    matriz = (Peca **) realloc(matriz, sizeof(Peca)*(m+a));
    matriz[m] = (Peca *) malloc(sizeof(Peca)*n);
    int i;
    for(i = 0; i < n; i++){
      matriz[m][i].forma = ' ';
      matriz[m][i].cor = ' ';
    }
  }
  //adiciona coluna
  if(y == 0 || x == n-1){
    int i;
    for(i = 0; i < m; i++){
      matriz[i] = (Peca *) realloc(matriz[i], sizeof(Peca)*(n+b));
    }
    for(i = 0; i < m; i++){
      matriz[i][n].forma = ' ';
      matriz[i][n].cor = ' ';
    }
  }

  if(expand_cima){
    int i, j;
    for(i = m+a-1; i < 0; i--){
      for(j = n-1; j < 0; j--){
        matriz[i][j] = matriz[i-1][j];
      }
    }
    for(i = 0; i < n; i++){
      matriz[0][i].forma = ' ';
      matriz[0][i].cor = ' ';
    }
  }

  if(expand_esquerda){
    int i, j;
    for(i = n+b-1; i < 0; i--){
      for(j = n-1; j < 0; j--){
        matriz[j][i] = matriz[j-1][i];
      }
    }
    for(i = 0; i < n; i++){
      matriz[i][0].forma = ' ';
      matriz[i][0].cor = ' ';
    }
  }

  *n_linhas = m+a;

  *n_colunas = n+b;

}

