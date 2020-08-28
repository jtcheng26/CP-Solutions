#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
string passwords[200001];

struct DSU {
  vector<int> sz;
  vector<int> items;
  vector<int> parent;
  void build(int size) {
    sz.resize(size + 1);
    parent.resize(size + 1);
    items.resize(size + 1);
  }

  void inc_size(int v) {
    items[v]++;
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
      items[a] += items[b];
      items[b] = 0;
      sz[b] = 0;
    }
  }

  int get_size(int a) {
    return items[a];
  }
};

int solve() {
  int res = 0;
  DSU dsu;
  dsu.build(26);
  for (int i=0;i<26;i++) dsu.make_set(i);
  for (int i=0;i<n;i++) {
    for (int j=0;j<passwords[i].length();i++) {
      dsu.inc_size(passwords[i][j] - 'a');
    }
  }
  for (int i=0;i<n;i++) {
    char prev = passwords[i][0];
    for (int j=1;j<passwords[i].length();j++) {
      dsu.union_sets(prev - 'a', passwords[i][j] - 'a');
    }
  }
  for (int i=0;i<26;i++) {
    if (dsu.get_size(i) > 0) res++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> passwords[i];
  }
  cout << solve() << endl;
  return 0;
}
