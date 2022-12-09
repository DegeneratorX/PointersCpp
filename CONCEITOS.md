# Conceitos de C++

Reuni os conceitos mais falados de C++ e que servem inclusive para outras linguagens.

Requisitos para entender esse arquivo:
- Programação básica e procedural em C/C++
- POO em qualquer linguagem derivada do C++ (Java, Python)
- Ler o arquivo README.md nesse rep


## lvalue

lvalue é um objeto que é identificado na memória e capaz de armazenar dado. Pode aparecer tanto no lado esquerdo quanto lado direito da expressão, e pode existir ao longo da execução do programa.

```cpp
int x = 10;
int a = x;
```

*x* nesse caso seria um lvalue, e *a* também. Podem Aparecer tanto no lado esquerdo quanto direito da expressão.


## rvalue

rvalue é um objeto constante, ou seja, não pode ser modificado e nem armazena memória. Não pode ser colocado no lado esquerdo da expressão, somente no direito.


```cpp
int x = 10; // O 10 é uma constante de valor puro, um rvalue.
True // rvalue
5==10 // Retorna um bool. É um rvalue
"Olá" // rvalue
int 10 = 5 // Não posso simplesmente mudar o valor constante de 10 pra 5.
```


## Cópia

Fazer uma cópia é passar um valor de uma variável para outra variável, e elas passam a serem independentes. Ou seja, mudar o valor de uma não afetará a outra.

```cpp
int a = 10;
int b = a; // 'b' copia 'a' (ou 'b' recebe 'a'). Agora b = 10.
```
* *b* agora é 10.
> Nota: mudar o valor de *b* não mudará o valor de *a*.


## Referência

Uma variável é referenciada quando usa o **operador** *ampersand &* e atrubi o valor com o operador *&* a uma outra variável do tipo ponteiro que aponta pra inteiro - int*. Esse tipo só aceita endereços e nada mais, que é um tipo especial de valor, e por isso que ele pode receber variáveis com &. Esse conceito já foi discutido no **README.md**.

```cpp
int a = 10;
int* b = &a; // b referencia a. b = 0x?????
```
* *b* agora é 0x?????. Passa a guardar o endereço da variável *a*.
* Se mudar o valor de *b* por uma variável com *&* (exemplo, *&c*), muda pra onde aponta (no caso apontará pra *c*).
* Se mudar sem *&*, dará erro. Afinal, *b* só pode receber endereço, e não valores, pois *b* é do tipo intpointer (int*).


Eis um exemplo mais extremo:

```cpp
int    a = 10;
int*   b = &a;
int**  c = &b;
int*** d = &c;
```

- Adivinha o valor de ***d? Pois é, o mesmo valor de *a*.
- Adivinha o valor de *d*? Pois é, o mesmo valor de *&c*, afinal, *d = &c*.
- *d* aponta pra *c*, que *c* aponta pra *b*, que *b* aponta pra *a*. Ou seja, *d* "aponta" pra *a*.


## Derreferência (ou deferência)

Dereferenciar é acessar o conteúdo/a informação no endereço contido por um ponteiro e atribuir um valor qualquer a ele. Isso é feito através do operador '*'. Esse conceito já foi discutido no **README.md**.

```cpp
int a = 10
int b = &a // Referência
*b = 12 // Dereferência.
```

Se mudar o *b pra 12, por exemplo (derreferência), muda o valor de 'a' para 12 também. ' *b' é o conteúdo de 'a'. 'b' guarda e referencia o endereço de 'a'.

Eis o mesmo exemplo extremo:

```cpp
int    a = 10;
int*   b = &a;
int**  c = &b;
int*** d = &c;
```

Relembrando que d aponta indiretamente para a, é possível acessar o conteúdo de a através de d. Basta usar o operador de derreferência 3 vezes: * ( * ( * d)), ou ***d.

