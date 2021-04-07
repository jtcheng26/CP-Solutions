#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, k;
int a[500001];

pair<int, int> solve() {
  pair<int, int> res;
  vector<int> cnt(1000001, 0);
  int l = 0;
  int r = 1;
  cnt[a[l]] = 1;
  res.F = l;
  res.S = l;
  int c = 1;
  while (r < n) {
    cnt[a[r]]++;
    if (cnt[a[r]] == 1) c++;
    while (c > k && l < n) {
      cnt[a[l]]--;
      if (cnt[a[l]] == 0) c--;
      l++;
    }
    if (l == n) break;
    if (res.S - res.F < r - l) {
      res.F = l;
      res.S = r;
    }
    r++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> a[i];
  pair<int, int> ans = solve();
  cout << ans.F+1 << " " << ans.S+1 << "\n";
  return 0;
}
