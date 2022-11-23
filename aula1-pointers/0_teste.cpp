#include <iostream>

using std::cin; using std::cout; using std::endl;

#define print(x) cout << x << endl;

class Car
{
public:
    char nome[50];
    int ano;
};

class Pessoa{};

int main()
{

int valor1 = 10;

int array1[5];
array1[0] = 1; 
array1[1] = 2;
array1[2] = 3;
array1[3] = 4;
array1[4] = 5;

int* valor2 = new int(10);

int* array2 = new int[5];
array2[0] = 1; 
array2[1] = 2;
array2[2] = 3;
array2[3] = 4;
array2[4] = 5;


print(&valor1)
for(int i = 0;i < 5; i++) print(&array1[i])

print("")

print(&valor2)
for(int i = 0;i < 5; i++) print(&array2[i])
}