#include <iostream>

const int TAM = 20;

// Preenche vetor
void preencherVetor(int vetor[TAM]) {

    for (int i = 0; i < TAM; i++) {

        std::cout << "Digite o valor da posicao "
                  << i << ": ";

        std::cin >> vetor[i];
    }
}

// Organiza vetor
void organizarVetor(int vetor[TAM]) {

    // Percorre índices pares
    for (int i = 0; i < TAM; i += 2) {

        // Se índice par contém número par -> errado
        if (vetor[i] % 2 == 0) {

            // Procura índice ímpar errado
            for (int j = 1; j < TAM; j += 2) {

                // Número ímpar em índice ímpar -> errado
                if (vetor[j] % 2 != 0) {

                    std::swap(vetor[i], vetor[j]);

                    // Posição corrigida
                    break;
                }
            }
        }
    }
}

// Imprime vetor
void imprimirVetor(const int vetor[TAM]) {

    std::cout << "\nVetor organizado:\n";

    for (int i = 0; i < TAM; i++) {
        std::cout << vetor[i] << " ";
    }

    std::cout << std::endl;
}

int main() {

    int vetor[TAM];

    preencherVetor(vetor);

    organizarVetor(vetor);

    imprimirVetor(vetor);

    return 0;
}