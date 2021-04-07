#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, a, b;
int arr[200001];

ll solve() {
  ll res = 0;
  vector<ll> pfx(n+1, 0);
  for (int i=1;i<=n;i++) {
    pfx[i] = pfx[i-1] + arr[i];
  }
  multiset<ll> s;
  s.insert(0);
  int l = 0;
  int r = 0;
  res = pfx[a];
  for (int i=a+1;i<=n;i++) {
    if (i - l > b) {
      s.erase(s.find(pfx[l]));
      l++;
    }
    if (i - r > a) {
      r++;
      s.insert(pfx[r]);
    }
    res = max(res, pfx[i] - *s.begin());
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> a >> b;
  for (int i=1;i<=n;i++) cin >> arr[i];
  cout << solve() << "\n";
  return 0;
}
