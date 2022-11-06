//
// Created by César de Souza on 05/11/22.
//

#ifndef FDE_COM_PRIORIDADE_FILA_H
#define FDE_COM_PRIORIDADE_FILA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int valor;
    struct no *proximo;
    struct no *anterior;
}No;
typedef struct {
    No *primeiro;
    No *fim;
    int tam;

}Fila;


void criaFila(Fila *fila);

void inserir(Fila *fila, int num);
No* remover(Fila *fila);
void imprimir(Fila *fila);
int buscaNaFrente(No *no, Fila *p);
#endif //FDE_COM_PRIORIDADE_FILA_H
