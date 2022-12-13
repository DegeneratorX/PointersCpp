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
    // char str[] = "Ola mundo";
    char arr_1[] = {'O', 'l', 'a', '\0'};
    // char arr_2[4] = "Ola";
    cout << sizeof(arr_1) << endl;
}