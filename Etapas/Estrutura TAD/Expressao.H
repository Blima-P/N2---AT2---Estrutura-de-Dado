#ifndef EXPRESSAO_H
#define EXPRESSAO_H

#define TAM 256

typedef struct {
    float dados[TAM];
    int topo;
} PilhaNum;

typedef struct {
    char dados[TAM][TAM];  // para suportar operadores e números como strings
    int topo;
} PilhaStr;

void inicializaPilhaNum(PilhaNum* p);
int vaziaNum(PilhaNum* p);
void pushNum(PilhaNum* p, float valor);
float popNum(PilhaNum* p);

void inicializaPilhaStr(PilhaStr* p);
int vaziaStr(PilhaStr* p);
void pushStr(PilhaStr* p, char* str);
char* popStr(PilhaStr* p);

void infixaParaPosfixa(char* infixa, char* posfixa);
float avaliarPosfixa(char* posfixa);

#endif
