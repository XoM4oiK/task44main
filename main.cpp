#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm> 
#include <sstream>  
#include <string>

using namespace std;


void initRandomArray(int arr[], int size, int minVal, int maxVal) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % (maxVal - minVal + 1) + minVal;
    }
}

string arrayToString(int arr[], int size) {
    stringstream ss;
    for (int i = 0; i < size; ++i) {
        ss << arr[i] << " ";
    }
    return ss.str();
}


int findFirstMinAbsIndex(int arr[], int size) {
    if (size <= 0) return -1; // Handle empty array
    int minAbs = abs(arr[0]);
    int minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (abs(arr[i]) < minAbs) {
            minAbs = abs(arr[i]);
            minIndex = i;
        }
    }
    return minIndex;
}


int findLastMaxAbsIndex(int arr[], int size) {
    if (size <= 0) return -1; // Handle empty array
    int maxAbs = abs(arr[0]);
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (abs(arr[i]) >= maxAbs) {
            maxAbs = abs(arr[i]);
            maxIndex = i;
        }
    }
    return maxIndex;
}

int calculateSumBetween(int arr[], int size) {
    int minIndex = findFirstMinAbsIndex(arr, size);
    int maxIndex = findLastMaxAbsIndex(arr, size);

    if (minIndex == -1 || maxIndex == -1) return 0; // Handle empty array or no min/max

    int start = min(minIndex, maxIndex);
    int end = max(minIndex, maxIndex);
    int sum = 0;

    for (int i = start + 1; i < end; ++i) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    srand(time(0)); 

    int size, minVal, maxVal;

    cout << "Input size of array: ";
    cin >> size;

    cout << "Input range of values (min, max): ";
    cin >> minVal >> maxVal;

    int* arr = new int[size];

    initRandomArray(arr, size, minVal, maxVal);

    cout << "Array elements: " << arrayToString(arr, size) << endl;

    int sum = calculateSumBetween(arr, size);
    cout << "Sum of array values between min and max values is: " << sum << endl;

    delete[] arr;

    return 0;
}


