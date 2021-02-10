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

ll ah, bh, n;
ll a[100001];
ll b[100001];

bool solve() {
  ll total = 0;
  for (int i=0;i<n;i++) {
    int attacks = (b[i] + ah - 1) / ah;
    total += attacks * a[i];
  }
  bool flag = false;
  for (int i=0;i<n;i++) {
    int attacks = (b[i] + ah - 1) / ah;
    ll before = total - attacks * a[i];
    ll health = bh - before;
    if (health - attacks * a[i] > -1 * a[i]) flag = true;
  }
  return flag;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> ah >> bh;
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    for (int i=0;i<n;i++) {
      cin >> b[i];
    }
    cout << (solve() ? "YES" : "NO") << "\n";
  }
  return 0;
}
