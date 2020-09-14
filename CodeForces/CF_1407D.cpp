#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int h[300001];
vector<pair<int, int> > vp;
vector<int> adj[300001];

void makeGraph() {
  set<int> s;
  for (int i=0;i<n;i++) {
    int height = vp[i].F;
    int idx = vp[i].S;
    auto it = s.lower_bound(idx);
    if (it != s.begin()) adj[*prev(it)].pb(idx); // left element
    if (it != s.end() && (idx == n - 1 || vp[i+1].F != height || vp[i+1].S > *it)) adj[idx].pb(*it); // right element
    s.insert(idx);
  }
}

int bfs() {
  int dist[n];
  for (int i=0;i<n;i++) dist[i] = 500001;
  queue<int> q;
  q.push(0); dist[0] = 0;
  while (!q.empty()) {
    int top = q.front(); q.pop();
    for (int child : adj[top]) {
      if (dist[top] + 1 < dist[child]) {
        dist[child] = dist[top] + 1;
        q.push(child);
      }
    }
  }
  return dist[n-1];
}

int solve() {
  int res = 0;
  sort(vp.begin(), vp.end());
  makeGraph();
  for (int i=0;i<n;i++) vp[i].F = -vp[i].F;
  sort(vp.begin(), vp.end());
  makeGraph();
  return bfs();
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> h[i];
    vp.pb(mp(h[i], i));
  }
  cout << solve() << endl;
  return 0;
}
