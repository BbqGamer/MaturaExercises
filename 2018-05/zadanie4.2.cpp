/* 
Znajdź słowo, w którym występuje największa liczba różnych liter. 
Wypisz to słowo i liczbęwystępujących w nim różnych liter. 
Jeśli słów o największej liczbie różnych liter jest więcej niż jedno, 
wypisz pierwsze z nich pojawiające się w pliku z danymi. 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    bool letters[26];
    string signal;
    int maxLetters = 0;
    string maxSignal;

    ifstream file;
    file.open("sygnaly.txt");

    for(int i = 0; i < 1000; i++) {

        file >> signal;

        for(int j = 0; j < 26; j++) {
            letters[j] = false;
        }

        for(int j = 0; j < signal.length(); j++) {
            letters[signal[j]-'A'] = true;
        }
        
        int DifferentLetters = 0;

        for(int j = 0; j < 26; j++) {
            DifferentLetters += letters[j];
        }

        if(DifferentLetters > maxLetters) {
            maxLetters = DifferentLetters;
            maxSignal = signal;
        }
    }
    cout << maxSignal << " " << maxLetters << endl;
}