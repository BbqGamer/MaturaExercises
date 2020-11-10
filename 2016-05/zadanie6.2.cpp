#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

char moveLetter(char letter, int k) {
    letter = letter - 65;
    letter = (letter + k) % 26;
    letter = letter + 65;
    return letter;
}

int main() {

    ifstream file;
    file.open("dane_6_2.txt");

    ofstream oFile;
    oFile.open("wynik_6_2.txt");

    string word;
    string number;

    for(int i = 0; i < 3000; i++) {

        file >> word;
        file >> number;

        cout << word << " " << number << endl;

        int x = 0;
        int move = 26 - (stoi(number)%26);

        while(word[x] != '\0') {
            
           word[x] = moveLetter(word[x], move);
           x += 1;
        }

        oFile << word << endl;
    }
}