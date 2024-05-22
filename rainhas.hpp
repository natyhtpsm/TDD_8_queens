#ifndef TABULEIRO_HPP_
#define TABULEIRO_HPP_

#include <string>
#include <vector>
#include <utility>

const int TAMANHO = 8;
const bool DEBUG = false;

int verificar_solucao(const std::string& arquivo);
bool carregar_tabuleiro(const std::string& arquivo_txt, char tabuleiro[TAMANHO][TAMANHO]);
bool contar_rainhas(char tabuleiro[TAMANHO][TAMANHO]);
int ataques(char tabuleiro[TAMANHO][TAMANHO]);
std::string nome_arquivo(std::string diretorio);
std::vector<std::pair<int, int>> encontrar_rainhas(char tabuleiro[TAMANHO][TAMANHO]);
std::vector<std::string> ataques_possiveis(const std::vector<std::pair<int, int>>& rainhas);
bool salvar_ataques(std::string nome_arquivo, const std::vector<std::string>& ataques);
void exibir_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]);

#endif  // RAINHAS_HPP_
