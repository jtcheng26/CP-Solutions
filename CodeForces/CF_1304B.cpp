#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 100000007

typedef long long ll;

using namespace std;

int n, m;
string s[101];

bool isPalindrome(string s) {
  for (int i=0;i<s.length() / 2;i++) {
    if (s[i] != s[s.length() - i - 1])
      return false;
  }
  return true;
}

bool isReverse(string a, string b) {
  //if (a.length() != b.length()) return false;
  for (int i=0;i<a.length();i++) {
    if (a[i] != b[a.length() - i - 1]) return false;
  }
  return true;
}

string solve() {
  string res = "";
  for (int i=0;i<n;i++) {
    if (isPalindrome(s[i]) && res.length() == 0) {
      res = s[i];
    }
  }
  for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      if (isReverse(s[i], s[j]))
        res = s[i] + res + s[j];
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    cin >> s[i];
  }
  string ans = solve();
  cout << ans.length() << endl;
  cout << ans << endl;
  return 0;
}
