#include <iostream>
#include <utility>

const int N = 20;

// Preenche vetor
void preencherVetor(int vetor[N]) {

    for (int i = 0; i < N; i++) {

        std::cout << "Digite o elemento " << i << ": ";

        std::cin >> vetor[i];
    }
}

// Retorna 1 se composto, 0 caso contrário
int ehComposto(int num) {

    if (num <= 3) {
        return 0;
    }

    for (int i = 2; i * i <= num; i++) {

        if (num % i == 0) {
            return 1;
        }
    }

    return 0;
}

// Função recursiva
void organizarVetor(int vetor[N], int esquerda, int direita) {

    // Caso base
    if (esquerda >= direita) {
        return;
    }

    // Esquerda já correta
    if (ehComposto(vetor[esquerda])) {
         organizarVetor(vetor, esquerda + 1, direita);
    }

    // Direita já correta
    else if (!ehComposto(vetor[direita])) {
        organizarVetor(vetor, esquerda, direita - 1);
    }

    // Ambos errados
    else {
        std::swap(vetor[esquerda], vetor[direita]);
        organizarVetor(vetor, esquerda + 1, direita - 1);
    }
}

int main() {

    int vetor[N];

    preencherVetor(vetor);

    organizarVetor(vetor, 0, N - 1);

    std::cout << "\nVetor organizado:\n";

    for (int i = 0; i < N; i++) {
        std::cout << vetor[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}