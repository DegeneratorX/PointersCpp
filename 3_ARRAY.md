# Arrays em C++

Esse é um tópico que decidi separar, pois achei (sinceramente) até mais complexo que ponteiros na parte de sintaxe.

Requisitos para entender esse arquivo:
- Programação básica e procedural em C/C++
- POO em qualquer linguagem derivada do C++ (Java, Python)
- Ler os arquivos README.md e CONCEITOS.md nesse rep


# O que é um array?

Array é uma coleção de elementos. Um conjunto de elementos em uma ordem particular. Em C++ é basicamente uma coleção de variáveis, geralmente do mesmo tipo, em uma fileira. E um array é um ponteiro, e isso será detalhado depois.


## Por que se utiliza arrays em C++?

Existem vários momentos onde é preciso representar uma coleção inteira de dados, e não faz sentido declarar dezenas de variáveis só para guardar valores que poderiam ser guardados em um array. Se torna impraticável até para a manutenção do código.


## Como declarar um array padrão

```cpp
int x[5]; // 5 x 4 bytes = array de 20 bytes de espaço
double y[10]; // 10 x 8 bytes = array de 80 bytes de espaço
char z[20]; // 20 x 1 byte = array de 20 bytes de espaço

int n = 10;
int arr[n]; // Qual será o tamanho do array. (nesse caso 10)
```

- 'x' tem a capacidade de armazenar 5 valores inteiros. Eles são indexados de 0 a 4 (não inclui o 5).
- 'y' armazena 10 doubles.
- 'z' armazena 20 caracteres. Detalharei mais sobre o uso de char com arrays mais pra frente.
- 'n' pode ser qualquer número em tempo de execução, e isso determina o tamanho do array futuramente.

Existem diversas outras formas de declarar e representar arrays. Todas essas formas serão discutidas.


# Bibliotecas alternativas para arrays (estrutura de dados)

Em C++ os programadores utilizam bastante bibliotecas que tentam trabalhar com estrutura de dados de forma mais segura, com pouco impacto na performance em tempo de execução. Por convenção se usam mais bibliotecas do C++, para evitar o uso de heranças do C que podem causar dores de cabeça. Essas bibliotecas são padrões da STL (Standard Template Library) e estão na categoria de Containers.

Alguns exemplos são:

```cpp
// Sequence Containers
#include <array>  // Array primitivo do C versão "Classe"
#include <vector>  // Array modernizado, mas lento.
#include <forward_list> // Lista Simplesmente Encadeada.
#include <list> // Lista Duplamente Encadeada
#include <deque> // Fila Duplamente Encadeada

// Container Adaptors
#include <stack> // Pilha
#include <queue> // Fila
#include <priority_queue> // Fila de prioridade

// Associative Containers
#include <set> // Conjunto ordenado
#include <multiset> // Conjunto ordenado com valores repetidos
#include <map> // Dicionário ordenado (espécie de JSON, chave e valor)
#include <multimap> // Dicionário ordenado com chaves repetidas

// Unordered Associative Containters
#include <unordered_set> // Conjunto não ordenado
#include <unordered_map> // Dicionário não ordenado
#include <unordered_multiset> // Conjunto não ordenado com valores repetidos
#include <unordered_multimap> // Dicionário não ordenado com chaves repetidas

// Outros
#include <string> // const char* modernizado
```

Irei detalhar apenas os mais importantes pra falar sobre arrays.

- A biblioteca **array** é basicamente uma versão Classe do array clássico herdado do C. Possui vários métodos built-in e é alocado na memória na Pilha, o que significa que seu tamanho é constante em tempo de compilação. Diferente do array primitivo do C, *std::array* pode ser retornado em uma função.

- A biblioteca **vector** é uma estrutura de dados que se utiliza da keyword **new** para criar novos elementos em um bloco de memória. Assim como qualquer Classe de bibliotecas, possui vários métodos built-in e é alocado na Heap, o que significa perda de performance, porém seu tamanho pode variar em tempo de execução, e a grande vantagem é como o *std::vector* consegue alocar dados simulando um array tradicional, ou seja, os dados são armazenados lado a lado em uma fileira (em grandes blocos), acelerando o processo de iteração entre elementos, com a desvantagem de ocorrer fragmentação na Heap quando se tem muitos dados armazenados.

- A biblioteca **deque** é uma estrutura de dados que é parecida com o *std::vector*, mas os blocos de dados são levemente mais fragmentados e espalhados na Heap. Possui mais métodos para se trabalhar que *std::vector*. Por conta da fragmentação de blocos que contém dados ser levemente maior, os elementos não estão sempre enfileirados na memória, dificultando uma iteração. A vantagem sobre o *std::vector* é que a inserção no começo ou fim do *std::deque* é O(1), enquando que no *std::vector* não é. Isso significa que para dados extremamente grandes, o *std::deque* leva muita vantagem.

