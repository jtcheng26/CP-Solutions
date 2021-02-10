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
  int r, c, d; // row, col, direction entered from
  bool o; // orange
};

int n, m;
int a[1001][1001];
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { -1, 0, 1, 0 };

int solve() {
  int dist[n][m][4][2];
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      for (int k=0;k<4;k++) {
        for (int l=0;l<2;l++) {
          dist[i][j][k][l] = -1;
        }
      }
    }
  }
  queue<state> q;
  dist[0][0][0][0] = 0;
  state start = { 0, 0, 0, 0 };
  q.push(start);
  while (!q.empty()) {
    state top = q.front();
    q.pop();
    int dTop = dist[top.r][top.c][top.d][top.o];
    if (top.r == n - 1 && top.c == m - 1) return dTop;
    if (a[top.r][top.c] == 4) {
      int r = top.r + dr[top.d];
      int c = top.c + dc[top.d];
      if (!(r < 0 || r >= n || c < 0 || c >= m)) {
        if (a[r][c] != 3 && a[r][c] != 0) {
          if (dist[r][c][top.d][0] == -1) {
            dist[r][c][top.d][0] = dTop + 1;
            state nxt = { r, c, top.d, 0 };
            q.push(nxt);
          }
          continue;
        }
      }
    }
    for (int i=0;i<4;i++) {
      int r = top.r + dr[i];
      int c = top.c + dc[i];
      bool o = (top.o || a[top.r][top.c] == 2) && (a[top.r][top.c] != 4);
      if (r < 0 || r >= n || c < 0 || c >= m) continue;
      if (dist[r][c][i][o] == -1 && a[r][c] != 0) {
        if (!(a[r][c] == 3 && !o)) {
          dist[r][c][i][o] = dTop + 1;
          state nxt = { r, c, i, o };
          q.push(nxt);
        }
      }
    }
  }
  return -1;
}

int main() {
  ofstream cout ("dream.out");
  ifstream cin ("dream.in");
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      cin >> a[i][j];
    }
  }
  cout << solve() << endl;
  return 0;
}
