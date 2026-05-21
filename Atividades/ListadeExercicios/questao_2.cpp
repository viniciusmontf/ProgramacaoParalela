#include <iostream>
#include <cstdlib>
#include <ctime>

const int N = 4;

void geraMatriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand() % 30;
        }
    }
}

//Função auxiliar para imprimir a matriz
void imprimirMatriz(const int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matriz[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void calcularTransposta(const int matriz[N][N], int transposta[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }
}

void multiplicarMatrizes(const int matriz[N][N], const int transposta[N][N], int resultado[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < N; k++) {
                resultado[i][j] += matriz[i][k] * transposta[k][j];
            }
        }
    }
}

bool ehOrtogonal(const int resultado[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j && resultado[i][j] != 1) {
                return false;
            } else if (i != j && resultado[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int matriz[N][N];
    int transposta[N][N];
    int resultado[N][N];

    geraMatriz(matriz);
    std::cout << "Matriz Original:" << std::endl;
    imprimirMatriz(matriz);

    calcularTransposta(matriz, transposta);

    std::cout << "\nMatriz Transposta:\n";
    imprimirMatriz(transposta);

    multiplicarMatrizes(matriz, transposta, resultado);

    std::cout << "Matriz Resultado (M * M^T):" << std::endl;
    imprimirMatriz(resultado);

    if (ehOrtogonal(resultado)) {
        std::cout << "A matriz é ortogonal." << std::endl;
    } else {
        std::cout << "A matriz não é ortogonal." << std::endl;
    }

    return 0;
}