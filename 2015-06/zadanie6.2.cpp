#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    string kody[10] = {
        "10101110111010",
        "11101010101110",
        "10111010101110",
        "11101110101010",
        "10101110101110",
        "11101011101010",
        "10111011101010",
        "10101011101110",
        "11101010111010",
        "10111010111010"};

    int liczba;
    int cyfra;

    ifstream file;
    file.open("kody.txt");

    ofstream oFile;
    oFile.open("kody2.txt");

    for(int i = 0; i < 500; i++) {

        int parzyste = 0;
        int nieparzyste = 0;

        file >> liczba;
        for(int j = 0; j < 6; j++) {
            cyfra = liczba % 10;
            liczba /= 10;

            if(j % 2 == 0) {
                parzyste += cyfra;
            } else {
                nieparzyste += cyfra;
            }
        }

        int sumaKontrolna;
        sumaKontrolna = 3 * parzyste + nieparzyste;
        sumaKontrolna = sumaKontrolna % 10;
        sumaKontrolna = 10 - sumaKontrolna;
        sumaKontrolna = sumaKontrolna % 10;
    
        oFile << kody[sumaKontrolna] << endl;

    }

    return 0;
}