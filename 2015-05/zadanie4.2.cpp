//Podaj, ile liczb w pliku liczby.txt jest podzielnych przez 2 
//oraz ile liczb jest podzielnych przez 8. 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ifstream file;
    file.open("liczby.txt");

    string binNumber;

    int divisableByTwo = 0;
    int divisableByEight = 0;
    
    for(int i = 0; i < 1000; i++) {
        file >> binNumber;
        int length = binNumber.length();

        if(binNumber[length-1] == '0') {
            divisableByTwo++;
            if(binNumber[length-2] == '0') {
                divisableByEight++;
            }
        }
    }
    cout << "Podzielne przez 2: " << divisableByTwo << ", Podzielne przez 8: " << divisableByEight;

    return 0;
}