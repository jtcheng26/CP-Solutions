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

int n;
string s;

int solve() {
  int qCnt = 0;
  if (s[0] == ')' || s[s.length() - 1] == '(') return false;
  for (int i=0;i<s.length();i++) {
    if (s[i] == '?') qCnt++;
  }
  return qCnt % 2 == 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> s;
    cout << (solve() ? "YES" : "NO") << "\n";
  }
  return 0;
}
