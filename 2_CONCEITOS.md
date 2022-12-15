# Conceitos de C++

Reuni os conceitos mais falados de C++ e que servem inclusive para outras linguagens.

Requisitos para entender esse arquivo:
- Programação básica e procedural em C/C++
- POO em qualquer linguagem derivada do C++ (Java, Python)
- Ler o arquivo README.md nesse rep


# Conceitos

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

> Nota: se o objeto não possuir construtor escrito na classe, o C++, em tempo de compilação, cria um método construtor vazio no momento que vê a declaração **Pessoa p**.


## Alocar

O ato de alocar significa preparar um bloco de memória específico na memória RAM para depois jogar dados lá.

Existem quatro tipos de alocações:
- De código (no executável, existe até o programa encerrar)
- Automática (na pilha, temporária no escopo)
- Estática (na data segment e bbs segment, ambos no executável, existem até o programa encerrar)
- Dinâmica (na heap, existe até o programa encerrar, deletável em tempo de execução)
- Rodata (no executável, existe até o programa encerrar)

![image](https://user-images.githubusercontent.com/98990221/206921825-6f1813c4-3f3b-4d05-bafb-5747081a57b0.png)

*source: Programming: Principles and Practice Using C++ (2nd Edition)*

![image](https://user-images.githubusercontent.com/98990221/206921975-510c9429-099c-4286-b866-df3226f41a37.png)

*source: https://www.geeksforgeeks.org/memory-layout-of-c-program/*

### Alocação do Código (code segment)

- A alocação de memória para o código é feita em tempo de compilação no **code segment** que fica no próprio executável (object file). Reserva o espaço necessário para as instruções de máquina (linguagem de máquina). Possui armazenamento fixo e no geral é read-only. Morre assim que o programa termina.


### Alocação Automática (call stack segment)

- A alocação automática de memória é feita em tempo de execução em uma **pilha** (também chamada de **call stack**) na **stack segment** dentro da memória RAM. É um espaço para guardar variáveis definidas com tempo de vida que duram um escopo. Possui armazenamento fixo. Morre assim que acaba o escopo (pop).

```cpp
{
    int a; // Defino 'a'. Portanto ocorre alocação de memória. (automática na pilha)
    Pessoa p; // Defino 'p'. Portanto alocação de memória. (automática na pilha).
}
cout << a << ", " << p << endl; // printará lixo em a e p. Memória "destruída".
```

> Nota: isso será aprofundado no tópico sobre Pilhas e Heap.


### Alocação Estática (data segment and bbs segment)

- A alocação estática de memória é feita em tempo de compilação (pelo linker) em um local chamado **data and bbs segment**, que fica no próprio executável (object file). Reserva o espaço necessário para armazenar as variáveis estáticas, com tempo de vida que duram a execução toda do programa. Possui armazenamento fixo. Morre quando o programa encerra. 

> Nota: É um tipo de alocação menos importante, mais complexa e será abordada melhor em ARQUIVOS.md. 

A região armazena qualquer entidade declarada em um namespace ou no namespace global (que é um namespace implícito), seja usando a keyword **static** ou não. Já dentro de funções ou classes, é obrigatório o uso da **static** para alocar na data and bbs segment, caso contrário será automática (na pilha). A alocação estática é permanente e dura até o fim do programa.

```cpp
int a; // Está no namespace Global. Alocação estática.
static int z; // Está no namespace Global. Alocação estática.
namespace Exemplo{
    int b; // Alocação estática.
    void imprimir(){
        static int c; // Alocação estática.
        int d; // Alocação automática.
        c = 10; d = 5;
        cout << c << ", " << d << endl;
    }
}
int main(){
    static int e; // Alocação estática.
    int f; // Alocação automática.
}
```

> Nota: A memória estática é subdividida em duas: memória estática inicializada (data segment) e memória estática não inicializada (bbs segment), e estão em dois subblocos adjacentes.

```cpp
// namespace Global
int a; // Alocação estática não inicializada. Por padrão tem valor 0.
a = 10; // Alocação estática inicializada.

static int b; // Alocação estática não inicializada
b = 20 // Alocação estática inicializada.

int main(){
    static int c; // Alocação estática não inicializada
    c = 30; // Alocação estática inicializada
}
```

No momento que a = 10, a alocação estática não inicializada para 'a' é deletada, e a alocação estática inicializada para 'a' é criada. O mesmo vale para 'b' e 'c'.

> Nota: por hora basta saber que dentro de namespaces **utilizando ou não static** ou dentro de funções e classes **utilizando 'static'**, as entidades serão alocadas estaticamente na memória. O uso da keyword **static** é mais complexo e será aprofundado em ARQUIVOS.md.


### Alocação Dinâmica (heap segment)

- A alocação dinâmica de memória é feita em tempo de execução numa heap na **heap segment** dentro da memória RAM. É um espaço para guardar variáveis com tempo de vida que o programador define. Possui armazenamento dinâmico (tamanho da RAM). Morre assim que o programador usar a keyword *delete*, ou seja, quando o programador quiser.

```cpp
int* a = new int();
delete a;
```
- *new int()* é um objeto anônimo alocado em uma memória dinâmica na heap. 'a' é um ponteiro na pilha que aponta pra esse objeto para não se perder.
- *delete a* é uma operação feita sobre o conteúdo para o qual 'a' aponta, que é a liberação de memória desse 'new int' na heap (deletar).

> Nota: isso será aprofundado mais pra frente e no tópico sobre Pilhas e Heap.

### Alocação .rodata (rodata segment)

- A alocação de memória para constantes é feita em tempo de compilação na **read-only data segment** (rodata segment), que fica no próprio executável (object file). Reserva o espaço necessário para as constantes (exemplo: strings literais). Possui armazenamento fixo e é read-only. Morre assim que o programa termina.

> Nota: não se trata dos 'const'. A keyword 'const' apenas proíbe uma variável de ser modificada, mas ela não deixa de ser variável. É como se fosse uma promessa, mas qualquer promessa pode ser quebrada. Com 'const', o compilador sempre assume que a variável não foi e não será mudada, mas não é garantia. Há um mito de que 'const' gera ganho de desempenho do programa, mas é comprovadamente falso. Ou seja, normalmente na .rodata contém objetos imutáveis presentes no programa, como strings literais. Nada de variáveis 'const'.

## Declarar 

Declarar é especificar um nome e um tipo para uma entidade (classe, tipo, função, variável) no programa.

Declarar diz para o compilador que a entidade existe, é única, poderá ser usada depois, e dependendo da declaração, se também for definição (próximo tópico), aloca memória.

No caso de declaração de objetos de uma Classe (tipo não-primitivo de dado), o compilador trata isso automaticamente como instanciação de uma Classe (será mais detalhado no tópico de instanciação de Classes).

```cpp
int f(int a); // Declaração de função que retorna um tipo inteiro. Não há definição, portanto não aloca memória
class Pessoa; // Declaração de classe. Não há definição, portanto não aloca memória.

int k; // Declaração em namespace Global. É também definição, e portanto aloca memória (estática).

int main(){
    int a; // Declaração trivial (e definição). Aloca memória automática.
    int* b; // Declaração (e definição) de ponteiro pra algum inteiro na memória. Aloca memória automática.
    int& c; // ERRO: apesar de que dá pra fazer isso com parâmetro de funções.
    Pessoa person; // Declaração (e definição) de um objeto da classe Pessoa. Também é uma instanciação. Aloca memória automática.
    int z = int(); // Declaração (e definição) não convencional, com parênteses vazio ("construtor"). Aloca memória automática.
}
```

> Nota: o caso 'int z() = int();' fará mais sentido logo abaixo.


## Definir

Toda definição é uma declaração. Toda definição aloca espaço na memória. Seja estática ou automática.

```cpp
int x; // Definição (e declaração). Alocação estática. Inicializada com lixo.
static int z; // Definição (e declaração). Alocação estática. Inicializa com lixo.
int main(){
    int a; // Definição. Alocação automática. Inicializada com lixo.
    int* b; // Definição. Alocação automática. Inicializada com lixo.
    static int c; // Definição. Alocação estática. Inicializada com lixo.
    Pessoa p; // Definição. Alocação automática.
}
```

Mas nem toda declaração é uma definição.

```cpp
class Pessoa; // Declaração apenas. Nada definido. Não aloca memória.
class Pessoa{}; // Declaração e definição. Aloca memória estática.
void print(); // Declaração apenas. Nada definido. Não aloca memória.
void print(){} // Deckaralçai e definição. Aloca memória estática.
```

No momento que se utiliza *{}*, ocorre a definição de uma classe ou função.


## Inicializar

Inicializar é o ato de atribuir um primeiro valor a uma variável já declarada. Pode haver declaração/definição junto com inicialização.

```cpp
int main(){
    int a; // Declaração (e definição para os casos também abaixo). É alocada memória automática na pilha.
    a = 10 // Inicialização.
    int* b; // Declaração. É alocada memória automática na pilha.
    b = &a; // Inicialização. 
    int** c = &b; // Declaração e inicialização. Aqui c aponta pra b, e b aponta pra a.


    int* x; // Declaração. Aloca memória automática na pilha
    x = new int(22); // Inicialização. É alocada memória dinâmica na heap (new int).
    int* y = new int(15); // Declaração e inicialização. É alocada memória automática na pilha e memória dinâmica na heap.
}
```

> Nota: o uso do **new** e a alocação dinâmica de memória serão detalhados mais abaixo.

Além disso, existem diversos outras formas de inicializar e declarar variáveis:

```cpp
int main(){
    int valor(10); // Declaração e inicialização. Desaconselhado o uso. Aloca memória automática na pilha.
    int valor = int(10); // Declaração e inicialização. Apenas não convencional. Aloca memória automática na pilha.
    Pessoa person = Pessoa(); // Declaração e inicialização. Aloca memória automática na pilha.
}
```

- Perceba que uso um "construtor" que passa 10 pro 'valor'. São formas alternativas de inicializar, equivalentes a *'int valor = 10'*, e as duas estão corretas e fazem a mesma coisa.

> Nota: o primeiro caso pode ser confundido com uma função, e portanto seu uso não é convencional e é desaconselhado. Porém, o compilador sabe a diferença. Se não tiver escopo {} e for passado **rvalues** diretamente, é uma variável sendo inicializada na pilha. Caso contrário, é uma declaração de função. Não é possível apenas declarar dessa forma, por exemplo, apenas colocando 'int valor();', pois nesse caso o compilador entende como declaração de função, e não é possível inicializar depois.

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


## Instanciar

Instanciar é criar um objeto de uma Classe específica. Quando dizemos "instanciar a Classe", significa que estamos criando um objeto do tipo "Classe".

```cpp
class Pessoa{...};

int main(){
    int valor; // "Instanciação" de uma "classe" int.
    Pessoa p1; // Instanciação de uma classe Pessoa. Aloca memória automática na pilha.
    Pessoa* p2 = new Pessoa(); // Instanciação de uma classe Pessoa. Aloca memória dinâmica na heap.
}
```

> Nota: A partir de agora, para os exemplos com uso de Classes, suponha que todas as Classes apresentadas nos exemplos tenham atributos e métodos funcionais e fictícios pré-definidos e preenchidos no escopo. Não irei colocar o código completo de uma Classe, pois isso iria ficar massante, e a ideia é simplificar a explicação e ir direto ao ponto. Portanto, os códigos abaixo são hipotéticos e, por motivos óbvios, não irão funcionar em um programa real.

### Instanciação sem ponteiros

A instanciação sem uso de ponteiros envolve você simplesmente declarar o objeto, e ao inicializar seus atributos, os dados são alocados na Pilha da memória da RAM, que possui aproximadamente 2MB.

```cpp
class Pessoa{...}; // Suponha que essa classe esteja completa, com atributos e métodos.
int main(){
    Pessoa p1; // Prepara espaço automático na pilha dizendo pro compilador que existe p1.
    p1.nome = "Zé" // Joga dados nesse espaço criado na pilha
    p1.correr(5) // Executa o método 'correr' 5km/h.

    int valor; // Isso não é instanciação. Não há preparo de espaço na pilha, apenas diz pro compilador que existe.
    valor = 10; // Aloca dados nesse espaço criado na pilha e joga 10 para o espaço alocado.
}
```

Existem diversas formas de instanciar uma Classe sem ponteiros.

```cpp
class Pessoa{...};
int main(){
    Pessoa p1; // Forma 1. Executa o construtor implicitamente.
    Pessoa p1(); // Forma 1.1. Age igual o de cima. Parênteses opcional.

    Pessoa p2("Zé", 18) // Forma 2. Executa o construtor diretamente.
    Pessoa p2 = Pessoa("Zé", 18) // Forma 3. Executa o construtor diretamente.
}
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

### Instanciação com ponteiros - Dinâmica

A instanciação com ponteiros de forma dinâmica é a segunda forma mais utilizada para instanciar uma Classe. Envolve alocar espaço na Heap e retornar um ponteiro para aquele local alocado dentro da heap. A heap fica localizada também na memória RAM, e seu espaço é ilimitado até a RAM estourar. Esse espaço alocado é permanente e não encerra após o término de uma função. Ou seja, pode ser acessado fora do escopo dela desde que não se perca o ponteiro que aponta para ela (que estará na pilha).

Usamos ponteiros apontados para objetos na Heap, pois na heap os objetos são muito espalhados, então precisamos de um ponteiro (dentro da pilha) que aponte para esse objeto anônimo na Heap, a fim de garantir seu "track" e não se perder na memória. O ponteiro dentro da pilha é essencial, pois a pilha é uma memória super organizada e que o compilador sabe onde esse ponteiro vai estar exatamente. Sabendo o ponteiro, ele sabe onde o objeto que é apontado na heap estará.

> Nota: falo sobre armazenamento em Pilha e Heap no último tópico desse arquivo. Por hora, basta saber que inicializar qualquer coisa automática é alocar memória na Pilha, e inicializar qualquer coisa dinâmica é alocar memória na Heap.

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

> Lê-se: *obj* é um tipo ponteiro para um inteiro que aponta pra um tipo int anônimo na memoria (int*), geralmente lixo. Ao "igualar" a um novo inteiro, o *obj* recebe o mesmo endereço desse novo (new) objeto do tipo inteiro (int) criado, e com atributos devidamente alocados (5, métodos da classe int, etc). Lembrando que new retorna um endereço do tipo void* (pois ele precisa apontar pra qualquer tipo de memória alocada inicialmente), e é feito um casting automático para int*.

Mais exemplos:

```cpp
Pessoa* pessoa = (Pessoa*)malloc(sizeof(Pessoa)); // C
pessoa->Pessoa() // Construtor
pessoa->nome = "Zé";
pessoa->idade = 18;
```

```cpp
// C++. O código abaixo faz a mesma coisa das duas linhas de código acima.
Pessoa* pessoa = new Pessoa(); // Pessoa() é também o construtor.
pessoa->nome = "Zé";
pessoa->idade = 18;
```

- Uso de Classe ou Struct para instanciar objetos. O uso dos parênteses em Pessoa() é opcional desde que não precise passar nada pelo construtor.
- pessoa é um ponteiro do tipo Pessoa* que passa a apontar para um objeto alocado na memória do tipo Pessoa através do seu endereço.

```cpp
char* vec = (char*)malloc(100 * sizeof(char)); // Vetor de tamanho 100.
char* vec = new char[100]; // Vetor de tamanho 100
```

> Nota: O uso de arrays será muito detalhado no arquivo ARRAY.md.

- Aqui mostro a alocação de um array de 100 bytes. Lembrando que um char é 1 byte.
- *vec* é um ponteiro que aponta pro primeiro elemento do vetor alocado na memória. Nesse caso o conteúdo é obviamente lixo, pois o vetor não foi preenchido.

> Nota: a função malloc() é do tipo void*, ou seja, retorna um ponteiro do tipo void*.

```cpp
void* ptr_coringa = malloc(sizeof(int));
int* ptr_pra_int = (int*)ptr_coringa; // casting de void* pra int*.
```

### Instanciação com ponteiros - Automática

Menos utilizada, mas possível. A instanciação de uma classe na pilha (automática) e o uso de ponteiro também na pilha para capturar o endereço dessa instância é menos comum, pois normalmente usamos ponteiros apontados para objetos na Heap pelo motivo já explicado (não perder o track do objeto).

```cpp
class Pessoa{...}
Pessoa person;
Pessoa* ptr = &person;
ptr->nome = "Zé";
ptr->idade = 18;
```

Aqui fica claro o motivo do uso da seta ->. A seta nada mais é do que isso:

```cpp
(*ptr).nome = "Zé";
(*ptr).idade = 18;
```

Acesso o conteúdo do ponteiro (que é person), e assim consigo atribuir valores. Mesma coisa vale o uso da seta na alocação dinâmica.


## Liberar (desalocar)

É o ato de liberar dados armazenados da memória RAM que não serão mais utilizados. Desalocação de memória é feito de forma automática em uma alocação automática quando o escopo termina. Já em alocação estática não é feita nenhuma desalocação.

Porém, em alocação dinâmica, todo **malloc()** ou **new** precisa estar acompanhado de um **free()** ou **delete**, ou teremos o famoso Memory Leak.

Memory leak é algo muito comum. Em jogos sandbox, o uso de memória RAM é alto, pois em uma cidade de mundo aberto temos vários objetos, várias instâncias atuando em um raio ao redor do player. E quando esses objetos saem do alcance do jogador, são deletados para liberar memória, caso contrário o jogo pode gerar crash devido ao alto consumo de memória e overflow. O navegador Google Chrome também já sofreu com isso, e tem um histórico considerável de reclamações por consumo excessivo de RAM devido a memory leak.

Como C++ é uma linguagem que não possui coletor de lixo automático (Garbage Collector), toda vez que se instancia um objeto na heap, é preciso deletar essa mesma instancia no fim de um programa ou ao longo dele quando não se precisa mais daquela memória.

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


# Atribuir valores para uma instância de Classe: qual utilizar?

Existem 3 principais formas de atribuir valores a atributos de uma classe.


## Atribuição 1: Padrão

```cpp
Pessoa pessoa1;
pessoa1.nome = "João";
pessoa1.idade = 20;
```

- Ao declarar e inicializar um objeto normal e cru, você está declarando algo que só funcionará naquele escopo {} específico. Ou seja, **quando o escopo acabar, o objeto não existirá mais**. É basicamente alocada uma memória temporária e automática na pilha pra guardar o objeto que se perderá em breve.


## Atribuição 2: Ponteiro apontando para um só objeto

```cpp
Pessoa* pessoa3 = new Pessoa;
pessoa3->nome = "Carlos";
pessoa3->idade = 31
delete pessoa3;
```

- Ao instanciar na heap, o objeto pode ser acessado dentro e fora de classes, funções, métodos, na função main, por outros arquivos... e todos os seus atributos também poderão ser utilizados. O problema disso é o risco de se criar inúmeros objetos da mesma Classe, e como eles não são apagados automaticamente, pode ocorrer um Memory Leak e consumo excessivo de RAM enquanto o programa estiver rodando.

![image](https://user-images.githubusercontent.com/98990221/197656441-91f55da2-9450-407b-a6c1-836162423b14.png)

- Em linguagens como Python e Java, ao instanciar um objeto, todos os atributos daquele objeto são passados por referência através do "self" ou "this" de forma automática, sem precisar usar ponteiros para isso. Por isso é possível criar estrutura de dados nessas linguagens, mesmo elas não utilizando ponteiros na sintaxe, pois ela tem ponteiros implicitos. As linguagens mais avançadas já entendem que certas coisas devem passadas por cópia, e outras por referência sem precisar explicitar o asterisco ou ampersand.

> Nota: Normalmente outras linguagens mais modernas, como já falado antes, já fazem por referência, só que utilizando o '.' ao invés do '->'. Já no C++, o '.' é de fato feito sobre uma cópia, enquanto que em Java ou Python, o '.' é algumas vezes feito sobre uma referência, principalmente dentro de Classes sobre a keyword "this/self".


## Atribuição 3: Dois ponteiros apontando pro mesmo objeto

```cpp
Pessoa* p2; // Isso não é instanciação!
p2->nome = "Zé"; // ERRO!!!!
p2->idade = 18
```

- Ao declarar e inicializar um objeto que aponta pra um tipo Pessoa, no modo como foi apresentado acima, atribuindo valores diretamente, dará erro, pois não tem memória alocada para passar esses atributos, afinal foi declarado um ponteiro para um tipo Pessoa, e não o objeto em si. A única forma de realmente fazer o caso acima é nesses dois casos:

```cpp
Pessoa* p2;
Pessoa* p1 = new Pessoa; // 'new Pessoa' é uma instanciação da classe Pessoa. p1 aponta pra essa instância.
p2 = p1; // p2 recebe o endereço de p1, portanto, aponta pro mesmo lugar onde p1 aponta.
p2->nome = "Zé";
p2->idade = 18;
delete p1;
```

- Passando por referência um objeto do tipo Pessoa* (pessoa1) para outro objeto do tipo Pessoa* (pessoa2), *pessoa2* passa a apontar pro mesmo objeto que *pessoa1* aponta, pois você está passando o endereço de pessoa1 para pessoa2.
- Se mudar qualquer atributo em *pessoa2*, muda também em *pessoa1*, afinal os dois apontam pro mesmo lugar, pois essa inicialização é por referência. Como *pessoa1* é um ponteiro, então não precisa do ampersand & pra passar por referência. Somente igualar já é suficiente, pois são do mesmo tipo 'Pessoa*'.

```cpp
Pessoa p1;
Pessoa* p2 = &p1;
p2->nome = "Zé"; // Muda os atributos de p1.
p2->idade = 18;
```

- Esse é o segundo caso. Já foi exeemplificado no tópico *Instanciação com ponteiros - Automática*.


# Pilha (Stack) vs Heap na RAM (Random Access Memory)

Uma memória RAM possui duas principais estrutura de dados. A **Pilha**, que o compilador reserva cerca de 2MB de dados fixos (varia por compilador ou por SO), e a **Heap**, que armazena dados indefinidamente de forma dinâmica até a RAM estourar.

Elas são duas estruturas muito diferentes, mas fazem a mesma coisa. O programador pede um bloco de memória com um tamanho específico, e o compilador nos dá esse bloco de memória se tudo der certo. A diferença está na forma como essa memória é alocada. E sem contar que alocação e inicialização na Pilha é somente um comando *(int x = 10)*, enquanto que na Heap são diversos, incluindo *malloc()* e uso de ponteiros (mais lenta).

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

- Alocar na pilha é uma alocação automática de memória (ocorre em tempo de execução), enquanto que na Heap é uma alocação dinâmica de memória (ocorre em tempo de execução, é criado ou destruído quando o programador quiser).
- A pilha possui memória de duração automática (temporária), enquanto que na Heap possui memória de duração dinâmica.


## Pilha

Alocação em Pilha é extremamente rápida e feita em tempo de compilação, pois os valores ficam exatamente um ao lado de outro na memória, como uma pilha mesmo. Então seu acesso é bem fácil e rápido, basta incrementar o endereço. O ponteiro para o topo da pilha basicamente anda pro lado e vai acessando valores. Normalmente a região do topo da pilha é onde estão variáveis criadas recentemente que com certeza vão ser destruídas quando um escopo atual acabar.

A desvantagem é o limite do uso de memória. Ao estourar essa memória, temos um estouro de pilha (stack overflow). É raro mas pode ocorrer.

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

- Outra coisa é que alocação na pilha faz com que o objeto dentro do escopo seja deletado (free) assim que o escopo acaba. Isso já foi exemplificado na parte de alocação.

```cpp
int main(){
    {
        int x = 10; // Alocação na pilha
    }
// x não existe mais.
}
```


## Heap

Alocação em Heap é mais lenta e feita em tempo de execução, mas não possui limite de memória, e o objeto alocado dessa forma pode ser acessado pelo programa todo, inclusive fora de escopos.

O limite do uso de memória é justamente a própria memória RAM do computador. Se um programa consumir 2GB de ram, por exemplo, muito provavelmente a maior fatia desse espaço é de objetos alocados na Heap.

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
int main(){
    {
        int* x = new int(10); // Alocação na Heap
    }
// x continua existindo.
}
```


## Quando usar Pilha e quando usar Heap?

**Sempre que possível, é melhor utilizar alocação na pilha**, pois as operações são muito mais rápidas para a CPU. É óbvio que não dá pra alocar em pilha todo tempo, afinal são 2MB de espaço dependendo do compilador e do SO. E também não dá pra alocar na Heap todo tempo. É inimaginável o programador dar 'new' pra qualquer tipo de variável que ele inicializa, e ainda ter de deletar tudo no final.

Alocação (automática) na pilha é a mais comum em C++. A maioria das coisas se declaram na pilha, incluindo instâncias de Classes. Para quem veio de linguagens como Java ou C#, é estranho ver isso, pois normalmente nessas linguagens esse tipo de instanciação tem chance de levantar exceção de NullPointer em tempo de execução. Todo objeto em Java ou C# é instanciado na heap usando **new**, sem ressalvas. Mas em C++ temos a opção de instanciar direto na pilha, o que torna as operações muito mais rápidas e seguras, porém limitadas em espaço.

Mas no caso da Pilha estar cheia, o que é difícil acontecer em programas bem otimizados, usa-se alocação na Heap. E também se usa alocação na Heap quando se deseja acessar objetos fora de escopos. Também é usado para objetos complexos, por exemplo, uma textura de 5MB, nesse caso é impossível alocar tanto assim na pilha.


# Const

A keyword **const** é uma promessa (contrato) que o programador firma com o compilador de que a variável não deverá ser alterada. E o compilador previne a sua mudança e a torna imutável, mas não há garantia.

Ela pode ser utilizada de várias formas. Mas é obrigatório que se inicialize a variável caso use **const**. Somente declaração não é suficiente.


## Const sem ponteiros

```cpp
const int a; //ERRO
const int b = 10;
b = 5; // ERRO
int const c = 17; // Equivalente a const int. OK
```

> Nota: 'const int' e 'int const' são válidos e equivalentes. Fazem a mesma coisa. Porém, no próximo tópico, ao utilizar ponteiros, essa troca possui diferenças.


## Const com ponteiros

```cpp
int x = 55;
const int* a = &x; // Caso 1
int* const b = &x; // Caso 2
const int* const c  = &x; // Caso 3
```

- Caso 1: Derreferenciar 'a' é proibido. Você pode mudar diretamente 'x', já que 'x' não é const, mas não pode mudar 'x' através de 'a' com derreferencia, pois 'a' é um ponteiro que aponta pra um int constante (const int). Ex: *a = 10. Erro!

- Caso 2: Mudar o ponteiro b pra onde ele vai apontar é proibido. 'b' é um ponteiro constante que aponta pra um inteiro (const b). Ex: b = &j. Erro!

- Caso 3: Uma combinação do caso 1 e 2, tornando impossível tanto mudar pra onde o ponteiro aponta, quanto mudar o valor para o qual o ponteiro aponta. Mudar o ponteiro 'c' e derreferenciar ele são proibidos. 'c' é um ponteiro constante que aponta pra um inteiro constante (const int, const c).

Existe outra forma de representar o caso 1, porém com sintaxe mais confusa e não aconselhada para ponteiros simples. Pode-se encontrar eventualmente dessa forma em códigos espalhados pela internet, e é possível que seja utilizado para casos de arrays multidimensionais e strings passadas por parâmetro de uma função. Isso será abordado no arquivo ARRAYS.md.

```cpp
int x = 55;
// Equivalente ao caso 1. Asterisco na frente de const.
int const* a = &x; // Mais utilizado para arrays multidimensionais.
```

Outra regra de const com ponteiros é o caso de proibição de atribuição:

```cpp
const int* a = new int(44); // Caso 1: inteiro anônimo constante
int* b = a; // ERRO!

int* const a = new int(44); // Caso 2: ponteiro constante
int** b = &a; // ERRO!
```

- Em ambos os casos, estou tentando "burlar a promessa" de não modificar valores const através de referências. Pois se não desse erro, eu poderia dereferenciar 'b' em ambos os casos. Derreferenciando 'b', eu posso no *caso 1* mudar o conteúdo de 'a', e no *caso 2* posso mudar pra onde o 'a' aponta.

- Para evitar derreferência, o C++ proíbe que esse tipo de operação acima seja possível. Porém, existe um ÚNICO caso onde isso é permitido, que é no seguinte caso:

```cpp
char* str = "Ola mundo";
```

Parece esquisito, afinal não tem const visível. Porém ele existe, é o próprio "Ola mundo". Um 'const char*'. Essa conversão é a única possível devida a retrocompatibilidade com C. Essa parte será discutida no arquivo ARRAYS.md.

## Const como parâmetro de função

Existem alguns casos que se trabalha com const em parâmetro de função

### Caso 1 - Cópia

```cpp
// passo um não-const para um const como parâmetro
void imprime_com_const(const int objeto_1){
    // objeto_1 = 3; ERRO!
    cout << objeto_1 << endl;
}

// passo um const para um não const como parâmetro
void imprime_sem_const(int objeto_2){
    // objeto_2 = 3; OK!
    cout << objeto_2 << endl;
}

int main(){
    int objeto_1 = 10; imprime_com_const(objeto_1);
    const int objeto_2 = 20; imprime_com_const(objeto_2);
}
```

Ao passar por cópia, as variáveis objeto agem de forma independente, inclusive quando são constantes. Modificar uma não-const por parâmetro não vai afetar ela const na main. Por se tratar de cópia, são dois objetos completamente distintos.

### Caso 2 - Referência

```cpp
void imprimir_const(const int* objeto){
    cout << objeto << endl;
}
void imprimir(int* objeto){
    cout << objeto << endl;
}

int main(){
    int* objeto_1 = new int(10);
    const int* objeto_2 = new int (20);

    imprimir_const(objeto_1); // OK! Um int* pode se tornar um const int* como parâmetro da função, mas não o contrário.
    imprimir_const(objeto_2); // OK!

    imprimir(objeto_1); // OK!
    imprimir(objeto_2); // ERRO! Um const int* não pode ser passado para um int*. Isso é para prevenir derreferência e mudança do valor constante na heap.
}
```

O mesmo caso se aplica se o const fosse atrelado ao ponteiro **(int* const objeto)**.


## Const como retorno de um valor de uma função

```cpp
const int get_idade(){
    return this->idade;
}
```

A operação acima é inútil, tanto pra método quanto função. Const como retorno de função faz basicamente nada. O retorno de uma função é um r-value, o que já o torna não modificável.

## Const como conteúdo de uma método

```cpp
int get_idade() const{ // Coloco após o método.
    return this->idade;
}

void set_idade(int idade) const{
    int i = 10; // Permitido
    char* str = "Ola"; // Permitido
    i = 4; str = "Mundo". // Permitido

    this->idade = idade; // PROIBIDO
}
```

A operação acima proíbe qualquer tipo de modificação de atributos de uma Classe dentro de um método. Outras variáveis inicializadas e atribuidas são permitidas.

> Nota: isso só funciona com métodos. O uso em funções fora de Classes causará erro na compilação.

## Const como instanciação de Classe

```cpp
class Pessoa{
    int idade;
public:
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
    p.set_idade(22); // ERRO! Chamei um método com conteúdo não constante.
}
```

Basicamente uma instância de classe const só pode chamar métodos com conteúdo const. Atributos da classe também não podem ser modificados pela instância. Tudo isso combinado previne que qualquer valor dessa instância seja modificado.

# Entendido o básico de conceitos...

Fiz um documento sobre arrays, e como ponteiros e arrays são tão parecidos, ao mesmo tempo diferentes.
Leia o arquivo **ARRAY.md**.
