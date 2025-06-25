# N2 - AT2 - Estrutura de Dados

## Conversão e Avaliação de Expressões Matemáticas Utilizando Pilhas em C

Trabalho prático da disciplina de Estrutura de Dados, desenvolvido no curso de Engenharia de Software - GPE17N0554.

**Professor:** Ranyelson Neres Carvalho

---

###  **Grupo 5 - Integrantes (ordem alfabética):**

* Lívia Fernandes Ribeiro Bezerra
* Maria Clara Ferreira dos Santos
* Maria Clara Paiva Oliveira Camelo
* Nicole Reinaldo de Carvalho
* Pedro Braga de Lima
* Rafael Lucas de Sousa Silva
* Wemerson Conceição Silva

---

##  Organização da Apresentação (ordem de fala):

* **Introdução e Objetivo do Projeto** - *Pedro Braga de Lima*
* **Diferença entre Expressão Infixada e Pós-Fixada** - *Maria Clara Ferreira dos Santos*
* **Conversão de Expressão Infixada → Pós-Fixada** - *Rafael Lucas de Sousa Silva*
* **Conversão de Pós-Fixada → Infixada** - *Lívia Fernandes Ribeiro Bezerra*
* **Avaliação da Expressão e Operações Especiais** - *Nicole Reinaldo de Carvalho*
* **Estrutura do Código e Organização em Arquivos** - *Wemerson Conceição Silva*
* **Demonstração Prática e Conclusão** - *Rafael Lucas de Sousa Silva*

---

##  **Resumo do Projeto:**

Este projeto tem como objetivo implementar, em linguagem C, um programa capaz de:

Converter expressões matemáticas da notação infixada para pós-fixada (Notação Polonesa Reversa).

Avaliar o resultado final da expressão utilizando estruturas de dados do tipo **Pilha**.

Operar com números e operadores básicos, além de suporte a potenciação e raiz quadrada.

O código segue o padrão de TAD (Tipo Abstrato de Dados), modularizado em três arquivos principais: `expressao.h`, `expressao.c` e `main.c`.

---

##  **Tecnologias e Conceitos Utilizados:**

* Linguagem C padrão ANSI
* Estrutura de Dados: Pilha
* Manipulação de Strings
* Funções Matemáticas (`math.h`)
* Conversão de Notações Matemáticas

---

##  **Estrutura de Arquivos:**

```
├── expressao.h      // Declaração de structs e funções
├── expressao.c      // Implementação da lógica das pilhas e conversões
├── main.c           // Função principal e interação com o usuário
```

---

##  **Compilação e Execução:**

Para compilar o projeto, utilize:

```
gcc main.c expressao.c -o programa -lm
```

Para executar:

```
./programa
```

Exemplo de entrada:

```
Digite a expressao (Ex: 3+4*(2-1)): 3+4*2
```

Saída esperada:

```
Expressao em pos-fixada: 342*+
Resultado final: 11.00
```

---

##  **Conclusão:**

Este projeto reforça o uso prático de estruturas de dados, conceitos matemáticos e manipulação de expressões, simulando o comportamento de calculadoras algébricas. A modularização em arquivos facilita a manutenção e compreensão do código.

---

**Obrigado pela atenção!**
