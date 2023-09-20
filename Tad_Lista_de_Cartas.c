#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "tad_cartas.h"
#include "Tad_Lista_de_Cartas.h"


// Inicializar a lista
void Inicializar(ListaDeCartas* lista) {
    lista->topo = NULL;
    lista->tamanho = 0;
}

// Retornar tamanho
int TamanhoLista(ListaDeCartas* lista) {
    return lista->tamanho;
}

// Verificar se est� vazia
bool EstaVazia(ListaDeCartas* lista) {
    return lista->tamanho == 0;
}


// Retornar a carta que est� no topo
void CartaNoTopo(ListaDeCartas* lista, Carta* carta) {
    if (!EstaVazia(lista)) {
        *carta = lista->topo->carta;
    } else {
       printf("Lista vazia");
    }
}


// Retornar a carta que est� numa dada posi��o
void CartaNaPosicao(ListaDeCartas* lista, int posicao, Carta* carta) {
    if (posicao >= 0 && posicao < lista->tamanho) {
        No* atual = lista->topo;
        for (int i = 0; i < posicao; i++) {
            atual = atual->proximo;
        }
        *carta = atual->carta;
    } else {
        printf("Posicao Invalida");
    }
}


// Adicionar carta ao topo
void AdicionarNoTopo(ListaDeCartas* lista, Carta carta) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro na aloca��o de memoria");
        exit(1);
    }
    novoNo->carta = carta;
    novoNo->proximo = lista->topo;
    lista->topo = novoNo;
    lista->tamanho++;
}

// Retirar carta do topo
void RetirarDoTopo(ListaDeCartas* lista, Carta* carta) {
    if (!EstaVazia(lista)) {
        No* noRemovido = lista->topo;
        *carta = noRemovido->carta;
        lista->topo = lista->topo->proximo;
        free(noRemovido);
        lista->tamanho--;
    } else {
        printf("Lista Vazia\n");
        // Aqui voc� pode tratar o caso em que a lista est� vazia
    }
}



// Transferir cartas
void TransferirCartas(ListaDeCartas* listaOrigem, ListaDeCartas* listaDestino, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        if (!EstaVazia(listaOrigem)) {
            Carta cartaTransferida;
            RetirarDoTopo(listaOrigem, &cartaTransferida);
            AdicionarNoTopo(listaDestino, cartaTransferida);
        } else {
            printf("A lista de origem est� vazia.\n");
            // Aqui voc� pode tratar o caso em que a lista de origem est� vazia
            // Por exemplo, encerrando o loop ou exibindo uma mensagem de erro
            break;
        }
    }
}

// Embaralha a lista de cartas usando o algoritmo de Fisher-Yates
void Embaralhar(ListaDeCartas* lista) {
    // Obt�m o tempo atual para inicializar a semente do gerador de n�meros aleat�rios
    srand(time(NULL));

    int tamanho = lista->tamanho;
    if (tamanho <= 1) {
        // N�o � necess�rio embaralhar listas com 0 ou 1 carta
        return;
    }

    No* atual = lista->topo;

    // Percorre a lista e troca cada carta com uma carta aleat�ria subsequente
    for (int i = 0; i < tamanho - 1; i++) {
        int j = i + rand() % (tamanho - i); // Gera um �ndice aleat�rio a partir de i at� o fim
        Carta temp = atual->carta;

        // Move o ponteiro 'atual' para a carta no �ndice j
        No* n = lista->topo;
        for (int k = 0; k < j; k++) {
            n = n->proximo;
        }

        atual->carta = n->carta;
        n->carta = temp;

        atual = atual->proximo;
    }
}
// Exibir
void Exibir(ListaDeCartas* lista, bool todasAsCartas) {
    if (EstaVazia(lista)) {
        printf("A lista de cartas est� vazia.\n");
    } else {
        No* atual = lista->topo;
        printf("Lista de Cartas:\n");
        int i = 0;
        while (atual != NULL) {
            if (todasAsCartas || i == 0) {
                printf("%d%c ", atual->carta.valor, atual->carta.naipe);
            } else {
                printf("?? "); // Para cartas n�o vis�veis
            }
            atual = atual->proximo;
            i++;
        }
        printf("\n");
    }
}
