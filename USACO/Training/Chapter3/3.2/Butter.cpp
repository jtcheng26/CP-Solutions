/*
   LANG: C++11
   PROG: butter
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e9+7

typedef long long ll;

using namespace std;

ll n, p, c;
vector<ll> adj[801];
ll w[801][801];
ll cow[501];
ll dist[801][801];

void dijkstra(int c) {
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  bool visited[p+1];
  for (int i=1;i<=p;i++) {
    dist[c][i] = INFI;
    visited[i] = false;
    pair<int, int> p(dist[c][c], c);
    pq.push(p);
  }
  dist[c][c] = 0;
  pair<int, int> p(dist[c][c], c);
  pq.push(p);
  while (pq.size() > 0) {
    pair<int, int> u = pq.top();
    pq.pop();
    int idx = u.second;
    if (visited[idx]) continue;
    visited[idx] = true;
    for (int i=0;i<adj[idx].size();i++) {
      int child = adj[idx][i];
      if (visited[child]) continue;
      int d = dist[c][idx] + w[idx][child];
      if (dist[c][child] > d)
        dist[c][child] = d;
      pair<int, int> node(dist[c][child], child);
      pq.push(node);
    }
  }
}

int solve() {
  ll res = INFI;
  for (int i=0;i<n;i++)
    dijkstra(cow[i]);
  //cout << "d" << endl;
  for (int i=1;i<=p;i++) {
    ll d = 0;
    for (int j=0;j<n;j++) {
      d += dist[cow[j]][i];
    }
    res = min(res, d);
  }
  return res;
}

int main() {
  ofstream cout ("butter.out");
  ifstream cin ("butter.in");
  cin >> n >> p >> c;
  for (int i=0;i<n;i++) {
    cin >> cow[i];
  }
  for (int i=0;i<c;i++) {
    int a, b, wt;
    cin >> a >> b >> wt;
    w[a][b] = wt;
    w[b][a] = wt;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  cout << solve() << endl;
  return 0;
}
