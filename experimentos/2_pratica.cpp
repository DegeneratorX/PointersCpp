#include<iostream>
#include<algorithm>

using std::cout; using std::cin; using std::endl;

class Pessoa{

public:
    const int idade;
    Pessoa(int idade){this->idade = idade;}
    
    int get_idade() const{ // Método com conteúdo const
        return this->idade;
    }

    void set_idade(int idade){ // Método com conteúdo não const
        this->idade = idade;
    }
};
int main(){
    const Pessoa p(32); // p é uma instância constante. Isso significa que só posso chamar métodos com conteúdo constante.
    int idade = p.get_idade(); // OK, pois o método que se chama tem conteúdo constante.
    p.idade = 10;
}