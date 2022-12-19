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

Em C++ os programadores utilizam bastante bibliotecas que tentam trabalhar com estrutura de dados de forma mais segura, com pouco impacto na performance em tempo de execução. Por convenção se usam mais bibliotecas do C++, para evitar o uso de heranças primitivas do C que podem causar dores de cabeça. Essas bibliotecas são padrões da STL (Standard Template Library) e estão na categoria de Containers.

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


# Arrays e aritmética de ponteiros

Um array "é" um ponteiro. Um ponteiro que aponta pro primeiro elemento de um bloco de dados.

Se eu quero acessar o último elemento do array e imprimir, basta eu fazer isso:

```cpp
int array[6] = {20, 40, 60, 80, 100, 120}; // Array de 6 elementos, index 0 a 5
cout << array[5] << endl; // index 5 é o último elemento. Index 6 é lixo.
```

Basicamente eu acesso o index *5* do array, e isso irá imprimir o elemento 120.
E isso é equivalente a isso aqui (derreferência):

```cpp
cout << *(array+5) << endl; // 120
```

A sintaxe do array com o uso do operador [] para acessar índices de um array é puramente açúcar sintático para melhorar a leitura do código. Ou seja, o índex dentro do operador [] é praticamente um açúcar sintático, pois de trás dos panos o que ocorre é uma derreferência. Portanto, isso aqui tudo vale:

```cpp
array[5] == *(array+5); // True - 120
array[4] == *(array+4); // True - 100
array[0] == *array;     // True - 20
array[n] == *(array+n); // True
```

Isso ocorre, pois no array os elementos estão lado a lado dentro de um bloco de memória reservado, não importa se o array foi inicializado na pilha ou heap. Ou seja, cada elemento de um endereço de memória para outro é aumentado em bytes do tipo de dado que o array carrega. Exemplo:

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

> Nota: o uso do operador [] (squarebrackets) é obrigatório para inicializar o array no momento da declaração ou inicialização (exceto com strings, ver tópico sobre char*). Ele não é um açúcar sintático nesses momentos. A sua função é definir um bloco de memória e o seu tamanho, que é o tamanho do array. Porém, ao acessar valores do array usando índices dentro dos colchetes, [] se torna um operador de derreferência e açúcar sintático. Seu uso é alternativo, podendo ser substituído pelo operador de derreferência '*' (não convencional).

> Nota 2: baseado nisso tudo, é preciso saber que int* é diferente de int[]. Os dois são ponteiros, mas possuem comportamentos diferentes. Suas principais diferenças serão discutidas no tópico **char[] vs char*: qual utilizar?**.


## Diferenças entre Arrays e Ponteiros

Existem algumas diferenças entre arrays e ponteiros. Arrays tendem a receber cópia de dados e alocar um espaço de memória para eles. Já um ponteiro aponta diretamente para um dado, sem fazer cópias. O objeto *array* em si é um ponteiro que guarda um endereço que aponta pro primeiro elemento de seu bloco de memória. O ponteiro faz a mesma coisa, porém ele não cria espaço para isso. O espaço foi criado por outra entidade qualquer.

- Sizeof são diferentes:

```cpp
int arr[15]; // 60 bytes = 15 * 4 bytes (int)
int* ptr = arr; // ptr recebe o endereço "arr". Passa a apontar pro mesmo primeiro elemento que arr.
cout << sizeof(arr) << endl; // Output: 60 (bytes)
cout << sizeof(ptr) << endl; // Output: 8 (bytes)
cout << sizeof(*ptr) << endl; // Output: 4 (bytes) (Captura o tamanho do int do primeiro elemento do array)
```

- Atribuição de endereços a um array é proibido:

```cpp
int arr[] = {10, 20};
int *ptr = new int(23); // *ptr = 23
int x = 5;

ptr = &x; // OK! 'ptr' agora aponta para x. *ptr = 5
arr = &x;  // ERRO!
```


## Semelhanças entre Arrays e Ponteiros

