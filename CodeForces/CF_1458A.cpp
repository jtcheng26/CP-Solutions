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
#define MOD 1e9+7

typedef long long ll;

using namespace std;

int n, m;
ll a[200001];
ll b;
ll g;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll query(ll b) {
  return gcd(a[0] + b, g);
}

void solve() {
  sort(a, a+n);
  g = 0;
  for (int i=1;i<n;i++) {
    g = gcd(g, a[i] - a[0]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i=0;i<n;i++) cin >> a[i];
  solve();
  for (int j=0;j<m;j++) {
    cin >> b;
    cout << query(b) << (j == m-1 ? "\n" : " ");
  }
  return 0;
}
