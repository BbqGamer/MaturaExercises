#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int getDistance(int a, int b) {
    return abs(a - b);
}

int main() {

    ifstream file;
    file.open("dane4.txt");

    int numbers[1000];

    for(int i = 0; i < 1000; i++) {
        file >> numbers[i];
    }

    int currentDistance = getDistance(numbers[0], numbers[1]);
    int maxDistance = currentDistance;
    int minDistance = currentDistance;
    

    for(int i = 1; i < 999; i++) {
        currentDistance = getDistance(numbers[i], numbers[i+1]);
        if(currentDistance < minDistance) {
            minDistance = currentDistance;
        }

        if(currentDistance > maxDistance) {
            maxDistance = currentDistance;
        }
    }

    cout << maxDistance << endl;
    cout << minDistance << endl;

}