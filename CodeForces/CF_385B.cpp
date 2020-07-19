#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solve(string s) {
    int b = 0; int lastB = -1;
    for (int i=0;i<s.length();i++) {
        if (s.substr(i, 1) == "b") {
            if (s.substr(i, 4) == "bear") {
                b += ((s.length() - (i+3)) * (i - lastB));
                lastB = i;
            }
        }
    }
    return b;
}

int main()
{
    string s; int result;
    cin >> s;
    result = solve(s);
    cout << result;
}
