//Znajdź  najmniejszą  i  największą  liczbę  w  pliku  liczby.txt. 
//Jako  odpowiedź  podaj  numery wierszy, w których się one znajdują. 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isBigger(string first, string second) {
    if(first.length() > second.length()) {
        return true;
    } else if (first.length() < second.length()) {
        return false;
    } else {
        for(int j = 0; j < first.length(); j++) {
            if(first[j] == '0' && second[j] == '0') {
                continue;
            } else if(first[j] == '0') {
                return false;
            } else if (second[j] == '0')
                return true;
            }
        }
        return false;
}

int main() {

    ifstream file;
    file.open("liczby.txt");

    string binNumber;

    string biggestNumber;
    string smallestNumber;
    
    file >> binNumber;
    biggestNumber = binNumber;
    smallestNumber = binNumber;

    int biggestIndex = 1;
    int smallestIndex = 1;

    for(int i = 1; i < 1000; i++) {
        file >> binNumber;
        
        if(isBigger(binNumber, biggestNumber)) {
            biggestNumber = binNumber;
            biggestIndex = i+1;
        }

        if(!isBigger(binNumber, smallestNumber)) {
            smallestNumber = binNumber;
            smallestIndex = i+1;
        }
    }

    cout << "Najmniejsza: " << smallestIndex << ", największa: " << biggestIndex << endl;

    return 0;
}