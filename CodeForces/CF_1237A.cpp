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
int a[13846];
int res[13846];

int solve() {
  int up = 0;
  int down = 0;
  for (int i=0;i<n;i++) {
    if (a[i] % 2 == 0) {
      res[i] = a[i] / 2;
      continue;
    }
    if (up > down) {
      down++;
      if (a[i] >= 0)
        res[i] = a[i] / 2;
      else
        res[i] = (a[i] - 1) / 2;
    }
    else {
      up++;
      res[i] = (a[i] + 1) / 2;
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  solve();
  for (int i=0;i<n;i++) {
    cout << res[i] << endl;
  }
  return 0;
}
