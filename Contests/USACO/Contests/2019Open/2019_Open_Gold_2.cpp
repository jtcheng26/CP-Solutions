#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mpr make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, k;

ll solve() {
  vector<ll> d(n+1, 2019201997);
  vector<bool> v(n+1, false);
  for (int l=0;l<n;l++) {
    int c = -1;
    for (int i=1;i<=n;i++) {
      if (!v[i] && (c == -1 || d[i] < d[c])) {
        c = i;
      }
    }
    v[c] = true;
    for (int j=1;j<=n;j++) {
      if (!v[j]) {
        d[j] = min(d[j], (2019201913LL * min(c, j) + 2019201949LL * max(c, j)) % 2019201997);
      }
    }
  }
  sort(d.begin(), d.end());
  return d[n - k];
}

int main() {
  ofstream cout ("walk.out");
  ifstream cin ("walk.in");
  cin >> n >> k;
  cout << solve() << "\n";
  return 0;
}
