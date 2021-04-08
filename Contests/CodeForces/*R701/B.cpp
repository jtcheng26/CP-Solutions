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

int n, q, k;
ll a[100001];
ll pfx[100001];

ll query(int l, int r) {
  ll x = pfx[r] - pfx[l];
  ll y = a[l] - 1;
  ll z = k - a[r];
  //cout << x << " " << y << " " << z << "\n";
  return x + y + z;
}

void solve() {
  pfx[0] = 0;
  for (int i=1;i<n;i++) {
    pfx[i] = pfx[i-1] + 2 * (a[i] - a[i-1] - 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> q >> k;
  for (int i=0;i<n;i++) cin >> a[i];
  solve();
  for (int i=0;i<q;i++) {
    int l, r;
    cin >> l >> r;
    cout << query(l-1, r-1) << "\n";
  }
  return 0;
}
