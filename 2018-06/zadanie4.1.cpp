#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream file1;
    ifstream file2;

    file1.open("dane1.txt");
    file2.open("dane2.txt");

    int number1;
    int number2;

    int ile = 0;

    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 10; j++) {
            file1 >> number1;
            file2 >> number2;
        }
        if(number1 == number2) {
            ile += 1;
        }

    }
    cout << ile;
}