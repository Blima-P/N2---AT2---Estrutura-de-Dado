#ifndef EXPRESSAO_H
#define EXPRESSAO_H

#define TAM 100

typedef struct {
    float dados[TAM]; // Vetor para guardar os numeros
    int topo;         // Controla o topo da pilha
} PilhaNum;

typedef struct {
    char dados[TAM];  // Vetor para os operadores
    int topo;
} PilhaChar;

// Funções básicas das pilhas
void inicializaPilhaNum(PilhaNum* p);
int vaziaNum(PilhaNum* p);
void pushNum(PilhaNum* p, float valor);
float popNum(PilhaNum* p);

void inicializaPilhaChar(PilhaChar* p);
int vaziaChar(PilhaChar* p);
void pushChar(PilhaChar* p, char c);
char popChar(PilhaChar* p);

// Funções para manipular expressões
void infixaParaPosfixa(char* infixa, char* posfixa);
float avaliarPosfixa(char* posfixa);

#endif
