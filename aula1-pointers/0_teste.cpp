#include<iostream>

using namespace std;

class Car{
public:
    char nome[50];
    int ano;
};


int main(){

    int a = 3;
    int* b = &a;
    int** c = &b;
    int& d = a;

    int* e = &d;

    cout << d << endl;

}