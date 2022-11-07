//
// Created by César de Souza on 05/11/22.
//

#include "FILA.h"
void criaFila(Fila *fila){
    fila->primeiro=NULL;
    fila->tam=0;
    fila->fim=NULL;
    fila->refMovel = NULL;
}

void inserir(Fila *fila, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor= num;
        novo->proximo=NULL;
        novo->anterior=NULL;
        if(fila->primeiro==NULL){
            fila->primeiro=novo;
            fila->fim=novo;
            fila->refMovel=novo;
        }else{
            if(num>59){                                     //testa se é prioridade
                if(fila->primeiro->valor<59){               //testa se é a 1º prioridade
                    novo->proximo=fila->primeiro;           //o primeiro da fila se torna o proximo do nulo
                    fila->primeiro=novo;
                    fila->refMovel=novo;                    //o novo se torna o primeiro
                }else{                                      //não é a primeira prioridade, portanto caminhará até o último em prioridade
                    aux=fila->primeiro;

                    if(aux->proximo!=NULL){                 //testa se existe um próximo na fila
                        while (aux->proximo->valor>59){     //testa se o próximo da fila ainda é prioridade
                            aux=aux->proximo;               //caminha um nó na fila
                            if (aux->proximo == NULL){
                                break;                      //caso não exista um próximo, sai do loop
                            }
                        }
                        novo->proximo = aux->proximo;       //o proximo do novo se torna o proximo de onde paramos na fila
                        novo->anterior = aux;               //o anterior do novo se torna o atual de onde paramos na fila
                        aux->proximo = novo;                //insere o novo na fila
                    }
                }
            }else{
                novo->anterior=fila->fim;                   //anterior do novo aponta para a cauda atual
                fila->fim->proximo=novo;                    //encadeia o novo no próximo do fim
                fila->fim=novo;                             //cauda da fila agora é o novo
            }

        }
        fila->tam++;
    }else{
        printf("\nErro ao alocar memória\n");
    }
}
No* remover(Fila *fila){
    No *remover=NULL;
    if(fila->primeiro){
        remover=fila->primeiro;
        fila->primeiro=remover->proximo;
        fila->tam--;
    }else{
        printf("\nFila vazia\n");
    }
    return remover;
}
void imprimir(Fila *fila){
    No *aux = fila->primeiro;
    printf("\n----------FILA----------\n\t");
    while (aux) {
        printf("%i\t", aux->valor);
        aux=aux->proximo;
    }
    printf("\n--------FIM FILA--------\n");
}




int buscaNaFrente(int *num, Fila *fila){
    int x = 0;
    if(fila->primeiro&&fila->fim){              //testa se existe um primeiro e um último
        *num = fila->primeiro->valor;
        x=1;
    }
    return x;
}
int buscaNaCauda(int *num, Fila *fila){
    int x = 0;
    if(fila->fim&&fila->primeiro){
        *num = fila->fim->valor;
        x = 1;
    }
    return x;
}
int buscaReferencialMovel(int *num, Fila *fila){
    int x = 0;
    if(fila->refMovel){
        *num = fila->refMovel->valor;
        x = 1;
    }
    return x;
}
int reinicia(Fila *fila){
    int x=0;
    No *aux=NULL;

    if(fila->primeiro&&fila->fim){
        aux = fila->fim->proximo;
        while(aux){
            free(fila->fim);
            fila->fim = aux;
            aux = aux->proximo;
        }
        free(fila->fim);
        fila->primeiro = NULL;
        fila->fim = NULL;
        x=1;
    }
    return x;
}
Fila *destroi(Fila *fila){
    reinicia(fila);
    free(fila);
    return NULL;
}
int retiraDaFila(int *num, Fila *fila){
    int x = 0;
    if(fila->primeiro){
        No *aux = fila->primeiro;
        while (aux->proximo->valor != *num){
            aux=aux->proximo;
            if (aux->proximo == NULL){
                break;                      //caso não exista um próximo, sai do loop
            }
        }
        *num = aux->valor;
        x = 1;
    }
    return x;
}
int testaVazia(Fila *fila){
    if(fila){
        if(fila->primeiro||fila->fim||fila->refMovel){
            return 0;
        }
        return 1;
    }
    return 1;
}
void inverte(Fila *fila){
    No *tmp, *aux = fila->primeiro;
    while(aux){
        tmp= aux->proximo;
        aux->proximo= aux->anterior;
        aux->anterior=tmp;
        aux=aux->anterior;
    }
    tmp = fila->primeiro;
    fila->primeiro=fila->fim;
    fila->fim= tmp;
}