Ao printar ***d, resultará no valor 10. Ao printar **d, resultará no endereço de 'a', que é o conteúdo de b. E obviamente, ao printar *d, resulta no conteúdo de c.

## Construtor

Construtor é um método especial de uma Classe que define os principais atributos de um objeto (instância) criado dessa Classe. Como dito anteriormente, é recomendado entender POO para compreender mais os tópicos que vem adiante.

```cpp
class Pessoa{
public:
    Pessoa(){} // Construtor
}
```

O construtor (e destrutor) levam o mesmo nome da Classe, e por não terem objetivo de retornarem algo, não precisam de um tipo específico.

Construtores em C++, diferente de outras linguagens com foco mais pesado em POO, como Python e Java, não aparecem em tipos primitivos de dados, como **int**, **float** e **char**, devido a herança do C, porém algo "parecido" existe:

```cpp
int valor(10); // Exemplo de "construtor" de um int.
```

> Nota: isso não é construtor, é uma inicialização, mas é como se fosse um construtor.

Construtor aparece de fato em objetos que possuem tipo não-primitivo de dados. Ou seja, em Classes criadas pelo programador.

```cpp
class Pessoa{
public:
    Pessoa(){} // Construtor
}

int main(){
    Pessoa p; // Automaticamente chama o construtor.
    Pessoa p(); // Forma alternativa de chamar o construtor.
    Pessoa p = Pessoa(); // Outra forma alternativa.
}
```

> Nota: se o objeto não possuir construtor escrito na classe, o C++, em tempo de compilação, cria um método construtor vazio no momento que vê a declaração **Pessoa p**. Pois ao declarar um objeto com tipo não primitivo de dado (Pessoa), o compilador também aloca memória (estática em compilação na pilha, dinâmica em execução na heap) para esse objeto. Declarar um objeto (lvalue) como tipo primitivo de dado não aloca memória. Tudo isso será abordado mais abaixo.

## Declarar

Basicamente é só pra dizer para o compilador que o objeto existe, é único e poderá ser usado depois.

No caso de declaração de objetos de uma Classe (tipo não-primitivo de dado), o compilador trata isso automaticamente como instanciação de uma classe (será mais detalhado abaixo), e esse é o único caso onde é feito um preparo no espaço da memória junto com declaração. Declaração de tipos primitivos reservam espaço na memória apenas ao inicializar valores.

```cpp
int a; // Declaração trivial. Não aloca memória.
int* b; // Declaração de ponteiro pra algum inteiro na memória. Não aloca memória.
int& c; // ERRO: apesar de que dá pra fazer isso com parâmetro de funções.
int f(int a); // Declaração de função que retorna um tipo inteiro. Não aloca memória.
class Pessoa; // Declaração de classe. Não aloca memória.
Pessoa person; // Declaração de um objeto de uma classe Pessoa. Também é uma instanciação. Aloca memória estática na pilha.
int z = int(); // Declaração não convencional, com parênteses vazio ("construtor"). Não aloca memória.
```

> Nota: o caso 'int z() = int();' fará mais sentido logo abaixo.


## Inicializar

Inicializar é o ato de atribuir um primeiro valor a uma variável já declarada. Pode haver declaração junto com inicialização.

```cpp
int a; // Declaração
a = 10 // Inicialização. É alocada memória estática na pilha.
int* b; // Declaração
b = &a; // Inicialização. É alocada memória estática na pilha.
int** c = &b; // Declaração e inicialização. Aqui c aponta pra b, e b aponta pra a.


int* x; // Declaração. Não aloca memória.
x = new int(22); // Inicialização. É alocada memória estática na pilha e memória dinâmica na heap.
int* y = new int(15); // Declaração e inicialização. É alocada memória estática na pilha e memória dinâmica na heap.
```

> Nota: o uso do **new** e a alocação dinâmica de memória serão detalhados mais abaixo.

Além disso, existem diversos outras formas de inicializar e declarar variáveis:

