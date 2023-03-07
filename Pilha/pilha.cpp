#include "pilha.h"

int main(){
    int valor, i;
    Pedro::Pilha pilha(10);
    for (i = 0; i<10; i++){
        std::cout << "Insira um numero: ";
        std::cin >> valor;
        pilha.empilhar(valor);
    }

    for (i = 0; i<10; i++){
        std::cout << pilha.desempilhar() << std::endl;
    }

    return 0;
}