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

E quando se faz *array+n*, basicamente você está **somando o endereço do primeiro elemento do array com n**, sendo 'n' o número de passos dado. O passo é definido pelo tipo de dado. Levando isso em consideração, temos que por baixo dos panos ocorre a seguinte operação: *n vezes sizeof(tipo de dado)*. Ou seja, se o tipo de dado do array guardar int (4 bytes), e 'n' for 3 passos:

- 3 * 4 bytes = 12 bytes. Somará por baixo dos panos o endereço do primeiro elemento do array (hexadecimal) + C (12 em hexadecimal).

```cpp
int array[10];
*(array+3) == array[3]; // 0x55555556aed0 + c = endereço do 4° elemento.
```

E obviamente é preciso acessar o conteúdo desse endereço através do operador '*'.

> Nota: o uso do operador [] (squarebrackets) é obrigatório para inicializar o array no momento da declaração ou inicialização (exceto com strings, ver tópico sobre char*). Ele não é um açúcar sintático nesses momentos. A sua função é definir um bloco de memória e o seu tamanho, que é o tamanho do array. Porém, ao acessar valores do array usando índices dentro dos colchetes, [] se torna um operador de derreferência. Seu uso é alternativo, podendo ser substituído pelo operador de derreferência '*' (não convencional).


# Alocação de arrays

Existem algumas formas de alocar espaço para arrays. Na **pilha** e na **heap** são as principais. Alocação na **data and bss segment** também é possível, mas é mais uma derivação desses dois primeiros casos, e não será categorizado.


## Alocação de arrays na Pilha

Um exemplo de alocação automática:

```cpp
{
    int arr[10];
}
// arr não existe mais
```

O array sofre pop ao sair de um escopo e a memória é liberada.

## Alocação de arrays na Heap

A alocação dinâmica é um pouco mais elaborada.

```cpp
int* arr = new int[10];
delete[] arr;
```

Da mesma forma, preciso de um ponteiro na stack que aponte pra esse array anônimo na heap que guarda inteiros. A forma como ele aponta é apontando pro primeiro elemento do array. O *new* me retorna esse endereço do primeiro elemento e guarda em *arr*. E a sintaxe para apagar o array é um pouco diferente. As chaves precisam ser postas após o operador *delete*.

# Tamanho do array

A definição do tamanho de um array alocado na stack é feita em tempo de compilação. Portanto, é impossível mudar o tamanho de um array na stack em tempo de execução.

Códigos como esse geram erros, pois o compilador entende que em tempo de execução, *tamanho* podem mudar

```cpp
int tamanho = 5;
int exemplo[tamanho]; // Erro.
```

Para resolver isso, basta utilizar a keyword 'static' e uma promessa 'const' para evitar comportamentos indesejados. A 'static' irá alocar estaticamente em tempo de compilação a variável *tamanho* na data segment, permitindo portanto que o compilador reconheça essa variável já em tempo de compilação e implemente no array para que seja utilizada depois.

```cpp
static const int tamanho = 5;
int exemplo[tamanho]; // Correto.
```

Já na heap, os arrays podem receber valores de tamanho depois, pois os objetos são criados em tempo de execução quantas vezes for preciso.

```cpp
int tamanho;
int* arr;
cout << "Digite tamanho: "; cin >> tamanho;
arr = new int[tamanho];
```

> Nota: para manter o track do tamanho de um array, é interessante ter o auxílio de Classes. Caso contrário, pode ser difícil implementar. Mas de qualquer forma, std::array já faz esse track, e é altamente recomendado seu uso como substituto do array primitivo do C para muitos casos, pois tem baixíssimo impacto na performance.

# char VS char* VS const char* VS std::string

String nada mais é do que um array de conjunto de caracteres. Existem diversas formas de representar um array que contém caracteres. As mais conhecidas são:

- char
- char*
- const char*
- std::string (lib)
- outros (w_char_t, char'Number'_t, std::wstring)

## char

Um **char** armazena 1 byte = 8 bits = 2^8 possibilidades = 256 possibilidades de letras. Um char nada mais é que um "inteiro" de 1 byte ao invés de 4 bytes. É o tipo de dado mais simples possível. As instruções de máquina no executável converte esse número inteiro em caractere ao analisar que o tipo da variável é *char*, de acordo com a tabela ASCII. 

https://www.asciitable.com/

O range de um char é de -127 a 127 = (+/-)2^7-1, sendo o bit mais significativo o responsável por deixar o número positivo ou negativo, o que não tem muita influência quando se quer trabalhar com strings. No final, se usa mais os positivos.

Existe o **unsigned char**, que armazena também 1 byte = 8 bits = 2^8 possibilidades = 256 possibilidades de letras. Porém, o range de um unsigned char é de 0 a 255 = 2^8-1, portanto o bit mais significativo é consumido para que possa ter o dobro de caracteres positivos, com o downside de não usar os negativos, que são inúteis. Isso significa que dá pra usar a tabela ASCII extendida (ver site).

O número 0 representa o caractere nulo ('\0'), que indica quando uma string acaba. Isso será mais detalhado no tópico 'char*'.

