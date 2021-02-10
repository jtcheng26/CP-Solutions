#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, m;
char a[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string ans;

bool solve() {
  int dist[n][m];
  pair<int, int> parent[n][m];
  int mdist[n][m];
  pair<int, int> start;
  vector<pair<int, int> > monsters;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      dist[i][j] = INF;
      mdist[i][j] = INF;
      parent[i][j] = mp(-1, -1);
      if (a[i][j] == 'A') start = mp(i, j);
      if (a[i][j] == 'M') monsters.pb(mp(i, j));
    }
  }
  queue<pair<int, int> > q;
  for (pair<int, int>& monster : monsters) {
    mdist[monster.F][monster.S] = 0;
    q.push(mp(monster.F, monster.S));
  }
  while (!q.empty()) {
    pair<int, int> top = q.front();
    q.pop();
    for (int i=0;i<4;i++) {
      int x = top.F + dx[i];
      int y = top.S + dy[i];
      if (x < 0 || x > n - 1 || y < 0 || y > m - 1) continue;
      if (a[x][y] != '#' && mdist[x][y] == INF) {
        mdist[x][y] = mdist[top.F][top.S] + 1;
        q.push(mp(x, y));
      }
    }
  }
  dist[start.F][start.S] = 0;
  q.push(mp(start.F, start.S));
  pair<int, int> border(-1, -1);
  while (!q.empty()) {
    pair<int, int> top = q.front();
    q.pop();
    if (top.F == 0 || top.F == n - 1 || top.S == 0 || top.S == m - 1) {
      border.F = top.F;
      border.S = top.S;
      break;
    }
    for (int i=0;i<4;i++) {
      int x = top.F + dx[i];
      int y = top.S + dy[i];
      if (x < 0 || x > n - 1 || y < 0 || y > m - 1) continue;
      if (dist[top.F][top.S] + 1 >= mdist[x][y]) continue;
      if (a[x][y] != '#' && dist[x][y] == INF) {
        parent[x][y] = mp(top.F, top.S);
        dist[x][y] = dist[top.F][top.S] + 1;
        q.push(mp(x, y));
      }
    }
  }
  stack<char> st;
  if (border.F != -1) {
    pair<int, int> curr = border;
    while (!(curr.F == start.F && curr.S == start.S)) {
      int x = parent[curr.F][curr.S].F;
      int y = parent[curr.F][curr.S].S;
      if (x > curr.F) {
        st.push('U');
      } else if (x < curr.F) {
        st.push('D');
      } else if (y > curr.S) {
        st.push('L');
      } else {
        st.push('R');
      }
      curr.F = x;
      curr.S = y;
    }
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }
    return true;
  }
  return false;
}

int main() {
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      cin >> a[i][j];
    }
  }
  bool res = solve();
  if (res) {
    cout << "YES" << "\n";
    cout << ans.size() << "\n";
    cout << ans << "\n";
  } else {
    cout << "NO" << "\n";
  }
  return 0;
}
