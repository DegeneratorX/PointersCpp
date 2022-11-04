# Ponteiros em C++
Tudo sobre ponteiros, mastigado. Tive dificuldades para entender o conceito, e por isso criei esse repositório: para basicamente treinar e fixar o conhecimento. Conhecimento adquirido através desses cursos:

- https://youtu.be/zuegQmMdy8M
- https://youtu.be/kiUGf_Z08RQ
- https://www.udemy.com/course/data-structures-algorithms-cpp/
- https://www.udemy.com/course/data-structures-algorithms-python/ -> Esse aqui foi usado como referência para melhor compreensão do uso de POO.


Esse readme é para mostrar conceitos básicos da programação procedural e que até hoje alguns são extremamente utilizados.

# O que é um ponteiro?

Um ponteiro é basicamente um tipo de variável especial que pode receber apenas endereço de memória ou outra variável do tipo ponteiro. O endereço de memória possui um formato *0x????????*, onde *?* pode ser um número de 0 a f em hexadecimal, e um endereço nesse formato ocupa 8 bytes, 1 byte pra cada *?*.

```cpp
int* x; // Todos os tipos ocupam 8 bytes. O tipo int, float e double nesse caso são somente auxiliares, e somente diz pra que tipo de variável o ponteiro x, y ou z aponta para reservar a quantidade certa de memória ao manipular dados daquela região.
float* y;
double* z;
```

A grande vantagem do uso de um ponteiro é poder, de forma segura, alterar valores de variáveis pelo programa inteiro, inclusive fora do escopo de funções e classes. Isso seria possível sem o uso de ponteiros, mas necessita de muita gambiarra, o que torna praticamente inviável. Fora que para alocar memória dinamicamente, é obrigatório o seu uso. Falarei sobre isso depois.

> Nota: Inicialmente irei nesse readme utilizar bastante exemplos com int* para facilitar o entendimento, mas o uso de ponteiro serve para todos os tipos primitivos de dados e Classes, e são praticamente aplicados da mesma forma.

## Como declarar um ponteiro

3 formas de declarar ponteiros:

```cpp
int* p; // Caso 1
float * p; // Caso 2
double *p; // Caso 3
```

> Nota: Perceba que todos os casos acima são iguais. Isso serve pra mostrar que eventualmente é possível encontrar códigos onde se usa algumas dessas formas para declarar um tipo *ponteiro*.

- Didaticamente, o Caso 1 é o mais legível e convencional, visto que confunde menos ao colocar o **asterisco próximo do tipo** que o ponteiro aponta.
- O Caso 3 resulta em muita confusão para quem está começando a aprender ponteiros, pois mais pra frente vamos ver que usar '*p' de forma isolada possui funcionalidade **completamente diferente**, chamada de deferência.

## Como inicializar um ponteiro

Como já foi dito, ponteiro só pode receber 2 tipos de valores: um endereço, ou outra variável do tipo ponteiro (que já aponta pra um objeto através de um endereço, óbvio).

### Ponteiro recebendo endereço diretamente

```cpp
int a; // Declaração de variável
a = 2; // Inicialização

int* b; // Declaração de ponteiro (aponta pra um inteiro anônimo na memória)
b = &a; // Inicialização (agora b passa a apontar pra a)
```

- Aqui o ponteiro b recebe o endereço de a (&a).

> Nota: sempre que quiser acessar o endereço de um objeto na memória, usa-se '&objeto'. O operador & (ampersand) retorna o endereço que o objeto está localizado, em formato *0x????????*

- Pronto, criamos um ponteiro *b* que aponta pra *a*.

### Ponteiro recebendo outro ponteiro

```cpp
int* a;
a = &obj_generico;

int* b;
b = a; // isso é equivalente dizer que a = b = &obj_generico
```

- Aqui o ponteiro b recebe o ponteiro a. Ou seja, *b* recebe o endereço que *a* tem guardado (&obj_generico). Ou seja, os dois agora passam a apontar pro mesmo obj_generico.

### Ponteiro de ponteiro

