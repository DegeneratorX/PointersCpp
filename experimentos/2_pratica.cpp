#include<iostream>
#include<algorithm>
#include<string>

using std::cout; using std::cin; using std::endl;
using std::string;

int main(){
    int* arr = new int[3 * 7]; // Espaço da matriz já alocado de tamanho 3 x 7.
    // cout << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 7; j++){
            // Acessando índices. Multiplico sempre a soma deles pela largura da matriz.
            arr[i + j * 7] = 0; // Preencho a matriz i x j com zeros
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 7; j++){
            cout << arr[i + j * 7] << " ";
        }
        cout << "\n";
    }
}