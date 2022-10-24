# Ponteiros em C++
Tudo sobre ponteiros, mastigado. Tive dificuldades para entender o conceito, e por isso criei esse repositório: para basicamente treinar e fixar o conhecimento. Conhecimento adquirido através desses dois cursos:

- https://youtu.be/zuegQmMdy8M
- https://youtu.be/kiUGf_Z08RQ
- https://www.udemy.com/course/data-structures-algorithms-cpp/
- https://www.udemy.com/course/data-structures-algorithms-python/ -> Esse aqui foi usado como referência para melhor compreensão do uso de POO.

# Definições básicas

Esse readme é para mostrar conceitos básicos da programação procedural e que até hoje alguns são extremamente utilizados.
Aqui abordarei os seguintes conceitos:

- Copiar
- Referênciar
- Dereferênciar
- Declarar
- Inicializar
- Atribuir
- Instanciar
- Alocar
- Liberar
- Instanciação vs Inicialização: qual utilizar?

## Cópia

Fazer uma cópia é passar um valor de uma variável para outra variável, e elas passam a serem independentes. Ou seja, mudar o valor de uma não afetará a outra.

```cpp
int a = 10;
int b = a; // b copia a. b = 10.
```
* *b* agora é 10.
> Nota: mudar o valor de *b*, não mudará o valor de *a*.

## Referência

Uma variável é referenciada quando usa *ampersand &* e atrubi o valor capturado com *&* a uma outra variável do tipo ponteiro (int*).

```cpp
int a = 10;
int* b = &a; // b referencia a. b = 0x?????
```
* *b* agora é 0x?????. O endereço da variável *a*.
* Se mudar o valor de *b* por uma variável com *&*, muda pra onde aponta.
* Se mudar sem *&*, dará erro. Afinal, *b* só pode receber endereço, e não valores. Ele é do tipo **intponteiro*, ou simplesmente int*.
* Já se mudar o '*b', muda o valor de 'a'.

> Nota: isso ocorre, pois *b é uma variável que é criada automaticamente após *b* referenciar com &outra_variável. Ou seja, b aponta pra &a (referencia a) assim como *b é criado e agora passa a apontar pra *a*.

```cpp
int    a = 10;
int*   b = &a;
int**  c = &b;
int*** d = &c;
```

- Adivinha o valor de *&c*? Pois é, o mesmo valor de *&a*. Um endereço *0x?????* genérico na memória.
- Adivinha o valor de ***d? Pois é, o mesmo valor de *a*.
- Adivinha o valor de *d*? Pois é, o mesmo valor de *&c*, afinal, *d = &c*. E como *&c = &a, d = &a.*
- *d* aponta pra *c*, que *c* aponta pra *b*, que *b* aponta pra *a*. Ou seja, *d* "aponta" pra *a*.

## Dereferência (ou desreferência)

Dereferenciar é acessar a informação no endereço contido por um ponteiro e atribuir um valor qualquer a ele.

Conceito parecido com referência, a diferença é que se trabalha agora com valores, e não mais com endereços (ou pra quem está apontando).

```cpp
int a = 10
int b = &a // Referência
*b = 12 // Dereferência.
```

- Como *b = 12, 'a' agora passa a ser 12. Isso é dereferenciar.

## Declarar

Basicamente é só pra dizer que o objeto existe e será usado depois.

```cpp
int a; // Declaração trivial
int* b; // Declaração de ponteiro pra algum inteiro na memória
int f(int a); // Declaração de função
class Pessoa; // Declaração de classe
Pessoa person; // Declaração de um objeto.
```

## Inicializar

Inicializar é o ato de atribuir um primeiro valor a uma variável já declarada. Pode haver declaração junto com inicialização.

```cpp
int a; // Declaração
a = 10 // Inicialização
int* b; // Declaração
b = &a; // Inicialização

int** c = &b; // Declaração e inicialização. Aqui c aponta pra b, e b aponta pra a.
```

## Atribuir (assignment)

Atribuir é "inicializar" pela segunda vez, ou substituir o valor prévio de uma variável por outro.

```cpp
int a = 10;
int* b = &a;
int c = 15;

*b = 12; // Atribuição
b = &c; // Atribuição
```

- No primeiro momento, mudo o valor de *a*, que era 10, através de *b, que passa a ser 12. Isso é atribuição
- No segundo momento, mudo o valor de *b*, que era *&a*, e passa a ser *&c*. Outra atribuição. O valor de *b também muda de forma automática, passa a ser 15, mas isso não é atribuição.

## Instanciar

Instanciar é criar espaço na memória para guardar uma variável que aponta pra um tipo. Esse espaço é permanente e não encerra após o término do programa. Ou seja, pode ser acessado indefinidamente.

Em POO, ao invés de chamarmos de instanciação de tipo, chamamos de instanciação de alguma classe. E a instância criada é um objeto.

```cpp
int* obj = (int*)malloc(sizeof(int)); // C
int* obj = new int; // C++
int* obj = new int(5);
```

- Os dois casos acima são equivalentes. O primeiro é usado em C, que inclui um casting pra int*, e o outro em C++, que simplifica mais esse processo sem necessidade de casting. São alocações dinâmicas de memória. O terceiro caso extra é pra mostrar que você pode usar um "construtor" da classe *int* pra passar o valor 5. Ou seja, *obj* "terá valor" 5.
- Na verdade *obj* não tem valor de nada, por isso "terá valor" estava entre aspas. *obj* é um ponteiro que aponta pra um inteiro anônimo criado na memória, com valor 5.

