#include <iostream>
#include <fstream>

using namespace std;

bool isPrime(int number) {
    for(int i = 2; i < number/2; i++) {
        if(number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    ifstream file;
    file.open("liczby.txt");

    ofstream outputFile;
    outputFile.open("wyniki4_1.txt");

    int number;

    for(int i = 0; i < 300; i++) {
        file >> number;
        if(isPrime(number) && number > 100 && number < 5000) {
            outputFile << number << endl;
        }
    }
}