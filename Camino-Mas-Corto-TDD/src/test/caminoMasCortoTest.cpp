#include "../caminoMasCorto.hpp"
#include "catch2/catch.hpp"
/* Encontrar el camino más corto desde un nodo hasta el nodo final*/

SCENARIO( "Set de números de nodos y aristas", "" ) {
    GIVEN("Una instancia de caminoMasCorto") {
        CaminoMasCorto cmc;
        WHEN('Set nodos y aristas') {
            cmc.numeroNodos = 5;
            cmc.numeroAristas = 10;
            THEN('Obtengo los valores setados') {
                REQUIRE( cmc.numeroNodos == 5);
                REQUIRE( cmc.numeroAristas == 10);
            }
        }
    }
}