/*W tym zadaniu rozważmy odległość liter w alfabecie
– np. litery A i B są od siebie oddalone  o 1, A i E o 4, F i D o 2,
a każda litera od siebie samej jest oddalona o 0.
Wypisz wszystkie słowa, w których każde dwie litery oddalone są od siebie w alfabecie
co najwyżej o 10. Słowa wypisz w kolejności występowania w pliku sygnaly.txt, 
po jednym w wierszu. 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ifstream file;
    file.open("sygnaly.txt");
    string signal;

    ofstream wyniki;
    wyniki.open("zadanie4.3.txt");

    char maxLetter;
    char minLetter;

    for(int i = 0; i < 1000; i++) {
        
        maxLetter = 'A';
        minLetter = 'Z';

        file >> signal;

        for(int j = 0; j < signal.length(); j++) {
            if(signal[j] > maxLetter) {
                maxLetter = signal[j];
            } 
            if(signal[j] < minLetter) {
                minLetter = signal[j];
            }
        }

        if(maxLetter-minLetter <= 10) {
            wyniki << signal << endl;
        }
    }

    return 0;
}