
#include <stdio.h>
#include <string.h>
#include "aux.h"

#define X 1031


// Função de hash
unsigned int hash(char placa[], int tentativa){
    unsigned int h = ((placa[0] * 26 * 26 * 26 + placa[1] * 26 * 26 + placa[2] * 26 + placa[3]) * 10000 + placa[4] * 1000 + placa[5] * 100 + placa[6] * 10 + placa[7]) % X;
    int incremento = 0;
    for (int i = 0; i < tentativa; i++) {
        incremento += 2 * i + 1;
    }
    return (h + incremento * incremento) % X;
}


// Inserir uma nova placa no vetor com tratamento de colisão
int inserirPlaca(char placa[]) {
    unsigned int tentativa = 0;
    unsigned int i = hash(placa, tentativa);
    int colisoes = 0;
    while (vetor[i].placa[0] != '\0' && strcmp(vetor[i].placa, placa) != 0) {
        tentativa++;
        i = hash(placa, tentativa);
        colisoes++;
    }
    
    strcpy(vetor[i].placa, placa);
    return colisoes;
}


// Buscar uma placa no vetor
int buscar(char placa[], Placa vetor[]){
    int i = 0;
    int h, tentativa = 0;
    do {
        h = hash(placa, tentativa++);
        if (strcmp(vetor[h].placa, placa) == 0)
            return h;
    } while (vetor[h].placa[0] != '\0' && i++ < X);
    return -1;
}

// Remover uma placa do vetor
void remover(char placa[], Placa vetor[]){
  int pos=buscar(placa,vetor);
  strcpy(vetor[pos].placa,"\0");
}

// Funções para gerar o relatório

void gerarRelatorio(double tempo, int tam) {
    printf("====== Relatorio %d casos ======\n",tam);
    printf("Tempo de busca: %.7f segundos\n", tempo);
    printf("=================================\n");
}

void gerarRelatorioInsercao(int totalColisoes, double tempo, int tam) {
    printf("====== Relatorio %d casos ======\n",tam);
    printf("Total de colisoes: %d\n", totalColisoes);
    printf("Tempo de insercao: %.7f segundos\n", tempo);
    printf("=================================\n");
}
