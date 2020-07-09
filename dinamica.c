#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tabuleiro.h"

int check_move(Peca **matriz, int x, int y, int m, int n){
    int i, j;

    int flag_forma = 0;

    int flag_cor = 0;

    int flag_mesma = 0;

    int flag_h = 0;

    int flag_v = 0;

    int vazio = 0;

    if(y == 0 || matriz[x][y -1].forma == ' '){
      if(y == n-1 || matriz[x][y + 1].forma == ' '){
        vazio++;
      }
    }
    if(x == 0 || matriz[x-1][y].forma == ' '){
      if(x == m-1 || matriz[x+1][y].forma == ' '){
        vazio++;
      }  
    }

    if(vazio == 2 && ((m != 1) && (n != 1))){
      printf("\nposicao vazia\n");
      return 0;
    }

    //ESQUERDA
    i = 1;
    printf("x: %d y: %d", x, y);
    while(y-i >= 0 && matriz[x][y-i].forma != ' '){
        printf("aqui 1\n");
        if(matriz[x][y-i].forma != matriz[x][y].forma){
            flag_forma = 1;
            printf("ESQUERDA - FORMA 1");
            break;
        }else{
            if(matriz[x][y-i].cor == matriz[x][y].cor){
              flag_mesma = 1;
              printf("ESQUERDA - FORMA 2 Cor:%c\n", matriz[x][y-i].cor);
              break;
            }
        }
        i++;
    }
    i = 1;
    while(y-i >= 0 && matriz[x][y-i].forma != ' '){
        printf("aqui 2\n");
        if(matriz[x][y-i].cor != matriz[x][y].cor){
            flag_cor = 1;
            printf("ESQUERDA - COR 1");
            break;
        }else{
          if(matriz[x][y-i].forma == matriz[x][y].forma){
              flag_mesma = 1;
              printf("ESQUERDA - COR 2 Forma: %c\n", matriz[x][y-i].forma);
              break;
            }
        }
        i++;
    }

    //DIREITA
    i = 1;
    while(y+i < n  && matriz[x][y+i].forma != ' '){
        printf("aqui 3\n");
        if(matriz[x][y+i].forma != matriz[x][y].forma){
            printf("\nmatriz[x][y+i].forma: %c\n", matriz[x][y+i].forma);
            flag_forma = 1;
            printf("DIREITA - FORMA");
            break;
        }else{
            if(matriz[x][y+i].cor == matriz[x][y].cor){
              flag_mesma = 1;
              printf("DIREITA - FORMA");
              break;
            }
        }
        i++;
    }
    i = 1;
    while(y+i < n  && matriz[x][y+i].forma != ' '){
        printf("aqui 4\n");
        if(matriz[x][y+i].cor != matriz[x][y].cor){
            flag_cor = 1;
            printf("DIREITA - COR");
            break;
        }else{
            if(matriz[x][y+i].forma == matriz[x][y].forma){
              flag_mesma = 1;
              printf("DIREITA - COR");
              break;
            }
        }
        i++;
    }

    if(flag_cor == 1 && flag_forma == 1){
      flag_h = 1;
    }
    flag_cor = 0;
    flag_forma = 0;

    //CIMA
    i = 1;
    while(x-i >= 0 && matriz[x-i][y].forma != ' '){
        printf("aqui 5\n");
        if(matriz[x-i][y].forma != matriz[x][y].forma){
            flag_forma = 1;
            printf("CIMA - FORMA");
            break;
        }else{
          if(matriz[x-i][y].cor == matriz[x][y].cor){
              flag_mesma = 1;
              printf("CIMA - FORMA");
              break;
            }
        }
        i++;
    }
    i = 1;
    while(x-i >= 0  && matriz[x-i][y].forma != ' '){
        printf("aqui6\n");
        if(matriz[x-i][y].cor != matriz[x][y].cor){
            flag_cor = 1;
            printf("CIMA - COR");
            break;
        }else{
          if(matriz[x-i][y].forma == matriz[x][y].forma){
              flag_mesma = 1;
              printf("CIMA - COR");
              break;
            }
        }
        i++;
    }
    
    //BAIXO
    i = 1;
    while(x+i < m && matriz[x+i][y].forma != ' '){
        printf("aqui\n");
        if(matriz[x+i][y].forma != matriz[x][y].forma){
            flag_forma = 1;
            printf("BAIXO - FORMA");
            break;
        }else{
          if(matriz[x+i][y].cor == matriz[x][y].cor){
              flag_mesma = 1;
              printf("BAIXO - FORMA");
              break;
            }
        }
        i++;
    }
    i = 1;
    while(x+i < m && matriz[x+i][y].forma != ' '){
        printf("aqui\n");
        if(matriz[x+i][y].cor != matriz[x][y].cor){
            flag_cor = 1;
            printf("BAIXO - COR");
            break;
        }else{
          if(matriz[x+i][y].forma == matriz[x][y].forma){
              flag_mesma = 1;
              printf("BAIXO - COR");
              break;
            }
        }
        i++;
    }

    if(flag_cor == 1 && flag_forma == 1){
      flag_v = 1;
    }
    printf("\nhorizontal = %d\nvertical = %d\nmesma = %d\n",flag_h,flag_v, flag_mesma);
    if(flag_h == 0 && flag_v == 0 && flag_mesma == 0){
      return 1;
    }else{
      return 0;
    }
}

