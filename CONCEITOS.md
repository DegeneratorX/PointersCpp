# Conceitos Básicos de C++

## Cópia

Fazer uma cópia é passar um valor de uma variável para outra variável, e elas passam a serem independentes. Ou seja, mudar o valor de uma não afetará a outra.

```cpp
int a = 10;
int b = a; // b copia a. b = 10.
```
* *b* agora é 10.
> Nota: mudar o valor de *b*, não mudará o valor de *a*.

## Referência

Uma variável é referenciada quando usa *ampersand &* e atrubi o valor capturado com *&* a uma outra variável do tipo ponteiro que aponta pra inteiro - int*. Esse tipo só aceita endereços e nada mais, que é um tipo especial de valor.

```cpp
int a = 10;
int* b = &a; // b referencia a. b = 0x?????
```
* *b* agora é 0x?????. O endereço da variável *a*.
* Se mudar o valor de *b* por uma variável com *&* (exemplo, *&c*), muda pra onde aponta (no caso apontará pra *c*).
* Se mudar sem *&*, dará erro. Afinal, *b* só pode receber endereço, e não valores. Ele é do tipo intptr, ou simplesmente int*.
* Já se mudar o *b pra 12, por exemplo (derreferência), muda o valor de 'a' para 12 também.

```cpp
int    a = 10;
int*   b = &a;
int**  c = &b;
int*** d = &c;
```

- Adivinha o valor de *&c*? Pois é, o mesmo valor de *&a*. Um endereço *0x?????* genérico na memória.
- Adivinha o valor de ***d? Pois é, o mesmo valor de *a*.
- Adivinha o valor de *d*? Pois é, o mesmo valor de *&c*, afinal, *d = &c*.
- *d* aponta pra *c*, que *c* aponta pra *b*, que *b* aponta pra *a*. Ou seja, *d* "aponta" pra *a*.


## Derreferência (ou deferência)

Dereferenciar é acessar a informação no endereço contido por um ponteiro e atribuir um valor qualquer a ele.

```cpp
int a = 10
int b = &a // Referência
*b = 12 // Dereferência.
```

- Como *b = 12, 'a' agora passa a ser 12. Isso é derreferenciar.

## Declarar

Basicamente é só pra dizer para o compilador que o objeto existe e será usado depois.

