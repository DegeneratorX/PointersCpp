# Ponteiros em C++
Tudo sobre ponteiros, mastigado. Tive dificuldades para entender o conceito, e por isso criei esse repositório: para basicamente treinar e fixar o conhecimento. Conhecimento adquirido através desses cursos:

- https://youtu.be/zuegQmMdy8M
- https://youtu.be/kiUGf_Z08RQ
- https://www.youtube.com/watch?v=18c3MTX0PK0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&ab_channel=TheCherno -> playlist de vários vídeos super interessantes e simplificados sobre C++.
- https://www.udemy.com/course/data-structures-algorithms-cpp/
- https://www.udemy.com/course/data-structures-algorithms-python/ -> Esse aqui foi usado como referência para melhor compreensão do uso de POO.


Esse readme é para mostrar conceitos básicos da programação procedural e que até hoje alguns são extremamente utilizados.

# O que é um ponteiro?

Um ponteiro é basicamente um tipo de variável especial que pode receber apenas endereço de memória ou "recebe" outra variável do tipo ponteiro (as aspas em "recebe" será explicada depois).

O endereço de memória normalmente possui um formato *0x????????*, onde *?* pode ser um número de 0 a f em hexadecimal. A quantidade de *?* pode variar de acordo com o computador e compilador. Um endereço nesse formato ocupa 8 bytes em sistemas 64bit, 4 bytes em sistemas 32bit e 2 bytes em sistemas 16bit. Adotarei 8 bytes como um "sizeof" padrão de um ponteiro.

A grande vantagem do uso de um ponteiro é poder, de forma segura, alterar valores de variáveis pelo programa inteiro, inclusive fora do escopo de funções e classes. Isso seria possível sem o uso de ponteiros, mas necessita de muita gambiarra e uso bem maior de memória/processamento, o que torna praticamente inviável quando se exige desempenho, e por isso seu uso é tão influente em estruturas de dados. Fora que para alocar memória dinamicamente, é obrigatório o seu uso. Falo sobre isso no arquivo CONCEITOS.md.

> Nota: Inicialmente irei nesse readme utilizar bastante exemplos com inteiros para facilitar o entendimento, mas o uso de ponteiro serve para todos os tipos primitivos de dados e Classes, e são praticamente aplicados da mesma forma.

## Por que se utiliza ponteiros em C?

Na verdade se utiliza ponteiros em todas as linguagens, desde assembly. Só que em C e seus derivados, o uso é explícito, porém com uma interface bonita.

Imagine o seguinte: existe uma string de 200 bytes (200 caracteres) de dados em um local na memória. E eu preciso acessar esses dados e substituir por outro de 500 bytes, por exemplo. O processador já teria um trabalho imenso de ler 200 bytes, para depois sobrescrever esses dados. Os ponteiros solucionam esse desgaste desnecessário, pois ele lê apenas 8 bytes, que é o endereço de onde o objeto se localiza. A partir desse registro, nós podemos sobrescrever dados.

É mais fácil dar o endereço de uma casa do que dar a cópia de uma casa para alguém.

## Como declarar um ponteiro

Há 3 formas de declarar ponteiros:

```cpp
int* p; // Caso 1 - Mais utilizado
float * p; // Caso 2
double *p; // Caso 3
```

> Nota: Perceba que todos os casos acima são iguais. Isso serve pra mostrar que eventualmente é possível encontrar códigos onde se usa algumas dessas formas para declarar um tipo *ponteiro*.

- Didaticamente, o Caso 1 é o mais legível e convencional, visto que confunde menos ao colocar o **asterisco próximo do tipo** que o ponteiro aponta.
- O Caso 3 resulta em muita confusão para quem está começando a aprender ponteiros, pois mais pra frente vamos ver que usar '*p' de forma isolada possui funcionalidade **completamente diferente**, chamada de deferência.

```cpp
int* x; // 8 bytes
float* y; // 8 bytes
double* z; // 8 bytes
```

Todos os tipos ocupam 8 bytes. O tipo int, float e double nesse caso são somente auxiliares, e somente diz para o compilador para que tipo de variável o ponteiro x, y ou z pode apontar no futuro, se vai ser um int, float ou double. E claro, declarar um ponteiro avisa para o compilador reservar 8 bytes para guardar o endereço.

