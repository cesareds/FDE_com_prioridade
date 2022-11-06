#include <stdio.h>
#include "FILA.h"

int main() {
    No *r;
    Fila fila;
    criaFila(&fila);
    int valor, opcao=0;
    do {
        printf("0-Sair\n1-Inserir\n2-Remover\n3-Imprimir\n");
        scanf("%i", &opcao);
        switch (opcao) {
            case 0:
                printf("encerrando...\n");
                break;
            case 1:
                printf("\nInsira um valor\n");
                scanf("%i", &valor);
                inserir(&fila, valor);
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

            default:
                printf("\nOpcao inválida\n");
                break;
        }
    } while (opcao!=0);
    return 0;
}
