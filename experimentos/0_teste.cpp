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
    int x;
    //Pessoa() { std::cout << "Fui executado" << std::endl; } // Construtor
    Pessoa* getX()
    {
        return this;
    }
    
    int setX(int x){
        this->x = x;
    }
};

void* funcao(int x){
    return x;
}


using std::string;

int main()
{
    int* array;
}