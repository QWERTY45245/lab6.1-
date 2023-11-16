#include<Windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ARRAY_SIZE = 24;
const int LOWER_BOUND = -15;
const int UPPER_BOUND = 75;

void generateArray(int arr[], int size);
void displayArray(const int arr[], int size);
void processArray(int arr[], int size, int& count, int& sum, int index = 0);
void modifyArray(int arr[], int size, int index = 0);

int main() {
    srand(time(0));

    int arr[ARRAY_SIZE];
    generateArray(arr, ARRAY_SIZE);
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "Початковий масив:\n";
    displayArray(arr, ARRAY_SIZE);

    int count = 0, sum = 0;
    processArray(arr, ARRAY_SIZE, count, sum);

    cout << "Кількість елементів, які задовольняють критерію: " << count << endl;
    cout << "Сума елементів, які задовольняють критерію: " << sum << endl;

    modifyArray(arr, ARRAY_SIZE);

    cout << "\nМодифікований масив:\n";
    displayArray(arr, ARRAY_SIZE);

    return 0;
}

void generateArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;
    }
}

void displayArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void processArray(int arr[], int size, int& count, int& sum, int i) {
    if (i < size) {
        if (arr[i] % 2 == 0 && arr[i] <= 0) {
            count++;
            sum += arr[i];
        }
        processArray(arr, size, count, sum, i + 1);
    }
}

void modifyArray(int arr[], int size, int index) {
    if (index < size) {
        if (arr[index] % 2 == 0 && arr[index] <= 0) {
            arr[index] = 0;
        }
        modifyArray(arr, size, index + 1);
    }
}
