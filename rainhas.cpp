#include "rainhas.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

bool carregar_tabuleiro(const std::string& arquivo_txt, char tabuleiro[TAMANHO][TAMANHO]) {
    std::ifstream arquivo(arquivo_txt);
    if (!arquivo.is_open()) return false;

    std::string linha;
    for (int i = 0; i < TAMANHO; ++i) {
        if (!std::getline(arquivo, linha) || linha.length() != TAMANHO) return false;
        for (int j = 0; j < TAMANHO; ++j) {
            tabuleiro[i][j] = linha[j];
        }
    }
    return true;
}

bool carregar_tabuleiro_da_string(const std::string& conteudo, char tabuleiro[TAMANHO][TAMANHO]) {
    std::istringstream stream(conteudo);
    std::string linha;
    for (int i = 0; i < TAMANHO; ++i) {
        if (!std::getline(stream, linha) || linha.length() != TAMANHO) return false;
        for (int j = 0; j < TAMANHO; ++j) {
            tabuleiro[i][j] = linha[j];
        }
    }
    return true;
}

bool contar_rainhas(char tabuleiro[TAMANHO][TAMANHO]) {
    int count = 0;
    for (int i = 0; i < TAMANHO; ++i) {
        for (int j = 0; j < TAMANHO; ++j) {
            if (tabuleiro[i][j] == '1') count++;
        }
    }
    return count == 8;
}

int ataques(char tabuleiro[TAMANHO][TAMANHO]) {
    auto rainhas = encontrar_rainhas(tabuleiro);
    auto ataques = ataques_possiveis(rainhas);
    return ataques.empty() ? 1 : 0;
}

std::string nome_arquivo(std::string diretorio) {
    static int count = 0;
    return diretorio + "/ataques_" + std::to_string(count++) + ".txt";
}

std::vector<std::pair<int, int>> encontrar_rainhas(char tabuleiro[TAMANHO][TAMANHO]) {
    std::vector<std::pair<int, int>> posicoes;
    for (int i = 0; i < TAMANHO; ++i) {
        for (int j = 0; j < TAMANHO; ++j) {
            if (tabuleiro[i][j] == '1') posicoes.emplace_back(i, j);
        }
    }
    return posicoes;
}

std::vector<std::string> ataques_possiveis(const std::vector<std::pair<int, int>>& rainhas) {
    std::vector<std::string> ataques;
    for (size_t i = 0; i < rainhas.size(); ++i) {
        for (size_t j = i + 1; j < rainhas.size(); ++j) {
            if (rainhas[i].first == rainhas[j].first || rainhas[i].second == rainhas[j].second ||
                abs(rainhas[i].first - rainhas[j].first) == abs(rainhas[i].second - rainhas[j].second)) {
                std::stringstream ss;
                ss << rainhas[i].first << "," << rainhas[i].second << " " << rainhas[j].first << "," << rainhas[j].second;
                ataques.push_back(ss.str());
            }
        }
    }
    return ataques;
}

bool salvar_ataques(std::string nome_arquivo, const std::vector<std::string>& ataques) {
    std::ofstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) return false;
    for (const auto& ataque : ataques) {
        arquivo << ataque << "\n";
    }
    return true;
}

void exibir_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; ++i) {
        for (int j = 0; j < TAMANHO; ++j) {
            std::cout << tabuleiro[i][j];
        }
        std::cout << "\n";
    }
}

int verificar_solucao(const std::string& arquivo) {
    char tabuleiro[TAMANHO][TAMANHO];
    if (!carregar_tabuleiro(arquivo, tabuleiro)) return -1;
    if (!contar_rainhas(tabuleiro)) return -1;
    return ataques(tabuleiro);
}
