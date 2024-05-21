#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rainhas.hpp"

TEST_CASE("Tabuleiro válido", "[verifica_solucao]") {
    const char* tabuleiro[8] = {
        "00001000",
        "01000000",
        "00010000",
        "00000010",
        "00100000",
        "00000001",
        "00000100",
        "10000000"
    };
    REQUIRE(verifica_solucao(tabuleiro) == 1);
}

TEST_CASE("Tabuleiro inválido - menos rainhas", "[verifica_solucao]") {
    const char* tabuleiro[8] = {
        "00000000",
        "01000000",
        "00010000",
        "00000010",
        "00100000",
        "00000001",
        "00000100",
        "10000000"
    };
    REQUIRE(verifica_solucao(tabuleiro) == -1);
}

TEST_CASE("Tabuleiro inválido - rainhas se atacando", "[verifica_solucao]") {
    const char* tabuleiro[8] = {
        "01001000",
        "01000000",
        "00010000",
        "00000010",
        "00100000",
        "00000001",
        "00000100",
        "10000000"
    };
    REQUIRE(verifica_solucao(tabuleiro) == 0);
}
