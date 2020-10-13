//Podaj, ile liczb z pliku liczby.txt ma w swoim zapisie binarnym więcej zer niż jedynek. 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    string liczba;

    ifstream file;
    file.open("liczbt.txt");

    int length;
    int zeroCount = 0;
    int liczbyCount = 0;

    for(int i = 0; i < 1000; i++) {

        file >> liczba;
        length = liczba.length();
        zeroCount = 0;

        for(int j = 0; j < length; j++) {
            if(liczba[j] == '0') {
                zeroCount++;
            }
        }

        if(zeroCount > (length - zeroCount)) {
            liczbyCount++;
        }
    }
    cout << liczbyCount;
    
    return 0;
}