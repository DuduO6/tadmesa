#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tad_cartas.h"
#include "tad_cartas.c"
#include "Tad_Lista_de_Cartas.h"
#include "tad_lista_de_cartas.c"
#include "Tad_Mesa.h"
#include "Tad_Mesa.c"


int main(){
    // Inicialize a lista de cartas
    ListaDeCartas lista;
    Inicializar(&lista);

    // Crie algumas cartas
    Carta carta1 = criarCarta(1, 0, 1); // AS de Copas
    Carta carta2 = criarCarta(2, 0, 1); // 2 de Copas
    Carta carta3 = criarCarta(3, 0, 1); // 3 de Copas
    Carta carta4 = criarCarta(7, 2, 1);

    // Adicione as cartas à lista
    AdicionarNoTopo(&lista, carta1);
    AdicionarNoTopo(&lista, carta2);
    AdicionarNoTopo(&lista, carta3);
    AdicionarNoTopo(&lista, carta4);

    // Exiba a lista de cartas
    Exibir(&lista, true);

    // Embaralhe as cartas
    Embaralhar(&lista);

    // Exiba a lista de cartas embaralhada
    Exibir(&lista, true);

    // Retire uma carta do topo
    Carta cartaRetirada;
    RetirarDoTopo(&lista, &cartaRetirada);
    printf("Carta retirada: ");
    exibir_carta(cartaRetirada);

    // Exiba a lista de cartas após a retirada

    Exibir(&lista, true);

    srand(time(NULL));
    Mesa mesa;
    InicializarMesa(&mesa);
    CarregarBaralhoAleatorio(&mesa);
    Preparar(&mesa);
    return 0;
}
