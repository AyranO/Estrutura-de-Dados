#include <stdio.h>
#include <stdlib.h>

typedef struct s_no {
    int conteudo;
    struct s_no *prox;
}No;

typedef struct s_lista {
    int contagem;
    No *primeiro;
}Lista;

//Função para iniciar uma Lista.
Lista* IniciarLista() {
    Lista *pl = (Lista*)malloc(sizeof(Lista));
    pl -> contagem = 0;
    pl -> primeiro = NULL;
    return pl;
}

//Função para inserir um No na lista.
void InserirNo (Lista *p, int x, int pos) {
    No *nova = (No*)malloc(sizeof(No));
    nova -> conteudo = x;
    //Caso seja o primeiro elemento.
    if (p -> primeiro == NULL) {
        nova -> prox = p -> primeiro;
        p -> primeiro = nova;
    }
    //Caso seja um elemento em uma pos muito longe.
    else if (pos > p -> contagem) {
        No* aux = p -> primeiro;
        while (aux -> prox != NULL) {
            aux = aux -> prox;
        }
        aux -> prox = nova;
        nova -> prox = NULL;
    }
    //Caso queira inserir na primeira posição.
    else if (pos == 1 || pos == 0) {
        nova -> prox = p -> primeiro;
        p -> primeiro = nova;
    }
    //Caso em que o No fica no meio de outros elementos.
    else {
        No* aux = p -> primeiro;
        for(int i = 1; i < (pos - 1);i++) {
            aux = aux -> prox;
        }
        nova -> prox = aux -> prox;
        aux -> prox = nova;
    }
     p -> contagem++;
}

//Função para buscar um elemento.
No* BuscarElemento(Lista *p, int chave) {
    No *aux = p -> primeiro;
    while (aux != NULL && aux -> conteudo != chave) {
        aux = aux -> prox;
    }
    return aux;
    
}

//Função para apagar um elemento.
void BuscaRemove(Lista*p, int chave) {
    No *lixo = BuscarElemento(p, chave);
    No *aux = p -> primeiro;
    if(lixo == NULL) {
        printf("O elemento %i não foi encontrado na lista.\n\n", chave);
        return;
        }
    else if(aux == lixo) {
        p -> primeiro = aux -> prox;
        free(lixo);
    }
    else {
        while (aux -> prox != lixo) {
            aux = aux->prox;
        }
        aux -> prox = lixo -> prox;
        free(lixo);
    }
    p -> contagem--;
}

//Função para imprimir a  lista.
void ImprimeLista (Lista *p) {
    No* aux = p -> primeiro;
    while (aux != NULL) {
        printf("%i ", aux -> conteudo);
        aux = aux -> prox;
    }
}

//Função para inserir após um elemento dado.
void InserirNoDepoisDe(Lista *p, int chave, int depois) {
    No *auxD = BuscarElemento(p, depois);
    if(auxD == NULL) {
        printf("O elemento %i não existe na lista.\n\n", depois);
        return;
    }
    No *nova = (No*)malloc(sizeof(No));
    nova -> conteudo = chave;
    nova -> prox = auxD -> prox;
    auxD -> prox = nova;
    p -> contagem++;
}

//Função para excluir toda a lista.
void ExcluirLista(Lista *p) {
    while (p -> primeiro != NULL) {
        No *aux = p -> primeiro;
        p->contagem--;
        p -> primeiro = p -> primeiro -> prox;
        free(aux);
    }
    free(p);
}

int main() {
  
}