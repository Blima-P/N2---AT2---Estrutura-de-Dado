#include "expressao.h"
#include <math.h>

// Implementação das pilhas
void inicializaPilhaNum(PilhaNum* p) { p->topo = -1; }
int vaziaNum(PilhaNum* p) { return p->topo == -1; }
void pushNum(PilhaNum* p, float valor) { p->dados[++p->topo] = valor; }
float popNum(PilhaNum* p) { return p->dados[p->topo--]; }

void inicializaPilhaChar(PilhaChar* p) { p->topo = -1; }
int vaziaChar(PilhaChar* p) { return p->topo == -1; }
void pushChar(PilhaChar* p, char c) { p->dados[++p->topo] = c; }
char popChar(PilhaChar* p) { return p->dados[p->topo--]; }

// Função que retorna a prioridade dos operadores
int precedencia(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^' || op == '√') return 3;
    return 0;
}

// Função que transforma expressão normal em pos-fixada
void infixaParaPosfixa(char* infixa, char* posfixa) {
    PilhaChar pilha;
    inicializaPilhaChar(&pilha);
    int j = 0;

    for (int i = 0; infixa[i] != '\0'; i++) {
        if (infixa[i] >= '0' && infixa[i] <= '9') {
            posfixa[j++] = infixa[i];
        } else if (infixa[i] == '(') {
            pushChar(&pilha, '(');
        } else if (infixa[i] == ')') {
            while (!vaziaChar(&pilha) && pilha.dados[pilha.topo] != '(') {
                posfixa[j++] = popChar(&pilha);
            }
            popChar(&pilha); // Tira o '('
        } else {
            while (!vaziaChar(&pilha) && precedencia(pilha.dados[pilha.topo]) >= precedencia(infixa[i])) {
                posfixa[j++] = popChar(&pilha);
            }
            pushChar(&pilha, infixa[i]);
        }
    }

    while (!vaziaChar(&pilha)) {
        posfixa[j++] = popChar(&pilha);
    }

    posfixa[j] = '\0';
}

// Função que resolve a expressão pos-fixada
float avaliarPosfixa(char* posfixa) {
    PilhaNum pilha;
    inicializaPilhaNum(&pilha);

    for (int i = 0; posfixa[i] != '\0'; i++) {
        if (posfixa[i] >= '0' && posfixa[i] <= '9') {
            pushNum(&pilha, posfixa[i] - '0');
        } else {
            float b = popNum(&pilha);
            float a = !vaziaNum(&pilha) ? popNum(&pilha) : 0;

            switch (posfixa[i]) {
                case '+': pushNum(&pilha, a + b); break;
                case '-': pushNum(&pilha, a - b); break;
                case '*': pushNum(&pilha, a * b); break;
                case '/': pushNum(&pilha, a / b); break;
                case '^': pushNum(&pilha, pow(a, b)); break;
                case '√': pushNum(&pilha, sqrt(b)); break;
            }
        }
    }

    return popNum(&pilha);
}