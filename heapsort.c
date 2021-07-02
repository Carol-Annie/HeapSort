#include "heapsort.h"
#include <stdio.h>

void subir (int i, int *vetor, int tamanho) {
    int pai = i/2;
    if(pai >= 1) {
        if(vetor[i] > vetor[pai]) {
            int aux = vetor[i];
            vetor[i] = vetor[pai];
            vetor[pai] = aux;
            subir(pai, vetor, tamanho);
        }
    }
}

void descer (int i, int *vetor, int tamanho) {
    int filhoEsq = 2*i;
    int filhoDir = (2*i)+1;

    if(filhoDir <= tamanho) {

        if(vetor[i] < vetor[filhoEsq] || vetor[i] < vetor[filhoDir]) {
            if(vetor[filhoEsq] >= vetor[filhoDir]) {
                int aux = vetor[i];
                vetor[i] = vetor[filhoEsq];
                vetor[filhoEsq] = aux;
                descer(filhoEsq, vetor, tamanho);
            } else {
                int aux = vetor[i];
                vetor[i] = vetor[filhoDir];
                vetor[filhoDir] = aux;
                descer(filhoDir, vetor, tamanho);
            }
        }

    } else if (filhoEsq <= tamanho && filhoDir > tamanho) {

        if(vetor[filhoEsq] >= vetor[i]) {
            int aux = vetor[i];
            vetor[i] = vetor[filhoEsq];
            vetor[filhoEsq] = aux;
            descer(filhoEsq, vetor, tamanho);
        }
    }
}

void inserir (int novo, int *vetor, int tamanho) {
    vetor[tamanho+1] = novo;
    tamanho = tamanho + 1;
    subir(tamanho, vetor, tamanho);
}

void remover (int *vetor, int tamanho) {

    if (tamanho != 0) {
        vetor[1] = vetor[tamanho];
        tamanho = tamanho - 1;
        descer(1, vetor, tamanho);
    } else {
        printf("Underflow!");
    }
}

void construir (int *vetor, int tamanho) {
    for (int i = (tamanho/2); i >= 1; i--) {
        descer(i,vetor,tamanho);
    }
}

void heapSort (int *vetor, int tamanho) {

    construir(vetor, tamanho);

    int i;
    for( i = tamanho; i >= 2; i--){
        int aux = vetor[i];
        vetor[i] = vetor[1];
        vetor[1] = aux;
        descer(1, vetor, i-1);
    }
    printf("\n");
    for(i = 1; i <= tamanho; i++){
        printf("\t%d", vetor[i]);
    }
}
