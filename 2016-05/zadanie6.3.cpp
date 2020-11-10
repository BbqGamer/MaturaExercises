#include <iostream>
#include <fstream>

using namespace std;

char moveLetter(char letter, int k) {
    letter = letter - 65;
    letter = (letter + k) % 26;
    letter = letter + 65;
    return letter;
}

bool isCoded(string word, string expectedResult) {
    for(int j = 0; j < 26; j++) {

        int x = 0;
        bool canBe = 1;

        while(expectedResult[x] != '\0') {
           if(moveLetter(expectedResult[x], j) != word[x]) {
               canBe = 0;
               break;
           }
           x += 1;
        }
        if(canBe) {
            return true;
        }
    }
    return false;
}

int main() {

    ifstream file;
    file.open("dane_6_3.txt");

    ofstream oFile;
    oFile.open("wynik_6_3.txt");

    string word;
    string expectedResult;

    int count = 0;

    for(int i = 0; i < 3000; i++) {
        file >> word;
        file >> expectedResult;

        if(!isCoded(word, expectedResult)) {
            oFile << word << endl;
        }
    }
    cout << count;
}