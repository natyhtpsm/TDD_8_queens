#define CATCH_CONFIG_MAIN
#include "./catch.hpp"
#include "./rainhas.hpp"

TEST_CASE("Tabuleiro válido", "[verificar_solucao]") {
    const char tabuleiro[TAMANHO][TAMANHO] = {
        {'0', '0', '0', '0', '1', '0', '0', '0'},
        {'0', '1', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '1', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '1', '0'},
        {'0', '0', '1', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '1'},
        {'0', '0', '0', '0', '0', '1', '0', '0'},
        {'1', '0', '0', '0', '0', '0', '0', '0'}
    };
    REQUIRE(verificar_solucao(tabuleiro) == 1);
}