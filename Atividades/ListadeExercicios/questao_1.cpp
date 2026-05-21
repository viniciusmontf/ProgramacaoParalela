#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

const int N = 4;
const int M = 5;

// Gera matriz com valores aleatórios de 1 a 20
void geraMatriz(int matriz[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matriz[i][j] = rand() % 20 + 1;
        }
    }
}

// Imprime matriz
void imprimirMatriz(const int matriz[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << matriz[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// Verifica condição matemática
bool verificarCondicao(const int matriz[N][M]) {

    // Guarda a menor soma encontrada
    int menorSoma = std::numeric_limits<int>::max();

    // Percorre colunas
    for (int j = 0; j < M; j++) {

        int somaAtual = 0;

        // Soma elementos da coluna
        for (int i = 0; i < N; i++) {
            somaAtual += abs(matriz[i][j]);
        }

        // Atualiza menor soma
        if (somaAtual < menorSoma) {
            menorSoma = somaAtual;
        }
    }

    // Guarda o maior produto encontrado
    long long maiorProduto = 0;

    // Percorre linhas
    for (int i = 0; i < N; i++) {

        long long produtoAtual = 1;

        // Multiplica elementos da linha
        for (int j = 0; j < M; j++) {
            produtoAtual *= matriz[i][j];
        }

        // Atualiza maior produto
        if (produtoAtual > maiorProduto) {
            maiorProduto = produtoAtual;
        }
    }

    // Retorna resultado da condição
    return menorSoma <= maiorProduto;
}

int main() {

    srand(time(0));

    int matriz[N][M];

    geraMatriz(matriz);

    std::cout << "Matriz Gerada:\n\n";

    imprimirMatriz(matriz);

    std::cout << std::endl;

    if (verificarCondicao(matriz)) {
        std::cout << "Condicao Satisfeita" << std::endl;
    }
    else {
        std::cout << "Condicao Nao Satisfeita" << std::endl;
    }

    return 0;
}