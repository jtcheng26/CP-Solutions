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
char s[201];
int res[201];

bool solve() {
  int prev[2] = {0};
  prev[0] = s[0];
  prev[1] = 0;
  for (int i=1;i<n;i++) {
    if (s[i] >= prev[0]) {
      res[i] = 0;
      prev[0] = s[i];
    }
    else if (s[i] >= prev[1]) {
      res[i] = 1;
      prev[1] = s[i];
    }
    else return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> s[i];
  bool ans = solve();
  cout << (ans ? "YES" : "NO") << endl;
  if (!ans) return 0;
  for (int i=0;i<n;i++) {
    cout << res[i] << (i == n-1 ? "\n" : "");
  }
  return 0;
}
