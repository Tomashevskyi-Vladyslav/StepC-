# include <iostream>

using namespace std;

void sort_function(int array[], int count_of_elements) {

    const int half = count_of_elements / 2;
    
    int* array_fall_sort = new int [half] {};
    int* array_up_sort = new int[half] {};
    
    for (int i = 0; i < count_of_elements; ++i) {
        if (i < half) array_fall_sort[i] = array[i];
        else array_up_sort[i - half] = array[i];
    }
    
    for (int i = 1; i < half; i++) {
        int key = array_fall_sort[i];
        int j = i - 1;
        
        while (j >= 0 && array_fall_sort[j] < key) {
            array_fall_sort[j + 1] = array_fall_sort[j];
            j--;;
        }
        
        array_fall_sort[j + 1] = key;
    }

    for (int i = 1; i < half; i++) {
        int key = array_up_sort[i];
        int j = i - 1;

        while (j >= 0 && array_up_sort[j] > key) {
            array_up_sort[j + 1] = array_up_sort[j];
            j--;
        }
        array_up_sort[j + 1] = key;
    }
    
    cout << "fall sort: ";
    for (int i = 0; i < half; i++) {
        cout << array_fall_sort[i] << " ";
    }

    cout << endl << "up sort: ";
    for (int i = 0; i < half; i++) {
        cout << array_up_sort[i] << " ";
    }
    delete[] array_fall_sort;
    delete[] array_up_sort;
}


void sort_between_negatives(int array[], int size) {
    int first_neg = -1;
    int last_neg = -1;

    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            first_neg = i;
            break;
        }
    }

    for (int i = size - 1; i >= 0; i--) {
        if (array[i] < 0) {
            last_neg = i;
            break;
        }
    }

    if (first_neg == -1 || last_neg == -1 || first_neg >= last_neg - 1) {
        cout << "There are no items to sort between negative numbers" << endl;
        return;
    }

    cout << "Sort by index " << first_neg + 1 << " to " << last_neg - 1 << endl;

    for (int i = first_neg + 2; i < last_neg; i++) {
        int key = array[i];
        int j = i - 1;

        while (j > first_neg && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int get_sum_recursive(string text, int index) {
    if (index >= text.length()) {
        return 0;
    }

    int current_digit = 0;
    if (isdigit(text[index])) {
        current_digit = text[index] - '0';
    }

    return current_digit + get_sum_recursive(text, index + 1);
}

void sum_of_str(string text) {
    int total_sum = get_sum_recursive(text, 0);
    cout << "Sum of digits: " << total_sum << endl;
}

int output(int from, int to){
    if (from == to) return 0;

}

void print_reverse(int current, int end) {
    if (current < end) {
        return;
    }

    cout << current << " ";

    print_reverse(current - 1, end);
}

int main() {
    //int array[10] = { 1, 3, 2, 4, 5, 0, 8, 7, 6, 9 };
    //sort_function(array, 10);
    
    //int arr[10] = { 5, -3, 10, 2, 8, 1, -5, 4, -2, 7 };
    //int elements = 10;
    //sort_between_negatives(arr, elements);
    //cout << "Array after middle sorting: ";
    //for (int i = 0; i < n; i++) cout << arr[i] << " ";
    //cout << endl;
    
    //string text;
    //cout << "Enter nambers :"; cin >> text;
    //sum_of_str(text);

    int from;
    int to;
    cout << "Enter namber from :"; cin >> from;
    cout << "Enter namber to :"; cin >> to;
    print_reverse(from, to);

    return 0;




}