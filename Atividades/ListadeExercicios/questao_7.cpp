#include <iostream>
#include <cstdlib>
#include <ctime>

const int N = 50;

void preencherVetor(int vetor[N]) {
    for (int i = 0; i < N ; i++) {
        vetor[i] = std::rand() % 100 + 1;
    }
}

int maiorValor(int vetor[N], int indice) {
    if (indice == N - 1) {
        return vetor[indice];
    }

    int maiorRestante = maiorValor(vetor, indice + 1);

    if(vetor[indice] > maiorRestante) {
        return vetor[indice];
    } else {
        return maiorRestante;
    }
}

int main() {
    srand(time(0));
    int vetor[N];
    preencherVetor(vetor);

    std::cout << "Vetor:\n";

    for (int i = 0; i < N; i++) {
        std::cout << vetor[i] << " ";
    }

    std::cout << "\n O maior valor do vetor é: " << maiorValor(vetor, 0) << std::endl;

    return 0;
}