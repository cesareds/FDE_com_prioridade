#include <stdio.h>
#include "FILA.h"

int main() {
    No *r;
    Fila fila;
    int y;
    criaFila(&fila);
    int valor, opcao=0;
    do {
        printf("0-Sair\n1-Inserir\n2-Remover\n3-Imprimir\n4-Busca na Frente\n5-Busca na Cauda\n6-Busca no Referencial Móvel\n7-Reinicia\n8-Destroi\n9-Retira da Fila\n10-Testa Vazia\n11-Inverte");
        scanf("%i", &opcao);
        switch (opcao) {
            case 0:
                printf("encerrando...\n");
                break;
            case 1:
                printf("\nInsira um valor\n");
                scanf("%i", &valor);
                printf("\nInsira o nome\n");
                char nome[30];
                scanf(" %s", nome);
                Pessoa *pessoa = malloc(sizeof (Pessoa));
                pessoa->idade=valor;
                printf("\n %i \n", pessoa->idade);
                for(int i = 0; i<15; i++){
                    pessoa->nome[i]=nome[i];
                }
                printf("%s", pessoa->nome);
                printf("%i\n", pessoa->idade);
                inserir(&fila, pessoa);
                break;
            case 2:
                r=remover(&fila);
                if(r){
                    printf("Removido:\t%i\n", r->valor);
                    free(r);
                }
                break;
            case 3:
                imprimir(&fila);
                break;
            case 4:
                if(buscaNaFrente(&y, &fila)){
                    printf("\nBuscou na frente\n");
                }
                printf("%i\n", y);
                break;
            case 5:
                if(buscaNaCauda(&y, &fila)){
                    printf("\nBuscou na cauda\n");
                }
                printf("%i\n", y);
                break;
            case 6:
                if(buscaReferencialMovel(&y, &fila)){
                    printf("\nBuscou no Referencial Móvel\n");
                }
                printf("%i\n", y);
                break;
            case 7:
                if(reinicia(&fila)){
                    printf("Reiniciou a fila");
                }
                break;
                Fila *fila2;
            case 8:
                fila2 = destroi(&fila);
                break;
            case 9:
                printf("\n\tInsira o elemento que deseja retirar\t\n");
                scanf(" %i", &y);
                printf("\nvoce inseriu\t%i\n", y);
                if(retiraDaFila(y, &fila)){
                    printf("\nretirado da fila\n");
                }
                break;
            case 10:
                if(testaVazia(&fila)){
                    printf("\na fila está vazia\n");
                } else{
                    printf("\na fila nao está vazia\n");
                }
                break;
            case 11:
                printf("\nantes:\n");
                imprimir(&fila);
                inverte(&fila);
                printf("\ndepois:\n");
                imprimir(&fila);
                break;
            case 12:
                printf("\nantes:\n");
                imprimir(&fila);
                inverte2(&fila);
                printf("\ndepois:\n");
                imprimir(&fila);

                break;

            default:
                printf("\nOpcao inválida\n");
                break;
        }
    } while (opcao!=0);
    return 0;
}
