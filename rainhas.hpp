#ifndef RAINHAS_HPP_
#define RAINHAS_HPP_

#include <string>
#include <vector>
#include <utility>

const int TAMANHO = 8;
const bool VERBOSE = false;

int verifica_solucao(const std::string& arquivo);
bool arquivo_para_matriz(const std::string& arquivo_txt, char tabuleiro[TAMANHO][TAMANHO]);
bool verifica_rainhas(char tabuleiro[TAMANHO][TAMANHO]);
int ataques(char tabuleiro[TAMANHO][TAMANHO]);
std::string cria_nome_arquivo(std::string diretorio);
std::vector<std::pair<int, int>> posicoes_rainhas(char tabuleiro[TAMANHO][TAMANHO]);
std::vector<std::string> possiveis_ataques(const std::vector<std::pair<int, int>>& rainhas);
bool registra_ataques(std::string nome_arquivo, const std::vector<std::string>& ataques);
void imprime_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]);

#endif  // RAINHAS_HPP_