Ou seja, esqueça os tipos quando se trata de ponteiro. Um ponteiro, para qualquer tipo, é só um inteiro que guarda um endereço de memória.

## Como inicializar um ponteiro

Como já foi dito, ponteiro só pode receber 2 tipos de valores: um endereço, ou outra variável do tipo ponteiro (que já aponta pra um objeto através de um endereço, óbvio).

### Ponteiro recebendo endereço diretamente

```cpp
int a; // Declaração de variável
a = 2; // Inicialização

int* b; // Declaração de ponteiro.
b = &a; // Inicialização (agora b passa a apontar pra a).
```

- Aqui o ponteiro b recebe o endereço de a (&a). 
- Basicamente o '&a' por si só é um **tipo ponteiro para 'a'**, e 'b' recebe esse ponteiro. 
- De forma análoga, é como se fosse uma string *"Olá Mundo"*. Por si só ela é uma string mesmo não tendo sido inicializada em nenhuma variável.

> Nota: sempre que quiser acessar o endereço de um objeto na memória, usa-se '&objeto'. O operador & (ampersand) retorna o endereço que o objeto está localizado, em formato *0x????????*

- Pronto, criamos um ponteiro *b* que aponta pra um inteiro *a* através do uso do endereço.

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

- *d* aponta pra *c*, que *c* aponta pra *b*, que *b* aponta pra *a*. Ou seja, *d* "aponta" pra *a* de forma indireta. A partir de *d*, é possível, por incrível que pareça, obter informações de *a* e mudar eles, por exemplo, o valor 10.

## Tipos de ponteiros

Existem 2 tipos de ponteiros: um que guarda um endereço de um objeto na memória e referencia seu conteúdo, e outro que referencia seu conteúdo apenas, sem guardar nada.

```cpp
int* // Tipo ponteiro normal
int& // Tipo ponteiro referência
```

Os dois tem a mesma função: apontar pra um objeto na memória.

- 'int*' é muito mais poderoso que o 'int&', pois aponta pro endereço de memória e guarda esse endereço, ao custo de ocupar memória (8 bytes), pois o ponteiro também é uma variável que armazena o endereço de *a*. É o mais utilizado pelos programadores.
- 'int&' é menos comum e é usado para economizar linhas de código, pois diferente do int*, em tempo de compilação, na maioria dos casos, o int& não ocupa memória. Pois é. Ou seja, serve puramente para enxugar linhas de código, além de operar bem mais rápido que o uso de um int*. Assim como o int*, o int& também modifica valores via referência. A grande desvantagem de não usarem frequentemente int& é que a partir do momento que se referencia algo, não tem mais como mudar a referência, ou seja, apontar pra outro objeto. Somente ponteiro é capaz, graças a capacidade de armazenar endereços.


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

> Curiosidade: *b* **"não existe"**. Somente no código fonte. b não existe em tempo de compilação, nem ocupa memória nem armazena nada, pois como foi dito anteriormente, int& é um ponteiro invisível que serve somente para enxugar código e puramente serve para modificarmos o valor de *a* diretamente em qualquer parte do programa. É como se b = a, só que tudo que acontece em b, acontece em a. É uma forma também de dar um outro nome a mesma variável. Inclusive ambos possuem o mesmo endereço de memória. Se b fosse int*, teria endereço de memória diferente, e aí sim ocuparia os 8 bytes de espaço armazenando o endereço de a.

Entenda *int a* como um **arquivo.txt** e *int& b* um **atalho** para esse .txt no desktop. Porém, um atalho que ocupa 0 bytes. E tudo que for escrito e modificado abrindo pelo atalho, será modificado no arquivo original.

> Nota: TUDO que se faz com int& também dá pra fazer com int*, mas não o inverso. Aconselha-se usar int& apenas em caso de mudanças simples de valores por referência ao longo do programa.

Para mudar valores via referẽncia usando int&, simplesmente mudamos o valor de *b*, que aponta para *a*.

```cpp
int a = 10;
int& b = a; // ponteiro invisível que aponta pra 'a'.
b = 12 // é como se fosse a = b = 12 de forma completamente automática
cout << a << endl; // agora 'a' passa a assumir valor 12. Printará 12 na tela.
```

> Nota: Para fazer o mesmo com int*, chamamos de deferência, e será abordado em breve abaixo, pois possui maior complexidade.

