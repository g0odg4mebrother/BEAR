#include <iostream>
using namespace std;

struct SeparatedArrays {
    int* positives;
    int* negatives;
    int* zeros;
};

SeparatedArrays separateElements(int* arr, int size) {
    int posCount = 0, negCount = 0, zeroCount = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0)
            posCount++;
        else if (arr[i] < 0)
            negCount++;
        else
            zeroCount++;
    }

    SeparatedArrays result;
    result.positives = new int[posCount];
    result.negatives = new int[negCount];
    result.zeros = new int[zeroCount];

    int posIdx = 0, negIdx = 0, zeroIdx = 0;

  
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0)
            result.positives[posIdx++] = arr[i];
        else if (arr[i] < 0)
            result.negatives[negIdx++] = arr[i];
        else
            result.zeros[zeroIdx++] = arr[i];
    }

    return result;
}

void printSeparatedArrays(SeparatedArrays arrays) {
    cout << "Положительные элементы: ";
    for (int i = 0; i < sizeof(arrays.positives) / sizeof(*arrays.positives); ++i) {
        cout << arrays.positives[i] << ' ';
    }
    cout << endl;

    cout << "Отрицательные элементы: ";
    for (int i = 0; i < sizeof(arrays.negatives) / sizeof(*arrays.negatives); ++i) {
        cout << arrays.negatives[i] << ' ';
    }
    cout << endl;

    cout << "Нулевые элементы: ";
    for (int i = 0; i < sizeof(arrays.zeros) / sizeof(*arrays.zeros); ++i) {
        cout << arrays.zeros[i] << ' ';
    }
    cout << endl;
}

int main() {
    int arr[] = { 1, -2, 0, 3, -4, 0, 5, -6, 7, 0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    SeparatedArrays separated = separateElements(arr, size);

    printSeparatedArrays(separated);

    delete[] separated.positives;
    delete[] separated.negatives;
    delete[] separated.zeros;

    return 0;
}