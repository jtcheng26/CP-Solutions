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

int n, k;
int a[31];

double solve() {
  if (k == 1) return 0;
  double res = 0;
  vector<int> dist;
  sort(a, a+n);
  int best = 0;
  dist.pb(a[0]);
  for (int i=1;i<n;i++) {
    dist.pb(a[i] - a[i-1]);
    best = max(best, a[i] - a[i-1]);
  }
  dist.pb(k + 1 - a[n-1]);
  res = max(res, (dist[0] - 1 + best / 2) / ((double)k));
  res = max(res, (dist[n] - 1 + best / 2) / ((double)k));
  res = max(res, (dist[0] - 1 + dist[n] - 1) / ((double) k));
  sort(dist.begin(), dist.end());
  res = max(res, max((dist[n] / 2 + dist[n-1] / 2) / ((double) k), (dist[n] - 1) / ((double)k)));
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  for (int z=1;z<=t;z++) {
    cin >> n >> k;
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    cout << "Case #" << z << ": " << solve() << "\n";
  }
  return 0;
}