- O objeto array guarda o endereço para o primeiro elemento, assim como um ponteiro.
- Membros de um array são acessados por derreferência (artimética de ponteiros).
- Parâmetros de uma função com arrays são automaticamente reduzidos a uma passagem de ponteiro, mesmo usando os brackets [].

> Nota: ver mais sobre a última semelhança no tópico "Arrays como parâmetro de funções".

Mais em: https://www.geeksforgeeks.org/difference-pointer-array-c/

# Alocação de Arrays

Existem algumas formas de alocar espaço para arrays. Na **pilha** e na **heap** são as principais. Alocação na **data and bss segment** também é possível, mas é mais uma derivação desses dois primeiros casos, e não será categorizado.


## Alocação de Arrays na Pilha

Um exemplo de alocação automática:

```cpp
{
    int arr[10];
}
// arr não existe mais
```

O array sofre pop ao sair de um escopo e a memória é liberada.

## Alocação de Arrays na Heap

A alocação dinâmica é um pouco mais elaborada.

```cpp
int* arr = new int[10];
delete[] arr;
```

Da mesma forma, preciso de um ponteiro na stack que aponte pra esse array anônimo na heap que guarda inteiros. A forma como ele aponta é apontando pro primeiro elemento do array. O *new* me retorna esse endereço do primeiro elemento e guarda em *arr*. E a sintaxe para apagar o array é um pouco diferente. As chaves precisam ser postas após o operador *delete*.

# Tamanho do Array

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

# String literal

Uma string é um conjunto de caracteres normalmente concatenados na memória. Existem diversas formas de representar strings em um programa em C++, e isso será discutido de forma muito aprofundada logo no próximo tópico. Por hora, basta saber que as duas formas mais convencionais de representar uma string em C++ são essas:

```cpp
const char* ptr = "Ola mundo" // primitivo, rápido
std::string str = "Ola mundo com lib" // #include<string>, sofisticado (usa classe), lento
```

Uma string literal é uma string imutável alocada na .rodata segment. Ou seja, alocada no executável em tempo de compilação (veja sobre alocação no arquivo CONCEITOS.md). 

Por exemplo, acima temos o caso 'const char*', que é um ponteiro, e o "Ola mundo" é uma string literal. Ou seja, uma string bruta escrita no código fonte, e o ponteiro 'ptr' aponta pra ela.

```cpp
cout << "Sou uma string literal" << endl;
```

Por ela estar na .rodata, é somente read-only (leitura). E para evitar sua modificação através de ponteiros, o compilador do C++ decide tratar toda string literal como *const*. Ou seja, uma string literal no C++ é do tipo **const char[]** quando trazida pro programa, e qualquer ação bizarra de tentar modificar essa string literal através de ponteiros pode causar erros de segmentation fault. Isso será aprofundado também já no próximo tópico.

A imutabilidade de strings literais se tornou tendência no mercado. Um dos maiores problemas do C é o fato de que a string literal é do tipo **char[]**, o que não faz sentido, dado que esse tipo de dado não deve ser modificável pelo programador, pois ele estaria alterando, em tempo de execução, dados do próprio arquivo fonte que sequer são para escrita. O C++ resolveu esse problema parcialmente e adicionou o *const*. Infelizmente devida a retrocompatibilidade com C, o problema realmente ficou resolvido somente de forma parcial, e isso será detalhado no tópico "Herança do C: const virando mutável?".

Hoje a imutabilidade de strings literais virou tendência de mercado, e praticamente toda linguagem de programação de alto nível já trata strings como imutáveis.

# char VS const char VS std::string VS outros

 Existem diversas formas de representar caracteres e strings, que é um array que contém caracteres. As principais são:

- char
- char[]
- char*
- const char[]
- const char*
- std::string (lib)
- outros (wchar_t, char'Number'_t, std::wstring)

## char

