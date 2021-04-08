#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define MOD 998244353
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

struct event {
  int time;
  int end;
  int type;
};

int n, k;
event events[600001];
int factorial[300001];

bool cmp(event a, event b) {
  if (a.type == 0 && b.type == 1) {
    return a.time <= b.time;
  }
  return a.time < b.time;
}

void get_facts(int n) {
  factorial[0] = 1;
  for (int i=1;i<=n;i++) {
    factorial[i] = (ll)((ll)i * (ll)factorial[i-1]) % MOD;
  }
}
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    if (a == 0) {
      *x = 0, *y = 1;
      return b;
    }
    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
      ll res = (x%m + m) % m;
      return res;
}
int solve() {
  int res = 0;
  int on = 0;
  get_facts(n);
  sort(events, events+2*n, cmp);
  for (int i=0;i<2*n;i++) {
    //cout << events[i].type << " " << events[i].time << endl;
    if (events[i].type == 0) {
      int cnt = on;
      int choose;
      //cout << cnt << endl;
      //cout << factorial[cnt] << " " <<  factorial[k-1] << " " << modInverse(factorial[k-1], MOD) << " " <<  modInverse(factorial[cnt-(k-1)], MOD) << endl;
      if (cnt >= k-1) res += ((factorial[cnt] * modInverse(factorial[k-1], MOD)) % MOD * modInverse(factorial[cnt-(k-1)], MOD)) % MOD;
      res %= MOD;
    }
    if (events[i].type == 1) {
      on--;
    } else on++;
    //cout << res << endl;
  }
  return res % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i=0;i<n;i++) {
    cin >> events[i].time >> events[n+i].time;
    events[i].end = events[n + i].time;
    events[i].type = 0;
    events[n+i].type = 1;
  }
  cout << solve() << endl;
  return 0;
}
