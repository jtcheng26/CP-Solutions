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

int n;
ll a[100001];

ll highestOneBit(ll i) {
    i |= (i >>  1);
    i |= (i >>  2);
    i |= (i >>  4);
    i |= (i >>  8);
    i |= (i >> 16);
    i |= (i >> 32);
    i |= (i >> 64);
    return i - ((unsigned)i >> 1);
}

ll solve() {
  ll res = 0;
  map<ll, ll> oneBit;
  for (int i=0;i<n;i++) {
    oneBit[highestOneBit(a[i])]++;
  }
  for (auto i : oneBit) {
    res += (i.S * (i.S - 1)) / 2;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << solve() << endl;
  }
  return 0;
}
