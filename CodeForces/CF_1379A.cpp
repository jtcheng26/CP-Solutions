#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
string s;

bool solve() {
  string goal = "abacaba";
  int times = 0;
  for (int i=0;i+6 < n;i++) {
    string curr = "";
    for (int j=0;j<n;j++) {
      if (s[j] == '?') {
        if (j >= i && j < i+7)
          curr += goal[j-i];
        else curr += "z";
      } else curr += s[j];
    }
    int cnt = 0;
    for (int j=0;j+6 < n;j++) {
      if (curr.substr(j, 7) == goal) cnt++;
    }
    if (cnt == 1) {
      s = curr;
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    bool ans = solve();
    cout << (ans ? "Yes" : "No") << endl;
    if (ans) {
      for (int i=0;i<n-1;i++) {
        cout << s[i];
      }
      cout << s[n-1] << endl;
    }
  }
  return 0;
}
