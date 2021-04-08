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
#define INF 1000000007

typedef long long ll;

using namespace std;

int n, d;
char grid[1001][1001];

int solve() {
  int res = 0;
  bool ans[n][n];
  int rockDist[n][n];
  int dist[n][n];
  queue<pair<int, int> > rocks;
  queue<pair<int, int> > sources;
  for (int r=0;r<n;r++) {
    for (int c=0;c<n;c++) {
      ans[r][c] = 0;
      if (grid[r][c] == '#') {
        rocks.push(mp(r, c));
        rockDist[r][c] = 0;
      } else {
        rockDist[r][c] = INF;
        dist[r][c] = INF;
        if (grid[r][c] == 'S') {
          sources.push(mp(r, c));
          dist[r][c] = 0;
        }
      }
    }
  }
  while (!rocks.empty()) {
    pair<int, int> top = rocks.front();
    rocks.pop();
    vector<pair<int, int> > emptyNeighbors;
    if (top.F > 0 && grid[top.F - 1][top.S] != '#' && rockDist[top.F - 1][top.S] == INF) {
      emptyNeighbors.pb(mp(top.F - 1, top.S));
    }
    if (top.F < n && grid[top.F + 1][top.S] != '#' && rockDist[top.F + 1][top.S] == INF) {
      emptyNeighbors.pb(mp(top.F + 1, top.S));
    }
    if (top.S > 0 && grid[top.F][top.S - 1] != '#' && rockDist[top.F][top.S - 1] == INF) {
      emptyNeighbors.pb(mp(top.F, top.S - 1));
    }
    if (top.S < n && grid[top.F][top.S + 1] != '#' && rockDist[top.F][top.S + 1] == INF) {
      emptyNeighbors.pb(mp(top.F, top.S + 1));
    }
    for (pair<int, int> neighbor : emptyNeighbors) {
      rockDist[neighbor.F][neighbor.S] = rockDist[top.F][top.S] + 1;
      rocks.push(neighbor);
    }
  }
  vector<pair<int, int> > centers[n*n];
  while (!sources.empty()) {
    pair<int, int> top = sources.front();
    sources.pop();
    vector<pair<int, int> > emptyNeighbors;
    if (dist[top.F][top.S] / d <= rockDist[top.F][top.S]) {
      ans[top.F][top.S] = 1;
      centers[rockDist[top.F][top.S] - 1].pb(top);
      if (dist[top.F][top.S] / d == rockDist[top.F][top.S]) continue;
      if (top.F > 0 && grid[top.F - 1][top.S] != '#' && dist[top.F - 1][top.S] == INF) {
        emptyNeighbors.pb(mp(top.F - 1, top.S));
      }
      if (top.F < n && grid[top.F + 1][top.S] != '#' && dist[top.F + 1][top.S] == INF) {
        emptyNeighbors.pb(mp(top.F + 1, top.S));
      }
      if (top.S > 0 && grid[top.F][top.S - 1] != '#' && dist[top.F][top.S - 1] == INF) {
        emptyNeighbors.pb(mp(top.F, top.S - 1));
      }
      if (top.S < n && grid[top.F][top.S + 1] != '#' && dist[top.F][top.S + 1] == INF) {
        emptyNeighbors.pb(mp(top.F, top.S + 1));
      }
      for (pair<int, int> neighbor : emptyNeighbors) {
        dist[neighbor.F][neighbor.S] = dist[top.F][top.S] + 1;
        sources.push(neighbor);
      }
    }
  }
  for (int i=n*n-1;i>0;i--) {
    for (int j=0;j<centers[i].size();j++) {
      pair<int, int> top = centers[i][j];
      vector<pair<int, int> > emptyNeighbors;
      if (top.F > 0 && grid[top.F - 1][top.S] != '#' && ans[top.F - 1][top.S] == 0) {
        emptyNeighbors.pb(mp(top.F - 1, top.S));
      }
      if (top.F < n && grid[top.F + 1][top.S] != '#' && ans[top.F + 1][top.S] == 0) {
        emptyNeighbors.pb(mp(top.F + 1, top.S));
      }
      if (top.S > 0 && grid[top.F][top.S - 1] != '#' && ans[top.F][top.S - 1] == 0) {
        emptyNeighbors.pb(mp(top.F, top.S - 1));
      }
      if (top.S < n && grid[top.F][top.S + 1] != '#' && ans[top.F][top.S + 1] == 0) {
        emptyNeighbors.pb(mp(top.F, top.S + 1));
      }
      for (pair<int, int> neighbor : emptyNeighbors) {
        ans[neighbor.F][neighbor.S] = 1;
        centers[i - 1].pb(neighbor);
      }
    }
  }
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (ans[i][j]) res++;
    }
  }
  return res;
}

int main() {
  cin >> n >> d;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      cin >> grid[i][j];
    }
  }
  cout << solve() << endl;
  return 0;
}
