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

int n, q;
int a[100001];
ll pfx[100001];
ll sum;

ll query(int u, int v) {
  return min(pfx[v-1] - pfx[u-1], sum - (pfx[v-1] - pfx[u-1]));
}

void solve() {
  sum = 0;
  pfx[0] = 0;
  for (int i=1;i<=n;i++) {
    sum += a[i];
    pfx[i] = pfx[i-1] + a[i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> q;
  for (int i=1;i<=n;i++) cin >> a[i];
  solve();
  for (int i=0;i<q;i++) {
    int u, v;
    cin >> u >> v;
    if (v < u) swap(u, v);
    cout << query(u, v) << "\n";
  }
  return 0;
}
