#include <iostream>
#include <fstream>

using namespace std;

int main() {

    int liczba;
    int cyfra;

    ifstream file;
    file.open("kody.txt");

    ofstream oFile;
    oFile.open("kody1.txt");

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

        oFile << parzyste << " " << nieparzyste << endl;

    }

    return 0;
}