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

int digitSum(int number) {
    int sum = 0;
    while(number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int weigth(int number) {
    int sum = digitSum(number);
    if(sum / 10 == 0) {
        return sum;
    } else {
        return weigth(sum);
    }
}

int main() {

    ifstream file;
    file.open("pierwsze.txt");

    int number;
    int weightOneCount = 0;

    for(int i = 0; i < 300; i++) {
        file >> number;
        if(weigth(number) == 1) {
            weightOneCount += 1;
        }
    }
    cout << weightOneCount << endl;
}