int points(Peca **matriz, int **track, int linha, int pos, int m, int n){
    pos--;
    int c_x = track[pos][0];
    int c_y = track[pos][1];
    int i = 0;
    int pontuacao = 0;
    int pontuacao_ = 0;
    if(!pos){
        int flag = 0;
        while(matriz[c_x][c_y+i+1].forma != ' '){
            if(i == 0){
              pontuacao++;
              flag++;
            }
            i++;
        }
        pontuacao += i;
        i = 0;
        while(matriz[c_x][c_y-i-1].forma != ' '){
            if(i == 0){
              pontuacao++;
              flag++;

            }
            i++;
        }
        pontuacao += i;
        if(pontuacao == 6){
          pontuacao += 6;
        }
        i = 0;
        while(matriz[c_x+i+1][c_y].forma != ' '){
            if(i == 0){
              pontuacao++;
              flag++;

            }
            i++;
        }
        pontuacao += i;
        i = 0;
        while(matriz[c_x-i-1][c_y].forma != ' '){
            if(i == 0){
              pontuacao++;
              flag++;

            }
            i++;
        }
        pontuacao += i;
        if(pontuacao == 6){
          pontuacao += 6;
        }
        if(!flag){
          return 1;
        }else{
          return pontuacao;
        }
    
    }
    if(linha){
        pontuacao = 1;
        while(matriz[c_x][c_y+i+1].forma != ' '){
            i++;
        }
        pontuacao += i;
        i = 0;
        while(matriz[c_x][c_y-i-1].forma != ' '){
            i++;
        }
        pontuacao += i;

        if(pontuacao == 6){
          pontuacao += 6;
        }
        
        for(i = 0; i <= pos; i++){
          c_x = track[i][0];
          c_y = track[i][1];
          int j = 0;
          while(matriz[c_x+j+1][c_y].forma != ' ' && c_x +j+1 < m){
            if(j == 0){
               pontuacao_++;
            }
            j++;
          }
        pontuacao_ += j;
        j = 0;
        while(matriz[c_x-j-1][c_y].forma != ' ' && c_x -j-1 >= 0){
            if(j == 0){
               pontuacao_++;
            }
            j++;
        }
        pontuacao_ += j;
        if(pontuacao == 6){
          pontuacao += 6;
        }
        }
        
    }else{
        pontuacao = 1;
        while(matriz[c_x+i+1][c_y].forma != ' '){
            i++;
        }
        pontuacao += i;
        i = 0;
        while(matriz[c_x-i-1][c_y].forma != ' '){
            i++;
        }
        pontuacao += i;

        if(pontuacao == 6){
          pontuacao += 6;
        }
        
        for(i = 0; i <= pos; i++){
          c_x = track[i][0];
          c_y = track[i][1];
          int j = 0;
          while(matriz[c_x][c_y+j+1].forma != ' ' && c_y +j+1 < n){
            if(j == 0){
               pontuacao_++;
            }
            j++;
          }
        pontuacao_ += j;
        j = 0;
        while(matriz[c_x][c_y-j-1].forma != ' ' && c_y -j-1 >= 0){
            if(j == 0){
               pontuacao_++;
            }
            j++;
        }
        pontuacao_ += j;
        if(pontuacao == 6){
          pontuacao += 6;
        }
        }      
        
    }
    printf("\npontuacao: %d pontuacao_: %d\n", pontuacao, pontuacao_);

    return pontuacao + pontuacao_;
}

int ver(Peca **matriz, int c_x, int c_y, int **track, int *pos, int linha){
    int x_old = track[*pos-1][0];
    int y_old = track[*pos-1][1];
    int i;

    if(linha == 0){
        if(y_old != c_y){
          printf("aaaaaaaaaaaa - y_old: %d c_y :%d", y_old, c_y);
          return 0;
        }
        int a  = c_x;
        int b = x_old;
        if(x_old > c_x){
            a = x_old;
            b = c_x;
        }
        i = 1;
        while(b + i < a){
          if(matriz[b+i][y_old].forma == ' '){
            return 0;
          }
          i++;
        }
    }else{
        if(x_old != c_x){
          return 0;
        }
       int a = c_y;
        int b = y_old;
        if(y_old > c_y){
            a = y_old;
            b = c_y;
        }
        i = 1;
        while(b + i < a){
          if(matriz[x_old][b+i].forma == ' '){
            return 0;
          }
          i++;
        }
    }

    return 1;
}