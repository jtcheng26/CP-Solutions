#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

struct state {
  int x, y, vx, vy;
};

int dx[7] = {-1, 1, 0, 0, -1, 1, 0};
int dy[7] = {-1, 1, 0, 1, 0, 0, -1};

int r, c;
vector<string> a;
pair<int, int> s;

int solve() {
  int dist[r][c][8][8];
  for (int i=0;i<r;i++) {
    for (int j=0;j<c;j++) {
      for (int k=0;k<8;k++) {
        for (int l=0;l<8;l++) {
          dist[i][j][k][l] = INF;
        }
      }
    }
  }
  queue<state> q;
  state start;
  start.x = s.F;
  start.y = s.S;
  start.vx = 0;
  start.vy = 0;
  //cout << s.F << " " << s.S << "\n";
  dist[s.F][s.S][3][3] = 0;
  q.push(start);
  while (!q.empty()) {
    state top = q.front();
    q.pop();
    int x = top.x;
    int y = top.y;
    int vx = top.vx;
    int vy = top.vy;
    int x2 = x + vx;
    int y2 = y + vy;
    //cout << x << " " << y << " " << vx << " " << vy << "\n";
    bool ok1 = true;
    if (vx < 0) {
      for (int j=0;j >= vx;j--) {
        if (x + j < 0 || x + j >= r) ok1 = false;
        else if (a[x + j][y] == '#') ok1 = false;
        else if (ok1 && a[x+j][y] == '$') return dist[x][y][vx + 3][vy + 3] + 1;
      }
    } else {
      for (int j=0;j<=vx;j++) {
        if (x + j < 0 || x + j >= r) ok1 = false;
        else if (a[x+j][y] == '#') ok1 = false;
        else if (ok1 && a[x+j][y] == '$') return dist[x][y][vx + 3][vy + 3] + 1;
      }
    }
    if (ok1) {
      if (vy < 0) {
        for (int j=0;j >=vy;j--) {
          if (y + j < 0 || y + j >= c) ok1 = false;
          else if (a[x+vx][y + j] == '#') ok1 = false;
          else if (ok1 && a[x+vx][y + j] == '$') return dist[x][y][vx + 3][vy + 3] + 1;
        }
      } else {
        for (int j=0;j<=vy;j++) {
          if (y + j < 0 || y + j >= c) ok1 = false;
          else if (a[x+vx][y + j] == '#') ok1 = false;
          else if (ok1 && a[x+vx][y + j] == '$') return dist[x][y][vx + 3][vy + 3] + 1;
        }
      }
    }
    bool ok2 = true;
    if (vy < 0) {
      for (int j=0;j >= vy;j--) {
        if (y + j < 0 || y + j >= c) ok2 = false;
        else if (a[x][y + j] == '#') ok2 = false;
        else if (ok2 && a[x][y + j] == '$') return dist[x][y][vx + 3][vy + 3] + 1;
      }
    } else {
      for (int j=0;j<=vy;j++) {
        if (y + j < 0 || y + j >= c) ok2 = false;
        else if (a[x][y + j] == '#') ok2 = false;
        else if (ok2 && a[x][y + j] == '$') return dist[x][y][vx + 3][vy + 3] + 1;
      }
    }
    if (ok2) {
      if (vx < 0) {
        for (int j=0;j >=vx;j--) {
          if (x + j < 0 || x + j >= r) ok2 = false;
          else if (a[x + j][y + vy] == '#') ok2 = false;
          else if (ok2 && a[x+j][y + vy] == '$') return dist[x][y][vx + 3][vy + 3] + 1;
        }
      } else {
        for (int j=0;j<=vx;j++) {
          if (x + j < 0 || x + j >= r) ok2 = false;
          else if (a[x+j][y + vy] == '#') ok2 = false;
          else if (ok2 && a[x+j][y + vy] == '$') return dist[x][y][vx + 3][vy + 3] + 1;
        }
      }
    }
    if (!ok1 && !ok2) continue;
    for (int i=0;i<7;i++) {
      if (vx + dx[i] >= -3 && vx + dx[i] <= 3 && vy + dy[i] >= -3 && vy + dy[i] <= 3) {
        if (dist[x + vx][y + vy][vx + dx[i] + 3][vy + dy[i] + 3] == INF) {
          dist[x + vx][y + vy][vx + dx[i] + 3][vy + dy[i] + 3] = dist[x][y][vx+3][vy+3] + 1;
          state nxt;
          nxt.x = x + vx;
          nxt.y = y + vy;
          nxt.vx = vx + dx[i];
          nxt.vy = vy + dy[i];
          q.push(nxt);
        }
      }
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    a.clear();
    cin >> r >> c;
    a.resize(r);
    getline(cin, a[0]);
    for (int i=0;i<r;i++) {
      getline(cin, a[i]);
      for (int j=0;j<c;j++) {
        if (a[i][j] == 'C') {
          s.F = i;
          s.S = j;
        }
      }
    }
    cout << solve() << "\n";
  }
  return 0;
}