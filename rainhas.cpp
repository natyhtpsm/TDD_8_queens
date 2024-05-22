// Copyright 2024 Nathália P. Assis

#include "./rainhas.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

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

std::string nome_arquivo(const std::string& diretorio) {
  static int count = 0;
  return diretorio + "/ataques_" + std::to_string(count++) + ".txt";
}

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

int ataques(const char tabuleiro[TAMANHO][TAMANHO]) {
  auto rainhas = encontrar_rainhas(tabuleiro);
  auto ataques = ataques_possiveis(rainhas);
  return ataques.empty() ? 1 : 0;
}

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
