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

/*
  Disjoint Set Union implementations.
*/

/*
  Simple DSU with find and union operations.
  Credit to cp-algorithms website authors.
*/
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


int n, p;
int a[200001];

ll solve() {
  ll res = 0;
  vector<int> b[n+1];
  map<int, int> c;
  vector<int> d;
  for (int i=0;i<n;i++) {
    d.pb(a[i]);
  }
  sort(d.begin(), d.end());
  int j = 0;
  for (int i=0;i<n;i++) {
    if (c[d[i]] == 0) {
      c[d[i]] = ++j;
    }
  }
  for (int i=0;i<n;i++) {
    b[c[a[i]]].pb(i);
  }
  DSU dsu;
  dsu.build(n);
  for (int i=0;i<n;i++) {
    dsu.make_set(i);
  }
  vector<int> of(n, 0);
  for (int i=1;i<=n;i++) {
    for (int j : b[i]) {
      if (a[j] >= p) break;
      of[j] = a[j];
      for (int k=j+1;k<n;k++) {
        if (of[k] == 0 && a[k] % a[j] == 0 && dsu.find_set(j) != dsu.find_set(k)) {
          dsu.union_sets(j, k);
          res += a[j];
        } else if (of[k] != 0) {
          if (a[k] < a[j]) break;
          if (dsu.find_set(k) != dsu.find_set(j) && a[k] % a[j] == 0) {
            dsu.union_sets(j, k);
            res += a[j];
          }
          break;
        } else {
          break;
        }
      }
      for (int k=j-1;k>=0;k--) {
        if (of[k] == 0 && a[k] % a[j] == 0 && dsu.find_set(j) != dsu.find_set(k)) {
          dsu.union_sets(j, k);
          res += a[j];
        } else if (of[k] != 0) {
          if (a[k] < a[j]) break;
          if (dsu.find_set(k) != dsu.find_set(j) && a[k] % a[j] == 0) {
            dsu.union_sets(j, k);
            res += a[j];
            break;
          }
          break;
        } else {
          break;
        }        
      }
    }
  }
  for (int i=1;i<n;i++) {
    if (dsu.find_set(i) != dsu.find_set(i-1)) {
      dsu.union_sets(i, i-1);
      res += p;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> p;
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    cout << solve() << "\n";
  }
  return 0;
}