#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

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

    int operator<<(int x){
        
    }
};

class Pessoa
{
public:
    static int x;
    static void print()
    {
        cout << x << endl;
    }
};
int Pessoa::x;

using std::string;

extern void teste();

int main()
{
    while(true){
        Pessoa* p = new Pessoa;
    }
}