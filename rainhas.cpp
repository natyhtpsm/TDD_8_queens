// Copyright 2024 Nathália P. Assis
/**
*@file rainhas.cpp
*/


#include "./rainhas.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

/**
* @brief Conta o número de rainhas no tabuleiro e verifica se existem caracteres inválidos.
*
* @param tabuleiro Matriz 8x8 representando o tabuleiro.
* @return true se houver exatamente 8 rainhas e nenhum caractere inválido, false caso contrário.
*/

bool contar_rainhas(const char tabuleiro[TAMANHO][TAMANHO]) {
  int count = 0;
  bool caracteres_validos = true;
  for (int i = 0; i < TAMANHO; ++i) {
      for (int j = 0; j < TAMANHO; ++j) {
          if (tabuleiro[i][j] == '1') {
            count++;
          } else if (tabuleiro[i][j] != '0') {
            caracteres_validos = false;
          }
      }
  }
  if (!caracteres_validos) return false;
  return count == 8;
}

/**
* @brief Gera um nome de arquivo único para armazenar os ataques.
*
* @param diretorio Diretório onde o arquivo será salvo.
* @return O nome do arquivo gerado.
*/

std::string nome_arquivo(const std::string& diretorio) {
  static int count = 0;
  return diretorio + "/ataques_" + std::to_string(count++) + ".txt";
}

/**
* @brief Encontra a posição de todas as rainhas no tabuleiro.
*
* @param tabuleiro Matriz 8x8 representando o tabuleiro.
* @return Um vetor de pares representando as posições das rainhas.
*/

std::vector<std::pair<int, int>>
encontrar_rainhas(const char tabuleiro[TAMANHO][TAMANHO]) {
  std::vector<std::pair<int, int>> posicoes;
  for (int i = 0; i < TAMANHO; ++i) {
      for (int j = 0; j < TAMANHO; ++j) {
          if (tabuleiro[i][j] == '1') posicoes.emplace_back(i, j);
      }
  }
  return posicoes;
}

/**
* @brief Identifica todos os ataques possíveis entre as rainhas no tabuleiro.
*
* @param rainhas Vetor de pares representando as posições das rainhas.
* @return Um vetor de strings representando os ataques.
*/

std::vector<std::string>
ataques_possiveis(const std::vector<std::pair<int, int>>& rainhas) {
  std::vector<std::string> ataques;
  for (size_t i = 0; i < rainhas.size(); ++i) {
      for (size_t j = i + 1; j < rainhas.size(); ++j) {
          if (rainhas[i].first == rainhas[j].first ||
          rainhas[i].second == rainhas[j].second ||
              abs(rainhas[i].first - rainhas[j].first) ==
              abs(rainhas[i].second - rainhas[j].second)) {
              std::stringstream ss;
              ss << rainhas[i].first << "," <<
              rainhas[i].second << " " <<
              rainhas[j].first << "," << rainhas[j].second;
              ataques.push_back(ss.str());
          }
      }
  }
  return ataques;
}

/**
* @brief Salva os ataques identificados em um arquivo.
*
* @param diretorio Diretório onde o arquivo será salvo.
* @param ataques Vetor de strings representando os ataques.
* @return true se o arquivo for salvo com sucesso, false caso contrário.
*/

bool salvar_ataques(const std::string& diretorio,
  const std::vector<std::string>& ataques) {
  std::string nome_arq = nome_arquivo(diretorio);
  std::ofstream arquivo(nome_arq);
  if (!arquivo.is_open()) return false;
  for (const auto& ataque : ataques) {
      arquivo << ataque << "\n";
  }
  return true;
}

/**
* @brief Verifica se há ataques entre as rainhas no tabuleiro.
*
* @param tabuleiro Matriz 8x8 representando o tabuleiro.
* @return 1 se não houver ataques, 0 se houver ataques.
*/

int ataques(const char tabuleiro[TAMANHO][TAMANHO]) {
  auto rainhas = encontrar_rainhas(tabuleiro);
  auto ataques = ataques_possiveis(rainhas);
  return ataques.empty() ? 1 : 0;
}

/**
* @brief Verifica a solução do problema das 8 rainhas.
*
* @param tabuleiro Matriz 8x8 representando o tabuleiro.
* @return 1 se a solução é válida, 0 se há ataques entre rainhas, -1 se a configuração é inválida.
*/

int verificar_solucao(const char tabuleiro[TAMANHO][TAMANHO]) {
  if (!contar_rainhas(tabuleiro)) return -1;
  int resultado = ataques(tabuleiro);
  if (resultado == 0) {
    auto rainhas = encontrar_rainhas(tabuleiro);
    auto ataques = ataques_possiveis(rainhas);
    if (!salvar_ataques("ataques", ataques)) {
      std::cout << "Erro ao salvar arquivo de ataques." << std::endl;
    }
  }
  return resultado;
}
