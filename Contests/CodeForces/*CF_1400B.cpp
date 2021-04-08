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

ll n, p, f;
ll s, w;
ll cnts, cntw;

ll solve() {
  if (s > w) {
    int temp = w;
    w = s;
    s = temp;
    temp = cntw;
    cntw = cnts;
    cnts = temp;
  }
  ll res = 0;
  for (int i=0;i<=cnts;i++) {
    if ((ll)(s * i) > p) continue;
    ll wtake = min((p - (i * s)) / w, cntw);
    ll p1 = wtake + i;
    ll p2 = cnts - i + min((f - ((cnts - i) * s)) / w, cntw - wtake);
    if ((ll)s * (ll)(cnts - i) > f) { // take all swords
      p2 = f / s;
      //cout << "all" << f << " " << s << endl;
    }
    res = max(res, p1 + p2);
  }
  return min((ll)(cnts + cntw), res);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> p >> f;
    cin >> cnts >> cntw;
    cin >> s >> w;
    cout << solve() << endl;
  }
  return 0;
}
