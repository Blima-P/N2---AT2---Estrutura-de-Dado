#include <stdio.h>
#include <string.h>
#include "expressao.h"

int main() {
    char infixa[TAM], posfixa[TAM];

    printf("Digite a expressao infixada (ex: 3 + sin(0.5) * 2):\n> ");
    fgets(infixa, TAM, stdin);
    infixa[strcspn(infixa, "\n")] = 0; // remove \n

    infixaParaPosfixa(infixa, posfixa);
    printf("Expressao posfixada: %s\n", posfixa);

    float resultado = avaliarPosfixa(posfixa);
    printf("Resultado: %.4f\n", resultado);

    return 0;
}