Um **char** armazena 1 byte = 8 bits = 2^8 possibilidades = 256 possibilidades de letras. Um char nada mais é que um "inteiro" de 1 byte ao invés de 4 bytes. É o tipo de dado mais simples possível. As instruções de máquina no executável converte esse número inteiro em caractere ao analisar que o tipo da variável é *char*, de acordo com a tabela ASCII. 

https://www.asciitable.com/

O range de um char é de -127 a 127 = (+/-)2^7-1, sendo o bit mais significativo o responsável por deixar o número positivo ou negativo, o que não tem muita influência quando se quer trabalhar com strings. No final, se usa mais os positivos.

Existe o **unsigned char**, que armazena também 1 byte = 8 bits = 2^8 possibilidades = 256 possibilidades de letras. Porém, o range de um unsigned char é de 0 a 255 = 2^8-1, portanto o bit mais significativo é consumido para que possa ter o dobro de caracteres positivos, com o downside de não usar os negativos, que são inúteis. Isso significa que dá pra usar a tabela ASCII extendida (ver site).

O número 0 representa o caractere nulo ('\0'), que indica quando uma string acaba. Isso será mais detalhado no tópico 'char[]'.

```cpp
char letra = 'F';
int i = 70;

if (letra == i){ // Sim, isso dá true
    cout << "São diferentes visualmente, mas são iguais por baixo dos panos." << endl;
}

if ('F' == i){ // True
    cout << "Dá até pra comparar o caractere diretamente com o número" << endl;
}

// Casting de 70 para char. Printará 'F'. O 70 se mantém, mas o char põe uma "máscara" sobre o 70, que é o 'F' usando ASCII.
cout << (char) i << endl; // Tenho inclusive a opção de converter char pra int.

char outra_letra = 64; // Sim, char pode receber número.
cout << outra_letra << endl; // Printará '@'
```

O tipo *char* é muito primitivo, e atualmente é pouquíssimo utilizado por convenção. Possui inúmeras limitações. Mas é ideal para entender como funcionam as strings, que nada mais são do que um array de char.

## char[]

O **char[]** é o tipo de dado primitivo padrão em C para strings literais. Já em C++, houve a adição de um 'const' para strings literais. Será detalhado no tópico 'const char[]'.

É um tipo muito obsoleto (juntamente com char*) em C++. Isso porque ao inicializar uma variável do tipo **char[]**, o programador estará criando uma cópia da string literal da .rodata na stack, o que afeta muito a performance, principalmente se a string for grande, o que poderia ser bem possível (Exemplo: 1000 caracteres = 1KB na stack ocupado).

Ou seja, o seu uso é raro devido ao fator de cópia, que cria uma operação de iteração por toda a string O(n) e ainda ocupa espaço na pilha que depende do número de caracteres, já que se trata de uma cópia direta do que estava na .rodata. 

Supondo uma mutabilidade da string literal, alterar qualquer coisa nela precisaria iterar sobre a string novamente O(n) na .rodata para uma checagem e nova cópia. E O(n) se aplicará sempre que houver mudanças mesmo que sejam mínimas (como um simples caractere), e portanto seria um big deal para performance.

Perceba o uso de aspas simples '' para o tipo *char*. Já as aspas duplas "" define o tipo char[] (ou char*). Essa é uma forma básica de diferenciar um char de um char[]/char*. Ao passar o mouse em cima de uma string já com aspas duplas usando uma IDE ou vscode, geralmente aparecerá 'const char[]'.

Eis alguns exemplos de um array de char:

```cpp
char arr_1[4] = {'O', 'l', 'a', '\0'}; // Inicialização clássica de um array de 4 elementos (4 chars).
char arr_2[] = {'O', 'l', 'a', '\0'} // sizeof(arr_2) = 4. É possível inicializar sem tamanho definido.

char arr_3[4] = "Ola"; // Caractere nulo fica escondido na string (const char*).
char arr_4[] = "Ola"; // sizeof(arr_4) = 4. É possível inicializar sem tamanho definido.

char declaracao_arr2[4]; // OK! Pode inicializar depois. 
char declaracao_arr1[]; // ERRO!
```

