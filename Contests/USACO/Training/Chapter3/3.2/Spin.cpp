/*
   LANG: C++11
   PROG: spin
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int spd[5];
int rot[5];
vector<pair<int, int> > wedge[5];

bool check() {
  bool gap[5][360];
  for (int i=0;i<5;i++)
  for (int j=0;j<360;j++)
    gap[i][j] = false;
  for (int i=0;i<5;i++) {
    for (pair<int, int> j : wedge[i]) {
      int e = j.second;
      if (e < j.first) e = 360 + e;
      for (int k=j.first;k<=e;k++) {
        gap[i][k % 360] = true;
      }
    }
  }
  for (int i=0;i<360;i++) {
    int j;
    for (j=0;j<5;j++) {
      if (!gap[j][i]) break;
    }
    if (j == 5) return true;
  }
  return false;
}

bool cycle() {
  int i;
  for (i=0;i<5;i++) {
    if (rot[i] != 0) break;
  }
  if (i == 5) return true;
  return false;
}

int solve() {
  int cnt = 0;
  while (!check()) {
    for (int i=0;i<5;i++) {
      rot[i] += spd[i];
      rot[i] %= 360;
      for (int j=0;j<wedge[i].size();j++) {
        wedge[i][j].first += spd[i];
        wedge[i][j].second += spd[i];
        wedge[i][j].first %= 360;
        wedge[i][j].second %= 360;
      }
      //cout << "cnt " << cnt + 1 << endl;
      //cout << rot[i] << endl;
    }
    cnt++;
    if (cycle()) return -1;
  }
  return cnt;
}

int main() {
  ofstream cout ("spin.out");
  ifstream cin ("spin.in");
  for (int i=0;i<5;i++) {
    cin >> spd[i];
    rot[i] = 0;
    int w;
    cin >> w;
    wedge[i].resize(w);
    for (int j=0;j<w;j++) {
      pair<int, int> p;
      wedge[i][j] = p;
      cin >> wedge[i][j].first >> wedge[i][j].second;
      wedge[i][j].second = (wedge[i][j].first + wedge[i][j].second) % 360;
    }
  }
  int ans = solve();
  if (ans == -1) cout << "none" << endl;
  else cout << ans << endl;
  return 0;
}
