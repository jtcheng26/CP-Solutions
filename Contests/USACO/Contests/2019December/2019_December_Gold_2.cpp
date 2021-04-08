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

struct query {
  int start, end, type, index;
};

int n, m;
vector<query> a[100001]; // queries starting and ending at i
vector<int> adj[100001];
vector<pair<int, int> > ofType[100001]; // node, index
vector<int> stak;
pair<int, int> range[100001];
int milk[100001];
int ans[100001];

bool anc(int possibleAncestor, int node) {
  return range[possibleAncestor].F <= range[node].F && range[node].S <= range[possibleAncestor].S;
}

int preorder(int parent, int node, int cnt) {
  range[node].F = ++cnt;
  for (int child : adj[node]) {
    if (parent == child) continue;
    cnt = preorder(node, child, cnt);
  }
  range[node].S = cnt;
  return cnt;
}

void dfs(int parent, int node) {
  stak.pb(node);
  ofType[milk[node]].pb(mp(node, stak.size()-1));
  for (query q : a[node]) {
    if (ans[q.index] == 1 || ofType[q.type].empty()) continue;
    pair<int, int> top = ofType[q.type].back();
    if (top.F == node) ans[q.index] = 1;
    else {
      int b = q.start == node ? q.end : q.start;
      if (anc(top.F, b)) {
        if (!anc(stak[top.S + 1], b)) ans[q.index] = 1;
      } else {
        ans[q.index] = 1;
      }
    }
  }
  for (int child : adj[node]) {
    if (parent == child) continue;
    dfs(node, child);
  }
  stak.pop_back();
  ofType[milk[node]].pop_back();
}

void test() {
  preorder(0, 1, 0);
  for (int i=1;i<=n;i++) {
    cout << range[i].F << " " << range[i].S << "\n";
  }
}

void solve() {
  for (int i=0;i<m;i++) {
    ans[i] = 0;
  }
  preorder(0, 1, 0);
  dfs(0, 1);
}

int main() {
  ofstream cout ("milkvisits.out");
  ifstream cin ("milkvisits.in");
  cin >> n >> m;
  for (int i=1;i<=n;i++) cin >> milk[i];
  for (int i=0;i<n-1;i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for (int i=0;i<m;i++) {
    query q;
    cin >> q.start >> q.end >> q.type;
    q.index = i;
    a[q.start].pb(q);
    a[q.end].pb(q);
  }
  solve();
  //test();
  for (int i=0;i<m;i++) {
    cout << ans[i] << (i == m-1 ? "\n": "");
  }
  return 0;
}