Diversas formas de inicializar um array de char.

- Em **arr_1**, sem o caractere \0, printando esse objeto pode resultar em Ola@#%!...#@ até procurar um byte 00 (nulo) na memória "sem querer" e parar. Os símbolos representam lixo na memória. Por isso é importante o \0, para o operador *cout* parar a leitura/iteração do array no momento certo definido pelo programador, que é quando verifica se é nulo. Caso contrário o operador *cout* começará a iterar no array fora dos limites, e no C++ não há levantamento de exceção para leitura de índices fora dos limites.

- Em **arr_2** e **arr_4**, é possível inicializar sem definir um tamanho. O compilador já aloca inteligentemente o tamanho baseado no que recebe.

Também é possível também acessar índices, ou seja, derreferenciar e acessar caracteres da string. E por se tratar de uma cópia da string literal, posso também substituir esses caracteres derreferenciando.

```cpp
char arr[] = "Ola";
arr[2] = 'e';
cout << arr << endl; // Printará "Ole"
```

> Nota: Para reforçar, **array de char = string**. Portanto, para todos os exemplos desse tópico acima (incluindo o arr_1 e arr_2), são strings, mesmo definindo caractere por caractere no array. É uma string.

## char*

O char* possui semelhanças explícitas com o char[], incluindo a forma de inicializar, mas existem diferenças sucintas por trás dos panos e em algumas sintaxes de inicialização.

```cpp
char* str = "Ola";
char str[] = "Ola";
```

Qual a diferença? Será abordada no tópico **"char[] vs char*: qual utilizar?"** devida a alta complexidade e quantidade de informações. Por hora basta saber que as duas são aparentemente equivalentes, a fim de não causar confusão.

Também é possível alocar uma string na heap graças ao uso de um ponteiro na stack.

```cpp
char* arr = new char[4];
arr = "Ola";
cout << arr[2] << endl; // Printará 'a'.
delete[] arr;
```

- 12/12

https://www.google.com/search?q=%5B%5D+vs+*+c%2B%2B&ei=upaXY5vzKbqY1sQPvJixiAs&ved=0ahUKEwibuMj9_PT7AhU6jJUCHTxMDLEQ4dUDCA8&uact=5&oq=%5B%5D+vs+*+c%2B%2B&gs_lcp=Cgxnd3Mtd2l6LXNlcnAQAzIGCAAQFhAeMgYIABAWEB4yBggAEBYQHjIGCAAQFhAeMgYIABAWEB4yBggAEBYQHjIGCAAQFhAeMgYIABAWEB4yBggAEBYQHjIGCAAQFhAeOgsIABAHEB4QsAMQEzoHCAAQgAQQEzoICAAQFhAeEBM6DQgAEIAEELEDEIMBEA06BwgAEIAEEA06CggAEIAEELEDEA06CQgAEBYQHhDxBEoECEEYAUoECEYYAFDLA1jpB2CUCWgBcAB4AIABogGIAesEkgEDMC40mAEAoAEByAEKwAEB&sclient=gws-wiz-serp

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

## const char[]

O **const char[]** é o tipo de dado padrão em C++ para strings literais, porém não muito utilizado para tipos de variáveis criadas pelo programador pelo mesmo motivo do char[], a baixa performance.

Sua diferença convencional para o 'char[]' está no fato de que o "const" promete que a variável não será modificada de forma alguma. Ou seja, indexar e mudar caracteres é proibido. 

O const char[] é útil para casos onde é preciso fazer uma cópia de uma string literal, mas é preciso passar esse 'const char[]' em parâmetro de uma função, que se reduz a uma passagem por referência (abordo sobre isso no tópico *Arrays e Funções*).

```cpp
const char[] str = "Ola";
```

## const char*

