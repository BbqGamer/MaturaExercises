#include <iostream>
#include <fstream>

using namespace std;

bool isPowerOfThree(int number) {
    while(number % 3 == 0) {
        number /= 3;
    }
    if(number == 1) {
        return true;
    }
    return false;
}

int main() {

    ifstream file;
    file.open("przyklad.txt");

    int number;
    int count = 0;

    for(int i = 0; i < 500; i++) {
        file >> number;
        if(isPowerOfThree(number)) {
            count += 1;
        }
    }

    cout << count << endl;

    return 0;
}