> Nota 2: Existe a possibilidade de um int& ocupar espaço na memória, mas tudo vai depender de como o compilador vai ver essa necessidade. No geral ele não ocupa.

## Acessar o conteúdo de um objeto (Deferência, Derreferência, ou desreferência)

Após aprender a apontar para um objeto, precisamos saber como funciona o acesso e a modificação do conteúdo desse objeto.

Vimos que para acessar o conteúdo de um objeto usando int& é super simples. E para mudar o valor por referência, basta mudar o valor de *b*, que *a* mudava automaticamente.

Mas no caso do *b* ser do tipo int*, envolve uma sintaxe extra para acessar esse mesmo conteúdo. O nome disso é derreferenciar,

Derreferenciar é acessar a informação (conteúdo) no endereço contido por um ponteiro, com a possibilidade de modificar esse conteúdo, e como consequência, o conteúdo da variável para o qual o ponteiro aponta também muda para o mesmo valor. É um conceito parecidíssimo com referência, a diferença é que int& trabalha com valores diretamente, e int* passa a trabalhar também com endereços (ou pra quem está apontando).

Para deferenciar, utilizamos o operador '*' antes de um ponteiro para acessar o conteúdo para o qual o ponteiro aponta. Se prepara, pois agora vai ter bastante confusão.

```cpp
int a = 10
int* b = &a // Referência. Capturo o endereço de a. b agora aponta pra a.
*b = 12 // Dereferência. Acesso o conteúdo para o qual b aponta (10). Modifico ele e coloco 12.
cout << a << endl; // agora 'a' passa a assumir valor 12. Printará 12 na tela.
```

- Como atribui *b = 12, 'a' agora passa a ser 12. Isso é derreferenciar. 
- Basta colocar o asterisco * antes do b, e pronto, fará a mesma coisa do int& b = a.
- O * nesse caso não é multiplicação e nada tem a ver com int*. O * nesse momento é outra coisa completamente diferente, no caso um OPERADOR que diz pro compilador que você quer acessar o conteúdo para o qual o *b* aponta, que é o valor (conteúdo) de *a*.

Aqui está a diferença trivial desse uso do asterisco, para evitar confusão:

```cpp
int* p = &a; // Asterisco acoplado ao inteiro, indica que não é mais tipo 'int', mas agora é o tipo intptr, que é um ponteiro para um inteiro 'a'.
*p = 10 // Asterisco acoplado a variável ponteiro. Significa um operador que diz que vc quer acessar o conteúdo da variável que p aponta. Ou seja, acessar o conteúdo de 'a'.
```

Ou seja, int* p != *p. 

> int* é um tipo de variável. O asterisco (*) antes de p é um operador.


## int* vs int&: qual utilizar?

- int*
    - Aponta para um objeto do tipo inteiro;
    - Muda valores por referência;
    - Opera mais lentamente em tempo de compilação;
    - Armazena endereço (8/4/2 bytes para 64/32/16bit);
    - Pode mudar e apontar pra outros objetos a qualquer hora;
    - Comumente utilizado (tanto para operações simples quanto complexas).

- int&
    - Aponta para um objeto do tipo inteiro;
    - Muda valores por referência;
    - Opera mais rapidamente em tempo de compilação;
    - Não armazena nada (não é variável, boa parte dos casos é invisível na compilação, puramente estético para enxugar código);
    - Não pode mudar apontamento para outros objetos.
    - Menos utilizado (normalmente para operações simples).

```cpp
int a = 10; // a = 10, &a = 0xAAA, *a = ERRO

int& b = a; // b = 10, &b = 0xAAA, *b = ERRO

int* c = &a; // c = 0xAAA, &c = 0xCCC, *c = 10
```
- Tanto o caso do int& quando o caso do int* estão fazendo exatamente a **MESMA** coisa. **Referenciando**.
- A diferença é que **int* aponta pro endereço de memória de um objeto**. Ou seja, qualquer variável do tipo int* só pode receber valores do tipo **endereço de memória**.
- E o **int& meio que aponta pro valor de um objeto, não endereço**. Ou seja, qualquer variável do tipo int& pode receber valores inteiros diretamente. 

