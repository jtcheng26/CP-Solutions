#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, m, c;
vector<pair<int, int> > out[100001]; // F = dist S = node
vector<pair<int, int> > in[100001];
int s[100001];
int ans[100001];

int dfs(int node) {
  if (ans[node] != -1) return ans[node];
  ans[node] = s[node];
  for (pair<int, int> adj : in[node]) {
    ans[node] = max(ans[node], adj.F + dfs(adj.S));
  }
  return ans[node];
}

int solve() {
  for (int i=1;i<=n;i++) {
    ans[i] = -1;
  }
  for (int i=1;i<=n;i++) {
    if (out[i].size() == 0) {
      dfs(i);
    }
  }
  return 0;
}

int main() {
  ofstream cout ("timeline.out");
  ifstream cin ("timeline.in");
  cin >> n >> m >> c;
  for (int i=1;i<=n;i++) {
    cin >> s[i];
  }
  for (int i=0;i<c;i++) {
    int a, b, x;
    cin >> a >> b >> x;
    out[a].pb(mp(x, b));
    in[b].pb(mp(x, a));
  }
  solve();
  for (int i=1;i<=n;i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