```cpp
Pessoa* pessoa = (Pessoa*)malloc(sizeof(Pessoa));
Pessoa* pessoa = new Pessoa();
```

- Uso de class ou struct para instanciar objetos. Ao usar (), chamamos também o construtor da classe Pessoa. Se não tiver, não precisa usar os parênteses.
- pessoa é um ponteiro do tipo Pessoa* que aponta pra um objeto criado na memória do tipo Pessoa.

```cpp
char* vec = (char*)malloc(100 * sizeof(char)); // Vetor de tamanho 100.
char* vec = new char[100]; // Vetor de tamanho 100
```

- Aqui mostro a alocação de um vetor de 100 bytes. Lembrando que um char é 1 byte.
- *vec* é um ponteiro que aponta pro primeiro elemento do vetor alocado na memória. Nesse caso é obviamente lixo.

## Alocar

Basicamente tudo que fizemos acima também foi alocar memória. Ou seja, criamos memória para que o ponteiro aponte para aquela memória. 

> Nota: Alocar não é criar ponteiro. É criar espaço de memória para que um ponteiro aponte para aquele espaço alocado. Não se cria nem deleta ponteiros.

## Liberar (desalocar)

É o ato de deletar memória que não é mais utilizada. Todo malloc() ou new precisa estar acompanhado de um free() ou delete, ou teremos o famoso Memory Leak.

Memory leak é algo muito comum. Aconteceu recentemente, por exemplo, em jogos como GTA V, onde o programa não parava de consumir RAM de forma desenfreada, pois inúmeras instâncias de algo eram criadas e não eram deletadas logo em seguida. Algumas semanas depois foi patcheado. Google Chrome também já sofreu com isso, e tem um histórico considerável de reclamações por consumo excessivo de RAM.

Como C++ é uma linguagem que não possui coletor de lixo automático (Garbage Collector), toda vez que se instancia um objeto, é preciso deletar essa mesma instanciação no fim de um programa ou ao longo dele quando não se precisa mais daquela memória.

```cpp
int* a = (int*)malloc(sizeof(int));
free(a); // Libero memória que não será mais utilizada
int* a = new int(7);
delete a; // Libero memória que não será mais utilizada

char* vec = (char*)malloc(100 * sizeof(char));
free(vec); // Libero memória que não será mais utilizada
char* vec = new char[100];
delete[] vec; // Libero memória que não será mais utilizada
```

## Instanciação vs Inicialização: qual utilizar?

```cpp
Pessoa pessoa1;
pessoa1.nome = "João";
pessoa1.idade = 20;
/////////////////
Livro* calculo = new Livro;
calculo->titulo = "O calculo com Geometria Analitica"
calculo->autor = "Leithold"
delete calculo;
```

Qual dos dois usar? Quando usar?

Ao declarar e inicializar um objeto normal e cru, você está declarando algo que só funcionará naquela função específica. Ou seja, quando a função ou algoritmo acabar, ele não existirá mais. É basicamente alocada uma memória temporária pra guardar o objeto que se perderá em breve. É mais utilizado para criar objetos de controle 'aux' (ou temp) que não serão utilizados a não ser pra isso.

Já ao instanciar um objeto, ele poderá ser acessado dentro e fora de classes, funções, métodos, na função main, por outros arquivos... e todos os seus atributos também poderão ser utilizados. O problema disso é o risco de se criar inúmeros objetos da mesma classe, e como eles não são apagados automaticamente, ocorre um Memory Leak e consumo excessivo de RAM.

Um exemplo clássico de uso de instanciação é ao utilizar uma classe ListaEncadeada. É impossível criar uma lista encadeada apenas com declaração e inicialização, pois nenhum método de uma classe dessas ou outras classes poderiam ter acesso a atributos e nós de uma lista encadeada, afinal, não teria ponteiros para referenciar esses valores de longe.

Em programas como Python e Java, ao instanciar um objeto, todos os atributos daquele objeto são passados por referência através do "self" ou "this" de forma automática, sem precisar usar ponteiros para isso. Por isso é possível criar estrutura de dados nessas linguagens, mesmo elas não utilizando ponteiros. As linguagens mais avançadas já entendem que certas coisas devem passadas por cópia, e outras por referência sem precisar explicitar o asterisco ou ampersand.

> Nota: é possível passar valores por cópia para um objeto em C++, como mostra o primeiro exemplo com *pessoa1*, mas não é muito utilizado, e é altamente desaconselhado o uso. Normalmente outras linguagens mais modernas, como já falado antes, já faz por referência, só que utilizando o '.' ao invés do '->'. Já no C++, o '.' é de fato cópia, enquanto que em Java ou Python, o '.' é referência.

### Ou seja...

- Usar declaração e inicialização apenas para variáveis locais e de pouca importância. Pode usar também para variáveis de controle, tipo um armazenamento temporário de um nó;
- Não usar declaração e inicialização para objetos mais complexos, como classes robustas, pois terá pouca utilidade e pode gerar erros;
- Usar instanciação para guardar valores importantes na memória e poder utilizá-los onde bem entender, e só deletar quando o programador quiser;
- Não usar instanciação para valores temporários ou de pouca relevância.