```cpp
int* a;
a = &obj;

int** b;
b = &a;
```

- Sim, isso é possível. *b* agora aponta pra *a*. Chama-se ponteiro de ponteiro. Para entender melhor o que se passa, usamos o exemplo extremo abaixo:

```cpp
int    a = 10;
int*   b = &a;
int**  c = &b;
int*** d = &c;
```

- *d* aponta pra *c*, que *c* aponta pra *b*, que *b* aponta pra *a*. Ou seja, *d* "aponta" pra *a* de forma indireta. A partir de *d*, é possível, por incrível que pareça, obter informações de *a*.

## Tipos de ponteiros

Existem 2 tipos de ponteiros: um que guarda um endereço de um objeto na memória e referencia seu conteúdo, e outro que referencia seu conteúdo apenas, sem guardar nada.

```cpp
int* // Tipo ponteiro normal
int& // Tipo ponteiro referência
```

Os dois tem a mesma função: apontar pra um objeto na memória.

- 'int*' é muito mais poderoso que o 'int&', pois aponta pro endereço de memória e guarda esse endereço, ao custo de ocupar memória (8 bytes), pois o ponteiro também é uma variável que armazena o endereço de *a*. É o mais utilizado pelos programadores.
- 'int&' é menos comum e é usado apenas para economizar linhas de código, pois diferente do int*, o int& não ocupa memória nenhuma. Pois é. Ou seja, serve puramente para enxugar linhas de código, além de operar bem mais rápido que o uso de um int*. Assim como o int*, o int& também modifica valores via referência. A grande desvantagem de não usarem frequentemente int& é que a partir do momento que se referencia algo, não tem mais como mudar a referência, ou seja, apontar pra outro objeto. Somente ponteiro é capaz, graças a capacidade de armazenar endereços.


### Sintaxe do Asterisco int*:

```cpp
int a = 10;
int* b = &a;
```

- Já foi explicado como funciona a sintaxe, mas irei repetir aqui para efeito de comparação com o caso abaixo.

### Sintaxe do Ampersand int&:

```cpp
int a = 10;
int& b = a;
// int& c; <<< Declarar ponteiro assim é IMPOSSÍVEL, dado que 'c' não ocupa espaço nem é variável! Mais detalhes abaixo.
```

- Perceba que passei diretamente o valor de a, sem uso de &a nem nada. Isso porque b recebe o valor diretamente de uma variável.

> Curiosidade: *b* **não existe**. Somente no código fonte. b não existe em tempo de compilação, nem ocupa memória nem armazena nada, pois como foi dito anteriormente, int& é um ponteiro invisível que serve somente para enxugar código e puramente serve para modificarmos o valor de *a* diretamente em qualquer parte do programa. É como se b = a, só que tudo que acontece em b, acontece em a. Inclusive ambos possuem o mesmo endereço de memória. Se b fosse int*, teria endereço de memória diferente, e aí sim ocuparia os 8 bytes de espaço armazenando o endereço de a.

Entenda *int a* como um **arquivo.txt** e *int& b* um **atalho** para esse .txt no desktop. Porém, um atalho que ocupa 0 bytes. E tudo que for escrito e modificado abrindo pelo atalho, será modificado no arquivo original.

> Nota: TUDO que se faz com int& também dá pra fazer com int*, mas não o inverso. Aconselha-se usar int& apenas em caso de mudanças simples de valores por referência fora do escopo de funções ao longo do programa.

Para mudar valores via referẽncia usando int&, simplesmente mudamos o valor de *b*, que aponta para *a*.

```cpp
int a = 10;
int& b = a; // ponteiro invisível que aponta pra 'a'.
b = 12 // é como se fosse a = b = 12 de forma completamente automática
cout << a << endl; // agora 'a' passa a assumir valor 12. Printará 12 na tela.
```

> Nota: Para fazer o mesmo com int*, chamamos de deferência, e será abordado em breve abaixo, pois possui maior complexidade.


## Acessar o conteúdo de um objeto (Deferência, ou desreferência)

