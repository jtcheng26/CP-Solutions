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

int n, m;
vector<pair<int, int> > switches[101][101];

int solve() {
  int res = 1;
  int status[101][101]; // 0 = off 1 = neighboring 2 = on 3 = in queue
  for (int i=0;i<=n;i++) {
    for (int j=0;j<=n;j++) {
      status[i][j] = 0;
    }
  }
  status[1][1] = 3;
  queue<pair<int, int> > q;
  q.push(mp(1, 1));
  while (!q.empty()) {
    pair<int, int> top = q.front();
    q.pop();
    for (pair<int, int> on : switches[top.F][top.S]) {
      if (status[on.F][on.S] == 0) {
        status[on.F][on.S] = 2;
        res++;
      }
      else if (status[on.F][on.S] == 1) {
        status[on.F][on.S] = 3;
        res++;
        q.push(on);
      }
    }
    if (top.F > 1) {
      if (status[top.F-1][top.S] == 0) status[top.F-1][top.S] = 1;
      else if (status[top.F-1][top.S] == 2) {
        status[top.F-1][top.S] = 3;
        q.push(mp(top.F-1, top.S));
      }
    }
    if (top.S > 1) {
      if (status[top.F][top.S-1] == 0) status[top.F][top.S-1] = 1;
      else if (status[top.F][top.S-1] == 2) {
        status[top.F][top.S-1] = 3;
        q.push(mp(top.F, top.S-1));
      }
    }
    if (top.F < n) {
      if (status[top.F+1][top.S] == 0) status[top.F+1][top.S] = 1;
      else if (status[top.F+1][top.S] == 2) {
        status[top.F+1][top.S] = 3;
        q.push(mp(top.F+1, top.S));
      }
    }
    if (top.S < n) {
      if (status[top.F][top.S+1] == 0) status[top.F][top.S+1] = 1;
      else if (status[top.F][top.S+1] == 2) {
        status[top.F][top.S+1] = 3;
        q.push(mp(top.F, top.S+1));
      }
    }
  }
  return res;
}

int main() {
 ofstream cout ("lightson.out");
 ifstream cin ("lightson.in");
 cin >> n >> m;
 for (int i=0;i<m;i++) {
   int x, y;
   int a, b;
   cin >> x >> y >> a >> b;
   switches[x][y].pb(mp(a, b));
 }
 cout << solve() << endl;
 return 0;
}
