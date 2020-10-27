#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool isPrime(int number) {
    for(int i = 2; i < number/2; i++) {
        if(number % i == 0) {
            return false;
        }
    }
    return true;
}

int getLength(int number) {
    int length = 0;
    while(number > 0) {
        length += 1;
        number /= 10;
    }
    return length;
}

int revertNumber(int number) {
    int numLength = getLength(number);

    int newNumber = 0;
    numLength--;

    while(numLength >= 0) {
        newNumber += (number % 10) * pow(10, numLength);
        number /= 10;
        numLength--;
    }
    return newNumber;
}

int main() {

    ifstream file;
    file.open("pierwsze.txt");

    ofstream outputFile;
    outputFile.open("wynik4_2.txt");

    int number;
    int revertedNumber;

    for(int i = 0; i < 200; i++) {
        file >> number;
        revertedNumber = revertNumber(number);
        if(isPrime(revertedNumber)) {
            outputFile << number << endl;
        }
    }
}