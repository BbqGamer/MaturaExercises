#include <iostream>
#include <fstream>

using namespace std;

bool areSame(bool * tab1, bool * tab2) {
    for(int i = 0; i < 101; i++) {
        if(tab1[i] != tab2[i]) {
            return false;
        }
    }
    return true;
}

int main() {

    ifstream file1;
    ifstream file2;

    file1.open("dane1.txt");
    file2.open("dane2.txt");

    int number1;
    int number2;

    bool liczby1[101];
    bool liczby2[101];

    int ile = 0;

    for(int i = 0; i < 1000; i++) {

        for(int j = 0; j < 101; j++) {
            liczby1[j] = 0;
            liczby2[j] = 0;
        } //ZERUJ TABLICE LICZB

        for(int j = 0; j < 10; j++) {

            file1 >> number1;
            file2 >> number2;

            liczby1[number1] = 1;
            liczby2[number2] = 1;
        }

        if(areSame(liczby1, liczby2)) {
            ile += 1;
            cout << i + 1 << " ";
        }
    }
    cout << endl << ile << " pary ciągow" << endl;
}