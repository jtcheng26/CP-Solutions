#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define INF 1000000007

typedef long long ll;

using namespace std;

int n, k;
int h[200001];

bool solve() {
  int lo = h[0];
  int hi = h[0] + k;
  for (int i=1;i<n;i++) {
    if (h[i] < hi) {
      lo = max(lo - (k - 1), h[i]);
      hi = min(h[i] + k - 1 + k, hi + k - 1);
    } else {
      return false;
    }
    if (lo > h[i] + k - 1) return false;
    //cout << lo << " " << hi << "\n";
  }
  return lo == h[n-1];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> h[i];
    cout << (solve() ? "YES" : "NO") << "\n";
  }
  return 0;
}
