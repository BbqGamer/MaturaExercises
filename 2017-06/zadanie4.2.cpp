#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream file;
    file.open("punkty.txt");

    int number;
    int number2;
    bool digitTab[10];
    bool digitTab2[10];

    int similiarCount = 0;

    for(int i = 0; i < 1000; i++) {
        file >> number;
        file >> number2;

        for(int j = 0; j < 10; j++) {
            digitTab[j] = 0;
            digitTab2[j] = 0;
        }

        while(number > 0) {
            digitTab[number%10] = 1;
            number = number / 10;
        }

        while(number2 > 0) {
            digitTab2[number2%10] = 1;
            number2 = number2 / 10;
        }

        bool similiar = 1;

        for(int j = 0; j < 10; j++) {
            if(digitTab[j] != digitTab2[j]) {
                similiar = 0;
                break;
            }
        }

        if(similiar) {
            similiarCount++;
        }
    }

    cout << similiarCount << endl;

    return 0;
}