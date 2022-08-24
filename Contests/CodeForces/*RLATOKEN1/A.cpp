#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, m;
char a[51][51];
char ans[51][51];

bool solve() {
  bool res = false;
  bool ok = true;
  for (int i=0;i<n;i++) { // WR/RW
    for (int j=0;j<m;j++) {
      if (i % 2 == 0 && j % 2 == 0 && a[i][j] == 'R')
        ok = false;
      if (i % 2 == 0 && j % 2 == 1 && a[i][j] == 'W')
        ok = false;
      if (i % 2 == 1 && j % 2 == 0 && a[i][j] == 'W')
        ok = false;
      if (i % 2 == 1 && j % 2 == 1 && a[i][j] == 'R')
        ok = false;
      if (i % 2 == 0 && j % 2 == 0)
        ans[i][j] = 'W';
      if (i % 2 == 0 && j % 2 == 1)
        ans[i][j] = 'R';
      if (i % 2 == 1 && j % 2 == 0)
        ans[i][j] = 'R';
      if (i % 2 == 1 && j % 2 == 1)
        ans[i][j] = 'W';
    }
  }
  if (ok) return true;
  ok = true;
  for (int i=0;i<n;i++) { // WR/RW
    for (int j=0;j<m;j++) {
      if (i % 2 == 0 && j % 2 == 0 && a[i][j] == 'W')
        ok = false;
      if (i % 2 == 0 && j % 2 == 1 && a[i][j] == 'R')
        ok = false;
      if (i % 2 == 1 && j % 2 == 0 && a[i][j] == 'R')
        ok = false;
      if (i % 2 == 1 && j % 2 == 1 && a[i][j] == 'W')
        ok = false;
      if (i % 2 == 0 && j % 2 == 0)
        ans[i][j] = 'R';
      if (i % 2 == 0 && j % 2 == 1)
        ans[i][j] = 'W';
      if (i % 2 == 1 && j % 2 == 0)
        ans[i][j] = 'W';
      if (i % 2 == 1 && j % 2 == 1)
        ans[i][j] = 'R';
    }
  }
  if (ok) res = true;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) {
        cin >> a[i][j];
      }
    }
    bool an = solve();
    if (an) {
      cout << "YES" << "\n";
      for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
          cout << ans[i][j];
        }
        cout << "\n";
      }
    } else {
      cout << "NO" << "\n";
    }
  }
  return 0;
}