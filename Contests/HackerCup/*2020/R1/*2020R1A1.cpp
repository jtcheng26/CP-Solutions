#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define MOD 1000000007
#define pb push_back
#define F first
#define S second

typedef unsigned long long ll;

using namespace std;

struct room {
  ll l, r, h, e; // e: extra (for inversion)
};

ll n, k, w;

vector<ll> l;
vector<ll> h;
vector<room> r;

ll solve() {
  vector<ll> ans;
  ans.reserve(n);
  ans[0] = (2 * w + 2 * r[0].h) % MOD;
  int mh = 0;
  for (int i=1;i<n;i++) {
    if (r[i].l > r[i-1].r) {
      ans[i] = ((2 * w + 2 * r[i].h) % MOD + ans[i-1]) % MOD;
      mh = i;
      continue;
    }
    int prev = i-1;
    ll add = 0;
    //cout << r[i].l << " " << r[mh].r << " "  << r[mh].h << " " << r[i].h << " ";
    bool flag = false;

    for (int j=i-1;j>=max(0, (int)(i-(int)w));j--) {
      if (r[i].l <= r[j].r && r[i].h <= r[j].h) {
        //prev = j;
        flag = true;
        break;
      } else if (r[i].l <= r[j].r && r[i].h > r[j].h) {
        if (r[j].h > r[prev].h) {
          prev = j;
        }
        flag = false;
      } else break;
    }

    if (r[i].h <= r[prev].h || flag) {
      add = 2 * (r[i].r - r[i-1].r);
      //cout << add << " ";
     //else if (r[i].h > r[prev].h) {
        //add = 2 * (r[i].r - r[i-1].r) + 2 * (r[i].h - r[prev].h);
    } else {
      add = 2 * (r[i].r - r[i-1].r) + 2 * (r[i].h - r[prev].h);
    }
    if (r[i].h >= r[mh].h) mh = i;
    ans[i] = (ans[i-1] + add) % MOD;
    //cout << ans[i] << endl;
  }
  ll res = ans[0];
  //cout << ans[0] << " " << res << endl;
  for (int i=1;i<n;i++) {
    //cout << ans[i] << " ";
    res = (res * ans[i]) % MOD;
    //cout << res << endl;
  }
  //cout << endl;
  return res;
}

void gen(ll aL, ll bL, ll cL, ll dL, ll aH, ll bH, ll cH, ll dH) {
  for (int i=k;i<n;i++) {
    ll li = ((aL * l[i-2] + bL*l[i-1] + cL) % dL) + 1;
    ll hi = ((aH * h[i-2] + bH*h[i-1] + cH) % dH) + 1;
    l[i] = li;
    h[i] = hi;
  }
  for (int i=0;i<n;i++) {
    room a;
    a.l = l[i];
    a.r = a.l + w;
    a.h = h[i];
    r.pb(a);
    //cout << a.l << " " << a.h << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream cin ("perimetric_chapter_1_input.txt");
  ofstream cout ("2020R1A.txt");
  int t;
  cin >> t;//
  for (int i=1;i<=t;i++) {
    ll aL, bL, cL, dL, aH, bH, cH, dH;
    cin >> n >> k >> w;
    l.reserve(n);
    h.reserve(n);
    for (int j=0;j<k;j++) cin >> l[j];
    cin >> aL >> bL >> cL >> dL;
    for (int j=0;j<k;j++) cin >> h[j];
    cin >> aH >> bH >> cH >> dH;
    gen(aL, bL, cL, dL, aH, bH, cH, dH);
    cout << "Case #" << i << ": " << solve() << endl;//
    l.clear();
    h.clear();
    r.clear();
  }
  return 0;
}
