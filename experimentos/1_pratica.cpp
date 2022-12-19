#include <iostream>
#include<array>

using std::cout; using std::cin; using std::endl;

std::array<int,3> retorno_stdarray(){ // Retorno um tipo 'array' de tamanho 3
    std::array<int,3> arr = {2, 4, 6}; // Funciona de forma idẽntica a um array.
    arr[1] = 15;
    return arr;
}
int main(){
	std::array<int,3> arr;
	arr = retorno_stdarray(); //function call
	for(int i=0 ; i<3 ; i++){
		cout << arr[i] << endl; // Imprime: 2, 15 e 6.
	}
}