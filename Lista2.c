#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_celula {
    int conteudo;
    struct s_celula *prox;
}Celula;

Celula *Topo;

//Função para Verificar se a Pilha está Vazia.
bool Vazia () {
    if (Topo == NULL) {return true;}
    else {return false;}
}

//Função para criar pilha.
void CriarPilha () {
    Topo = NULL;
}

//Função ára Empilhar Celula.
void Empilhar (int x) {
    Celula *p;
    p = (Celula*)malloc(sizeof(Celula));
    p -> conteudo = x;
    p -> prox = Topo;
    Topo = p;
}

//Função para Desempilhar.
void Desempilhar () {
    if(Vazia() == true) {printf("Não há elementos na pilha.\n");}
    else {
        Celula *aux;
        aux = Topo;
        Topo = Topo -> prox;
        free(aux);
    }
}

//Função para Imprimir a Pilha.
void ImprimirPilha () {
    if(Vazia() == true) {printf("Não há elementos na pilha.\n");}
    else {
        printf("Pilha:\n");
        Celula *aux;
        aux = Topo;
        while (Topo != NULL) {
            printf("%i\n", Topo -> conteudo);
            Topo = Topo -> prox;
    }
        Topo = aux;
        printf("\n");
    }
}

//Função para saber quantos elementos tem na pilha.
void Contagem() {
    Celula *aux;
    aux = Topo;
    int cont = 0;
    while (Topo != NULL) {
        cont++;
        Topo = Topo -> prox;
    }
    Topo = aux;
    printf("Existem: %i elementos na pilha\n\n", cont);
}

//Função auxiliar de contagem.
int ContagemAUX() {
    Celula *aux;
    aux = Topo;
    int cont = 0;
    while (Topo != NULL) {
        cont++;
        Topo = Topo -> prox;
    }
    Topo = aux;
    return cont;
}

//Função para reinicializar.
int ReiniciarPilha() {
    if(Topo == NULL) {printf ("A pilha já está vazia\n"); return 0;}
    while (Topo != NULL) {
        Celula *aux;
        aux = Topo;
        Topo = Topo -> prox;
        free(aux);
    }
    if(Topo == NULL) {printf("A pilha foi reinicializada :)\n\n");}
}

 //Função para buscar um elemento.
int BuscaSequencial(int chave) {
    if(Vazia() == true) {printf("Não há elementos na pilha.\n");}
    int local = ContagemAUX();
    Celula *aux;
    aux = Topo;
    while (Topo != NULL) {
        if(Topo -> conteudo == chave) {printf("A chave: %i foi encontrada.\nLocalização: %iº elemento da pilha.\n\n", chave, local);Topo = aux; return 0;}
        else {
            Topo = Topo -> prox;
            local--;
        }
    }
    if(Topo == NULL) {printf("O elemento %i não foi encontrado :(.\n\n", chave);}
    Topo = aux;
}

//Inverter pilha.
void InverterPilha() {
    int Tamanho = ContagemAUX();
    Celula *aux;
    aux = Topo;
    Celula **vetor;
    vetor = (Celula**)malloc(sizeof(Celula*) * Tamanho);
    for(int i = 0; i < Tamanho;i++) {
        vetor[i] = Topo;
        Topo = Topo -> prox;
    }
    for(int i = 0; i < Tamanho;i++) {
        vetor[i] -> prox = Topo;
        Topo = vetor[i];
    }
}

int main() {
    CriarPilha();
    for(int i = 1; i <= 10; i++) {
        Empilhar(i);
    }
    ImprimirPilha();
    Contagem();
   for(int i = 1; i <= 5;i++) {
       Desempilhar();
   }
   ImprimirPilha();
   Contagem();
   BuscaSequencial(4);
   BuscaSequencial(10);
   Empilhar(200);
   Empilhar(400);
   ImprimirPilha();
   BuscaSequencial(200);
   BuscaSequencial(400);
   printf("A pilha foi invertida para: \n\n");
   InverterPilha();
   ImprimirPilha();
}