```cpp
int valor(10); // Declaração e inicialização. Desaconselhado o uso. Aloca memória estática na pilha.
int valor = int(10); // Declaração e inicialização. Apenas não convencional. Aloca memória estática na pilha.
Pessoa person = Pessoa(); // Declaração e inicialização. Aloca memória estática na pilha.
```

- Perceba que uso um "construtor" que passa 10 pro 'valor'. São formas alternativas de inicializar, equivalentes a *'int valor = 10'*, e as duas estão corretas e fazem a mesma coisa.

> Nota: o primeiro caso pode ser confundido com uma função, e portanto seu uso não é convencional e é desaconselhado. Porém, o compilador sabe a diferença. Se não tiver escopo {} e for passado **rvalues** diretamente, é uma variável estática sendo inicialziada. Caso contrário, é uma declaração de função. Não é possível apenas declarar dessa forma, por exemplo, apenas colocando 'int valor();', pois nesse caso o compilador entende como declaração de função, e não é possível inicializar depois.

Em POO, normalmente as Classes são tratadas como tipo de variável criado pelo próprio programador, o que não deixa de ser verdade. Mas o contrário não ocorre em C++, pois nem todo tipo de variável é uma Classe. Porém, isso ocorre em Python, Java, etc. 

Por exemplo, *int* em Python ou Java é considerada uma Classe que possui vários métodos internos para manipular esses valores. Já em C++, *int* ainda é um tipo primitivo de dado herdado do C. Portanto, considerar *int* como Classe em C++ é errado na teoria. Mas na prática, se pensarmos assim, facilita o entendimento da criação de objetos e do uso de "construtores" diretamente sobre o tipo primitivo de dado.


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


## Alocar

O ato de alocar significa preparar um bloco de memória específico na memória RAM para depois jogar dados lá.

Existe dois tipos de alocações:
- Estática e temporária: feito numa pilha dentro da memória RAM.
- Dinâmica e permanente: feito numa heap dentro da memória RAM.

A forma como se implementa essas alocações é bem detalhada nos tópicos seguintes, e irá ficar mais compreensível.


## Instanciar

Instanciar é criar um objeto de uma Classe específica. Quando dizemos "instanciar a Classe", significa que estamos criando um objeto do tipo "Classe".

```cpp
class Pessoa{
};

int valor; // "Instanciação" de uma "classe" int. Não aloca memória.
Pessoa p1; // Instanciação de uma classe Pessoa. Aloca memória estática na pilha.
Pessoa* p2 = new Pessoa(); // Instanciação de uma classe Pessoa. Aloca memória dinâmica na heap.
```

> Nota: A partir de agora, para os exemplos com uso de Classes, suponha que todas as Classes apresentadas nos exemplos tenham atributos e métodos funcionais e fictícios pré-definidos e preenchidos no escopo. Não irei colocar o código completo de uma Classe, pois isso iria ficar massante, e a ideia é simplificar a explicação e ir direto ao ponto. Portanto, os códigos abaixo são hipotéticos e, por motivos óbvios, não irão funcionar em um programa real.

### Instanciação sem ponteiros

A instanciação sem uso de ponteiros envolve você simplesmente declarar o objeto, e ao inicializar seus atributos, os dados são alocados na Pilha da memória da RAM, que possui aproximadamente 2MB.


```cpp
class Pessoa{}; // Suponha que essa classe esteja completa, com atributos e métodos.
Pessoa p1; // Prepara espaço estático na pilha dizendo pro compilador que existe p1.
p1.nome = "Zé" // Joga dados nesse espaço criado na pilha
p1.correr(5) // Executa o método 'correr' 5km/h.

int valor; // Não há preparo de espaço na pilha, apenas diz pro compilador que existe.
valor = 10; // Aloca dados nesse espaço criado na pilha e joga 10 para o espaço alocado.
```

