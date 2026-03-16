#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool isValidPart(string s) {
    if (s.empty() || s.length() > 3) return false;

    if (s.length() > 1 && s[0] == '0') return false;

    for (char c : s) {
        if (!isdigit(c)) return false;
    }

    int num = stoi(s);
    return num >= 0 && num <= 255;
}

bool isValidIPv4(string ip) {
    if (ip.empty() || ip.front() == '.' || ip.back() == '.') return false;

    vector<string> parts;
    stringstream ss(ip);
    string temp;

    while (getline(ss, temp, '.')) {
        parts.push_back(temp);
    }

    if (parts.size() != 4) return false;

    for (string part : parts) {
        if (!isValidPart(part)) return false;
    }

    return true;
}

void student_name(vector <string> & students) {
    string name;
    
    for (int i = 0; i < 5; i++) {
        getline(cin, name);
        cin.ignore();
        students.push_back(name);
    }
    sort(students.rbegin(), students.rend());
}

string find_longest_word(string text) {
    stringstream ss(text);
    string word;
    string longest = "";

    while (ss >> word) {
        if (word.length() > longest.length()) {
            longest = word;
        }
    }

    return longest;
}


bool is_palindrome(string s) {
    int start = 0;
    int end = s.length() - 1;

    while (start < end) {
        if (tolower(s[start]) != tolower(s[end])) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}


int main() {
    //string ip;
    //cout << "Enter IP address: ";
    //cin >> ip;

    //if (isValidIPv4(ip)) {
    //    cout << "Result: Addresses are CORRECT" << endl;
    //}
    //else {
    //    cout << "Result: Addresses are INCORRECT" << endl;
    //}

    //vector <string> name_students;
    //student_name(name_students);
    //for (string i : name_students) {
    //    cout << endl << i << endl;
    //}

    //string text;
    //char target;
    //int count = 0;

    //cout << "Enter the line :";
    //getline(cin, text);

    //cout << "Enter a character to search for :";
    //cin >> target;

    //for (int i = 0; i < text.length(); i++) {
    //    if (text[i] == target) {
    //        count++;
    //    }
    //}

    //cout << "Symbol '" << target << "' occurs" << count << " times" << endl;
    
    
    //string userInput;

    //cout << "Enter the sentence :";
    //getline(cin, userInput);

    //string result = find_longest_word(userInput);

    //if (result.empty()) {
    //    cout << "You have not entered any words." << endl;
    //}
    //else {
    //    cout << "The longest word " << result << endl;
    //    cout << "Its length :" << result.length() << " symbols" << endl;
    //}

    //string word;
    //cout << "Enter a word or string :";
    //cin >> word;

    //if (is_palindrome(word)) {
    //    cout << "The string is a palindrome" << endl;
    //}
    //else {
    //    cout << "The string is NOT a palindrome" << endl;
    //}

    return 0;
}