#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> queue;
    int order = 0;

    while (true) {
        string input;
        cout << "Enter surname or 'Next' (type 'exit' to quit): ";
        cin >> input;

        if (input == "exit") {
            break;
        }

        if (input == "Next") {
            if (!queue.empty()) {
                auto it = queue.begin();
                cout << "Calling: " << it->first << endl;
                queue.erase(it);
            }
            else {
                cout << "Queue is empty!" << endl;
            }
        }
        else {
            queue.insert({ input, order++ });
        }
    }
    return 0;
}
