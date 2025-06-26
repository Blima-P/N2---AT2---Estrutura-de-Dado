#include "expressao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Pilha Numérica
void inicializaPilhaNum(PilhaNum *p) { p->topo = -1; }
int vaziaNum(PilhaNum *p) { return p->topo == -1; }
void pushNum(PilhaNum *p, float valor) { p->dados[++p->topo] = valor; }
float popNum(PilhaNum *p) { return p->dados[p->topo--]; }

// Pilha de Strings (para números e operadores)
void inicializaPilhaStr(PilhaStr *p) { p->topo = -1; }
int vaziaStr(PilhaStr *p) { return p->topo == -1; }
void pushStr(PilhaStr *p, char *str) { strcpy(p->dados[++p->topo], str); }
char* popStr(PilhaStr *p) { return p->dados[p->topo--]; }

// Precedência dos operadores
int precedencia(char* op) {
    if (strcmp(op, "sin") == 0 || strcmp(op, "cos") == 0) return 4;
    if (strcmp(op, "^") == 0 || strcmp(op, "√") == 0) return 3;
    if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0) return 2;
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) return 1;
    return 0;
}

// Verifica se é operador
int ehOperador(char* token) {
    return (
        strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
        strcmp(token, "*") == 0 || strcmp(token, "/") == 0 ||
        strcmp(token, "^") == 0 || strcmp(token, "√") == 0 ||
        strcmp(token, "sin") == 0 || strcmp(token, "cos") == 0
    );
}

// Converte infixada para posfixada
void infixaParaPosfixa(char *infixa, char *posfixa) {
    PilhaStr pilha;
    inicializaPilhaStr(&pilha);
    char token[TAM], resultado[TAM] = "";
    int i = 0;

    while (infixa[i] != '\0') {
        if (isspace(infixa[i])) {
            i++;
            continue;
        }

        if (isdigit(infixa[i]) || infixa[i] == '.') {
            int k = 0;
            while (isdigit(infixa[i]) || infixa[i] == '.') {
                token[k++] = infixa[i++];
            }
            token[k] = '\0';
            strcat(resultado, token);
            strcat(resultado, " ");
        } else if (isalpha(infixa[i])) {
            int k = 0;
            while (isalpha(infixa[i])) {
                token[k++] = infixa[i++];
            }
            token[k] = '\0';
            pushStr(&pilha, token);
        } else if (infixa[i] == '(') {
            token[0] = '('; token[1] = '\0';
            pushStr(&pilha, token);
            i++;
        } else if (infixa[i] == ')') {
            while (!vaziaStr(&pilha) && strcmp(pilha.dados[pilha.topo], "(") != 0) {
                strcat(resultado, popStr(&pilha));
                strcat(resultado, " ");
            }
            popStr(&pilha); // remove '('
            i++;
        } else {
            char op[2] = { infixa[i++], '\0' };
            while (!vaziaStr(&pilha) && precedencia(pilha.dados[pilha.topo]) >= precedencia(op)) {
                strcat(resultado, popStr(&pilha));
                strcat(resultado, " ");
            }
            pushStr(&pilha, op);
        }
    }

    while (!vaziaStr(&pilha)) {
        strcat(resultado, popStr(&pilha));
        strcat(resultado, " ");
    }

    strcpy(posfixa, resultado);
}

// Avalia expressão pós-fixada
float avaliarPosfixa(char* posfixa) {
    PilhaNum pilha;
    inicializaPilhaNum(&pilha);
    char* token = strtok(posfixa, " ");

    while (token != NULL) {
        if (ehOperador(token)) {
            float b = popNum(&pilha);
            float a = (!vaziaNum(&pilha)) ? popNum(&pilha) : 0;

            if (strcmp(token, "+") == 0) pushNum(&pilha, a + b);
            else if (strcmp(token, "-") == 0) pushNum(&pilha, a - b);
            else if (strcmp(token, "*") == 0) pushNum(&pilha, a * b);
            else if (strcmp(token, "/") == 0) pushNum(&pilha, a / b);
            else if (strcmp(token, "^") == 0) pushNum(&pilha, pow(a, b));
            else if (strcmp(token, "√") == 0) pushNum(&pilha, sqrt(b));
            else if (strcmp(token, "sin") == 0) pushNum(&pilha, sin(b));
            else if (strcmp(token, "cos") == 0) pushNum(&pilha, cos(b));
        } else {
            float valor = strtof(token, NULL);
            pushNum(&pilha, valor);
        }
        token = strtok(NULL, " ");
    }

    return popNum(&pilha);
}
