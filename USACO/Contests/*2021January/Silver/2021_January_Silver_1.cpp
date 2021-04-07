#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, k;
int cow[100001];
set<int> cycle[100001];
int cycleOf[100001];
pair<int, int> swaps[200001];

void dfs(int node) {
  //cout << node << "\n";
  if (cycleOf[cow[node]] != -1) {
    cycleOf[node] = cycleOf[cow[node]];
    cycle[cycleOf[cow[node]]].insert(cow[node]);
    cycle[cycleOf[cow[node]]].insert(node);
  } else {
    dfs(cow[node]);
    cycleOf[node] = cycleOf[cow[node]];
    cycle[cycleOf[cow[node]]].insert(node);
  }
}

vector<int> solve() {
  vector<int> res;
  for (int i=1;i<=n;i++) {
    //cout << cow[i] << " ";
    cycleOf[i] = -1;
  }
  //cout << "\n";
  int c = 0;
  for (int i=1;i<=n;i++) {
    if (cycleOf[i] == -1) {
      cycleOf[i] = c++;
      dfs(i);
    }
  }
  for (int i=0;i<k;i++) {
    int u = cow[swaps[i].F];
    int v = cow[swaps[i].S];
    cycle[cycleOf[u]].insert(swaps[i].S);
    cycle[cycleOf[v]].insert(swaps[i].F);
    /*
    if (!cycle[cycleOf[u]].count(swaps[i].S)) {
      cout << u << " u " << v << "\n";
      res[u-1]++;
    }
    if (!cycle[cycleOf[v]].count(swaps[i].F)) {
      cout << u << " v " << v << "\n";
      res[v-1]++;
    }
    */
    int temp = cow[swaps[i].F];
    cow[swaps[i].F] = cow[swaps[i].S];
    cow[swaps[i].S] = temp;
  }
  for (int i=1;i<=n;i++) {
    //cow[i] = i;
    res.pb(cycle[cycleOf[i]].size());
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i=1;i<=n;i++) cow[i] = i;
  for (int i=0;i<k;i++) {
    int u, v;
    cin >> u >> v;
    swaps[i] = mp(u, v);
    int temp = cow[u];
    cow[u] = cow[v];
    cow[v] = temp;
  }
  vector<int> ans = solve();
  for (int i : ans) {
    cout << i << "\n";
  }
  return 0;
}
