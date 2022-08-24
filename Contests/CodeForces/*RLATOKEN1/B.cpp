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

int n;
int a[400001];

ll solve() {
  ll res = a[0];
  if (n == 1) return a[0];
  for (int i=1;i<n;i++) {
    res += abs(a[i] - a[i-1]);
  }
  res += a[n-1];
  if (a[0] > a[1])
    res -= min(a[0] - a[1], a[0]);
  for (int i=1;i<n-1;i++) {
    if (a[i] > a[i-1] && a[i] > a[i+1]) {
      res -= min(a[i] - a[i-1], a[i] - a[i+1]);
    }
  }
  if (a[n-1] > a[n-2])
    res -= min(a[n-1] - a[n-2], a[n-1]);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    cout << solve() << "\n";
  }
  return 0;
}