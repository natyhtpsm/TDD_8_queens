#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rainhas.hpp"

TEST_CASE("Tabuleiro válido", "[verificar_solucao]") {
    std::string tabuleiro = 
        "00001000\n"
        "01000000\n"
        "00010000\n"
        "00000010\n"
        "00100000\n"
        "00000001\n"
        "00000100\n"
        "10000000\n";
    REQUIRE(verificar_solucao(tabuleiro) == 1);
}

TEST_CASE("Tabuleiro inválido (ataque)", "[verificar_solucao]") {
    std::string tabuleiro = 
        "00001000\n"
        "01000000\n"
        "00010000\n"
        "00000010\n"
        "00101000\n"
        "00000001\n"
        "00000100\n"
        "10000000\n";
    REQUIRE(verificar_solucao(tabuleiro) == 0);
}

TEST_CASE("Tabuleiro inválido (mais de 8 rainhas)", "[verificar_solucao]") {
    std::string tabuleiro = 
        "00001000\n"
        "01001000\n"
        "00010000\n"
        "00000010\n"
        "00100000\n"
        "00000001\n"
        "00000100\n"
        "10000000\n";
    REQUIRE(verificar_solucao(tabuleiro) == -1);
}
