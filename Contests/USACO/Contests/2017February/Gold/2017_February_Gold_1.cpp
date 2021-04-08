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
  int r, c, s, d;
};

inline bool operator<(const state& a, const state& b) {
  return a.d > b.d;
}

int n, t;
int cost[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void debug(state s) {
  cout << "state for r: " << s.r << " c: " << s.c << "\n";
  cout << "  steps " << s.s << " " << " time " << s.d << "\n";
}

int solve() {
  int res = INF;
  bool v[n][n][3];
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      for (int k=0;k<3;k++) {
        v[i][j][k] = false;
      }
    }
  }
  priority_queue<state> q;
  state init = {0, 0, 0, 0};
  q.push(init);
  v[0][0][0] = true;
  while (!q.empty()) {
    state top = q.top();
    //debug(top);
    if (top.r == n-1 && top.c == n-1) return top.d;
    for (int i=0;i<4;i++) {
      int r = top.r + dx[i];
      int c = top.c + dy[i];
      if (r < n && r >= 0 && c < n && c >= 0) {
        int s = (top.s + 1) % 3;
        int dist = s == 0 ? top.d + t + cost[r][c] : top.d + t;
        //cout << "adding " << r << " " << c << " " << top.s+1 << " " << dist << "\n";
        //cout << v[r][c][top.s+1] << "\n";
        if (!v[r][c][s]) {
          state ins = {r, c, s, dist};
          v[r][c][s] = true;
          q.push(ins);
        }
      }
    }
    q.pop();
  }
  return 0;
}

int main() {
  ofstream cout ("visitfj.out");
  ifstream cin ("visitfj.in");
  cin >> n >> t;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      cin >> cost[i][j];
    }
  }
  cout << solve() << "\n";
  return 0;
}
