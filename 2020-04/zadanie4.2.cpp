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

    int longestFragment = 0;
    int longestStart = 0;
    int longestEnd = 0;

    int currentFragment = 2;
    int currentStart = numbers[0];
    int currentEnd = numbers[1];
    int currentDistance = getDistance(numbers[0], numbers[1]);
    int newDistance;

    for(int i = 1; i < 999; i++) {
        newDistance = getDistance(numbers[i], numbers[i+1]);
        if(newDistance == currentDistance) {
            currentEnd = numbers[i+1];
            currentFragment += 1;
        } else {
            if(currentFragment > longestFragment) {
                longestStart = currentStart;
                longestEnd = currentEnd;
                longestFragment = currentFragment;
            }
            currentFragment = 2;
            currentStart = numbers[i];
            currentEnd = numbers[i+1];
            currentDistance = getDistance(numbers[i], numbers[i+1]);
        }
    }
    cout << "Longest fragment: " << longestFragment << " starts at: " << longestStart << " ends at: " << longestEnd << endl;

}