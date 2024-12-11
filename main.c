#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "aux.h"

#define X 1031
#define A 128
#define B 256
#define C 512
#define D 1000

// Vetor de placas com tratamento de colisão por endereçamento interno
Placa vetor[X]={0};

int main(void){
  char placa2[8];
  int i = 1, j,colisoes=0;
  clock_t inicio, fim_128, fim_256, fim_512, fim_1000;
  double tempo_insercao, tempo_busca;
  FILE* arq = fopen("placa.txt","r");
  if (arq==NULL){
    printf("Erro ao abrir o arquivo\n");
    exit(1);
  }

  //INSERÇÃO
  inicio = clock();
  printf("=============INSERCAO============\n\n");
  while(!feof(arq)&&i<=D){
    if(i==A){
      fim_128=clock();
      tempo_insercao = (double)(fim_128 - inicio) / CLOCKS_PER_SEC;
      gerarRelatorioInsercao(colisoes, tempo_insercao, A);
    }
    else if(i==B){
      fim_256=clock();
      tempo_insercao = (double)(fim_256 - inicio) / CLOCKS_PER_SEC;
      gerarRelatorioInsercao(colisoes, tempo_insercao, B);
    }

    else if(i==C){
      fim_512=clock();
      tempo_insercao = (double)(fim_512 - inicio) / CLOCKS_PER_SEC;
      gerarRelatorioInsercao(colisoes, tempo_insercao, C);
    }

    else if(i==D){
      fim_1000=clock();
      tempo_insercao = (double)(fim_1000 - inicio) / CLOCKS_PER_SEC;
      gerarRelatorioInsercao(colisoes, tempo_insercao, D);
    }
    fscanf(arq," %[^\n]\n",placa2);
    colisoes+=inserirPlaca(placa2);  
    i++;
  }
  
  rewind(arq);
  
  //BUSCA
  inicio = clock();
  printf("\n==============BUSCA==============\n\n");
  i=1;
  while(!feof(arq)&&i<=D){
    if(i==A){
      fim_128=clock();
      tempo_busca = (double)(fim_128 - inicio) / CLOCKS_PER_SEC;
      gerarRelatorio(tempo_busca, A);
    }
    else if(i==B){
      fim_256=clock();
      tempo_busca = (double)(fim_256 - inicio) / CLOCKS_PER_SEC;
      gerarRelatorio(tempo_busca, B);
    }

    else if(i==C){
      fim_512=clock();
      tempo_busca = (double)(fim_512 - inicio) / CLOCKS_PER_SEC;
      gerarRelatorio(tempo_busca, C);
    }

    else if(i==D){
      fim_1000=clock();
      tempo_busca = (double)(fim_1000 - inicio) / CLOCKS_PER_SEC;
      gerarRelatorio(tempo_busca, D);
    }
    fscanf(arq," %[^\n]\n",placa2);
    buscar(placa2,vetor);  
    i++;
  }  
    
  fclose(arq);
  return 0;
}