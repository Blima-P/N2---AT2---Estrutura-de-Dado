#include "expressao.h"
#include <stdio.h>
#include <string.h>

int main() {
    char infixa[TAM], posfixa[TAM];

    printf("Digite a expressao (Ex: 3+4*(2-1)): ");
    fgets(infixa, TAM, stdin);
    infixa[strcspn(infixa, "\n")] = 0;

    infixaParaPosfixa(infixa, posfixa);

    printf("Expressao em pos-fixada: %s\n", posfixa);
    printf("Resultado final: %.2f\n", avaliarPosfixa(posfixa));

    return 0;
}