- A biblioteca **list** é implementada como uma lista duplamente encadeada. Cada elemento é guardado em um nó, e cada nó está espalhado em diferentes partes da memória na Heap. Ou seja, nenhum elemento é sequencial a outro em uma lista encadeada, tornando O(n) a iteração sobre ela. Porém, ela possui um ponteiro que aponta para qualquer nó interno dela (index), afinal os elementos não estão guardados em grandes blocos, e sim fragmentados dentro de nós, o que torna uma opção para uso no melhor caso ou caso médio, pois o ponteiro não precisa re-iterar sobre a lista, diferente dos blocos de memória da *std::vector* e *std::deque*.

- A biblioteca **string** permite usar a classe *std::string* do C++ para facilitar a declaração de um array de caracteres. É um imprescindível substituto do tipo primitivo *'const char*'*, que é basicamente a "string" do C, além de ter vários métodos built-in e muita compatibilidade com outras bibliotecas. 

Apesar do uso expressivo da classe std::string, o const char* será muito detalhado nesse arquivo.


# Arrays e Ponteiros

Um array é um ponteiro. Um ponteiro que aponta pro primeiro elemento de um bloco de dados. A sintaxe do array com o uso do operador [] para acessar índices de um array é puramente açúcar sintático para melhorar a leitura do código.

Se eu quero acessar o último elemento do array e imprimir, basta eu fazer isso:

```cpp
array[6] = {20, 40, 60, 80, 100, 120}; // Array de 6 elementos, index 0 a 5
cout << array[5] << endl; // index 5 é o último elemento. Index 6 é lixo.
```

Basicamente eu acesso o index *5* do array, e isso irá imprimir o elemento 120.
E isso é equivalente a isso aqui:

```cpp
cout << *(array+5) << endl;
```

Ou seja, isso aqui tudo vale:

```cpp
array[5] == *(array+5); // True
array[4] == *(array+4); // True
array[0] == *array;     // True
array[n] == *(array+n); // True
```

Isso ocorre, pois no array os elementos estão lado a lado dentro de um bloco de memória reservado (na pilha ou heap). Ou seja, cada elemento de um endereço de memória para outro é aumentado em bytes do tipo de dado que o array carrega. Exemplo:

```cpp
array[0] = 20;  // 0x55555556aed0
array[1] = 40;  // 0x55555556aed4 +4 bytes (int)
array[2] = 65;  // 0x55555556aed8 +4 bytes
array[3] = 80;  // 0x55555556aedc +4 bytes
array[4] = 110; // 0x55555556aee0 +4 bytes
array[5] = 132; // 0x55555556aee4 +4 bytes
```

E quando se faz *array+n*, basicamente você está **somando o endereço do primeiro elemento do array com n**, sendo 'n' o número de passos dado. O passo é definido pelo tipo de dado. Levando isso em consideração, temos que por baixo dos panos ocorre a seguinte operação: *n vezes sizeof(tipo de dado)*. Ou seja, se o tipo de dado do array guardar double (8 bytes), e 'n' for 3 passos:

- 3 * 8 bytes = 24 bytes. Somará por baixo dos panos o endereço do primeiro elemento do array (hexadecimal) + 18 (24 em hexadecimal).

```cpp
double array[10];
*(array+3) == array[3]; // 0x55555556aed0 + 18 = endereço do 4° elemento.
```

E obviamente é preciso acessar o conteúdo desse endereço através do operador '*'.

> Nota: o uso do [] é obrigatório para definir o tamanho do array no momento da declaração ou inicialização (exceto para strings, detalhes depois). Ele não é um operador nesses momentos citados, muito menos açúcar sintático. Porém, ao acessar valores do array usando índices dentro dos colchetes, [] se torna um operador. Seu uso é opcional, podendo ser substituído pelo operador de derreferência '*'.


# Alocação de arrays

Existem algumas formas de alocar espaço para arrays. Na **pilha** e na **heap** são as principais. Alocação na **data and bss segment** também é possível, mas é mais uma derivação


## Alocação de arrays na Pilha

## Alocação de arrays na Heap

# char VS char* VS const char* VS std::string

## char

## char*

## const char*

## std::string

# Arrays Multidimensionais

# Arrays e Funções

## Arrays como parâmetro de funções

## Arrays como retorno de funções

# Smart Pointers

# Entendido arrays...