Existem diversas formas de instanciar uma Classe.

```cpp
class Pessoa{};
Pessoa p1; // Forma 1. Executa o construtor implicitamente.
Pessoa p1(); // Forma 1.1. Age igual o de cima. Parênteses opcional.

Pessoa p2("Zé", 18) // Forma 2. Executa o construtor diretamente.
Pessoa p2 = Pessoa("Zé", 18) // Forma 3. Executa o construtor diretamente.
```
> Nota: absolutamente **QUALQUER** instância criada executa o construtor de uma Classe. Então *Pessoa p1;* executa um construtor da classe Pessoa, sem passar nenhum argumento. Se a Classe não tiver construtor, o compilador cria em tempo de compilação um construtor vazio da Classe.

Exemplo real que prova que o construtor SEMPRE executa:

```cpp
class Pessoa{
public: Pessoa(){std::cout << "Fui executado" << std::endl;} // Construtor
};
int main(){Pessoa p1;} // Executa o construtor mesmo declarando
```

> Output: Fui executado


### Instanciação com ponteiros - Estática



### Instanciação com ponteiros - Dinâmica

A instanciação com ponteiros de forma dinâmica envolve alocar espaço na Heap e retornar um ponteiro para aquele local alocado dentro da Heap. A heap fica localizada também na memória RAM, e seu espaço é ilimitado até a RAM estourar. Esse espaço alocado é permanente e não encerra após o término de uma função. Ou seja, pode ser acessado fora do escopo dela.

> Nota: falo sobre armazenamento em Pilha e Heap no último tópico desse arquivo. Por hora, basta saber que inicializar qualquer coisa estática é alocar memória na Pilha, e inicializar qualquer coisa dinâmica é alocar memória na Heap.

```cpp
int* obj = (int*)malloc(sizeof(int)); // C
```

```cpp
int* obj = new int; // C++
int* obj = new int() // C++, parênteses opcional
int* obj = new int(5); // Inicialização
```

- Os dois casos de C e C++ acima são equivalentes.


- O primeiro caso é usado em C, que inclui um casting pra int* de um ponteiro que aponta para uma memória alocada do tamanho de um inteiro (4 bytes). malloc() retorna um ponteiro do tipo void*, que aponta para o endereço onde a memória foi alocada, e o casting para int* serve justamente para que esse o compilador saiba para que tipo de dado esse ponteiro aponta. E o obj, por ser um ponteiro, pode receber o mesmo endereço que malloc retornou, ou seja, obj agora aponta pra esse mesmo objeto inteiro anônimo que foi criado pelo malloc.

- O segundo caso é usado em C++, que simplifica mais esse processo sem necessidade de casting, pois já faz tudo por trás, com o operador **new**. Ambos são alocações dinâmicas de memória e fazem exatamente a mesma coisa.

- O terceiro e quarto caso são para mostrar que você pode usar um "construtor" da "Classe" *int* pra passar o valor 5 (ou nada). Ou seja, o conteúdo de obj (*obj) terá valor 5. 'obj' por si só recebe um endereço, que é o endereço de onde está localizado esse novo inteiro. 'obj' é um ponteiro para um inteiro (inicialmente lixo), recebe um endereço de outro objeto int, e a partir daí passa a apontar para esse inteiro anônimo criado na memória, do tipo int e com valor 5.

> Lê-se: *obj* é um tipo ponteiro para um inteiro que aponta pra um tipo int anônimo na memoria (int*), geralmente lixo. Ao "igualar" a um novo inteiro, o *obj* recebe o mesmo endereço desse novo (new) objeto do tipo inteiro (int) criado, e com atributos devidamente alocados (5, métodos da classe int, etc). Lembrando que new retorna um endereço do tipo void* (pq ele precisa apontar pra qualquer tipo de memória alocada inicialmente), e é feito um casting automático para int*.

