//
// Created by César de Souza on 05/11/22.
//

#ifndef FDE_COM_PRIORIDADE_FILA_H
#define FDE_COM_PRIORIDADE_FILA_H
#define PRIORIDADE 60
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int valor;
    struct no *proximo;
    struct no *anterior;
}No;
typedef struct{
    No *primeiro;
    No *fim;
    No *refMovel;
    int tam;
}Fila;


void criaFila(Fila *fila);

void inserir(Fila *fila, int num);  //refMovel é o último prioritário da fila
No* remover(Fila *fila);
void imprimir(Fila *fila);
int buscaNaFrente(int *num, Fila *fila);
int buscaNaCauda(int *num, Fila *fila);
int buscaReferencialMovel(int *num, Fila *fila);
int reinicia(Fila *fila);
Fila *destroi(Fila *fila);
int retiraDaFila(int num, Fila *fila);
int testaVazia(Fila *fila);
void inverte(Fila *fila);


#endif //FDE_COM_PRIORIDADE_FILA_H
