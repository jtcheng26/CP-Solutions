#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int x; string s;
char res[100001];

string solve() {
  int n = s.length();
  for (int i=0;i<n;i++) res[i] = 'a';
  for (int i=0;i<n;i++) {
    if (s[i] == '0') {
      if (i - x >= 0) res[i-x] = '0';
      if (i + x < n) res[i+x] = '0';
    }
  }
  for (int i=0;i<n;i++) {
    if (s[i] == '1') {
      if (i - x >= 0 && res[i-x] != '0') res[i-x] = '1';
      else if (i + x < n && res[i+x] != '0') res[i+x] = '1';
      else return "-1";
    }
  }
  for (int i=0;i<n;i++) {
    if (res[i] == 'a') res[i] = '1';
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> s;
    cin >> x;
    string ans = solve();
    if (ans == "-1") {
      cout << "-1" << endl;
      continue;
    }
    for (int i=0;i<s.length() - 1;i++) {
      cout << res[i];
    }
    cout << res[s.length() - 1] << endl;
  }
  return 0;
}
