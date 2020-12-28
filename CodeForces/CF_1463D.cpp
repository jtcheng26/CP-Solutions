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
bool a[400001];

int solve() {
  int res = 0;
  int cnt = 0;
  int good = 0;
  for (int i=2*n;i>=1;i--) {
    if (!a[i]) cnt++;
    else {
      if (cnt > 0) {
        cnt--;
        good++;
      }
    }
  }
  res = good;
  good = 0;
  cnt = 0;
  for (int i=1;i<=2*n;i++) {
    if (!a[i]) cnt++;
    else {
      if (cnt > 0) {
        cnt--;
        good++;
      }
    }
  }
  return res - (n - good - 1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=1;i<=2*n;i++) a[i] = false;
    for (int i=0;i<n;i++) {
      int k;
      cin >> k;
      a[k] = true;
    }
    cout << solve() << "\n";
  }
  return 0;
}
