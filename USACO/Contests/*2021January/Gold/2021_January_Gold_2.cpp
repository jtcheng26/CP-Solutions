#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 10e17
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, k;
int a[50001];
int ok[51][51];

ll solve() {
  ll dist[k+1][n];
  for (int i=0;i<=k;i++) {
    for (int j=0;j<n;j++) {
      dist[i][j] = -1;
    }
  }
  queue<pair<int, int> > q;
  q.push(mp(a[0], 0));
  dist[a[0]][0] = 0;
  while (!q.empty()) {
    int color = q.front().F;
    int u = q.front().S;
    //cout << color << " " << u << " " << dist[color][u] << "\n";
    q.pop();
    if (u == n - 1 && ok[color][a[u]]) {
      return dist[color][u];
    }
    if (ok[color][a[u]]) {
      if (u && dist[a[u]][u-1] == -1) {
        dist[a[u]][u-1] = dist[color][u] + 1;
        q.push(mp(a[u], u-1));
      }
      if (u < n - 1 && dist[a[u]][u+1] == -1) {
        dist[a[u]][u+1] = dist[color][u] + 1;
        q.push(mp(a[u], u+1));
      }
    }
    if (u && dist[color][u-1] == -1) {
      dist[color][u-1] = dist[color][u] + 1;
      q.push(mp(color, u-1));
    }
    if (u < n - 1 && dist[color][u+1] == -1) {
      dist[color][u+1] = dist[color][u] + 1;
      q.push(mp(color, u+1));
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=1;i<=k;i++) {
    for (int j=1;j<=k;j++) {
      char c;
      cin >> c;
      ok[i][j] = c - '0';
    }
  }
  cout << solve() << endl;
  return 0;
}