O **'const char*'** é o tipo mais utilizado em C++ para casos onde a std::string não pode ser utilizada ou o sistema necessita de mais performance. O motivo do **'const char*'** ser utilizado mais que qualquer outro tipo de representação de char é o simples fato de que toda string literal em C++ é automaticamente alocada como **const char[]**, e o ponteiro para essa string literal é de apenas 8 bytes (const char*). O fato de ser *const* é para evitar que o programador modifique dados na .rodata via derreferência do ponteiro, afinal, diferente do const char[], o const char* não faz cópia alguma, pois é apenas um ponteiro, o que torna seu uso extremamente eficiente.

O fato de que as **strings** que o ponteiro aponta são **literais** (e portanto guardadas na .rodata), elas podem ser capturadas pelo ponteiros e usadas em O(1) a qualquer momento do programa.

Em C++, o **'const char*'** é somente utilizado no lugar da biblioteca convencional std::string em situações onde a performance da aplicação precisa ser priorizada, pois std::string aloca string na heap.

```cpp
const char* str = "Ola";
```

## std::string

O uso da Classe std::string é convencional no C++ para praticamente tudo, pois ela oferece uma série de métodos que podem facilitar muito o trabalho com strings.

```cpp
std::string str = "Ola";
```

Documentação não oficial mastigada:
https://www.geeksforgeeks.org/stdstring-class-in-c/

A instância de pode ser alocado tanto na Stack quanto na Heap. Porém, a string em si é guardada na heap, e todas as suas operações também são feitas na heap.

A Classe também permite fazer certas *operation overloadings*.

### Concatenação

```cpp
std::string str = "Ola" + " mundo"; // ERRO!

std::string str = "Ola";
std::string str = str + " mundo"; // OK!

std::string str = std::string("Ola") + " mundo"; // OK! Chamo o construtor da string.
```

A concateação se utiliza do *operator overloading*, que são métodos de classe que capturam o uso de operadores como "=,*,+,-,<<, >>, &, []" e por ai vai.
Mais detalhes em: https://www.geeksforgeeks.org/operator-overloading-c/

### Descobrir se tem uma string na string.

```cpp
std::string str = "Ola mundo";
bool contem = str.find("und") != std::string::npos;
```

O método *find()* retorna a posição do texto. Já o *npos* é um static const de valor -1. Se find() retornar -1, significa que será igual a npos, ou seja, não encontrou a string dentro da outra, e contem será **false**.


## Outros chars

Existem diversos outros chars. Irei trabalhar com o padrão ASCII, que também é compatível com o sistema UTF-8, que é o *char* tradicional. Mas aqui estão as definições mastigadas dos outros tipos:

- wchar_t: Trabalha com a variante UTF16-LE e é 2 bytes (16 bits) no Windows e 4 bytes (32 bits) no Linux.
- wchar_8: Basicamente um typedef do unsigned char. Trabalha com UTF-8 e é 1 byte (8 bits). Recentemente introduzido na versão C++20.
- wchar_16: Trabalha com o sistema UTF-16 e é 2 bytes (16 bits).
- wchar_32: Trabalha com o sistema UTF-32 e é 4 bytes (32 bits).
- std::wstring: Lib string que trabalha com wchar_t.

# char[] vs char*: qual utilizar?

- O char[] é um array. O char* é um ponteiro.

- O sizeof() de um char[] é a quantidade de caracteres da string. O sizeof() de um char* é 8 bytes (tamanho do ponteiro).

- Strings literais com char[] são copiados da .rodata para a pilha (para a variável char[]). Strings literals com char* não existe cópia, char é um ponteiro que apontado direto pra string literal na .rodata.

- É possível editar elementos em um char[], pois é feita uma cópia da string literal para a pilha, onde a variável do tipo char[] recebe essa cópia. Não é possível editar elementos em um char* (derreferenciar), pois o ponteiro aponta pra string literal diretamente na .rodata.

Outros exemplos:

```cpp
char arr_str[] = "Ola";
char* ptr_str = "Ola";

arr_str[0] = 'T'; // VÁLIDO.
ptr_str[0] = 'T'; // INVÁLIDO.

arr_str++; // INVÁLIDO.
ptr_str++; // VÁLIDO.

arr_str = "Mundo!" // INVÁLIDO.
ptr_str = "Mundo!" // VÁLIDO.
```

