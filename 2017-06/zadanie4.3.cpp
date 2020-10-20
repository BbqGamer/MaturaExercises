#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

float getDistance(long x1, long y1, long x2, long y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

int main() {

    ifstream file;
    file.open("punkty.txt");

    int xTab[1000];
    int yTab[1000];

    for(int i = 0; i < 1000; i++) {
        file >> xTab[i];
        file >> yTab[i];
    }

    float maxDistance = 0;
    int maxX1;
    int maxY1;
    int maxX2;
    int maxY2;
    int newDistance;

    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            newDistance = getDistance(xTab[i], yTab[i], xTab[j], yTab[j]);
            if(newDistance > maxDistance) {
                maxDistance = newDistance;
                maxX1 = xTab[i];
                maxY1 = yTab[i];
                maxX2 = xTab[j];
                maxY2 = yTab[j];
            }
        }
    }

    cout << "(" << maxX1 << ", " << maxY1 << ") and " 
         << "(" << maxX2 << ", " << maxY2 << ") with distance: " << round(maxDistance) << endl;

    return 0;
}