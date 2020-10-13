//Podaj, ile liczb w pliku liczby.txt zapisano w systemie ósemkowym. 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    int octCount = 0;
    string number;

    ifstream file;
    file.open("liczby.txt");
    
    for(int i = 0; i < 999; i++) {
        file >> number;
        if(number[number.length()-1] == '8') {
            octCount++;
        }
    }
    cout << octCount;
}