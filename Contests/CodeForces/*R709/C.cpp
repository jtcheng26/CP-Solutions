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
vector<int> a[100001];
vector<int> occ[100001];
vector<int> one[100001];

vector<int> solve() {
  vector<int> res(m, 0);
  for (int i=1;i<=n;i++) {
    if (one[i].size() > (m+1)/2) {
      res.clear();
      return res;
    }
  }
  int s = -1;
  for (int i=1;i<=n;i++) {
    if (s == -1 && occ[i].size() >= m/2) {
      s = i;
      int cnt = 0;
      for (int j : one[i]) {
        res[j] = i;
        cnt++;
      }
      for (int j : occ[i]) {
        if (cnt >= m / 2) break;
        if (res[j] == 0) {
          res[j] = i;
          cnt++;
        }
      }
    }
  }
  for (int i=0;i<m;i++) {
    if (res[i] == 0) {
      for (int j : a[i]) {
        if (j != s) {
          res[i] = j;
          break;
        }
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i=0;i<=n;i++) {
      occ[i].clear();
      one[i].clear();
    }
    for (int i=0;i<m;i++) {
      a[i].clear();
      int k;
      cin >> k;
      for (int j=0;j<k;j++) {
        int ij;
        cin >> ij;
        a[i].pb(ij);
        occ[ij].pb(i);
        if (k == 1)
          one[ij].pb(i);
      }
    }
    vector<int> ans = solve();
    if (ans.size() == 0) {
      cout << "NO" << "\n";
    } else {
      cout << "YES" << "\n";
      for (int i=0;i<int(ans.size());i++) {
        cout << ans[i] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
