#include <iostream>

using namespace std;

class Car{
public:
    char nome[50];
    int ano;
};

int main()
{
    cout << "\n\n =============================== \n\n";

    cout << "Seja 'a' um int e 'p' um int*. p recebe &a.\n" << endl;

    int a;  // Declaração de uma variável 'a'. Possui lixo em seu valor.
    int* p; // Declaração de um ponteiro 'p' (que aponta pra um inteiro genérico não especificado, por ser int*, geralmente lixo).
    p = &a; // 'p' recebe o endereço de 'a', ou &a (mesma coisa). Ou seja, p REFERENCIA a.
    cout << "Valor de p apontando pra 'a':         " << p << endl;  // Basicamente é o valor que 'p' recebeu, um endereço, um &a.
    cout << "Valor de *p apontando pra 'a' (lixo): " << *p << endl; // Enquanto 'p' recebe o endereço de 'a', *p automaticamente recebe o valor de 'a'.
    cout << "Valor de &a, o endereço de a:         " << &a << endl;

    cout << "\nNesse momento 'a' recebe 10.\n" << endl;
    a = 10;

    cout << "Valor de p apontando pra 'a':         " << p << endl; // Ou seja, 'p' aponta pro endereço de 'a'...
    cout << "Valor de *p apontando pra 'a':        " << *p << endl; // ...e '*p' é o valor do endereço apontado por 'p'.

    cout << "\nNesse momento, '*p' recebe 12.\n" << endl;

    *p = 12; // Atribuo 12 ao *p. Isso significa que estou mudando o valor de a. *p DEFERENCIA a.

    cout << "Valor de p (igual ao &a): " << p << endl;
    cout << "Valor de *p:              " << *p << endl;
    cout << "Valor de a:               " << a << endl;

    int& x = a;

    cout << x << endl;

    cout << "\n\n =============================== \n\n";
}