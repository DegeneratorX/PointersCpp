#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

#define print(x) cout << x << endl;

class Car
{

public:
    const char *nome;
    int ano;
    Car(const char *nome, int ano)
    {
        this->nome = nome;
        this->ano = ano;
    }
};

class Pessoa
{
public:
    Pessoa() { std::cout << "Fui executado" << std::endl; } // Construtor
};


using std::string;

int main()
{
    string a = "Ola";
    // const char* nome = "Palio";
    // Car carro = Car("Palio", 18);
    // print(carro.nome);
    print(a);

}