```cpp
char letra = 'F';
int i = 70;

if (letra == i){ // Sim, isso dá true
    cout << "São diferentes visualmente, mas são iguais por baixo dos panos." << endl;
}

if ('F' == i){ // True
    cout << "Dá até pra comparar o caractere diretamente com o número" << endl;
}

cout << (char) i << endl; // Casting de 70 para char. Printará 'F'. O 70 se mantém, mas o char põe uma "máscara" sobre o 70, que é o 'F'.

char outra_letra = 64; // Sim, char pode receber número.
cout << outra_letra << endl; // Printará '@'
```

Perceba o uso de aspas simples '' para o tipo *char*. Já o tipo char* (string primitivo) é aspas duplas "". Essa é uma forma básica de diferenciar um char de um char*.

Tipo *char* é muito primitivo, e atualmente é pouquíssimo utilizado por convenção. Possui inúmeras limitações. Mas é ideal para entender como funcionam as strings, que nada mais são do que um array de char.

```cpp
char arr_1[4] = {'O', 'l', 'a', '\0'}; // Inicialização clássica de um char.
char arr_2[] = {'O', 'l', 'a', '\0'} // sizeof(arr_2) = 4. É possível inicializar sem tamanho definido.

char arr_3[4] = "Ola"; // Caractere nulo fica escondido na string (const char*).
char arr_4[] = "Ola"; // sizeof(arr_4) = 4. É possível inicializar sem tamanho definido.

char declaracao_arr1[]; // ERRO!
char declaracao_arr2[4]; // OK! Pode inicializar depois. 
```

Diversas formas de inicializar um array.

- Em **arr_1**, sem o caractere \0, printando esse objeto pode resultar em Ola@#%!...#@ até procurar um byte 00 (nulo) na memória "sem querer" e parar. Os símbolos representam lixo na memória. Por isso é importante o \0, para o operador *cout* parar a leitura/iteração do array no momento certo definido pelo programador, que é quando verifica se é nulo. Caso contrário o operador *cout* começará a iterar no array fora dos limites, e no C++ não há levantamento de exceção para leitura de índices fora dos limites.

- Em **arr_2** e **arr_4**, é possível inicializar sem definir um tamanho. O compilador já aloca inteligentemente o tamanho baseado no que recebe.

## char*

O char* é o tipo string primitivo herdado do C. Em C++, é somente utilizado no lugar da biblioteca convencional std::string para situações onde a performance da aplicação precisa ser priorizada.

- 12/12

https://www.google.com/search?q=%5B%5D+vs+*+c%2B%2B&ei=upaXY5vzKbqY1sQPvJixiAs&ved=0ahUKEwibuMj9_PT7AhU6jJUCHTxMDLEQ4dUDCA8&uact=5&oq=%5B%5D+vs+*+c%2B%2B&gs_lcp=Cgxnd3Mtd2l6LXNlcnAQAzIGCAAQFhAeMgYIABAWEB4yBggAEBYQHjIGCAAQFhAeMgYIABAWEB4yBggAEBYQHjIGCAAQFhAeMgYIABAWEB4yBggAEBYQHjIGCAAQFhAeOgsIABAHEB4QsAMQEzoHCAAQgAQQEzoICAAQFhAeEBM6DQgAEIAEELEDEIMBEA06BwgAEIAEEA06CggAEIAEELEDEA06CQgAEBYQHhDxBEoECEEYAUoECEYYAFDLA1jpB2CUCWgBcAB4AIABogGIAesEkgEDMC40mAEAoAEByAEKwAEB&sclient=gws-wiz-serp

https://www.geeksforgeeks.org/difference-pointer-array-c/

https://stackoverflow.com/questions/10760893/c-vs-as-a-function-parameter

https://stackoverflow.com/questions/27890375/int-vs-int-vs-int-in-function-parameters-which-one-should-i-use

https://stackoverflow.com/questions/24041263/is-there-a-differene-between-int-x-and-int-x

https://www.geeksforgeeks.org/storage-for-strings-in-c/

https://www.geeksforgeeks.org/introduction-of-shared-memory-segment/

- 13/12

https://www.google.com/search?q=why+const+char*+instead+of&oq=why+const+char*+instead+of&aqs=chrome..69i57.5656j0j1&sourceid=chrome&ie=UTF-8

https://www.geeksforgeeks.org/difference-const-char-p-char-const-p-const-char-const-p/

https://www.google.com/search?q=undefined+behaviour+c%2B%2B&ei=8AuZY7GjNrGb1sQPwbWosAI&ved=0ahUKEwix29Hz4Pf7AhWxjZUCHcEaCiYQ4dUDCA8&uact=5&oq=undefined+behaviour+c%2B%2B&gs_lcp=Cgxnd3Mtd2l6LXNlcnAQAzIHCAAQgAQQEzIICAAQFhAeEBMyCAgAEBYQHhATMggIABAWEB4QEzIICAAQFhAeEBMyCAgAEBYQHhATMggIABAWEB4QEzIICAAQFhAeEBMyCAgAEBYQHhATMgoIABAWEB4QDxATOgoIABBHENYEELADSgQIQRgASgQIRhgAUNsBWLcGYOIHaAFwAXgAgAGaAYgB3QSSAQMwLjSYAQCgAQHIAQjAAQE&sclient=gws-wiz-serp

https://www.geeksforgeeks.org/const-keyword-in-cpp/

## const char*

## std::string

# Arrays Multidimensionais

# Arrays e Funções

## Arrays como parâmetro de funções

## Arrays como retorno de funções

# Smart Pointers

# Entendido arrays...