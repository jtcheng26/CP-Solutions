#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solve(string s) {
    int n = s.length();
    if (n == 1) {
      cout << s << "\n";
      return 0;
    }
    bool flag = false;
    for (int i=1;i<n;i++) {
      if (s.substr(i, 1) != s.substr(i-1, 1))
        flag = true;
    }
    if (!flag) {
      cout << s[0];
      return 0;
    }
    char letters[3] = {'B', 'G', 'R'};
    for (int c=0;c<3;c++) {
      if (count(s.begin(), s.end(), letters[c]) != n-1)
        cout << letters[c];
    }
    cout << "\n";
    return 0;
}

int main()
{
    int n; string s;
    cin >> n; cin >> s;
    solve(s);
}
