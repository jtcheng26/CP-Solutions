#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
ll a[200001];

int solve() {
  set<ll> cnt;
  ll pfx = 0;
  cnt.insert(0);
  int res = 0;
  for (int i=0;i<n;i++) {
    pfx += a[i];
    if (cnt.find(pfx) != cnt.end()) {
      res++;
      cnt.clear();
      cnt.insert(0);
      pfx = a[i];
    }
    cnt.insert(pfx);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << "\n";
  return 0;
}
