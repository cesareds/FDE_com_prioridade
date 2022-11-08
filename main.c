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
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;

            default:
                printf("\nOpcao inválida\n");
                break;
        }
    } while (opcao!=0);
    return 0;
}
