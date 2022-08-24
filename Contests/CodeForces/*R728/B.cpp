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
ll a[100001];

ll solve() {
  ll res = 0;
  if (n == 1) return 0;
  for (int i=1;i<=n;i++) {
    int lim = (i % a[i]) - (a[i] - (i % a[i]));
    if (lim <= 0) lim += a[i];
    for (int j=i-lim;j>=1;j-=a[i]) {
      if (j == i) continue;
      if (a[j] * a[i] == i + j)
        res++;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    cout << solve() << "\n";
  }
  return 0;
}