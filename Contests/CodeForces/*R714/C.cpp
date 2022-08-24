#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, m;
ll numdp[200001];

ll num(int k) { // from 10
  if (k == 0) return 1;
  if (numdp[k] != -1) return numdp[k];
  numdp[k] = 1;
  if (k >= 10) {
    numdp[k] = (numdp[k] + (num(k - 9) + num(k - 10)) % MOD) % MOD;
  } else if (k == 9) {
    numdp[k] = 2;
  }
  return numdp[k];
}

ll solve() {
  vector<int> digits;
  while (n > 0) {
    digits.pb(n % 10);
    n /= 10;
  }
  ll res = digits.size();
  for (int d : digits) {
    if (10 - d <= m) {
      res = (res + numdp[m - (10 - d)]) % MOD;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  for (int i=0;i<=200000;i++) {
    numdp[i] = -1;
  }
  numdp[0] = 1;
  for (int i=0;i<=200000;i++) {
    num(i);
  }
  while (t--) {
    cin >> n >> m;
    cout << solve() << "\n";
  }
  return 0;
}