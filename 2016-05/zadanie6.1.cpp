#include <iostream>
#include <fstream>

using namespace std;

char moveLetter(char letter, int k) {
    letter = letter - 65;
    letter = (letter + k) % 26;
    letter = letter + 65;
    return letter;
}

int main() {

    int k = 107;

    ifstream file;
    file.open("dane_6_1.txt");

    ofstream oFile;
    oFile.open("wynik_6_1.txt");

    string word;

    for(int i = 0; i < 100; i++) {
        file >> word;
        int x = 0;
        while(word[x] != '\0') {
           word[x] = moveLetter(word[x], k);
           x += 1;
        }
        oFile << word << endl;
    }
}