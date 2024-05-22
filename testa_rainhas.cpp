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

TEST_CASE("Tabuleiro inválido (mais de 8 rainhas)", "[verificar_solucao]") {
    const char tabuleiro[TAMANHO][TAMANHO] = {
        {'0', '0', '0', '0', '1', '0', '0', '0'},
        {'0', '1', '0', '0', '1', '0', '0', '0'},
        {'0', '0', '0', '1', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '1', '0'},
        {'0', '0', '1', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '1'},
        {'0', '0', '0', '0', '0', '1', '0', '0'},
        {'1', '0', '0', '0', '0', '0', '0', '0'}
    };
    REQUIRE(verificar_solucao(tabuleiro) == -1);
}

TEST_CASE("Tabuleiro inválido (menos de 8 rainhas)", "[verificar_solucao]") {
    const char tabuleiro[TAMANHO][TAMANHO] = {
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '1', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '1', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '1', '0'},
        {'0', '0', '1', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '1'},
        {'0', '0', '0', '0', '0', '1', '0', '0'},
        {'1', '0', '0', '0', '0', '0', '0', '0'}
    };
    REQUIRE(verificar_solucao(tabuleiro) == -1);
}

TEST_CASE("Tabuleiro inválido (tamanho incorreto)", "[verificar_solucao]") {
    const char tabuleiro[7][TAMANHO] = {
        {'0', '0', '0', '0', '1', '0', '0', '0'},
        {'0', '1', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '1', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '1', '0'},
        {'0', '0', '1', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0'}
    };
    REQUIRE(verificar_solucao(reinterpret_cast<const char
    (*)[TAMANHO]>(tabuleiro)) == -1);
}