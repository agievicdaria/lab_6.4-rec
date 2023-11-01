#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void findMinMaxIndices(int array[], int n, int& minIndex, int& maxIndex, int currentIndex = 0) {
    if (currentIndex >= n) {
        return;
    }

    if (array[currentIndex] > array[maxIndex]) {
        maxIndex = currentIndex;
    }
    if (array[currentIndex] < array[minIndex]) {
        minIndex = currentIndex;
    }

    findMinMaxIndices(array, n, minIndex, maxIndex, currentIndex + 1);
}


int calculateProduct(int array[], int startIndex, int endIndex) {
    if (startIndex >= endIndex) {
        return 1;
    }
    return array[startIndex] * calculateProduct(array, startIndex + 1, endIndex);
}

void inputArray(int*& array, int n, int currentIndex = 0) {
    if (currentIndex >= n) {
        return;
    }
    cin >> array[currentIndex];
    inputArray(array, n, currentIndex + 1);
}

void sortEvenElements(int array[], int size, int currentIndex = 0) {
    if (currentIndex >= size - 1) {
        return;
    }

    if (array[currentIndex] % 2 == 0) {
        for (int j = currentIndex + 1; j < size; ++j) {
            if (array[j] % 2 == 0 && array[j] < array[currentIndex]) {
                int temp = array[currentIndex];
                array[currentIndex] = array[j];
                array[j] = temp;
            }
        }
    }

    sortEvenElements(array, size, currentIndex + 1);
}

void printArray(int array[], int n, int currentIndex = 0) {
    if (currentIndex >= n) {
        cout << endl;
        return;
    }
    cout << array[currentIndex] << " ";
    printArray(array, n, currentIndex + 1);
}

int main() {
    int n;
    cout << "Введіть кількість елементів у масиві: ";
    cin >> n;

    int *array = new int[n];

    cout << "Введіть елементи масиву:" << endl;
    inputArray(array, n);

    int minIndex = 0, maxIndex = 0;
    findMinMaxIndices(array, n, minIndex, maxIndex);

    int startIndex = (minIndex < maxIndex) ? (minIndex + 1) : (maxIndex + 1);
    int endIndex = (minIndex > maxIndex) ? minIndex : maxIndex;

    int product = calculateProduct(array, startIndex, endIndex);

    cout << "Масив: ";
    printArray(array, n);

    sortEvenElements(array, n);
    cout << "Масив після впорядкування парних елементів за зростанням: ";
    printArray(array, n);

    cout << "Добуток елементів між максимальним та мінімальним елементами: " << product << endl;

    delete[] array;

    return 0;
}
