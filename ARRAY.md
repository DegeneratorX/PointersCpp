# Arrays em C++

Esse é um tópico que decidi separar, pois achei (sinceramente) até mais complexo que ponteiros na parte de sintaxe.

Requisitos para entender esse arquivo:
- Programação básica e procedural em C/C++
- POO em qualquer linguagem derivada do C++ (Java, Python)
- Ler os arquivos README.md e CONCEITOS.md nesse rep


# O que é um array?

Array é uma coleção de elementos. Um conjunto de elementos em uma ordem particular. Em C++ é basicamente uma coleção de variáveis, geralmente do mesmo tipo, em uma fileira.


## Por que se utiliza arrays em C++?

Existem vários momentos onde é preciso representar uma coleção inteira de dados, e não faz sentido declarar dezenas de variáveis só para guardar valores que poderiam ser guardados em um array. Se torna impraticável até para a manutenção do código.


## Como declarar um array

```cpp
int x[5]; // 5 x 4 bytes = 20 bytes
double y[10]; // 10 x 8 bytes = 80 bytes
char z[20]; // 20 x 1 byte = 20 bytes

int n = 10;
int arr[n];
```

- 'x' tem a capacidade de armazenar 5 valores inteiros. Eles são indexados de 0 a 4 (não inclui o 5).
- 'y' armazena 10 doubles.
- 'z' armazena 20 caracteres. Detalharei mais sobre o uso de char com arrays mais pra frente.
- 'n' pode ser qualquer número em tempo de execução, e isso determina o tamanho do array futuramente.

//PAREI AQUI

# Bibliotecas alternativas para arrays (estrutura de dados)

Em C++ os programadores utilizam bastante bibliotecas que tentam trabalhar com arrays de forma mais segura, com pouco impacto na performance em tempo de execução. Por convenção se usam mais bibliotecas do C++, para evitar o uso de heranças do C que podem causar dores de cabeça.

Alguns exemplos são:

```cpp
#include <array>
#include <vector>
#include <deque>
#include <string>
```

- A biblioteca **array** é basicamente uma versão Classe do array clássico herdado do C. Possui vários métodos built-in e é alocado na Pilha, o que significa que seu tamanho é constante em tempo de compilação. Diferente do array primitivo do C, *std::array* pode ser retornado em uma função.

- A biblioteca **vector** é uma estrutura de dados que se utiliza da keyword **new** para criar novos elementos em um vetor. Assim como qualquer Classe de bibliotecas, possui vários métodos built-in e é alocado na Heap, o que significa perda de performance, porém seu tamanho pode variar em tempo de execução, e a grande vantagem é como o *std::vector* consegue alocar dados simulando um array tradicional, ou seja, os dados são armazenados lado a lado em uma fileira, acelerando o processo de iteração entre elementos, com a desvantagem de ocorrer fragmentação na Heap quando se tem muitos dados armazenados.

- A biblioteca **deque** é uma estrutura de dados que é parecida com o *std::vector*, mas os dados não são colocados lado a lado na Heap. Possui mais métodos para se trabalhar, e é uma lista duplamente encadeada, ou seja, os elementos não estão enfileirados, dificultando a iteração. A vantagem sobre o *std::vector* é que a inserção no começo ou fim do *std::deque* é O(1), enquando que no *std::vector* não é. Isso significa que para dados extremamente grandes, o *std::deque* leva muita vantagem.

- A biblioteca **string** permite usar a classe String do C++ para facilitar a declaração de um array de caracteres. É um imprescindível substituto do tipo primitivo *'const char*'*, que é basicamente a "string" do C, além de ter vários métodos built-in e muita compatibilidade com outras bibliotecas.