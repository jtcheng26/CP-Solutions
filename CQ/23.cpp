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

struct ta { 
  int x, y, d;
};

int n;
vector<ta> a;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> solve() {
  pair<int, int> ans;
  map<pair<int, int>, int> cnt;
  
  for (int j=0;j<3;j++) {
    if (a[j].d == 0) return mp(a[j].x, a[j].y);
    queue<pair<pair<int, int>, int> > q;
    q.push(mp(mp(a[j].x, a[j].y), 0));
    map<pair<int, int>, int> visited;
    visited[mp(a[j].x, a[j].y)] = true;
    while (!q.empty()) {
      pair<pair<int, int>, int> top = q.front();
      q.pop();
      int x = top.F.F;
      int y = top.F.S;
      int d = top.S;
      if (d == a[j].d) continue;
      for (int i=0;i<4;i++) {
        if (visited[mp(x + dx[i], y + dy[i])]) continue;
        if (d == a[j].d - 1) {
          cnt[mp(x + dx[i], y + dy[i])]++;
        }
        visited[mp(x + dx[i], y + dy[i])] = true;
        q.push(mp(mp(x + dx[i], y + dy[i]), d + 1));
      }
    }
  }
  for (auto it=cnt.begin(); it != cnt.end(); it++) {
    if (it->S == 3) return mp((it->F).F, (it->F).S);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    a.clear();
    a.resize(3);
    for (int j=0;j<3;j++) {
      cin >> a[j].x >> a[j].y >> a[j].d;
    }
    pair<int, int> ans = solve();
    cout << "(" << ans.F << "," << ans.S << ")" << "\n";
  }
  return 0;
}