#include <iostream>

using namespace std;

class Car
{
public:
    char nome[50];
    int ano;
};

int main()
{
    int a = 10;
    int& c = a;

    cout << &a << endl;
}