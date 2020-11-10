#include <iostream>
#include <fstream>

using namespace std;

int silnia (int n) {
    int wynik = 1;

    for(int j = 2; j <= n; j++) {
        wynik *= j;
    }

    return wynik;
}

int silnieCyfr(int number) {
    int wynik = 0;
    while(number > 0) {
        wynik += silnia(number % 10);
        number /= 10;
    }
    return wynik;
}

int main() {

    ifstream file;
    file.open("liczby.txt");

    int number;

    for(int i = 0; i < 500; i++) {
        file >> number;
        if(silnieCyfr(number) == number) {
            cout << number << endl;
        }
    }
    
    return 0;
}