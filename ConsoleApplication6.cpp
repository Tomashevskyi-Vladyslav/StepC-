# include <iostream>
# include <algorithm>

using namespace std;

int main() {
    //const int SIZE = 5;
    //int source[SIZE] = { 10, 20, 30, 40, 50 };
    //int destination[SIZE];

    //int* ptrSource = source;
    //int* ptrDest = destination;

    //for (int i = 0; i < SIZE; ++i) {
    //    *ptrDest = *ptrSource;

    //    ptrSource++;
    //    ptrDest++;
    //}

    //cout << "Destination array after copying :" << endl;
    //for (int i = 0; i < SIZE; ++i) {
    //    cout << destination[i] << " ";
    //}
    //cout << endl;


    //const int SIZE = 6;
    //int arr[SIZE] = { 1, 2, 3, 4, 5, 6 };

    //cout << "Original array :";
    //for (int i = 0; i < SIZE; ++i) cout << arr[i] << " ";
    //cout << endl;

    //int* left = arr;
    //int* right = arr + SIZE - 1;

    //while (left < right) {
    //    int temp = *left;
    //    *left = *right;
    //    *right = temp;

    //    left++;
    //    right--;
    //}

    //cout << "Inverted array :";
    //for (int i = 0; i < SIZE; ++i) cout << arr[i] << " ";
    //cout << endl;


    const int SIZE = 5;
    int source[SIZE] = { 1, 2, 3, 4, 5 };
    int destination[SIZE];

    int* ptrSource = source;

    int* ptrDest = destination + SIZE - 1;

    for (int i = 0; i < SIZE; ++i) {
        *ptrDest = *ptrSource;

        ptrSource++;
        ptrDest--;
    }

    cout << "Output array :";
    for (int i = 0; i < SIZE; i++) cout << source[i] << " ";

    cout << "\nTarget array (reverse) :";
    for (int i = 0; i < SIZE; i++) cout << destination[i] << " ";
    cout << endl;

    return 0;
}