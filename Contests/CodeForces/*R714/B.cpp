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

int n;
int a[200001];
ll fact[200001];

void precomp() {
  fact[0] = 1;
  for (int i=1;i<=n;i++) {
    fact[i] = (fact[i-1] * i) % MOD;
  }
}

ll solve() {
  precomp();
  ll res = 0;
  int goal = a[0];
  for (int i=1;i<n;i++) {
    goal &= a[i];
  }
  ll cnt = 0;
  for (int i=0;i<n;i++) {
    if (a[i] == goal) {
      cnt++;
    }
  }
  if (cnt < 2) return 0;
  return (((cnt * (cnt - 1)) % MOD) * fact[n-2]) % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    cout << solve() << "\n";
  }
  return 0;
}