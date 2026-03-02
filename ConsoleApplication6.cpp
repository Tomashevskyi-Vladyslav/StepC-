# include <iostream>
# include <string>
# include <cctype>

using namespace std;

void restriction(int max_calls) {
	int static count_of_calls = 0;
	count_of_calls++;
	
	if (count_of_calls == max_calls) {
		cout << "Calls limit exceeded!";
		count_of_calls = 0;
		cout << endl << "Counter reset : The counter has been reset" << endl;
	}
	
	else {
		cout << "Calls namber " << count_of_calls << ": " << "Function executed successfully" << endl;
	}
	
}

template <typename T>
T max_finde_one_dimention(T array[], int elements_count) {
	T maxVal = array[0];
	
	for (int i = 1; i < elements_count; i++) {
		if (array[i] > maxVal) {
			maxVal = array[i];
		}
	}
	return maxVal;
}

template <typename T, int raw, int cols>
T max_finde_two_dimention(T (&array)[raw][cols]) {
	T maxVal = array[0][0];

	for (int i = 0; i < raw; i++) {
		for (int j = 0; j < cols; j++) {
			if (array[i][j] > maxVal) {
				maxVal = array[i][j];
			}
		}
	}
	return maxVal;
}

void find_symbols() {
	string word = "Hello 123!";
	int letters = 0, digits = 0, others = 0;

	for (int i = 0; i < word.length(); i++) {
		if (isalpha(word[i])) {
			letters++;
		}
		else if (isdigit(word[i])) {
			digits++;
		}
		else {
			others++;
		}
	}

	cout << "Letters: " << letters << endl;
	cout << "Digits: " << digits << endl;
	cout << "Others: " << others << endl;
}

void find_leter() {
	string word;
	char target;
	int count = 0;

	cout << "Enter the word :";
	cin >> word;

	cout << "Enter a character to search for :";
	cin >> target;

	for (int i = 0; i < word.length(); i++) {
		if (word[i] == target) {
			count++;
		}
	}

	if (count > 0) {
		cout << "Symbol '" << target << "' meets " << count << " time(s)" << endl;
	}
	else {
		cout << "Symbol '" << target << "' there is no word" << endl;
	}
}

int main() {
	//for (int i = 0; i < 5; ++i)  restriction(3);
	
	//int array_int[5] = { 1, 2, 3, 4, 5 };
	//double array_double[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	//cout << "Max in array_int :" << max_finde_one_dimention(array_int, 5) << endl;
	//cout << "Max in array_double :" << max_finde_one_dimention(array_double, 5) << endl;

	//int matrix[2][3] = {
	//		{1, 5, 3},
	//		{8, 2, 6}};

	//double dMatrix[3][2] = {
	//	{1.1, 5.5},
	//	{12.7, 2.2},
	//	{9.9, 0.4}};

	//cout << "Max in matrix :" << max_finde_two_dimention(matrix) << endl;
	//cout << "Max in dMatrix :" << max_finde_two_dimention(dMatrix) << endl;

	//find_symbols();
	
	find_leter();
	return 0;
}