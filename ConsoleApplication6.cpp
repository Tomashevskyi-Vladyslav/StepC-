#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

void createAndFill(int*& arr, int size) {
    if (size <= 0) {
        arr = nullptr;
        return;
    }

    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 21 - 10;
    }
}

void printArray(const int* arr, int size, const string& name) {
    cout << name << ": [ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

void sortAscending(int* arr, int size) {
    sort(arr, arr + size);
}

void mergeAndSortDescending(int* arrA, int sizeA, int* arrB, int sizeB, int*& resArr, int& resSize) {
    resSize = sizeA + sizeB;
    resArr = new int[resSize];

    int i = 0, j = 0, k = 0;
    while (i < sizeA && j < sizeB) {
        if (arrA[i] <= arrB[j]) {
            resArr[k++] = arrA[i++];
        }
        else {
            resArr[k++] = arrB[j++];
        }
    }

    while (i < sizeA) resArr[k++] = arrA[i++];
    while (j < sizeB) resArr[k++] = arrB[j++];

    for (int s = 0; s < resSize / 2; s++) {
        swap(resArr[s], resArr[resSize - 1 - s]);
    }
}


int* flattenMatrix(int** matrix, int rows, int cols) {
    int totalElements = rows * cols;

    int* linearArray = new int[totalElements];

    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            linearArray[k++] = matrix[i][j];
        }
    }

    return linearArray;
}


bool isValidLength(int length) {
    return length >= 8;
}

void generatePassword(char*& password, int length) {
    password = new char[length + 1];

    const char lower[] = "abcdefghijklmnopqrstuvwxyz";
    const char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";
    const char special[] = "!@#$%^&*()-_=+[]{}<>?";

    const int lowerLen = sizeof(lower) - 1;
    const int upperLen = sizeof(upper) - 1;
    const int digitsLen = sizeof(digits) - 1;
    const int specialLen = sizeof(special) - 1;

    password[0] = lower[rand() % lowerLen];
    password[1] = upper[rand() % upperLen];
    password[2] = digits[rand() % digitsLen];
    password[3] = special[rand() % specialLen];

    const char allChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}<>?";
    int allCharsLen = sizeof(allChars) - 1;

    for (int i = 4; i < length; i++) {
        password[i] = allChars[rand() % allCharsLen];
    }

    for (int i = 0; i < length; i++) {
        swap(password[i], password[rand() % length]);
    }

    password[length] = '\0';
}

void printPassword(const char* password) {
    if (password != nullptr) {
        cout << "Generated password :" << password << endl;
    }
}

int main() {
    //srand(static_cast<unsigned int>(time(0)));

    //int M, N;
    //cout << "Enter the size of array A :";
    //cin >> M;
    //cout << "Enter the size of array B :";
    //cin >> N;

    //int* A = nullptr, * B = nullptr, * C = nullptr;
    //int sizeC = 0;

    //createAndFill(A, M);
    //createAndFill(B, N);

    //cout << "\nGenerated arrays :" << endl;
    //printArray(A, M, "A (initial)");
    //printArray(B, N, "B (initial)");

    //sortAscending(A, M);
    //sortAscending(B, N);

    //cout << "\nSorted arrays (ascending) :" << endl;
    //printArray(A, M, "A (sorted)");
    //printArray(B, N, "B (sorted)");

    //mergeAndSortDescending(A, M, B, N, C, sizeC);

    //cout << "\nMerge result (descending) :" << endl;
    //printArray(C, sizeC, "C (result)");

    //delete[] A;
    //delete[] B;
    //delete[] C;


    //int rows = 3, cols = 4;

    //int** matrix = new int* [rows];
    //cout << "Initial matrix :" << endl;
    //for (int i = 0; i < rows; i++) {
    //    matrix[i] = new int[cols];
    //    for (int j = 0; j < cols; j++) {
    //        matrix[i][j] = i * cols + j + 1;
    //        cout << matrix[i][j] << "\t";
    //    }
    //    cout << endl;
    //}

    //int* linear = flattenMatrix(matrix, rows, cols);

    //cout << "\nResult (one-dimensional array) :" << endl;
    //for (int i = 0; i < rows * cols; i++) {
    //    cout << linear[i] << " ";
    //}
    //cout << endl;

    //for (int i = 0; i < rows; i++) delete[] matrix[i];
    //delete[] matrix;
    //delete[] linear;


    srand(static_cast<unsigned int>(time(0)));

    int length;
    char* password = nullptr;

    cout << " Enter the desired password length (minimum 8) :";
    cin >> length;

    if (!isValidLength(length)) {
        cout << "Error: password length must be at least 8 characters!" << endl;
        return 1;
    }

    generatePassword(password, length);
    printPassword(password);

    delete[] password;

    return 0;
}