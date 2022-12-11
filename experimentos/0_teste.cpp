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
};

class Pessoa{
public:
    static int x;
    static void print(){
        cout << x << endl;
    }
};
int Pessoa::x;

using std::string;

extern void teste();

int main()
{
    Pessoa p;
    p.x = 10;
    p.print();

    Pessoa p2;
    p2.x = 20;
    p.print();

    teste();

}