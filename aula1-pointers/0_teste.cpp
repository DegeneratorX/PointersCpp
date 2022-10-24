#include<iostream>

using namespace std;

class Car{
public:
    char nome[50];
    int ano;
};

int main(){
    Car* car1 = new Car;
    car1->ano = 1990;
    cout << car1->ano;
}