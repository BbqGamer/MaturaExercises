//Podaj   kod   największej   oraz   kod   najmniejszej   spośród   liczb  
//zakodowanych   w   pliku   liczby.txt oraz ich wartości w systemie dziesiętnym.  

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

long long convertToDec(string _number) {
    long long number = 0;
    int length = _number.length()-1;
    int base = _number[length]-'0';

    for(int i = 0; i < length; i++) {
        number += (_number[i]-'0') * pow(base, length-1-i);
    }

    return number;
}

int main() {

    string number;

    ifstream file;
    file.open("liczby.txt");

    long long max = -1;
    long long min = 1231241;

    string codeMax;
    string codeMin;

    int converted;
    for(int i = 0; i < 999; i++) {
        file >> number;
        converted = convertToDec(number);

        if(converted > max) {
            max = converted;
            codeMax = number;
        }
        if(converted < min) {
            min = converted;
            codeMin = number;
        }
    }
    cout << "Min: " << min << ", with code: " << codeMin << endl;
    cout << "Max: " << max << ", with code: " << codeMax << endl;
}