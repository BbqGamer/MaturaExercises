//Naukowcy zauwazyli, ze 
//po złączeniu dziesiątych liter co czterdziestego 
//słowa (zaczynając od słowa czterdziestego) otrzymamy 
//pewne przesłanie. Wypisz to przesłanie. 
//Uwaga: Każde co czterdzieste słowo ma co najmniej 10 znaków. 
//Dla danych z pliku przyklad.txt wynikiem jest: NIECHCIMATURAPROSTABEDZIE

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {

    string signal;
    ifstream file;
    file.open("sygnaly.txt");

    for(int i = 1; i <= 1000; i++) {

        file >> signal;

        if(i % 40 == 0) {
            cout << signal[9];
        }
    }

    return 0;
}