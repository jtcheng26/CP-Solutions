#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
char a[300001];
int ans[300001];

void solve() {
  for (int i=0;i<=n;i++) {
    ans[i] = 1;
  }
  int cnt = 0;
  for (int i=1;i<=n;i++) {
    if (i == 1 || a[i] != a[i-1]) {
      cnt++;
    } else if (a[i] == a[i-1]) {
      cnt = 1;
    }
    if (a[i] == 'L') {
      ans[i] += cnt;
    }
  }
  cnt = 0;
  for (int i=n;i>=1;i--) {
    if (i == n || a[i] != a[i+1]) {
      cnt++;
    } else if (a[i] == a[i+1]) {
      cnt = 1;
    }
    if (a[i] == 'R') {
      ans[i-1] += cnt;
    }
  }
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
    solve();
    for (int i=0;i<=n;i++) {
      cout << ans[i] << (i == n ? "\n" : " ");
    }
  }
  return 0;
}
