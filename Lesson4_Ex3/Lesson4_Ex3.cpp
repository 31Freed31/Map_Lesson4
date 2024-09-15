#include <iostream>
#include <map>
#include <string>

using namespace std;

bool areAnagrams(const string& str1, const string& str2) {
    if (str1.size() != str2.size()) {
        return false;
    }

    map<char, int> charCount;

    for (char ch : str1) {
        charCount[ch]++;
    }

    for (char ch : str2) {
        charCount[ch]--;
    }

    for (const auto& entry : charCount) {
        if (entry.second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string str1, str2;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    if (areAnagrams(str1, str2)) {
        cout << "The strings are anagrams." << endl;
    }
    else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}
