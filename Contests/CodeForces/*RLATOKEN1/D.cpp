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
int d[2005][2005];
bool fnd[2005];
int depth[2005];
vector<int> ofD[2005];
vector<int> nd[2005];
int q[2005];

int dfs(int k, int dep) {
  int cnt = 0;
  int nxt = 0;
  for (int j : nd[dep+1]) {
    //cout << k << " " << j << " " << fnd[j] << "\n";
    if (depth[j] + 1 == depth[k])
      nxt = j;
    if (abs(depth[j] - depth[k]) == 1) {
      d[k][j] = 1;
      if (!fnd[j]) {
        fnd[j] = true;
        cnt++;
      }
    }
  }
  if (k == 1) return cnt;
  return cnt + dfs(nxt, dep + 1);
}

void done() {
  cout << "!" << "\n";
  for (int i=1;i<=n;i++) {
    for (int j=i+1;j<=n;j++) {
      //out << i << " " << j << d[i][j] << " " << d[j][i] << "\n";
      if (d[i][j] == 1 || d[j][i] == 1) {
        cout << i << " " << j << "\n";
      }
    }
  }
  cout.flush();
}

void query(int k) {
  cout << "? " << k << endl;
  for (int i=1;i<=n;i++) {
    cin >> q[i];
  }
}

void solve() {
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) {
      d[i][j] = 0;
    }
  }
  query(1);
  int deep = 0;
  int good = 1;
  fnd[1] = true;
  for (int i=1;i<=n;i++) {
    d[1][i] = q[i];
    depth[i] = q[i];
    ofD[q[i]].pb(i);
    deep = max(deep, q[i]);
    if (q[i] == 1) {
      fnd[i] = true;
      good++;
    }
  }
  int idx = 0;
  while (good < n) {
    int t = ofD[deep][idx];
    if (!fnd[t]) {
      query(t);
      for (int i=0;i<=n;i++) {
        nd[i].clear();
      }
      for (int i=1;i<=n;i++) {
        nd[q[i]].pb(i);
      }
      good += dfs(t, 0);
      good++;
      fnd[t] = true;
    }
    //cout << "G " << good << "\n";
    idx++;
    while (idx >= ofD[deep].size()) {
      deep--;
      idx = 0;
    }
  }
  done();
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  solve();
  return 0;
}