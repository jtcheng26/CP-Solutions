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

struct state {
  int r, c, o;
};

struct cmpState {
  bool operator()(pair<int, state> s1, pair<int, state> s2) {
    return s1.F >= s2.F;
  }
};

int n, m;
char a[501][501];
int dg[2] = {1, -1};
int dc[2] = {1,- 1};

int solve() {
  int dist[2][n][m];
  state c;
  state d;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      if (a[i][j] == 'C') {
        c.r = i;
        c.c = j;
        c.o = 0;
      }
      for (int k=0;k<2;k++) {
        dist[k][i][j] = -1;
      }
    }
  }
  priority_queue<pair<int, state>, vector<pair<int, state> >, cmpState> q;
  dist[c.o][c.r][c.c] = 0;
  q.push(mp(0, c));
  int ans = INF;
  while (!q.empty()) {
    pair<int, state> fnt = q.top();
    state top = fnt.S;
    q.pop();
    if (a[top.r][top.c] == 'D') {
      ans = min(ans, fnt.F);
    }
    if (top.r + dg[top.o] < 0 || top.r + dg[top.o] > n - 1) continue;
    else if (a[top.r + dg[top.o]][top.c] != '#') {
      if (dist[top.o][top.r + dg[top.o]][top.c] == -1 || dist[top.o][top.r + dg[top.o]][top.c] > fnt.F) {
        dist[top.o][top.r + dg[top.o]][top.c] = fnt.F;
        state s;
        s.o = top.o;
        s.r = top.r + dg[top.o];
        s.c = top.c;
        q.push(mp(fnt.F, s));
      }
    } else {
      for (int i=0;i<2;i++) {
        state nxt;
        nxt.c = top.c + dc[i];
        nxt.r = top.r;
        nxt.o = top.o;
        if (nxt.c < 0 || nxt.c > m - 1) continue;
        if (a[nxt.r][nxt.c] == '#') continue;
        if (dist[nxt.o][nxt.r][nxt.c] == -1 || dist[nxt.o][nxt.r][nxt.c] > fnt.F) {
          dist[nxt.o][nxt.r][nxt.c] = fnt.F;
          q.push(mp(fnt.F, nxt));
        }
      }
      state flip;
      flip.r = top.r;
      flip.c = top.c;
      flip.o = !top.o;
      if (dist[flip.o][flip.r][flip.c] == -1 || dist[flip.o][flip.r][flip.c] > fnt.F + 1) {
        dist[flip.o][flip.r][flip.c] = fnt.F + 1;
        q.push(mp(fnt.F + 1, flip));
      }
    }
  }
  return ans == INF ? -1 : ans;
}

int main() {
  ofstream cout ("gravity.out");
  ifstream cin ("gravity.in");
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      cin >> a[i][j];
    }
  }
  cout << solve() << endl;
  return 0;
}
