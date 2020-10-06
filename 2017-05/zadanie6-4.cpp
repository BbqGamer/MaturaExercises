#include <fstream>
#include <iostream>

using namespace std;

int linesPerColumn[320][256];

int main() {

    int screen[200][320];

    ifstream file;
    file.open("dane.txt");

    for(int i = 0; i < 200; i++) {
        for(int j = 0; j < 320; j++) {
            file >> screen[i][j];
        }
    }

    int lastPixel = 0;
    int currentPixel = 0;
    int currentLine = 0;
    for(int j = 0; j < 320; j++) {
        for(int i = 0; i < 200; i++) {
            currentPixel = screen[i][j];
            if(i == 0) {
                linesPerColumn[j][currentPixel] += 1;
                lastPixel = currentPixel;
                currentLine = 1;
            } else {
                if(currentPixel == lastPixel) {
                    currentLine += 1;
                    if(currentLine > linesPerColumn[j][currentPixel]) {
                        linesPerColumn[j][currentPixel] = currentLine;
                    }
                } else {
                    lastPixel = currentPixel;
                    currentLine = 1;
                }
            }
        }
    }
    int max = 0;
    int line;
    int pixel;
    for(int i = 0; i < 320; i++) {
        for(int j = 0; j < 256; j++) {
            if(linesPerColumn[i][j] > max) {
                max = linesPerColumn[i][j];
                line = i;
                pixel = j;
            }
        }
    }
    cout << max << " " << line << " " << pixel << endl;

}