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

    array[currentIndex] = 0;
    cout << "a[" << currentIndex << "]= ? ";
    cin >> array[currentIndex];

    inputArray(array, n, currentIndex + 1);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortEvenElements(int array[], int size, int currentIndex = 0, int nextIndex = 1) {
    if (currentIndex >= size - 1) {
        return;
    }

    if (nextIndex < size) {
        if (array[currentIndex] % 2 == 0 && array[nextIndex] % 2 == 0 && array[nextIndex] < array[currentIndex]) {
            swap(&array[currentIndex], &array[nextIndex]);
        }
        sortEvenElements(array, size, currentIndex, nextIndex + 1);
    } else {
        sortEvenElements(array, size, currentIndex + 1, currentIndex + 2);
    }
}

void printArray(int array[], int n, int currentIndex = 0) {
    if (currentIndex >= n) {
        cout << endl;
    } else {
        cout << setw(4) << array[currentIndex] << " ";
        printArray(array, n, currentIndex + 1);
    }
}

int calculateSumOfNegatives(int array[], int n, int currentIndex = 0) {
    if (currentIndex >= n) {
        return 0;
    }

    int currentElement = array[currentIndex];
    int sum = (currentElement < 0) ? currentElement : 0;
    return sum + calculateSumOfNegatives(array, n, currentIndex + 1);
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
    int sumOfNegatives = calculateSumOfNegatives(array, n);

    cout << "Масив: ";
    printArray(array, n);

    sortEvenElements(array, n);
    cout << "Масив після впорядкування парних елементів за зростанням: ";
    cout << endl;
    cout << "Масив: ";
    printArray(array, n);

    cout << "Добуток елементів між максимальним та мінімальним елементами: " << product << endl;
    cout << "Сума від'ємних елементів у масиві: " << sumOfNegatives << endl;

    delete[] array;

    return 0;
}
