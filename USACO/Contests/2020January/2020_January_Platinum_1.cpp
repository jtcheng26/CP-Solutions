#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

struct DSU {
  vector<int> sz;
  vector<int> parent;
  vector<ll> states;

  void build(int size) {
    sz.resize(size + 1);
    parent.resize(size + 1);
    states.resize(size + 1);
  }

  int find_set(int v) {
    if (v == parent[v])
      return v;
    return parent[v] = find_set(parent[v]);
  }

  void incDepth(int s) {
    states[s] = (states[s] + 1) % MOD;
  }

  void make_set(int v) {
    parent[v] = v;
    states[v] = 1;
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
      states[a] = (states[a] * states[b]) % MOD;
    }
  }
};

int n, m;
char painting[1001][1001];

ll solve() {
  ll res = 1;
  DSU dsu;
  dsu.build((n-2)*(m-2));
  for (int r=n-3;r>=0;r--) {
    for (int c=0;c<m-2;c++) {
      int idx = r * (m-2) + c;
      if (painting[r+1][c+1] == '.')
        dsu.make_set(idx);
    }
  }
  for (int r=n-3;r>=0;r--) {
    for (int c=0;c<m-2;c++) {
      int idx = r * (m-2) + c;
      if (painting[r+1][c+1] == '#') continue;
      if (r < n-3 && painting[r+2][c+1] == '.')
        dsu.union_sets(idx, idx+(m-2)); // bottom
      if (c < m-3 && painting[r+1][c+2] == '.')
        dsu.union_sets(idx, idx+1); // right
    }
    map<int, int> used;
    for (int c=0;c<m-2;c++) {
      if (painting[r+1][c+1] == '#') continue;
      int dsuSet = dsu.find_set(r * (m-2) + c);
      if (!used[dsuSet]) {
        used[dsuSet] = true;
        dsu.incDepth(dsuSet);
        //cout << "row " << r << " set " << dsuSet << " state " << dsu.states[dsuSet] << "\n";
      }
    }
  }
  map<int, int> used;
  for (int r=0;r<n-2;r++) {
    for (int c=0;c<m-2;c++) {
      if (painting[r+1][c+1] == '#') continue;
      int dsuSet = dsu.find_set(r * (m-2) + c);
      if (!used[dsuSet]) {
        //cout << dsu.states[dsuSet] << "\n";
        used[dsuSet] = true;
        res = (res * dsu.states[dsuSet]) % MOD;
      }
    }
  }
  return res;
}

int main() {
  ofstream cout ("cave.out");
  ifstream cin ("cave.in");
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      cin >> painting[i][j];
    }
  }
  cout << solve() << endl;
  return 0;
}
