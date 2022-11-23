#include <iostream>

using std::cin; using std::cout; using std::endl;

#define print(x) cout << x << endl;

class Car
{
public:
    char nome[50];
    int ano;
};

void* f(int* x){

    *x = (double) 5.5;

    return x;
}

int main()
{
    void* x;
    print(sizeof(x));
}