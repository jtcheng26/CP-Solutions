#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 100000007

typedef long long ll;

using namespace std;

ll n, d, m;
ll f[100001];
vector<ll> gm;
vector<ll> lm;

ll solve() {
  ll res = 0;
  sort(gm.rbegin(), gm.rend());
  sort(lm.rbegin(), lm.rend());
  for (int i=1;i<int(gm.size());i++) {
    gm[i] += gm[i-1];
  }
  for (int i=1;i<int(lm.size());i++) {
    lm[i] += lm[i-1];
  }
  if (gm.size() == 0) return lm[n - 1];
  if (lm.size() == 0) lm.push_back(0);
  for (int i=gm.size();i<n;i++) {
    gm.push_back(0);
  }
  for (int i=lm.size();i<n;i++) {
    lm.push_back(lm[i-1]);
  }
  for (int i=0;i<n;i++) {
    ll rem = n - i;
    ll big = (rem + d) / (d + 1);
    ll take = gm[big - 1];
    ll small = n - (big - 1) * (d + 1) - 2;
    //cout << lm[small] << endl;
    if (small >= 0) small = lm[small];
    else small = 0;
    res = max(res, take + small);
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> d >> m;
  for (int i=0;i<n;i++) {
    cin >> f[i];
    if (f[i] > m) gm.push_back(f[i]);
    else lm.push_back(f[i]);
  }
  cout << solve() << endl;
  return 0;
}
