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

int n, m;
int a[100001];

int solve() {
  int res = n;
  vector<int> cnt(m, 0);
  for (int i=0;i<n;i++) {
    cnt[a[i] % m]++;
  }
  for (int i=0;i<=m/2;i++) {
    if (i == (m - i) % m) res -= max(0, cnt[i] - 1);
    else {
      if (cnt[i] == cnt[(m-i) % m]) {
        res -= max(0, cnt[i] + cnt[(m-i) % m] - 1);
      } else {
        res -= max(0, 2 * min(cnt[i], cnt[(m-i)%m]));
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << solve() << "\n";
  }
  return 0;
}
