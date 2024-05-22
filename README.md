# Problema das 8 rainhas

## 📝 Descrição
Este projeto resolve o problema das 8 rainhas, onde o objetivo é posicionar 8 rainhas em um tabuleiro de xadrez 8x8 de forma que nenhuma rainha ataque a outra.

## 🚀 Funcionalidades
- Verificação de soluções para o problema das 8 rainhas.
- Detecção de ataques entre rainhas e registro em arquivos.

## 💻 Métodos Utilizados
- **carregar_tabuleiro**: Lê um arquivo .txt contendo um tabuleiro e carrega em uma matriz 8x8.
- **contar_rainhas**: Verifica se há exatamente 8 rainhas no tabuleiro.
- **ataques**: Verifica se há ataques entre rainhas no tabuleiro.
- **encontrar_rainhas**: Encontra as posições das rainhas no tabuleiro.
- **ataques_possiveis**: Identifica todos os ataques possíveis entre rainhas.
- **salvar_ataques**: Salva os ataques detectados em um arquivo.

## 🧪 Testes
Os testes são realizados utilizando a biblioteca Catch. Eles incluem verificação de soluções válidas e inválidas, bem como a detecção correta de ataques entre rainhas.

## 📖 Projeto
O projeto está estruturado da seguinte forma:
- **ataques/**: Contém arquivos de texto com registros de ataques entre rainhas.
- **doxygen_files/**: Contém os arquivos gerados pelo Doxygen.
- **raiz do projeto**: Contém os arquivos fonte(`rainhas.cpp`, `rainhas.hpp`, `testa_rainhas.cpp`).
- **makefile**: Arquivo Makefile para compilar o projeto.
- **cpplint.py**: Script para verificação do estilo de código.
- **Doxyfile**: Arquivo de configuração do Doxygen.