```cpp
Pessoa* pessoa = (Pessoa*)malloc(sizeof(Pessoa)); // C
pessoa->Pessoa() // Construtor
```

```cpp
// C++. Faz a mesma coisa das duas linhas de código acima.
Pessoa* pessoa = new Pessoa(); // Pessoa() é o construtor.
```

#PAREI AQUI

- Uso de class ou struct para instanciar objetos. O uso dos parênteses em Pessoa() é opcional desde que não precise passar nada pelo construtor.
- pessoa é um ponteiro do tipo Pessoa* que passa a apontar para um objeto criado e alocado na memória do tipo Pessoa.

```cpp
char* vec = (char*)malloc(100 * sizeof(char)); // Vetor de tamanho 100.
char* vec = new char[100]; // Vetor de tamanho 100
```

- Aqui mostro a alocação de um vetor de 100 bytes. Lembrando que um char é 1 byte.
- *vec* é um ponteiro que aponta pro primeiro elemento do vetor alocado na memória. Nesse caso é obviamente lixo, pois o vetor não foi preenchido.

> Nota: a função malloc() é do tipo void*, ou seja, retorna um ponteiro do tipo void*.

```cpp
void* ptr_coringa = malloc(sizeof(int));
int* ptr_pra_int = (int*)ptr_coringa;
```

## Liberar (desalocar)

É o ato de retirar dados armazenados da memória RAM que não serão mais utilizados. Todo **malloc()** ou **new** precisa estar acompanhado de um **free()** ou **delete**, ou teremos o famoso Memory Leak.

Memory leak é algo muito comum. Em jogos massivos como GTA V, o uso de memória RAM é alto, pois em uma cidade de mundo aberto temos vários objetos, várias instâncias atuando em um raio ao redor do jogador. E quando esses objetos saem do alcance do jogador, são deletadas para liberar memória, caso contrário o jogo pode crashar devido ao alto consumo de memória. O navegador Google Chrome também já sofreu com isso, e tem um histórico considerável de reclamações por consumo excessivo de RAM.

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


# Instanciação vs Inicialização: qual utilizar?

Existem 3 tipos de inicialização de uma classe. Qual dos três usar? Quando usar?


## Inicialização 1: memória estática

```cpp
Pessoa pessoa1;
pessoa1.nome = "João";
pessoa1.idade = 20;
```

- Ao declarar e inicializar um objeto normal e cru, você está declarando algo que só funcionará naquela função específica. Ou seja, **quando a função ou algoritmo acabar, o objeto não existirá mais**. É basicamente alocada uma memória temporária e estática pra guardar o objeto que se perderá em breve. É mais utilizado para criar objetos de controle 'aux' (ou temp) que não serão utilizados a não ser para isso.


## Inicialização 2: memória estática de um ponteiro

```cpp
Pessoa* p2;
p2->nome = "Zé"; // ERRO!!!!
p2->idade = 18
```

- Ao declarar e inicializar um objeto que aponta pra um tipo Pessoa, no modo como foi apresentado acima, atribuindo valores diretamente, dará erro, pois não tem memória alocada dinamicamente para passar esses atributos. A única forma de realmente fazer o caso acima é se:

```cpp
Pessoa* p2;
Pessoa* p1 = new Pessoa;
p2 = p1; // p2 recebe o endereço de p1, portanto, aponta pro mesmo lugar onde p1 aponta.
p2->nome = "Zé";
p2->idade = 18;
```

- Passando por referência um objeto do tipo Pessoa* (pessoa1) para outro objeto do tipo Pessoa* (pessoa2), *pessoa2* passa a apontar pro mesmo objeto que *pessoa1* aponta, pois você está passando o endereço de pessoa1 para pessoa2.
- Se mudar qualquer atributo em *pessoa2*, muda também em *pessoa1*, afinal os dois apontam pro mesmo lugar, pois essa inicialização é por referência. Como *pessoa1* é um ponteiro, então não precisa do ampersand & pra passar por referência. Somente igualar já é suficiente, pois são do mesmo tipo 'Pessoa*'.


