/*
   LANG: C++14
   PROG: cowtour
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#include <queue>

#define INFI 100000007

typedef long long ll;

using namespace std;

struct point {
  int x, y;
};

ll n;
point p[151];
bool adj[151][151];
double w[151][151];
double dist[151][151];
int comp[151];
double max_in_comp[151];

void fw() {
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      dist[i][j] = w[i][j] == 0 ? INFI : w[i][j];
    }
  }
  for (int k=0;k<n;k++) {
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
        if (i == j) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        //cout << dist[i][j] << " " << comp[i] << " " << comp[j] << endl;
      }
    }
  }
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (dist[i][j] < INFI) max_in_comp[comp[i]] = max(dist[i][j], max_in_comp[comp[i]]);
    }
  }
}

void ff(int c, int s) {
  int visited = 1; queue<int> q;
  q.push(s);
  while (q.size() > 0) {
    int a = q.front();
    q.pop();
    comp[a] = c;
    for (int i=0;i<n;i++) {
      if (adj[a][i] && comp[i] == -2)
        q.push(i);
    }
  }
}

double solve() {
  double res = INFI;
  int c = 0;
  for (int i=0;i<n;i++) comp[i] = -2;
  for (int i=0;i<n;i++) {
    if (comp[i] == -2) {
      ff(++c, i);
    }
  }
  fw();
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (comp[i] == comp[j]) continue;
      //cout << i << " " << j << endl;
      double i_max = 0; double j_max = 0;
      for (int k=0;k<n;k++) i_max = dist[i][k] < INFI ? max(i_max, dist[i][k]) : i_max;
      double weight = sqrt(pow(abs(p[i].x - p[j].x), 2) + pow(abs(p[i].y - p[j].y), 2));
      for (int k=0;k<n;k++) j_max = dist[j][k] < INFI ? max(j_max, dist[j][k]) : j_max;
      //cout << max_in_comp[comp[i]] << " " << max_in_comp[comp[j]] << endl;
      res = min(res, max(max(i_max + weight + j_max, max_in_comp[comp[i]]), max_in_comp[comp[j]]));
    }
  }
  return res;
}

int main() {
  ofstream cout ("cowtour.out");
  ifstream cin ("cowtour.in");
  cin >> n;
  for (int i=0;i<n;i++) {
    point a;
    cin >> a.x >> a.y;
    p[i] = a;
  }
  for (int i=0;i<n;i++) {
    string s;
    cin >> s;
    for (int j=0;j<n;j++) {
      if (s[j] == '1') {
        adj[i][j] = true;
        w[i][j] = sqrt(pow(abs(p[i].x - p[j].x), 2) + pow(abs(p[i].y - p[j].y), 2));
      }
    }
  }
  cout << setprecision(6) << fixed;
  cout << solve() << endl;
  return 0;
}
