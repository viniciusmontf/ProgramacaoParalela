#include <cstdlib>
#include <utility>
#include <iostream>
#include <ctime>

const int N = 30;

void preencherVetor(int vetor[N]) {
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 30 + 1;
    }
}

void ordenarVetor(int vetor[N]) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (vetor[j] < vetor[j+1]) {
                std::swap(vetor[j], vetor[j + 1]);
            }
        }
    }
}

void imprimirVetor(const int vetor[N]) {
    for (int i = 0; i < N; i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    srand(time(0));
    int vetor[N];

    preencherVetor(vetor);
    
    std::cout << "Vetor não-ordenado:\n";
    imprimirVetor(vetor);

    ordenarVetor(vetor);

    std::cout << "Vetor ordenado:\n";
    imprimirVetor(vetor);
}