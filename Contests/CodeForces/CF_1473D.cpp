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

int n, m;
char a[200005];
int pfxMax[200005];
int pfxMin[200005];
int sfxMax[200005];
int sfxMin[200005];
int pfxEnd[200005];
int sfxEnd[200005];

int query(int l, int r) {
  return max(pfxMax[l-1], pfxEnd[l-1] + sfxMax[r+1]) - min(pfxMin[l-1], pfxEnd[l-1] + sfxMin[r+1]) + 1;
}

void solve() {
  int curr = 0;
  pfxMax[0] = pfxMin[0] = sfxMax[n+1] = sfxMin[n+1] = pfxEnd[0] = 0;
  sfxEnd[n] = 0;
  for (int i=1;i<=n;i++) {
    if (a[i] == '-') {
      pfxEnd[i] = --curr;
    } else {
      pfxEnd[i] = ++curr;
    }
    pfxMax[i] = max(pfxMax[i-1], pfxEnd[i]);
    pfxMin[i] = min(pfxMin[i-1], pfxEnd[i]);
  }
  curr = 0;
  for (int i=n;i>=1;i--) {
    if (a[i] == '-') { // reverse going backwards
      sfxEnd[i-1] = ++curr;
    } else {
      sfxEnd[i-1] = --curr;
    }
    sfxMax[i] = max(sfxMax[i+1], curr);
    sfxMin[i] = min(sfxMin[i+1], curr);
  }
  for (int i=1;i<=n;i++) {
    sfxMax[i] -= sfxEnd[i-1];
    sfxMin[i] -= sfxEnd[i-1];
    //cout << sfxEnd[i] << (i == n ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    solve();
    for (int i=0;i<m;i++) {
      int l, r;
      cin >> l >> r;
      cout << query(l, r) << "\n";
    }
  }
  return 0;
}
