#include <iostream>
#include <fstream>
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

struct DSU {
  vector<int> sz;
  vector<int> parent;
  vector<int> sizes; //actual

  void build(int size) {
    sz.resize(size + 1);
    parent.resize(size + 1);
    sizes.resize(size + 1);
  }

  int find_set(int v) {
    if (v == parent[v])
      return v;
    return parent[v] = find_set(parent[v]);
  }

  void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
    sizes[v] = 1;
  }

  void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
      if (sz[a] < sz[b])
        swap(a, b);
      parent[b] = a;
      sz[a] += sz[b];
      sizes[a] = sz[a];
      sizes[b] = 0;
    }
  }

  vector<int> get_sizes() {
    return sizes;
  }
};

int n,m;
int bitString[4001];
vector<pair<int, int> > requests;
int comp[4001]; // connected component of bit i

string solve() {
  DSU dsu;
  dsu.build(n+1);
  string res = "";
  for (int i=0;i<n;i++) {
    comp[i] = -1;
  }
  for (int i=0;i<m;i++) {
    int start = requests[i].F - 1;
    int end = requests[i].S - 1;
    for (int j=0;j<=(end - start) / 2;j++) {
      int idx = start + j;
      int rev = end - j;
      if (comp[idx] == -1) dsu.make_set(idx);
      if (comp[rev] == -1) dsu.make_set(rev);
      dsu.union_sets(idx, rev);
      comp[idx] = dsu.find_set(idx);
      comp[rev] = dsu.find_set(rev);
      //cout << "union " << idx << " and " << rev << " in " << comp[idx] << " and " << comp[rev] << endl;
    }
  }
  int compDig[n+1];
  vector<int> compSizes = dsu.get_sizes();
  vector<pair<int, int> > compCopy;
  for (int i=0;i<compSizes.size();i++) {
    if (compSizes[i] > 0) {
      compCopy.pb(mp(compSizes[i], i));
    }
  }
  sort(compCopy.rbegin(), compCopy.rend());
  int cnt[2] = {0};
  for (int i=0;i<compCopy.size();i++) {
    //cout << compCopy[i].F <<  " " << compCopy[i].S << endl;
    if (compCopy[i].F > 0) {
      if (cnt[0] <= cnt[1]) {
        compDig[compCopy[i].S] = 0;
        cnt[0] += compCopy[i].F;
      } else {
        compDig[compCopy[i].S] = 1;
        cnt[1] += compCopy[i].F;
      }
    }
  }

  for (int i=0;i<n;i++) {
    if (comp[i] == -1) {
      if (cnt[0] <= cnt[1]) {
        res += "0";
        cnt[0]++;
        continue;
      } else {
        res += "1";
        cnt[1]++;
        continue;
      }
    }
    int c = dsu.find_set(i);
    //cout << i << " belongs to " << c << " with number " << compDig[c] << endl;
    res += compDig[c] == 1 ? "1" : "0";
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream cin ("bitstrings_as_a_service_input.txt");
  ofstream cout ("2019R2B.txt");
  int t;
  cin >> t;//
  for (int i=1;i<=t;i++) {
    requests.clear();
    cin >> n >> m;
    for (int i=0;i<m;i++) {
      int start, end;
      cin >> start >> end;
      requests.pb(mp(start, end));
    }
    cout << "Case #" << i << ": " << solve() << endl;//
  }
  return 0;
}
