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
  int r1, c1, r2, c2, o1, o2;
};

int n;
char a[21][21];

pair<int, int> deltas[4] = {mp(-1, 0), mp(0, 1), mp(1, 0), mp(0, -1)};
int delts[2] = {1, -1};

int solve() {
  int dist[n][n][4][n][n][4];
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      for (int a=0;a<4;a++) {
        for (int k=0;k<n;k++) {
          for (int l=0;l<n;l++) {
            for (int b=0;b<4;b++) {
              dist[i][j][a][k][l][b] = INF;
            }
          }
        }
      }
    }
  }
  queue<state> q;
  state s;
  s.r1 = n-1;
  s.r2 = n-1;
  s.o1 = 0;
  s.c1 = 0;
  s.c2 = 0;
  s.o2 = 1;
  q.push(s);
  dist[n-1][0][0][n-1][0][1] = 0;
  while (!q.empty()) {
    state top = q.front();
    //cout << (top.r1) << " " << (top.c1) << " " << (top.o1) << " " << (top.r2) << " " << (top.c2) << " " << (top.o2) << "\n";
    //cout << dist[top.r1][top.c1][top.o1][top.r2][top.c2][top.o2] << "\n";
    q.pop();
    int dTop = dist[top.r1][top.c1][top.o1][top.r2][top.c2][top.o2];
    if (top.r1 == 0 && top.c1 == n - 1 && top.r2 == 0 && top.c2 == n - 1) return dTop;
    for (int i=0;i<2;i++) {
      if (dist[top.r1][top.c1][(top.o1 + delts[i] + 4) % 4][top.r2][top.c2][(top.o2 + delts[i] + 4) % 4] == INF) {
        dist[top.r1][top.c1][(top.o1 + delts[i] + 4) % 4][top.r2][top.c2][(top.o2 + delts[i] + 4) % 4] = dTop + 1;
        state nxt;
        nxt.r1 = top.r1;
        nxt.r2 = top.r2;
        nxt.c1 = top.c1;
        nxt.c2 = top.c2;
        nxt.o1 = (top.o1 + delts[i] + 4) % 4;
        nxt.o2 = (top.o2 + delts[i] + 4) % 4;
        q.push(nxt);
      }
    }
    state nxt;
    nxt.r1 = top.r1;
    nxt.c1 = top.c1;
    if (!(top.r1 == 0 && top.c1 == n - 1)) {
      int newR = top.r1 + deltas[top.o1].F;
      int newC = top.c1 + deltas[top.o1].S;
      if (a[newR][newC] == 'E') {
        nxt.r1 = top.r1 + (newR >= 0 && newR < n ? deltas[top.o1].F : 0);
        nxt.c1 = top.c1 + (newC >= 0 && newC < n ? deltas[top.o1].S : 0);
      }
    }
    nxt.r2 = top.r2;
    nxt.c2 = top.c2;
    if (!(top.r2 == 0 && top.c2 == n - 1)) {
      int newR = top.r2 + deltas[top.o2].F;
      int newC = top.c2 + deltas[top.o2].S;
      if (a[newR][newC] == 'E') {
        nxt.r2 = top.r2 + (newR >= 0 && newR < n ? deltas[top.o2].F : 0);
        nxt.c2 = top.c2 + (newC >= 0 && newC < n ? deltas[top.o2].S : 0);
      }
    }
    nxt.o1 = top.o1;
    nxt.o2 = top.o2;
    //if (nxt.r1 < 0 || nxt.r1 > n - 1 || nxt.r2 < 0 || nxt.r2 > n - 1 || nxt.c1 < 0 || nxt.c1 > n - 1 || nxt.c2 < 0 || nxt.c2 > n - 1) continue;
    if (dist[nxt.r1][nxt.c1][nxt.o1][nxt.r2][nxt.c2][nxt.o2] == INF) {
      dist[nxt.r1][nxt.c1][nxt.o1][nxt.r2][nxt.c2][nxt.o2] = dTop + 1;
      q.push(nxt);
    }
  }
  int res = INF;
  for (int i=0;i<4;i++) {
    for (int j=0;j<4;j++) {
      res = min(res, dist[0][n-1][i][0][n-1][j]);
    }
  }
  return res;
}

int main() {
  ofstream cout ("cownav.out");
  ifstream cin ("cownav.in");
  cin >> n;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      cin >> a[i][j];
    }
  }
  cout << solve() << endl;
  return 0;
}
