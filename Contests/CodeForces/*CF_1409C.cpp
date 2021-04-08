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

int n, x, y;
int ans[51];

int solve() {
  if (x > y) swap(x, y);
  if (y > n) {
    ans[n-1] = y;
    for (int k=1;k<=50;k++) {
      bool flag = false;
      for (int i=n-2;i>=0;i--) {
        ans[i] = y - k * (n - i - 1);
        if (ans[i] == x) flag = true;
        if (ans[i] <= 0) flag = false;
      }
      if (flag == true) return 0;
    }
  }
  for (int j=1;j<=x;j++) {
    ans[0] = j;
    bool flag1 = false;
    bool flag2 = false;
    for (int k=1;k<=50;k++) {
      flag1 = false;
      flag2 = false;
      for (int i=0;i<n;i++) {
        ans[i] = j + k * i;
        if (ans[i] == x) flag1 = true;
        if (ans[i] == y) flag2 = true;
      }
      if (flag1 && flag2) return 0;
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> x >> y;
    solve();
    for (int i=0;i<n;i++) {
      cout << ans[i] << (i == n-1 ? "\n" : " ");
    }
  }
  return 0;
}
