#ifndef PILHA_H_
#define PILHA_H_
#include <iostream>

namespace Pedro{
    class Pilha{
        private:
        int *vet;
        int tamanho;
        int topo;

        public:
        Pilha(int tamanho);
        ~Pilha();
        void empilhar(int entrada);
        int desempilhar();
        int acessar()const;
        bool pilhaVazia()const;
        bool pilhaCheia()const;
    };

    Pilha::Pilha(int tamanho):
    vet(0),
    tamanho(0),
    topo(-1)
    {
        if (tamanho <= 0)
            throw std::string("Tamanho invalido");
        try{
            vet = new int[tamanho];
            this->tamanho = tamanho;
        }catch(std::bad_alloc &erro){
            throw std::string("Nao foi possivel alocar memoria");
        }
    }

    bool Pilha::pilhaVazia()const
    {
        return (topo==-1);
    }

    bool Pilha::pilhaCheia()const
    {
        return (topo == tamanho - 1);
    }



    void Pilha::empilhar(int entrada)
    {
        if (pilhaCheia())
            throw std::string("Pilha ja esta cheia");
        topo++;
        vet[topo] = entrada;
    }

    int Pilha::desempilhar()
    {
        if (pilhaVazia())
            throw std::string("Pilha ja esta vazia");
        return (vet[topo--]);
    }

    int Pilha::acessar()const
    {
        if (pilhaVazia())
            throw std::string("Nao foi possivel acessar, pilha vazia");
        return vet[topo];
    }

    Pilha::~Pilha()
    {
        if (vet){
            delete[] vet;
            vet = nullptr;
        }
    }
}

#endif