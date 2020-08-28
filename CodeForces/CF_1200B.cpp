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

int n, m, k;
int h[101];

int solve() {
  for (int i=0;i<n-1;i++) {
    if (h[i] >= h[i+1] - k) m += h[i] - max(0, (h[i+1] - k));
    else {
      if (m < h[i+1] - k - h[i]) return false;
      m -= h[i+1] - k - h[i];
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    for (int i=0;i<n;i++) cin >> h[i];
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}
