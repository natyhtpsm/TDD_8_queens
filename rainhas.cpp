#include <stdio.h>
#include "rainhas.hpp"

int verifica_solucao(const char* tabuleiro[8]) {
    int count_rainhas = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tabuleiro[i][j] == '1') {
                count_rainhas++;
            } else if (tabuleiro[i][j] != '0') {
                return -1;
            }
        }
    }
    if (count_rainhas != 8) return -1;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tabuleiro[i][j] == '1') {
                for (int k = 0; k < 8; ++k) {
                    if ((k != j && tabuleiro[i][k] == '1') || (k != i && tabuleiro[k][j] == '1')) {
                        return 0;
                    }
                }
                for (int k = 1; k < 8; ++k) {
                    if ((i + k < 8 && j + k < 8 && tabuleiro[i + k][j + k] == '1') ||
                        (i + k < 8 && j - k >= 0 && tabuleiro[i + k][j - k] == '1') ||
                        (i - k >= 0 && j + k < 8 && tabuleiro[i - k][j + k] == '1') ||
                        (i - k >= 0 && j - k >= 0 && tabuleiro[i - k][j - k] == '1')) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

void salva_ataques(const char* tabuleiro[8], const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) return;
    
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tabuleiro[i][j] == '1') {
                for (int k = 1; k < 8; ++k) {
                    if (i + k < 8 && j + k < 8 && tabuleiro[i + k][j + k] == '1') {
                        fprintf(file, "%d,%d %d,%d\n", i, j, i + k, j + k);
                    }
                    if (i + k < 8 && j - k >= 0 && tabuleiro[i + k][j - k] == '1') {
                        fprintf(file, "%d,%d %d,%d\n", i, j, i + k, j - k);
                    }
                    if (i - k >= 0 && j + k < 8 && tabuleiro[i - k][j + k] == '1') {
                        fprintf(file, "%d,%d %d,%d\n", i, j, i - k, j + k);
                    }
                    if (i - k >= 0 && j - k >= 0 && tabuleiro[i - k][j - k] == '1') {
                        fprintf(file, "%d,%d %d,%d\n", i, j, i - k, j - k);
                    }
                }
            }
        }
    }
    fclose(file);
}
