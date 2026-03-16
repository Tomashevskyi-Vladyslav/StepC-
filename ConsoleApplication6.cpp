#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool existsInArray(int value, const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) return true;
    }
    return false;
}

bool existsInVector(int value, const vector<int>& vec) {
    for (int x : vec) {
        if (x == value) return true;
    }
    return false;
}

int* removeEvenNumbers(int* oldArray, int size, int& newSize) {
    newSize = 0;
    if (oldArray == nullptr || size <= 0) {
        return nullptr;
    }

    for (int i = 0; i < size; i++) {
        if (oldArray[i] % 2 != 0) {
            newSize++;
        }
    }

    if (newSize == 0) return nullptr;

    int* newArray = new int[newSize];

    int index = 0;
    for (int i = 0; i < size; i++) {
        if (oldArray[i] % 2 != 0) {
            if (index < newSize) {
                newArray[index] = oldArray[i];
                index++;
            } 
            
            else {
                break;
            }
        }
    }

    return newArray;
}


void insertBlock(int*& arr, int& size, int index, int* newBlock, int blockSize) {
    if (index < 0) index = 0;
    if (index > size) index = size;

    int newSize = size + blockSize;
    int* newArray = new int[newSize];

    for (int i = 0; i < index; i++) {
        newArray[i] = arr[i];
    }

    for (int i = 0; i < blockSize; i++) {
        newArray[index + i] = newBlock[i];
    }

    for (int i = index; i < size; i++) {
        newArray[i + blockSize] = arr[i];
    }

    delete[] arr;
    arr = newArray;
    size = newSize;
}


int main() {
    //int M, N;

    //cout << "Enter the size of array A :";
    //cin >> M;
    //int* A = new int[M];
    //cout << "Enter the elements of array A :";
    //for (int i = 0; i < M; i++) cin >> A[i];

    //cout << "Enter the size of array B :";
    //cin >> N;
    //int* B = new int[N];
    //cout << "Enter the elements of array B :";
    //for (int i = 0; i < N; i++) cin >> B[i];

    //vector<int> C;

    //for (int i = 0; i < M; i++) {
    //    if (!existsInArray(A[i], B, N) && !existsInVector(A[i], C)) {
    //        C.push_back(A[i]);
    //    }
    //}

    //for (int i = 0; i < N; i++) {
    //    if (!existsInArray(B[i], A, M) && !existsInVector(B[i], C)) {
    //        C.push_back(B[i]);
    //    }
    //}

    //cout << "Result: [";
    //for (int x : C) {
    //    cout << x << " ";
    //}
    //cout << "]" << endl;

    //delete[] A;
    //delete[] B;


    //int size;
    //cout << "Enter the array size :";
    //cin >> size;

    //int* arr = new int[size];
    //cout << "Enter the items :";
    //for (int i = 0; i < size; i++) cin >> arr[i];

    //int newSize = 0;
    //int* result = removeEvenNumbers(arr, size, newSize);

    //if (result != nullptr) {
    //    cout << "Array without even numbers :";
    //    for (int i = 0; i < newSize; i++) {
    //        cout << result[i] << " ";
    //    }
    //    cout << endl;
    //    delete[] result;
    //}
    //else {
    //    cout << "There are no odd numbers in the array" << endl;
    //}

    //delete[] arr;


    int size = 5;
    int* arr = new int[size] {1, 2, 3, 4, 5};

    cout << "Initial array :";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    int index, blockSize;
    cout << "Enter the index to insert :";
    cin >> index;
    cout << "How many elements do you want to insert? :";
    cin >> blockSize;

    int* block = new int[blockSize];
    cout << "Enter the items to insert :";
    for (int i = 0; i < blockSize; i++) cin >> block[i];

    insertBlock(arr, size, index, block, blockSize);

    cout << "Array after insertion :";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    delete[] block;

    return 0;
}