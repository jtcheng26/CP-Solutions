#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int x, y, k, m;

int solve() {
  int res = m;
  int dist[x+1][y+1];
  for (int i=0;i<=x;i++) {
    for (int j=0;j<=y;j++) {
      dist[i][j] = INF;
    }
  }
  dist[0][0] = 0;
  queue<pair<int, int> > q;
  q.push(mp(0, 0));
  while (!q.empty()) {
    pair<int, int> top = q.front();
    q.pop();
    res = min(res, abs(m - (top.F + top.S)));
    if (dist[top.F][top.S] == k) continue;
    if (dist[0][top.S] == INF) {
      dist[0][top.S] = dist[top.F][top.S] + 1;
      q.push(mp(0, top.S));
    }
    if (dist[top.F][0] == INF) {
      dist[top.F][0] = dist[top.F][top.S] + 1;
      q.push(mp(top.F, 0));
    }
    if (dist[top.F][y] == INF) {
      dist[top.F][y] = dist[top.F][top.S] + 1;
      q.push(mp(top.F, y));
    }
    if (dist[x][top.S] == INF) {
      dist[x][top.S] = dist[top.F][top.S] + 1;
      q.push(mp(x, top.S));
    }
    if (dist[min(x, top.F + top.S)][top.F + top.S - min(x, top.F + top.S)] == INF) {
      dist[min(x, top.F + top.S)][top.F + top.S - min(x, top.F + top.S)] = dist[top.F][top.S] + 1;
      q.push(mp(min(x, top.F + top.S), top.F + top.S - min(x, top.F + top.S)));
    }
    if (dist[top.F + top.S - min(y, top.F + top.S)][min(y, top.F + top.S)] == INF) {
      dist[top.F + top.S - min(y, top.F + top.S)][min(y, top.F + top.S)] = dist[top.F][top.S] + 1;
      q.push(mp(top.F + top.S - min(y, top.F + top.S), min(y, top.F + top.S)));
    }
  }
  return res;
}

int main() {
  ofstream cout ("pails.out");
  ifstream cin ("pails.in");
  cin >> x >> y >> k >> m;
  cout << solve() << endl;
  return 0;
}
