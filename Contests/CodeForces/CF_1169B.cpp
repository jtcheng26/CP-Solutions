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
pair<int, int> a[300001];

bool solve() {
  int k[2] = {a[0].F, a[0].S};
  int cnt[n+1];
  for (int i=0;i<=n;i++) cnt[i] = 0;
  for (int i=0;i<2;i++) {
    int good = 0;
    for (int j=0;j<m;j++) {
      if (a[j].F == k[i] || a[j].S == k[i]) {
        good++;
      } else {
        cnt[a[j].F]++;
        cnt[a[j].S]++;
      }
    }
    for (int j=0;j<=n;j++) {
      if (cnt[j] + good == m) {
        return true;
      }
      cnt[j] = 0;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    cin >> a[i].F >> a[i].S;
  }
  cout << (solve() ? "YES" : "NO") << "\n";
  return 0;
}