Após aprender a apontar para um objeto, precisamos saber como funciona o acesso ao conteúdo desse objeto.

Vimos que para acessar o conteúdo de um objeto usando int& é super simples. E para mudar o valor por referência, basta mudar o valor de *b*, que *a* mudava automaticamente.

Mas no caso do *b* ser do tipo int*, envolve uma sintaxe extra para acessar esse mesmo conteúdo. O nome disso é deferenciar,

Dereferenciar é acessar a informação (conteúdo) no endereço contido por um ponteiro e atribuir um valor qualquer a ele. É um conceito parecidíssimo com referência, a diferença é que int& trabalha com valores diretamente, e int* passa a trabalhar também com endereços (ou pra quem está apontando).

Para deferenciar, utilizamos o operador '*' antes de um ponteiro para acessar o conteúdo para o qual o ponteiro aponta. Se prepara, pois agora vai ter bastante confusão.

```cpp
int a = 10
int* b = &a // Referência
*b = 12 // Dereferência.
cout << a << endl; // agora 'a' passa a assumir valor 12. Printará 12 na tela.
```

- Como atribui *b = 12, 'a' agora passa a ser 12. Isso é dereferenciar. Basta colocar o asterisco * antes do b, e pronto, fará a mesma coisa do int& b = a.
- O * nesse caso não é multiplicação e nada tem a ver com ponteiro. O * nesse momento é um OPERADOR que diz pro compilador que você quer acessar o conteúdo para o qual o *b* aponta, que é o valor (conteúdo) de *a*.

Aqui está a diferença trivial desse uso do asterisco, para evitar confusão:

```cpp
int* p = &a; // Asterisco acoplado ao inteiro, indica que não é mais tipo 'int', mas agora é o tipo intptr, que é um ponteiro para um inteiro 'a'.
*p = 10 // Asterisco acoplado a variável ponteiro. Significa um operador que diz que vc quer acessar o conteúdo da variável que p aponta. Ou seja, acessar o conteúdo de 'a'.
```


### int* vs int&: qual utilizar?

- int*
    - Aponta para um objeto do tipo inteiro;
    - Muda valores por referência;
    - Opera mais lentamente em tempo de compilação;
    - Armazena endereço (8 bytes);
    - Pode mudar e apontar pra outros objetos a qualquer hora;
    - Comumente utilizado (tanto para operações simples quanto complexas).

- int&
    - Aponta para um objeto do tipo inteiro;
    - Muda valores por referência;
    - Opera mais rapidamente em tempo de compilação;
    - Não armazena nada (não é variável, é invisível na compilação, puramente estético para enxugar código);
    - Não pode mudar apontamento para outros objetos.
    - Raramente utilizado (normalmente para operações simples).

```cpp
int a = 10; // a = 10, &a = 0xAAA, *a = ERRO

int& b = a; // b = 10, &b = 0xAAA, *b = ERRO

int* c = &a; // c = 0xAAA, &c = 0xCCC, *c = 10
```
- Tanto o caso do int& quando o caso do int* estão fazendo exatamente a **MESMA** coisa. **Referenciando**.
- A diferença é que **int* aponta pro endereço de memória de um objeto**. Ou seja, qualquer variável do tipo int* só pode receber valores do tipo **endereço de memória**.
- E o **int& aponta pro valor de um objeto, não endereço**. Ou seja, qualquer variável do tipo int& pode receber valores inteiros diretamente. 

