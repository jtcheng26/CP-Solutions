/*
   LANG: C++11
   PROG: agrinet
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define INFI 100000007

typedef long long ll;

using namespace std;

ll n;
int w[101][101];
vector<int> conn[101];

int solve() {
  int dist[n+1]; bool fnd[n+1]; int src[n+1];
  int sz = 1; int cost = 0;
  for (int i=0;i<=n;i++) {
    dist[i] = INFI;
    fnd[i] = false;
    src[i] = -1;
    for (int j=0;j<=n;j++)
      if (w[i][j] == 0) w[i][j] = INFI;
  }
  fnd[1] = true;
  for (int j : conn[1]) {
    dist[j] = w[1][j];
    src[j] = 1;
  }
  while (sz < n) {
    int v; int min_dist = INFI;
    for (int i=1;i<=n;i++) {
      if (!fnd[i] && dist[i] < min_dist) {
        v = i;
        min_dist = dist[i];
      }
    }
    sz++; cost += dist[v];
    fnd[v] = true;
    for (int j : conn[v]) {
      if (!fnd[j] && dist[j] > w[v][j]) {
        dist[j] = w[v][j];
        src[j] = v;
      }
    }
  }
  return cost;
}

int main() {
  ofstream cout ("agrinet.out");
  ifstream cin ("agrinet.in");
  cin >> n;
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) {
      cin >> w[i][j];
      if (i != j) {
        conn[i].push_back(j);
      }
    }
  }
  cout << solve() << endl;
  return 0;
}
