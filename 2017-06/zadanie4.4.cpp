#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream file;
    file.open("punkty.txt");

    int inSide = 0;
    int onSide = 0;
    int outSide = 0;

    int number;
    int number2;

    for(int i = 0; i < 1000; i++) {
        file >> number;
        file >> number2;
        if(number < 5000 && number2 < 5000) {
            inSide++;
        } else if((number == 5000 && number2 <= 5000) || (number2 == 5000 && number <= 5000)) {
            onSide++;
        } else {
            outSide++;
        }
    }

    cout << "Wewnątrz: " << inSide << endl;
    cout << "Na Boku: " << onSide << endl;
    cout << "Na zewnątrz: " << outSide << endl;

    return 0;
}