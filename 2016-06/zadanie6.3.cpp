//Podaj,  ile  wierszy  w  pliku 
//liczby.txt  zawiera  liczby  parzyste  zapisane  w  systemie  dwójkowym. 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    int numCount = 0;
    string number;

    ifstream file;
    file.open("liczby.txt");
    
    for(int i = 0; i < 999; i++) {
        file >> number;
        if(number[number.length()-1] == '2' && number[number.length()-2] == '0') {
            numCount++;
        }
    }
    cout << numCount;
}