- É possível derreferenciar char[], por se tratar de uma cópia da string literal. Não é possível derreferenciar char*, pois o ponteiro aponta direto pra .rodata, onde está a string literal.

- Não é possível incrementar um array. E possível incrementar um ponteiro para acessar novos endereços.

- Não é possível reatribuir char[] ou qualquer outro array (isso teria que ser feito elemento por elemento). É possível reatribuir valores em um char*, que basicamente muda pra onde o char* aponta (lembrando que a string literal é um array com endereço, ou seja, o char* com a reatribuição passa a apontar para esse novo array "Mundo").

Mais detalhes em:
https://www.codingninjas.com/codestudio/library/whats-the-difference-between-char-s-and-char-s-in-c

# Herança do C: const virando mutável?

> Nota: ler o tópico sobre *const* e *String literal*.

Existe um único caso em todo o C++ onde é possível passar um *const 'type'* para um não-const via referẽncia.

Normalmente esse comportamento é proibido, como já falado no tópico *Const Caso 2 - Referência*.

Mas a exceção está aqui:

```cpp
char* str_ptr = "Ola mundo";
```

A string literal é um *const char[]*, e esse endereço é passado via referência (por se tratar de um array) para uma variável não const. Como isso é possível?

O principal motivo é a herança do C e a manutenção da retrocompatibilidade. O objetivo principal do C++ foi herdar tudo do C e ser um superset do C, mas a muito tempo já divergiram. Porém, o objetivo de ser compatível com o C o máximo possível ainda se mantém.

Em C, a string literal *"Ola mundo"* é trazida da .rodata como **char[]**. Isso é bizarro, dado que permite que o programador "mude" caracteres acessando índices (derreferenciando) o array de forma irrestrita, resultando em erros já discutidos no tópico das strings literais.

Porém, o C++ adicionou a keyword *const*, porém isso não resolveu o problema. Existe uma conversão implícita proposital de const char[] para char* no exemplo acima, e essa conversão implícita só é feita por conta dessa tentativa de compatibilidade com C. A IDE ou vscode podem alertar que o C++ proíbe convencionalmente essa conversão, mas ela não deixa de ser possível. Portanto, o ponteiro *str_ptr* pode ser usado para derreferenciar e mudar valores da string literal, causando Undefined Behaviours.

Agora veja esse exemplo:

```cpp
char str_arr[] = "Ola mundo";
```

Aqui a conversão também existe, mas ela não é tão grave, dado que essa operação cria um array na Stack que recebe uma cópia da string literal tirada da .rodata, como já discutido no tópico **char[] vs char*: qual utilizar?'**. Já na conversão do exemplo str_ptr, o ponteiro na Stack aponta direto pra .rodata, sem cópia nenhuma da string literal. Modificar strings na Stack ou Heap não há problema. Porém, querer modificar na .rodata é acessar um ponto de memória que o programador ou o programa não tem autorização para acessar (segmentation fault, ou falha de segmentação de memória).

Conclusão: mesmo que em C++ se abra uma exceção (por conta da retrocompatibilidade com C) e seja "permitido" atribuir a char* uma string literal (const char*), o que é bizarro e vai contra o propósito do "const", o interessante e convencional é usar a keyword **const** sempre que criar um ponteiro que aponte pra string literal ou array que receba uma cópia dessa string literal.

# Arrays Multidimensionais

Arrays multidimensionais são arrays dentro de arrays.

Irei trabalha com array de duas dimensões (2D, matriz), que são arrays dentro de um array. 

A forma como se acessa os valores de uma matriz é pareciso com o array de uma dimensão.

## Matriz na pilha

```cpp
int matriz[3][5] = {
    {2, 4, 5, 10, 1},
    {55, 23, 2, 32, 0},
    {3, 50, 90, 43, 65}
};
```

