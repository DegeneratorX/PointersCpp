# Arquivos em C++

Abordarei aqui sobre linking, namespace, outros arquivos .cpp, .h, #include, mais sobre declarações e definições, extern, static, inline, diretivas de pre-processamento utilizando #, leitura e escrita de arquivos de texto e bibliotecas stream.

# Linking

- TODO

## Translation Unit

- TODO

# Namespace

- TODO

# .cpp e .h

- TODO

## cpp

- TODO

## h

- TODO

# #include

- TODO

# Declarações VS Definições (avançado)

- TODO

## Declaração

- TODO

## Definição

- TODO

# Extern

- TODO

# Static

A keyword **static** é peculiar, pois possui diversos comportamentos dependendo de como ela é utilizada. Para todo uso de **static**, é feita uma alocação estática de memória. Alguns casos específicos sem o uso da keyword (como variáveis em namespaces) também alocam estaticamente, como já foi falado em CONCEITOS.md.

Existem 4 tipos de usos principais para **static**

- Variável dentro de um escopo (local)
- Variável global ou função
- Variável de uma classe
- Método de uma classe

## Static em variável dentro de um escopo

```cpp
void print(){
    static int x = 0;
    cout << x << endl;
    x++;
}
int main(){
    print(); // i = 0
    print(); // i = 1
    print(); // i = 2
}
```

O que acontece aqui é que o x não irá resetar para 0 quando a função for chamada novamente. No fim do programa, x será 2.

O espaço alocado para entidades estáticas fica no armazenamento estático na RAM, e o espaço é alocado pelo linker logo antes do programa ser executado. Ou seja, a alocação estática de memória ocorre em tempo de compilação. Sempre é memorizada a variável mesmo depois de indefinidos call stacks, e previne uma reinicialização dela. Ou seja, uma variável estática só é inicialziada uma vez. Outras inicializações serão ignoradas.

A variável com static dura até o programa encerrar, e não é possível deletar. Sem static, x seria guardado na pilha e deletado assim que encerrasse o escopo da função. E para cada print, printaria 0, 0 e 0 ao invés de 0, 1 e 2.

## Static em variável global ou função

```cpp
// Global Namespace
static int x = 10;
static void print(){/*...*/}

int main(){
/* ... */
}
```

'x' será visível por todo o programa, mas não será visível por outros arquivos. Ou seja, ficará somente visível dentro da translation unit. O mesmo vale para a função print(). É como se fosse declarar uma variável "private" para outros arquivos não poderem ter acesso a ela. Sem static, x ou print() passam a serem utilizáveis por qualquer outro arquivo da build.

A variável também dura na memória até o programa encerrar.

## Static em atributo de classe

```cpp
class Pessoa{
public:
    static int idade = 19;
};
int Pessoa::idade; // OBRIGATÓRIO QUANDO SE USA VARIÁVEIS STATIC EM CLASSES.
int main(){
    Pessoa p1;
    Pessoa p2;
    Pessoa::idade = 25; // Ambos agora passam a ser 25
    cout << p1.idade == p2.idade << endl; // True. Mudou a idade para as duas (25).
}
```

O comportamento da static aqui é completamente diferente. Ao colocar em um atributo de classe, a static tem o papel de garantir que a variável *idade*, para qualquer instância da classe criada, compartilhe a mesma memória para todas essas instâncias. Isso significa que é como se idade de p1 e idade de p2 apontassem para uma só idade.

Para acessar essa idade, pode ser feito tanto pela instância quanto diretamente pela classe utilizando ::, que é muito mais convencional e utilizado.

## Static em método de classe

```cpp
class Pessoa{
public:
    static int idade;
    static void print(){ // Método estático
        cout << idade << endl;
    }
};
int Pessoa::idade;
int main(){
    Pessoa p;
    p.x = 10;
    p.print();

    Pessoa p2;
    p2.x = 20;
    p.print();

    Pessoa::print();
}
```

Um método estático é capaz de ser chamado sem ser pela instância, utilizando *::*. Um método estático só pode trabalhar com variáveis estáticas. Ou seja, trabalhar com variáveis não estáticas dentro do método estático ocasionará em erro. A instância "this" é proibida dentro do método, para evitar conflitos e acesso a membros da própria classe não estáticos.

# Inline

- TODO

# Diretivas de pré-processamento

- TODO

# Bibliotecas Stream

- TODO

# Leitra e escrita de arquivos

- TODO