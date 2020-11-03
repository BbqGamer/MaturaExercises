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
    oFile.open("kody3.txt");

    for(int i = 0; i < 500; i++) {

        oFile << "11011010"; //START

        int cyfry[6];
        int parzyste = 0;
        int nieparzyste = 0;

        file >> liczba;
        for(int j = 0; j < 6; j++) {
            cyfra = liczba % 10;
            liczba /= 10;
            cyfry[5-j] = cyfra;

            if(j % 2 == 0) {
                parzyste += cyfra;
            } else {
                nieparzyste += cyfra;
            }
        }

        for(int j = 0; j < 6; j++) {
            oFile << kody[cyfry[j]];
        }

        int sumaKontrolna;
        sumaKontrolna = 3 * parzyste + nieparzyste;
        sumaKontrolna = sumaKontrolna % 10;
        sumaKontrolna = 10 - sumaKontrolna;
        sumaKontrolna = sumaKontrolna % 10;
    
        oFile << kody[sumaKontrolna] //SUMA KONTROLNA
              << "11010110" //STOP
              << endl;

    }

    return 0;
}