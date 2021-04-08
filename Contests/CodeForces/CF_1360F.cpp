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

int n, m;
string s[11];
string ans;

bool solve() {
  int res = 0;
  int i;
  if (n == 1) {
    ans = s[0];
    return true;
  }
  for (int j=1;j<n;j++) {
    for (i=0;i<m;i++) {
      if (s[j][i] != s[j-1][i]) break;
    }
    if (i != m) break;
  }
  if (i == m) {
    ans = s[0];
    return true;
  }
  for (int j=0;j<n;j++) {
    for (int k=0;k<n;k++) {
      if (s[k][i] != s[j][i]) {
        ans = s[k].substr(0, i) + s[j][i] + s[k].substr(i+1);
        int a;
        for (a=0;a<n;a++) {
          int diff = 0;
          for (int b=0;b<m;b++) {
            if (s[a][b] != ans[b]) diff++;
          }
          if (diff > 1) break;
        }
        if (a == n) {
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> s[i];
    if (solve())
      cout << ans << "\n";
    else
      cout << "-1\n";
  }
  return 0;
}
