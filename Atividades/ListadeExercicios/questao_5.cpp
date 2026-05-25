#include <iostream>

int potencia(int a, int b) {
    if (b == 0) {
        return 1;
    } else {
        return a * potencia(a, b - 1);
    }
}

int main() {
    int a, b;
    std::cout << "Digite a base (a): ";
    std::cin >> a;
    std::cout << "Digite o expoente (b): ";
    std::cin >> b;
    std::cout << "Resultado: " << potencia(a, b) << std::endl;
    return 0;
}