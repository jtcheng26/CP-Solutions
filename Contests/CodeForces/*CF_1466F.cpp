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

struct vec {
  int k;
  vector<int> x;
};

struct DSU {
  vector<int> sz;
  vector<int> parent;

  void build(int size) {
    sz.resize(size + 1);
    parent.resize(size + 1);
  }

  int find_set(int v) {
    if (v == parent[v])
      return v;
    return parent[v] = find_set(parent[v]);
  }

  void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
  }

  void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
      if (sz[a] < sz[b])
        swap(a, b);
      parent[b] = a;
      sz[a] += sz[b];
    }
  }
};

int n, m;
vec vecs[500001];
ll T, S;
vector<int> ans;

void solve() {
  DSU dsu;
  dsu.build(m + 1);
  dsu.make_set(0);
  for (int i=1;i<=m;i++) {
    dsu.make_set(i);
  }
  for (int i=0;i<n;i++) {
    if (vecs[i].k == 1 && dsu.find_set(vecs[i].x[0]) != dsu.find_set(0)) {
      dsu.union_sets(0, vecs[i].x[0]);
      ans.pb(i + 1);
    } else if (vecs[i].k == 2 && dsu.find_set(vecs[i].x[0]) != dsu.find_set(vecs[i].x[1])) {
      dsu.union_sets(vecs[i].x[0], vecs[i].x[1]);
      ans.pb(i + 1);
    }
  }
  S = ans.size();
  T = 1;
  for (int i=1;i<=S;i++) {
    T = (2 * T) % MOD;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    cin >> vecs[i].k;
    for (int j=0;j<vecs[i].k;j++) {
      int x;
      cin >> x;
      vecs[i].x.pb(x);
    }
  }
  solve();
  cout << T << " " << S << "\n";
  for (int i=0;i<S;i++) {
    cout << ans[i] << (i == S-1 ? "\n" : " ");
  }
  return 0;
}