![image](https://user-images.githubusercontent.com/98990221/197656250-231bedaa-070d-40f6-9782-0f1bea1dd2d5.png)

> Nota: Referenciar usando endereços (int*) se torna mais seguro para alterar valores por referência, porém consome mais memória. Afinal, com endereço (int*), você sabe tanto o endereço quanto o conteúdo, e sabendo só o conteúdo (int&), você perde outras informações, por exemplo, nós de uma lista encadeada e consecutivos apontamentos, além de não poder apontar pra onde um tipo* ponteiro aponta.


### Asterisco tipo*


- **O primeiro caso** se refere a um p declarado como ponteiro que irá apontar pra um inteiro genérico na memória. O asterisco está acoplado com o *int*, e NÃO com o *p*, o que significa que é uma notação pra dizer que é um tipo intpointer, ou seja, int != int*. É como se int* fosse outro tipo totalmente diferente.
- **O segundo caso** o asterisco já tem outro significado completamente diferente. Significa um operador que diz sobre o conteúdo para onde o p aponta.
- **O terceiro caso**, sem operador nenhum, só recebe endereço e nada mais.
- **O quarto e último caso** é quando quero alterar o endereço de alguma variável em formato hexadecimal. Sinceramente **não sei se é possível diretamente dessa forma**. Mas dá pra fazer isso usando variável de controle, que captura endereço de outras variável e atribui a &p diretamente.

Há uma confusão do uso do 'int* p' e do *p somente. Como falei acima, são duas coisas distintas. Uma é declaração de tipo, outra é operador pra dizer pro compilador que vc quer o conteúdo da variável que p aponta.

> E o quinto caso extra, no caso de um **p? O asterisco junto a uma variável é um operador. O asterisco junto ao tipo transforma em um novo tipo. O que existe é 'int **', que é um tipo ponteiro de um ponteiro de um inteiro. **p mostra o conteúdo original para onde p aponta. Isso foi falado no primeiro tópico de referências.

```cpp
int* p = &a; // Asterisco acoplado ao inteiro, indica que não é mais tipo 'int', mas agora é o tipo intptr, que é um ponteiro para um inteiro
*p = 10 // Asterisco acoplado a variável. Significa um operador que diz que vc quer acessar o conteúdo da variável que p aponta.
```


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
* Se mudar sem *&*, dará erro. Afinal, *b* só pode receber endereço, e não valores. Ele é do tipo intponteiro, ou simplesmente int*.
* Já se mudar o *b pra 12, por exemplo, muda o valor de 'a' pra 12 também.

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

```cpp
int a = 10
int& b = a
```


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
int& c; // ERRO: apesar de que dá pra fazer isso com parâmetro de funções. Irei abordar mais abaixo sobre.
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

Instanciar é criar espaço na memória para guardar uma variável que aponta pra um tipo. Esse espaço é permanente e não encerra após o término de uma função. Ou seja, pode ser acessado indefinidamente.

Em POO, ao invés de chamarmos de instanciação de tipo, chamamos de instanciação de alguma classe. E a instância criada é um objeto.

```cpp
int* obj = (int*)malloc(sizeof(int)); // C
int* obj = new int; // C++
int* obj = new int(5);
```

- Os dois casos acima são equivalentes. O primeiro é usado em C, que inclui um casting pra int*, e o outro em C++, que simplifica mais esse processo sem necessidade de casting. São alocações dinâmicas de memória. O terceiro caso extra é pra mostrar que você pode usar um "construtor" da classe *int* pra passar o valor 5. Ou seja, *obj* "terá valor" 5.
- Na verdade *obj* não tem valor de nada, por isso "terá valor" estava entre aspas. *obj* é um ponteiro que aponta pra um inteiro anônimo criado na memória, do tipo int e com valor 5.
> Lê-se: *obj* é um tipo ponteiro que aponta pra um tipo int anônimo na memoria (int*), geralmente lixo. Ao igualar a um novo inteiro, apontamos (=) para esse novo (new) objeto do tipo inteiro (int) criado, e com atributos devidamente alocados (5, métodos da classe int, etc).

```cpp
Pessoa* pessoa = (Pessoa*)malloc(sizeof(Pessoa));
Pessoa* pessoa = new Pessoa();
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

## * vs ** vs & vs nada: quando e como utilizar?

Há muita confusão sobre o uso desses símbolos.

No geral, um ponteiro possui "3 valores":

- &p = endereço de 'p'.
- p = conteúdo de 'p', normalmente o endereço da variável para onde o 'p' aponta
- *p = conteúdo da variável para onde o 'p' aponta.

Imagine esse p como sendo um bloco com 3 seções. Uma com &p, outra com p e outra com *p. Segue imagem pra exemplificar melhor:

![image](https://user-images.githubusercontent.com/98990221/197656696-1f4c4c93-2429-4a0a-af69-8e3363567d51.png)

> Nota: Quando o asterisco é usado com declaração de variável, é algo totalmente diferente do uso do asterisco acompanhado apenas da variável. Ou seja, int* p != *p. Mais detalhes abaixo.


## Cópia vs Referência em parâmetro de método ou função

Por hora, por fim, falarei sobre o uso de ponteiros para passar valores por cópia, referência ou ponteiros.

### Passagem por cópia

```cpp
void atribuicao(int x, int y){
    x = 3
    y = 5
}

int main(){
    int x = 10, y = 20;
    atribuicao(x, y);
    cout << x << y << endl; // Printará 10 e 20
}
```

- **Perceba que quando passo os valores para a função, estou criando cópias dela**, e ao serem atribuídas com novos valores dentro da função, nada mudará na main. Esse tipo de passagem de parâmetro por cópia é default na maioria das linguagens de programação, incluindo Python e Java (exceto quando se usa self/this).

### Passagem por referência usando *

```cpp
void atribuicao(int* x1, int* y1){
    *x1 = 3
    *y1 = 5
}

int main(){
    int x = 10, y = 20;
    atribuicao(&x, &y);
    cout << x << y << endl; // Printará 3 e 5
}
```

- **Já aqui passei os valores por referência**. Não estou criando cópia nenhuma dentro da função. Passar valores assim pra função é equivalente a isso aqui:

```cpp
int* x1 = &x;
int* y1 = &y
```

### Passagem por referência usando &

```cpp
void atribuicao(int& x1, int& y1){ // uso do int&
    x1 = 3
    y1 = 5
}

int main(){
    int x = 10, y = 20;
    atribuicao(x, y);
    cout << x << y << endl; // Printará 3 e 5
}
```

- **Aqui passei os valores também por referência, só que usando &**. Basicamente usando & e usando * fazem a mesma coisa. Passar valores assim pra função é equivalente a isso aqui:

```cpp
int& x1 = x;
int& y1 = y
```

> Nota: como já dito no tópico sobre *Ampersand int&*, não é muito aconselhável fazer isso, apesar de diminuir linhas de código.


## E o tipo void?

O tipo **void** possui propriedades muito peculiares, e que mudam com o uso de ponteiro.

### Void com variáveis

```cpp
void x; // Caso 1: ERRO
void* y; // Caso 2: OK
void& z; // Caso 3: ERRO
```

- O caso 1 ocasiona erro, pois é impossível declarar uma variável bruta sem um tipo.
- O caso 2 age de forma completamente diferente. Significa que y é um ponteiro que aponta pra qualquer tipo de dado, podendo ser qualquer endereço. Ou seja, y aponta pra um endereço de objeto do tipo "coringa", pode ser qualquer tipo que assumirá sua forma somente depois.
- O caso 3 ocasiona erro, pois referenciar diretamente um valor de tipo não assumido é impossível, afinal, void& aponta pra um valor, e não pro endereço, e não existe valor "coringa" em C++. Void& sempre ocasionará erro, sem exceções. Nunca se usa.

### Void com funções

```cpp
void f(int x){} // Caso 1: OK
void* f(int* x){return x;} // Caso 2: OK
```

- O caso 1 é uma função que retorna nada, trivial.
- O caso 2 é uma função que retorna um ponteiro que aponta pra qualquer tipo de dado, não interessando o tipo dele quando se trabalha com o dado dentro da função. A vantagem do uso de void* é quando você não sabe que tipo de dado irá ser retornado ou o tipo de dado que será enviado por parâmetro.

> Nota: a função malloc() é do tipo void*, ou seja, retorna um ponteiro do tipo void*.

```cpp
void* ptr_coringa = malloc(sizeof(int));
int* ptr_pra_int = (int*)ptr_coringa;
```
