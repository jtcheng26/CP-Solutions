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

int n, m;
vector<int> adj[500001]; // colors adjacent to each node
vector<pair<int, int> > colors; // <color, node>
int color[500001]; // color of each node
vector<int> in[500001]; // nodes of each color

vector<int> solve() {
  vector<int> order;
  order.pb(-1);
  for (int i=1;i<=n;i++) {
    for (int j=0;j<adj[i].size();j++) {
      adj[i][j] = color[adj[i][j]];
    }
    sort(adj[i].begin(), adj[i].end());
  } // convert adjacent nodes to colors and sort by color
  for (int c=1;c<=n;c++) {
    for (auto u : in[c]) {
      int shouldBe = 1;
      for (auto v : adj[u]) {
        if (v == shouldBe) shouldBe++; // because colors in neighbors are sorted
      }
      if (shouldBe != c)
        return order;
    }
  }
  order.clear();
  sort(colors.begin(), colors.end());
  for (int i=0;i<n;i++) order.pb(colors[i].S);
  return order;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  int u, v;
  for (int i=0;i<m;i++) {
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for (int i=0;i<n;i++) {
    int c;
    cin >> c;
    colors.pb(mp(c, i+1));
    color[i+1] = c;
    in[c].pb(i+1);
    if (c > n) {
      cout << "-1 \n";
      return 0;
    }
  }
  vector<int> order = solve();
  for (int i=0;i<order.size();i++) {
    cout << order[i] << (i == n-1 ? "\n" : " ");
  }
  return 0;
}
