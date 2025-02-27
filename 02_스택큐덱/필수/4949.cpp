#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string line;

    while (true) {
        getline(cin, line);
        if (line == ".") break; 

        stack<char> s;
        bool balanced = true;

        for (char ch : line) {
            if (ch == '(' || ch == '[') {
                s.push(ch);
            }
            else if (ch == ')') {
                if (s.empty() || s.top() != '(') {
                    balanced = false;
                    break;
                }
                s.pop();
            }
            else if (ch == ']') {
                if (s.empty() || s.top() != '[') {
                    balanced = false;
                    break;
                }
                s.pop();
            }
        }

        if (!s.empty()) balanced = false; 

        cout << (balanced ? "yes" : "no") << "\n";
    }

    return 0;
}