![image](https://user-images.githubusercontent.com/98990221/197656250-231bedaa-070d-40f6-9782-0f1bea1dd2d5.png)

> Nota: Referenciar usando endereços (int*) se torna mais seguro para alterar valores por referência, porém consome mais memória. Afinal, com endereço (int*), você sabe tanto o endereço quanto o conteúdo, e sabendo só o conteúdo (int&), você perde outras informações, por exemplo, nós de uma lista encadeada e consecutivos apontamentos, além de não poder apontar pra onde um tipo* ponteiro aponta.

## * vs ** vs & vs nada: qual, quando e como utilizar?

Há muita confusão sobre o uso desses símbolos.

No geral, um ponteiro """possui 3 valores""" (entenda assim para facilitar o conceito):

- &p = retorna o endereço de 'p'.
- p = conteúdo de 'p', normalmente o endereço da variável para onde o 'p' aponta
- *p = conteúdo da variável para onde o 'p' aponta.

Imagine esse p como sendo um bloco com 3 seções. Uma com &p, outra com p e outra com *p. Segue imagem pra exemplificar melhor:

![image](https://user-images.githubusercontent.com/98990221/197656696-1f4c4c93-2429-4a0a-af69-8e3363567d51.png)

É claro que a imagem não representa realmente o que se passa na memória, mas é uma abstração do que ocorre de uma forma mais lógica, a fim de facilitar o entendimento.


## Cópia vs Referência em parâmetro de método ou função

Falarei sobre o uso de ponteiros para passar valores por cópia ou referência em funções.

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

- **Perceba que quando passo os valores para a função, estou criando cópias dela**, e ao serem atribuídas com novos valores dentro da função, nada mudará na main. Esse tipo de passagem de parâmetro por cópia é default na maioria das linguagens de programação, incluindo Python e Java (exceto quando se usa self/this, que trabalha automaticamente por referência).

### Passagem por referência usando int*

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

- **Já aqui passei os valores por referência**. Não estou criando cópia nenhuma dentro da função, e isso me economiza memória. Passar valores assim pra função é equivalente a isso aqui:

```cpp
int* x1 = &x;
int* y1 = &y
```

### Passagem por referência usando int&

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

Uma vantagem é que não preciso ficar derreferenciando dentro da função com o operador * para mudar o conteúdo de cada variável.


## E o tipo void?

O tipo **void** possui propriedades muito peculiares, e que mudam com o uso de ponteiro.

### Void com variáveis

```cpp
void x; // Caso 1: ERRO
void* y; // Caso 2: OK
void& z; // Caso 3: ERRO
```

- O caso 1 ocasiona erro, pois é impossível declarar uma variável bruta sem um tipo.
- O caso 2 age de forma completamente diferente. Significa que y é um ponteiro que aponta pra qualquer tipo de dado, podendo ser qualquer endereço. Ou seja, y aponta pra um endereço de objeto do tipo "coringa", pode ser qualquer tipo que assumirá sua forma somente depois. No código fonte, não importa pra que tipo de dado um ponteiro aponta. Só importará em tempo de compilação.
- O caso 3 ocasiona erro, pois referenciar diretamente um valor de tipo não assumido é impossível, afinal, void& aponta pra um valor, e não pro endereço, e não existe valor "coringa" em C++. Void& sempre ocasionará erro, sem exceções.

Um outro caso curioso é esse aqui:

```cpp
int x = 8;
void* p = &x;
*ptr = 10; // ERRO
```

- No momento que eu digo que 'p' é um ponteiro que não liga pra que tipo de variável ele vai apontar (void*), mas só quer o endereço, não há problemas. Mas se eu tentar mudar o conteúdo para qual 'p' aponta e colocar 10, o compilador definitivamente não sabe se aquele '10' é um int, ou um short, long long, ou até um char (char é um "int" com 1 byte). Ai é erro na certa.
- Basicamente se é preciso derreferenciar em algum momento, evitar usar void*.

### Void com funções

```cpp
void f(int x){} // Caso 1: OK
void* f(int* x){return x;} // Caso 2: OK
```

- O caso 1 é uma função que retorna nada, trivial.
- O caso 2 é uma função que retorna um ponteiro que aponta pra qualquer tipo de dado, não interessando o tipo dele quando se trabalha com o dado dentro da função. A vantagem do uso de void* é quando você não sabe que tipo de dado irá ser retornado ou o tipo de dado que será enviado por parâmetro.


# Entendido o básico de ponteiros...

Fiz um documento sobre conceitos mais utilizados na programação, e como ponteiros participam desses conceitos.
Leia o arquivo **CONCEITOS.md**.