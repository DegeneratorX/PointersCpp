#include<iostream>
#include<algorithm>

using std::cout; using std::cin; using std::endl;

void imprime_com_const(const int* objeto_1){
    objeto_1 = new int(3); // OK, pois estou mudando o endereço do ponteiro, não o valor do int anônimo na memória
    //*objeto_1 = 30;      // ERRO! Estou mudando o valor do int anônimo na memória, que é um const.
    //cout << *objeto_1 << endl;
}
void imprime_sem_const(int* objeto_2){
    objeto_2 = new int(3);
    *objeto_2 = 23;


}
int main(){
    int* objeto_1 = new int(10); imprime_com_const(objeto_1);
    const int* objeto_2 = new int(20); //imprime_sem_const(objeto_2);

    char* s = new char[4];
    s = "Ola";
    s[0] = 'f';


    //const char str[] = "Ola";
    //char* p_str = str;

    cout << s << endl;
}