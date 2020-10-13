//Podaj,  ile  wierszy  w  pliku  liczby.txt  zawiera  liczby  zapisane  
//w  systemie  czwórkowym  takie, że w ich zapisie nie występuje cyfra 0. 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool hasZero(string number) {
    for(int i = 0; i < number.length()-1; i++) {
        if(number[i] == '0') {
            return true;
        }
    }
    return false;
}

int main() {

    int numCount = 0;
    string number;

    ifstream file;
    file.open("liczby.txt");
    
    for(int i = 0; i < 999; i++) {
        file >> number;
        if(number[number.length()-1] == '4' && !hasZero(number)) {
            numCount++;
        }
    }
    cout << numCount;
}