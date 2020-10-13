//Podaj sumę wszystkich liczb z pliku liczby.txt,
//które zapisano w systemie ósemkowym. Wynik podaj w systemie dziesiętnym. 

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

long long convertFromOct(string octNum) {
    long long number = 0;
    int length = octNum.length()-1;

    for(int i = 0; i < length; i++) {
        number += (octNum[i]-'0') * pow(8, length-1-i);
    }

    return number;
}

int main() {
    
    long long octSum = 0;
    string number;

    ifstream file;
    file.open("liczby.txt");
    
    for(int i = 0; i < 999; i++) {
        file >> number;
        if(number[number.length()-1] == '8') {
            octSum += convertFromOct(number);
        }
    }
    cout << octSum << endl;
    
}