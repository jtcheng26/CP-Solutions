#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

typedef long long ll;

using namespace std;

struct Edge {
  ll a, b, w;
  void build(ll s, ll e, ll we) {
    a = s; b = e; w = we;
  }
};

int n, m;
Edge edges[100001];
vector<Edge> adj[100001];
int loc[100001];
ll max_w = 0;

bool dfs(int* comp, int ind, int x, int c) {
  if (comp[ind] == c) return 1;
  comp[ind] = c;
  for (Edge e : adj[ind]) if (e.w >= x) dfs(comp, e.b, x, c);
  return 1;
}

int valid(ll x) {
  int comp[n+1]; int c = 1;
  for (int i=1;i<=n;i++) comp[i] = 0;
  //cout << " try " << x << endl;
  for (int i=1;i<=n;i++) {
    if (comp[i] == 0) {
      dfs(comp, i, x, c++);
    }
  }
  for (int i=1;i<=n;i++) {
    if (comp[i] != comp[loc[i]]) return false;
  }
  return true;
}

ll solve() {
  int i;
  for (i=1;i<=n;i++) {
    if (loc[i] != i) break;
  }
  if (i == n+1) return -1;
  ll l = 0; ll r = max_w + 1; ll ans = 0;
  while (l < r) {
    //cout << l << " " << r << endl;
    ll m = (l + r) / 2;
    if (valid(m)) {
      l = m + 1; ans = m;
    }
    else
      r = m;
  }
  return ans;
}

int main() {
  ofstream cout ("wormsort.out");
  ifstream cin ("wormsort.in");
  cin >> n >> m;
  for (int i=1;i<=n;i++) {
    int c;
    cin >> c;
    loc[i] = c;
  }
  for (int i=0;i<m;i++) {
    Edge e1; Edge e2;
    ll b, e, w;
    cin >> b >> e >> w;
    e1.build(b, e, w);
    e2.build(e, b, w);
    adj[b].push_back(e1);
    adj[e].push_back(e2);
    max_w = max(max_w, w);
  }
  cout << solve() << endl;
  return 0;
}
