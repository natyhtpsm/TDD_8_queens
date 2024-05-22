// Copyright 2024 Nathália P. Assis
/**
*@file rainhas.hpp
*/


#ifndef RAINHAS_HPP_
#define RAINHAS_HPP_

#include <string>
#include <vector>
#include <utility>

const int TAMANHO = 8;
const bool DEBUG = false;

/**
* @brief Verifica a solução do problema das 8 rainhas.
*
* @param tabuleiro Matriz 8x8 representando o tabuleiro.
* @return 1 se a solução é válida, 0 se há ataques entre rainhas, -1 se a configuração é inválida.
*/
int verificar_solucao(const char tabuleiro[TAMANHO][TAMANHO]);


/**
* @brief Conta o número de rainhas no tabuleiro e verifica se existem caracteres inválidos.
*
* @param tabuleiro Matriz 8x8 representando o tabuleiro.
* @return true se houver exatamente 8 rainhas e nenhum caractere inválido, false caso contrário.
*/
bool contar_rainhas(const char tabuleiro[TAMANHO][TAMANHO]);

/**
* @brief Verifica se há ataques entre as rainhas no tabuleiro.
*
* @param tabuleiro Matriz 8x8 representando o tabuleiro.
* @return 1 se não houver ataques, 0 se houver ataques.
*/
int ataques(const char tabuleiro[TAMANHO][TAMANHO]);

/**
* @brief Gera um nome de arquivo único para armazenar os ataques.
*
* @param diretorio Diretório onde o arquivo será salvo.
* @return O nome do arquivo gerado.
*/
std::string nome_arquivo(const std::string& diretorio);

/**
* @brief Encontra a posição de todas as rainhas no tabuleiro.
*
* @param tabuleiro Matriz 8x8 representando o tabuleiro.
* @return Um vetor de pares representando as posições das rainhas.
*/
std::vector<std::pair<int, int>>
encontrar_rainhas(const char tabuleiro[TAMANHO][TAMANHO]);

/**
* @brief Identifica todos os ataques possíveis entre as rainhas no tabuleiro.
*
* @param rainhas Vetor de pares representando as posições das rainhas.
* @return Um vetor de strings representando os ataques.
*/

std::vector<std::string>
ataques_possiveis(const std::vector<std::pair<int, int>>& rainhas);

/**
* @brief Salva os ataques identificados em um arquivo.
*
* @param diretorio Diretório onde o arquivo será salvo.
* @param ataques Vetor de strings representando os ataques.
* @return true se o arquivo for salvo com sucesso, false caso contrário.
*/
bool salvar_ataques(const std::string& diretorio,
const std::vector<std::string>& ataques);

#endif  // RAINHAS_HPP_
