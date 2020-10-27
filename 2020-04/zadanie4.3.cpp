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

    int distances[1000];

    for(int i = 0; i < 999; i++) {
        distances[i] = getDistance(numbers[i], numbers[i+1]);
    }

    int distanceCounts[999];

    for(int i = 0; i < 999; i++) {
        distanceCounts[i] = 1;
        for(int j = i+1; j < 999; j++) {
            if(distances[j] == distances[i]) {
                distanceCounts[i] += 1;
            }
        }
    }

    int max = 0;
    for(int i = 0; i < 999; i++) {
        if(distanceCounts[i] > max) {
            max = distanceCounts[i];
        }
    }

    cout << "Max count: " << max << endl;
    for(int i = 0; i < 999; i++) {
        if(distanceCounts[i] == max) {
            cout << distances[i] << endl;
        }
    }
}