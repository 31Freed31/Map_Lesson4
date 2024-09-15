#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    map<string, string> phoneToName;
    map<string, string> nameToPhones;

    while (true) {
        string input;
        cout << "Enter a command (or type 'exit' to quit): ";
        cin >> input;

        if (input == "exit") {
            break;
        }

        if (isdigit(input[0])) {
            if (input.size() == 8) {
                string name;
                cin >> name;
                phoneToName[input] = name;
                nameToPhones.insert({ name, input });
                cout << "Added: " << input << " -> " << name << endl;
            }
            else {
                if (phoneToName.find(input) != phoneToName.end()) {
                    cout << "Name: " << phoneToName[input] << endl;
                }
                else {
                    cout << "Phone number not found!" << endl;
                }
            }
        }
        else {
            auto range = nameToPhones.equal_range(input);
            if (range.first != range.second) {
                cout << "Phone numbers for " << input << ": ";
                for (auto it = range.first; it != range.second; ++it) {
                    cout << it->second << " ";
                }
                cout << endl;
            }
            else {
                cout << "Name not found!" << endl;
            }
        }
    }
    return 0;
}