```cpp
int a; // Declaração trivial
int* b; // Declaração de ponteiro pra algum inteiro na memória
int& c; // ERRO: apesar de que dá pra fazer isso com parâmetro de funções.
int f(int a); // Declaração de função que retorna um tipo inteiro
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

Atribuir é "inicializar" pela segunda vez até n vezes, ou substituir o valor prévio de uma variável por outro.

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

Instanciar é criar espaço na memória para guardar uma variável que aponta pra um tipo. Esse espaço é permanente e não encerra após o término de uma função. Ou seja, pode ser acessado fora do escopo dela.

Em POO, ao invés de chamarmos de instanciação de tipo, chamamos de instanciação de alguma classe. E a instância criada é um objeto de uma classe.

```cpp
int* obj = (int*)malloc(sizeof(int)); // C
int* obj = new int; // C++
int* obj = new int(5);
```

- Os dois casos de C e C++ acima são equivalentes. 
- O primeiro é usado em C, que inclui um casting pra int* de uma memória alocada do tamanho de um inteiro (4 bytes). malloc() retorna um ponteiro do tipo void*, e o casting para int* serve justamente para que esse ponteiro possa apontar pra um inteiro. E o obj recebe o mesmo endereço que malloc retornou, ou seja, obj agora aponta pra esse mesmo objeto inteiro anônimo que foi criado pelo malloc.
- O segundo é usado em C++, que simplifica mais esse processo sem necessidade de casting, pois já faz tudo por trás, com o operador **new**. Ambos são alocações dinâmicas de memória e fazem exatamente a mesma coisa. 
- O terceiro caso extra é pra mostrar que você pode usar um "construtor" da classe *int* pra passar o valor 5. Ou seja, *obj* "terá valor" 5.
- Na verdade *obj* não tem valor de nada, por isso "terá valor" estava entre aspas. *obj* é um ponteiro que aponta pra um inteiro anônimo criado na memória, do tipo int e com valor 5.
> Lê-se: *obj* é um tipo ponteiro que aponta pra um tipo int anônimo na memoria (int*), geralmente lixo. Ao "igualar" a um novo inteiro, o *obj* recebe o mesmo endereço desse novo (new) objeto do tipo inteiro (int) criado, e com atributos devidamente alocados (5, métodos da classe int, etc). Lembrando que new retorna um endereço.

```cpp
Pessoa* pessoa = (Pessoa*)malloc(sizeof(Pessoa)); // C
Pessoa* pessoa = new Pessoa(); // C++
```

- Uso de class ou struct para instanciar objetos. Ao usar (), chamamos também o construtor da classe Pessoa. Se não tiver, não precisa usar os parênteses.
- pessoa é um ponteiro do tipo Pessoa* que aponta pra um objeto criado e alocado na memória do tipo Pessoa.

```cpp
char* vec = (char*)malloc(100 * sizeof(char)); // Vetor de tamanho 100.
char* vec = new char[100]; // Vetor de tamanho 100
```

- Aqui mostro a alocação de um vetor de 100 bytes. Lembrando que um char é 1 byte.
- *vec* é um ponteiro que aponta pro primeiro elemento do vetor alocado na memória. Nesse caso é obviamente lixo, pois o vetor não foi preenchido.

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
// PAREI AQUI
## Instanciação vs Inicialização: qual utilizar?

Existem 3 tipos de inicialização de uma classe. Qual dos três usar? Quando usar?

### Inicialização 1: memória estática

```cpp
Pessoa pessoa1;
pessoa1.nome = "João";
pessoa1.idade = 20;
```

- Ao declarar e inicializar um objeto normal e cru, você está declarando algo que só funcionará naquela função específica. Ou seja, **quando a função ou algoritmo acabar, ele não existirá mais**. É basicamente alocada uma memória temporária e estática pra guardar o objeto que se perderá em breve. É mais utilizado para criar objetos de controle 'aux' (ou temp) que não serão utilizados a não ser pra isso.

### Inicialização 2: memória estática de um ponteiro

```cpp
Pessoa* pessoa2;
pessoa2->nome = "Felipe"; // ERRO!!!!
pessoa2->idade = 18
```

- Ao declarar e inicializar um objeto que aponta pra um tipo Pessoa, no modo como foi apresentado acima, atribuindo valores diretamente, dará erro, pois não tem memória alocada para passar esses atributos. A única forma de realmente fazer o caso acima é se:

```cpp
Pessoa* pessoa2;
Pessoa* pessoa1 = new Pessoa;
pessoa2 = pessoa1;
pessoa2->nome = "Felipe";
pessoa2->idade = 18;
```

- Passando por referência um objeto do tipo Pessoa* (pessoa1) para outro objeto do tipo Pessoa* (pessoa2), *pessoa2* passa a apontar pro mesmo objeto que *pessoa1* aponta, pois você está passando as propriedades de pessoa1 para pessoa2.
- Se mudar qualquer atributo em *pessoa2*, muda também em *pessoa1*, afinal os dois apontam pro mesmo lugar, pois essa inicialização é por referência. Como *pessoa1* é um ponteiro, então não precisa do ampersand & pra passar por referência. Somente igualar já é suficiente, pois são do mesmo tipo 'Pessoa*'.

### Inicialização 3: memória dinâmica (instanciação)

```cpp
Pessoa* pessoa3 = new Pessoa;
pessoa3->nome = "Carlos";
pessoa3->idade = 31
delete pessoa3;
```

- Já ao instanciar um objeto, ele poderá ser acessado dentro e fora de classes, funções, métodos, na função main, por outros arquivos... e todos os seus atributos também poderão ser utilizados. O problema disso é o risco de se criar inúmeros objetos da mesma classe, e como eles não são apagados automaticamente, ocorre um Memory Leak e consumo excessivo de RAM enquanto o programa estiver rodando.

![image](https://user-images.githubusercontent.com/98990221/197656441-91f55da2-9450-407b-a6c1-836162423b14.png)

- Um exemplo clássico de uso de instanciação é ao utilizar uma classe ListaEncadeada. É impossível criar uma lista encadeada apenas com declaração e inicialização, pois nenhum método de uma classe dessas ou outras classes poderiam ter acesso a atributos e nós de uma lista encadeada, afinal, não teria ponteiros para referenciar esses valores de longe.

- Em programas como Python e Java, ao instanciar um objeto, todos os atributos daquele objeto são passados por referência através do "self" ou "this" de forma automática, sem precisar usar ponteiros para isso. Por isso é possível criar estrutura de dados nessas linguagens, mesmo elas não utilizando ponteiros. As linguagens mais avançadas já entendem que certas coisas devem passadas por cópia, e outras por referência sem precisar explicitar o asterisco ou ampersand.

> Nota: é possível passar valores por cópia para um objeto em C++, como mostra o *Primeiro tipo* com *pessoa1*, mas não é muito utilizado, e é altamente desaconselhado o uso. Normalmente outras linguagens mais modernas, como já falado antes, já faz por referência, só que utilizando o '.' ao invés do '->'. Já no C++, o '.' é de fato cópia, enquanto que em Java ou Python, o '.' é referência.

### Ou seja...

- Usar declaração e inicialização **apenas** para variáveis locais e de pouca importância. Pode usar também para variáveis de controle, tipo um armazenamento temporário de um nó;
- **Não usar** declaração e inicialização para objetos mais complexos, como classes robustas, pois terá pouca utilidade e pode gerar erros;
- Usar instanciação para guardar valores importantes na memória e poder utilizá-los onde bem entender, e só deletar quando o programador quiser;
- **Não usar** instanciação para valores temporários ou de pouca relevância.


> Nota: a função malloc() é do tipo void*, ou seja, retorna um ponteiro do tipo void*.

```cpp
void* ptr_coringa = malloc(sizeof(int));
int* ptr_pra_int = (int*)ptr_coringa;
```