// Copyright 2024 Nathália P. Assis
/**
*@file testa_rainhas.cpp
*/

#define CATCH_CONFIG_MAIN
#include "./catch.hpp"
#include "./rainhas.hpp"

/**
 * Teste para casos de soluções válidas.
*/
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

/**
 * Teste para casos em que há mais de 8 rainhas
*/
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

/**
 * Teste para casos em que há menos de 8 rainhas
*/
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

/**
 * Teste para casos em que o tabuleiro tem tamanho incorreto
*/
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

/**
 * Teste casos em que as rainhas se atacm na mesma linha, coluna ou diagonal
*/
TEST_CASE("Solucao inválida (ataque entre rainhas)", "[verificar_solucao]") {
    const char tabuleiro[TAMANHO][TAMANHO] = {
        {'0', '0', '0', '0', '1', '0', '0', '0'},
        {'0', '1', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '1', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '1', '0'},
        {'0', '0', '1', '0', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '1'},
        {'0', '0', '0', '0', '0', '1', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'}
    };
    const char tabuleiro2[TAMANHO][TAMANHO] = {
        {'0', '0', '0', '0', '1', '0', '0', '1'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '1', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '1', '0'},
        {'0', '0', '1', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '1'},
        {'0', '0', '0', '0', '0', '1', '0', '0'},
        {'1', '0', '0', '0', '0', '0', '0', '0'}
    };
    const char tabuleiro3[TAMANHO][TAMANHO] = {
    {'0', '0', '0', '1', '0', '0', '0', '0'},
    {'0', '0', '0', '0', '0', '0', '1', '0'},
    {'0', '0', '0', '0', '0', '1', '0', '0'},
    {'0', '0', '0', '0', '0', '0', '0', '1'},
    {'0', '0', '1', '0', '0', '0', '0', '0'},
    {'0', '0', '0', '0', '1', '0', '0', '0'},
    {'0', '1', '0', '0', '0', '0', '0', '0'},
    {'1', '0', '0', '0', '0', '0', '0', '0'}
    };
    const char tabuleiro4[TAMANHO][TAMANHO] = {
    {'1', '0', '0', '0', '0', '0', '0', '0'},
    {'0', '0', '0', '0', '0', '0', '1', '0'},
    {'0', '0', '0', '0', '0', '1', '0', '0'},
    {'0', '0', '0', '0', '0', '0', '0', '1'},
    {'0', '0', '1', '0', '0', '0', '0', '0'},
    {'0', '0', '0', '0', '1', '0', '0', '0'},
    {'0', '1', '0', '0', '0', '0', '0', '0'},
    {'0', '0', '0', '1', '0', '0', '0', '0'}
    };
    const char tabuleiro5[TAMANHO][TAMANHO] = {
    {'0', '0', '1', '0', '0', '0', '0', '0'},
    {'0', '0', '0', '0', '1', '0', '0', '0'},
    {'0', '0', '0', '0', '0', '1', '0', '0'},
    {'0', '0', '0', '0', '0', '0', '0', '1'},
    {'0', '0', '0', '0', '0', '0', '1', '0'},
    {'0', '0', '0', '1', '0', '0', '0', '0'},
    {'0', '1', '0', '0', '0', '0', '0', '0'},
    {'1', '0', '0', '0', '0', '0', '0', '0'}
    };

    REQUIRE(verificar_solucao(tabuleiro) == 0);
    REQUIRE(verificar_solucao(tabuleiro2) == 0);
    REQUIRE(verificar_solucao(tabuleiro3) == 0);
    REQUIRE(verificar_solucao(tabuleiro4) == 0);
    REQUIRE(verificar_solucao(tabuleiro5) == 0);
}

/**
 * Teste para casos em que o tabuleiro possui um caractere
 * inválido (diferente de '0' e '1')
*/
TEST_CASE("Tabuleiro com entradas inválidas (caracteres)",
"[verificar_solucao]") {
    const char tabuleiro[TAMANHO][TAMANHO] = {
        {'0', '0', '0', '0', '1', '0', '0', '0'},
        {'0', '1', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '1', '0', '0', '0', 'X'},
        {'0', '0', '0', '0', '0', '0', '1', '0'},
        {'0', '0', '1', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '1'},
        {'0', '0', '0', '0', '0', '1', '0', '0'},
        {'1', '0', '0', '0', '0', '0', '0', '0'}
    };
    REQUIRE(verificar_solucao(tabuleiro) == -1);
}
