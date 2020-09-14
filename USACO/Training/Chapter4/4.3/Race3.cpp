/*
   LANG: C++11
   PROG: race3
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

struct Graph {
  vector<int> adj[51];
  vector<int> chokes;
  vector<int> splits;
  int n;
  void init(int num) { n = num; }
  void add_edge(int from, int to) {
    if (from == to) return;
    adj[from].pb(to);
  }
  void find_chokes() {
    for (int i=1;i<n-1;i++) if (check_choke(i)) chokes.pb(i);

  }
  bool check_choke(int v) {
    bool visited[51] = {false};
    queue<int> q;
    vector<int> visits;
    q.push(0);
    visited[0] = true;
    //cout << "trying " << v << endl;
    while (q.size() > 0) {
      int u = q.front();
      //cout << u << endl;
      q.pop();
      if (u == v) continue;
      if (u == n-1) return false;
      visits.pb(u);
      for (int i=0;i<adj[u].size();i++) {
        if (visited[adj[u][i]]) continue;
        q.push(adj[u][i]);
        visited[adj[u][i]] = true;
      }
    }
    return true;
  }
  void find_splits() {
    for (int i=0;i<chokes.size();i++) if (check_split(chokes[i])) splits.pb(chokes[i]);
  }
  bool check_split(int v) {
    bool visited[51] = {false};
    bool leftOf[51] = {false};
    queue<int> q;
    q.push(0);
    while (q.size() > 0) {
      int u = q.front();
      q.pop();
      if (u == v) continue;
      leftOf[u] = true;
      for (int i=0;i<adj[u].size();i++) {
        if (!visited[adj[u][i]]) {
          q.push(adj[u][i]);
          visited[adj[u][i]] = true;
        }
      }
    }
    for (int i=0;i<n;i++) visited[i] = false;
    q = queue<int>();
    q.push(v);
    while (q.size() > 0) {
      int u = q.front();
      q.pop();
      if (leftOf[u]) return false;
      visited[u] = true;
      for (int i=0;i<adj[u].size();i++) {
        if (!visited[adj[u][i]]) q.push(adj[u][i]);
      }
    }
    return true;
  }
  vector<int> get_chokes() { return chokes; }
  vector<int> get_splits() { return splits; }
};

int n = 0;
Graph g;
vector<int> c;
vector<int> s;

int solve() {
  //if (n <= 2) return 0;
  g.find_chokes();
  g.find_splits();
  c = g.get_chokes();
  s = g.get_splits();
  sort(c.begin(), c.end());
  sort(s.begin(), s.end());
  return 0;
}

int main() {
  ofstream cout ("race3.out");
  ifstream cin ("race3.in");
  int u = 0;
  while (true) {
    while(true) {
      cin >> u;
      if (u < 0) break;
      g.add_edge(n, u);
    }
    n++;
    if (u == -1) break;
  }
  n--;
  g.init(n);
  solve();
  cout << c.size() << (c.size() == 0 ? "\n" : " ");
  for (int i=0;i<c.size();i++) {
    cout << c[i] << (i == c.size() - 1 ? "\n" : " ");
  }
  cout << s.size() << (s.size() == 0 ? "\n" : " ");
  for (int i=0;i<s.size();i++) {
    cout << s[i] << (i == s.size() - 1 ? "\n" : " ");
  }
  return 0;
}