- Inicialização de uma matriz de inteiros na pilha, com 3 linhas (i) e 5 colunas (j).

```cpp
const char matriz[4][6] = {"Ola", "Mundo", "Arroz", "Feijao"}; // Caso 1
const char* matriz[] = {"Ola", "Mundo", "Arroz", "Feijao"}; // Caso 2
std::string matriz[2][2] = { // Caso 3
    {"Ola", "Mundo"},
    {"Arroz", "Feijao"}
};
```

- Caso 1: Lembrar que string é um array de caracteres. Portanto, o tamanho da linha é definido pela string com a maior quantidade de caracteres + \0. Esse tipo de inicialização faz uma cópia da string literal.

- Caso 2: Caso onde não fica explícito o tamanho da string. O char* é um ponteiro que aponta para um array contendo várias cópias de strings literais.

- Caso 3: Uso mais convencional de strings. Como o tipo std::string é um objeto em si, é possível fazer uma matriz com esses objetos sem levar em consideração que os caracteres também seriam parte de um array. É como se isso fosse, por de trás dos panos, um array 3D.

## Matriz na heap

Inicializar uma matriz na heap é mais complexo. É preciso criar um array na heap de elementos "ponteiros", e cada ponteiro desse aponta para arrays na heap de elementos normais.

Exemplo:

```cpp
// Alocando Matriz 5 x 10.
int** matriz = new int*[5]; // Array de 5 elementos na heap 
for (int i = 0; i < 5, i++){
    matriz = new int[10];  // para cada elemento, crio um array de tamanho 10.
}

// Liberando Matriz 5 x 10
for (int i = 0; i < 5; i++){ // Para deletar da heap faço a mesma coisa.
    delete[] matriz[i];
}
delete[] matriz; // Por fim, deleto o array que guardava arrays.
```

- Na hora de deletar, é importante **NÃO** deletar o array que guarda arrays diretamente, ou acarretará em memory leak, pois perderemos o conjunto de ponteiros que apontam para aquelas diversas memórias que contém arrays. Ou seja, elas ficarão lá permanentemente e perdidas até o programa encerrar.

- É preciso iterar sobre cada linha e **deletar 1 array por vez**. Após ter liberado toda essa memória para cada linha, libera por fim o array principal que guarda os ponteiros.

Esse tipo de criação de matriz é OK, mas não é otimizado, dado que cada linha dessa contém ponteiros diferentes para diversos lugares na heap que apontam para arrays que estão em segmentos distantes na memória. Ou seja, para iterar sobre isso pode ser extremamente lento.

Uma forma de resolver isso é utilizando a seguinte façanha:

```cpp
int* arr = new int[3 * 7]; // Espaço da matriz já alocado de tamanho 3 x 7.
for (int i = 0; i < 3; i++){
    for (int j = 0; j < 7; j++){
        // Acessando índices. Multiplico sempre a soma deles pela largura da matriz.
        arr[i + j * 7] = 0; // Preencho a matriz i x j com zeros
    }
}
delete[] arr;
```

- É possível criar uma representação de uma matriz em um bloco de memória só. Ou seja, em um único array. Isso otimiza absurdamente qualquer acesso que o programador queira sobre essa matriz, pois todos os elementos estarão em um bloco de memória só, com endereços lado a lado.

- Para acessar índices dessa matriz, basta substituir i ou j pelos índices da matriz desejada e multiplicar pela largura da matriz, que nesse caso é 7.

# Arrays e Funções

O objeto *array* possui comportamento diferente quando se utiliza com funções.

## Arrays como parâmetro de funções

**Todo** array passado para um parâmetro de uma função é reduzido a uma passagem por referência.

```cpp
void imprimir(int vec[]){
    
}

int main(){
    int vec[] = {2, 4, 7};
    imprimir(vec);
}
```

*char const *const *const strings

https://stackoverflow.com/questions/34174761/char-const-const-const-varname

*char const *const *const strings

## Arrays como retorno de funções

# Smart Pointers

# Entendido arrays...