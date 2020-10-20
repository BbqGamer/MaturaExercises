#include <iostream>
#include <fstream>

using namespace std;

bool isPrime(int number) {
    if(number == 0 || number == 1) {
        return 0;
    }
    for(int i = 2; i < number-1; i++) {
        if(number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {

    ifstream file;
    file.open("punkty.txt");

    int primeNumber = 0;
    int number;
    int number2;

    for(int i = 0; i < 1000; i++) {
        file >> number;
        file >> number2;
        if(isPrime(number) && isPrime(number2)) {
            primeNumber++;
        }
    }

    cout << "Liczba pierwszych: " << primeNumber << endl;

    return 0;
}