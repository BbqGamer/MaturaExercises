#include <iostream>
#include <fstream>

using namespace std;

int calcNwd(int a, int b) {
    int c;
    while(b > 0) {
        c = a;
        a = b;
        b = c % b;
    }
    return a;
}

int main() {

    ifstream plik;
    plik.open("liczby.txt");

    int liczby[500];
    for(int i = 0; i < 500; i++) {
        plik >> liczby[i];
    }

    int maxStart;
    int maxLength = 0;
    int maxNwd;

    for(int i = 0; i < 500; i++) {

        int length = 0;
        int koniec = i;
        int lastNwd = liczby[i];

        while(calcNwd(lastNwd, liczby[koniec]) > 1 && koniec < 500) {
            lastNwd = calcNwd(lastNwd, liczby[koniec]);
            length += 1;
            koniec += 1;
        }

        if(length > maxLength) {
            maxStart = liczby[i];
            maxLength = length;
            maxNwd = lastNwd;
        }

    }

    cout << maxStart << "\n" 
    << maxLength << "\n"
    << maxNwd;

    return 0;
}