#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream file1;
    ifstream file2;
    ofstream oFile;

    file1.open("dane1.txt");
    file2.open("dane2.txt");
    oFile.open("wynik4_4.txt");

    int number1;
    int number2;

    int ile = 0;

    int elements1[10];
    int elements2[10];
    int merged[20];

    for(int i = 0; i < 1000; i++) {

        for(int j = 0; j < 10; j++) {

            file1 >> number1;
            file2 >> number2;

            elements1[j] = number1;
            elements2[j] = number2;
        }
        
        //MERGING

        int cursor1 = 0;
        int cursor2 = 0;

        for(int j = 0; j < 20; j++) {
            if(cursor1 >= 10) {
                merged[j] = elements2[cursor2];
                cursor2 += 1;
            } else if(cursor2 >= 10) {
                merged[j] = elements1[cursor1];
                cursor1 += 1;
            } else if(elements1[cursor1] < elements2[cursor2]) {
                merged[j] = elements1[cursor1];
                cursor1 += 1;
            } else {
                merged[j] = elements2[cursor2];
                cursor2 += 1;
            }
        }

        for(int j = 0; j < 20; j++) {
            oFile << merged[j] << " ";
        }

       oFile << endl;
    }
}