## Inicialização 3: memória dinâmica (instanciação)

```cpp
Pessoa* pessoa3 = new Pessoa;
pessoa3->nome = "Carlos";
pessoa3->idade = 31
delete pessoa3;
```

- Já ao instanciar um objeto, ele poderá ser acessado dentro e fora de classes, funções, métodos, na função main, por outros arquivos... e todos os seus atributos também poderão ser utilizados. O problema disso é o risco de se criar inúmeros objetos da mesma Classe, e como eles não são apagados automaticamente, pode ocorrer um Memory Leak e consumo excessivo de RAM enquanto o programa estiver rodando.

![image](https://user-images.githubusercontent.com/98990221/197656441-91f55da2-9450-407b-a6c1-836162423b14.png)

- Um exemplo clássico de uso de instanciação é ao utilizar uma classe ListaEncadeada. É impossível criar uma lista encadeada apenas com declaração e inicialização, pois nenhum método de uma classe dessas ou outras classes poderiam ter acesso a atributos e nós de uma lista encadeada, afinal, não teria ponteiros para referenciar esses valores de longe.

- Em programas como Python e Java, ao instanciar um objeto, todos os atributos daquele objeto são passados por referência através do "self" ou "this" de forma automática, sem precisar usar ponteiros para isso. Por isso é possível criar estrutura de dados nessas linguagens, mesmo elas não utilizando ponteiros. As linguagens mais avançadas já entendem que certas coisas devem passadas por cópia, e outras por referência sem precisar explicitar o asterisco ou ampersand.

> Nota: O tópico 'Inicialização 1' com atribuições a *p1* feita com ponto (.) não é comum, e é desaconselhado seu uso. Normalmente outras linguagens mais modernas, como já falado antes, já fazem por referência, só que utilizando o '.' ao invés do '->'. Já no C++, o '.' é de fato cópia, enquanto que em Java ou Python, o '.' é referência.


## Ou seja...

- Instanciar sem ponteiros é aconselhado **apenas** para variáveis locais e de pouca importância. Pode usar também para variáveis de controle, tipo um armazenamento temporário de um nó de uma lista encadeada;
- **Não usar** declaração e inicialização para objetos mais complexos, como classes robustas, pois terá pouca utilidade e pode gerar erros;
- Usar instanciação para guardar valores importantes na memória e poder utilizá-los onde bem entender, e só deletar quando o programador quiser;
- **Não usar** instanciação para valores temporários ou de pouca relevância.


# Pilha (Stack) vs Heap na RAM (Random Access Memory)

Uma memória RAM possui duas principais estrutura de dados. A **Pilha**, que o compilador reserva cerca de 2MB de dados de forma estática, e a **Heap**, que armazena dados indefinidamente de forma dinâmica.

Elas são duas estruturas muito diferentes, mas fazem a mesma coisa. O programador pede um bloco de memória com um tamanho específico, e o compilador nos dá esse bloco de memória se tudo der certo. A diferença está na forma como essa memória é alocada. E sem contar que alocação e inicialização na Pilha é somente um comando *(int x = 10)*, enquanto que na Heap são diversos, incluindo *malloc()* e uso de ponteiros.

```cpp
int valor = 5; // aloca memória da Pilha e coloca o valor 5 lá
int* heap_valor = new int; // aloca memória na Heap (malloc)
*heap_valor = 5; // coloca o valor 5 na heap

int array[5]; // aloca memória na Pilha de 20 bytes (4 bytes x 5 inteiros)
int* heap_array = new int[5]; // aloca memória na Heap
```

Mesma coisa vale para objetos de classes.

```cpp
struct Vector3{float x, y, z;};

Vector3 vec; // aloca memória na Pilha
Vector3* vec = new Vector3; // aloca memória na Heap
delete[] vec;
```

- Alocar na pilha é uma alocação estática de memória (ocorre em tempo de compilação), enquanto que na Heap é uma alocação dinâmica de memória (ocorre em tempo de execução).
- A pilha possui memória de duração automática (temporária), enquanto que na Heap possui memória de duração dinâmica.

## Pilha

Alocação em Pilha é extremamente rápida e feita em tempo de compilação, pois os valores ficam exatamente um ao lado de outro na memória, como uma pilha mesmo. Então seu acesso é bem fácil e rápido. O ponteiro para o topo da pilha basicamente anda pro lado e vai atribuindo os valores.

A desvantagem é o limite do uso de memória. Ao estourar essa memória, temos um estouro de pilha (stack overflow).

```cpp
int value = 10; // 0x7fffffffdce4  
int array[5];
array[0] = 1; // 0x7fffffffdcf4
array[1] = 2; // 0x7fffffffdcf8
array[2] = 3; // 0x7fffffffdcfc
array[3] = 4; // 0x7fffffffdd00
array[4] = 5; // 0x7fffffffdd04
```

- Estão literalmente próximos uns dos outros na memória, incluindo o 'value' próximo do array.

> Nota: perceba que o endereço pula de 4 em 4 bytes, justamente o sizeof de um inteiro. O ponteiro do topo da pilha retorna o primeiro endereço, o primeiro byte. O resto não interessa. A partir desse primeiro endereço (1 byte), eu leio os outros 3 bytes e tenho a informação do inteiro completa.

- Outra coisa é que alocação na pilha faz com que o objeto dentro do escopo seja deletado (free) assim que o escopo acaba.

```cpp
{
    int x = 10; // Alocação na pilha
}
// x não existe mais.
```

## Heap

Alocação em Heap é mais lenta e feita em tempo de execução, mas não possui limite de memória, e o objeto alocado dessa forma pode ser acessado pelo programa todo.

O limite do uso de memória é justamente a própria memória RAM do computador. Se o programa consumir 2GB de ram, muito provavelmente os 2GB são de objetos alocados na Heap.

```cpp
int* value = new int(10); // 0x7fffffffdb30
int* array = new int[5];
array[0] = 1; // 0x55555556aed0
array[1] = 2; // 0x55555556aed4
array[2] = 3; // 0x55555556aed8
array[3] = 4; // 0x55555556aedc
array[4] = 5; // 0x55555556aee0
delete[] array;
```

- Perceba o quão distante fica o 'value' do array na memória com essa alocação. O que acontece é que a memória RAM tem uma **free list**, que é uma lista que contém todos os blocos de memória livres na Heap de diversos tamanhos. Esses blocos são constantemente checados em frações extremamente pequenas de tempo e jogados na lista. O compilador faz um request de um bloco desses, verifica se tem do tamanho desejado na 'free list', e a RAM retorna esse bloco para o compilador usar e alocar o objeto ali.

E diferente da Pilha, na Heap o objeto continua existindo fora de um escopo.

```cpp
{
    int* x = new int(10); // Alocação na Heap
}
// x continua existindo.
```

## Quando usar Pilha e quando usar Heap?

**Sempre que possível, é melhor utilizar alocação na pilha**, pois as operações são muito mais rápidas para a CPU. É óbvio que não dá pra alocar em pilha todo tempo, afinal são 2MB de espaço no geral somente. E também não dá pra alocar na Heap todo tempo. É inimaginável o programador dar 'new' pra qualquer tipo de variável que ele inicializa, e ainda ter de deletar tudo no final.

Mas no caso da Pilha estar cheia, o que é difícil acontecer em programas bem otimizados, usa-se alocação na Heap. E também se usa alocação na Heap quando se deseja acessar objetos fora de escopos. Também é usado para objetos complexos, por exemplo, uma textura de 5MB, nesse caso é impossível alocar tanto assim na pilha.