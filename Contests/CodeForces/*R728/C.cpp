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
ll a[100002];

ll solve() {
  if (n == 1) return 0;
  ll diff = 0;
  ll curr = 0;
  sort(a+1,a+n+1);
  for (int i=2;i<=n;i++) {
    curr += (a[i]-a[i-1]) * (i-1);
    diff += curr;
  }
  return a[n] - diff;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=1;i<=n;i++) {
      cin >> a[i];
    }
    cout << solve() << "\n";
  }
  return 0;
}