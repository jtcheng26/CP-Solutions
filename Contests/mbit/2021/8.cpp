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

int n, m, L;
int a[100005];

bool valid(int k) {
  ll amt = 0;
  for (int i=1;i<=n;i++) {
    if (i > 1) {
      amt += min(k, (a[i] - a[i-1] - 1) / 2);
      if ((a[i] - a[i-1] - 1) % 2 == 1) {
        if ((a[i] - a[i-1] - 1) / 2 + 1 <= k) {
          amt++;
        }
      }
    }
    else
      amt += min(k, (a[i] - a[i-1] - 1));
    if (i < n)
      amt += min(k, (a[i+1] - a[i] - 1) / 2);
    else 
      amt += min(k, a[i+1] - a[i] - 1);
  }
  return amt >= m;
}

ll solve() {
  ll res = 0;
  a[0] = 0;
  a[n+1] = L + 1;
  int l = 1;
  int r = L;
  while (l < r) {
    int mid = (l + r) / 2;
    if (valid(mid)) {
      res = mid;
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> n >> m >> L;
  for (int i=1;i<=n;i++) {
    cin >> a[i];
  }
  sort(a+1, a+n+1);
  cout << solve() << "\n";
  return 0;
}