#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string prepareWord(string word) {
    word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

int main() {
    vector<string> forbidden;
    ifstream badWordsFile("bad_words.txt");
    string word;

    if (badWordsFile.is_open()) {
        while (badWordsFile >> word) {
            forbidden.push_back(prepareWord(word));
        }
        badWordsFile.close();
    }
    else {
        cerr << "Error: file bad_words.txt not found!" << endl;
        return 1;
    }

    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    while (inputFile >> word) {
        string clean = prepareWord(word);

        auto it = find(forbidden.begin(), forbidden.end(), clean);

        if (it == forbidden.end()) {
            outputFile << word << " ";
        }
        else {
            cout << "Forbidden word found :" << word << endl;
        }
    }

    cout << "Done! Check the output.txt file" << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}