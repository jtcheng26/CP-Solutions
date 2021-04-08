#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, k, d;
vector<int> adj[300001];
vector<int> idx[300001]; // index of edges
bool visited[300001];
vector<int> stations;
vector<int> ans;

void bfs() {
  queue<pair<int, int> > cities;
  for (int i=0;i<stations.size();i++)
    cities.push(make_pair(stations[i], 0));
  while (!cities.empty()) {
    int root = cities.front().F;
    int par = cities.front().S;
    cities.pop();
    if (visited[root]) continue;
    visited[root] = true;
    for (int i=0;i<adj[root].size();i++) {
      int child = adj[root][i];
      if (child == par) continue;
      if (visited[child]) ans.pb(idx[root][i]);
      else cities.push(make_pair(child, root));
    }
  }
}

int solve() {
  int res = 0;
  for (int i=0;i<=n;i++) visited[i] = false;
  bfs();
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> n >> k >> d;
  for (int i=0;i<k;i++) {
    int police_loc;
    cin >> police_loc;
    stations.pb(police_loc);
  }
  for (int i=0;i<n-1;i++) {
    int city1, city2;
    cin >> city1 >> city2;
    adj[city1].pb(city2);
    adj[city2].pb(city1);
    idx[city1].pb(i+1);
    idx[city2].pb(i+1);
  }
  solve();
  cout << int(ans.size()) << endl;
  if (ans.size() == 0) return 0;
  for (int i=0;i<int(ans.size()) - 1;i++) {
    cout << ans[i] << " ";
  }
  cout << ans[ans.size()-1] << endl;
  return 0;
}
