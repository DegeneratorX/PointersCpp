#include <iostream>

using std::cout; using std::cin; using std::endl;

class Pessoa{
    static int a;
};
 


int main()
{
    int* a = new int[10];
    int count = sizeof(*a)/sizeof(int);
    int b[10];
    cout << count << endl;
    cout << sizeof(b) << endl;
    
}