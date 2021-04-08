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

int n, m, c;
vector<int> adj[1001];
int money[1001];

int solve() {
  int best[n+1][1002];
  int visited[n+1];
  for (int i=0;i<=n;i++) {
    for (int j=0;j<=1001;j++) {
      best[i][j] = 0;
    }
    visited[i] = 0;
  }
  visited[1] = 1;
  for (int i=1;i<=1001;i++) {
    for (int j=1;j<=n;j++) {
      if (visited[j] == 1) visited[j] = 2;
    }
    for (int j=1;j<=n;j++) {
      if (visited[j] != 2) continue;
      for (int neighbor : adj[j]) {
        best[neighbor][i] = max(best[neighbor][i], best[j][i-1] + money[neighbor]);
        if (visited[neighbor] == 0)
          visited[neighbor] = 1;
      }
    }
  }
  int res = 0;
  for (int i=1;i<=1001;i++) {
    res = max(res, best[1][i] - c * i * i);
  }
  return res;
}

int main() {
  ofstream cout ("time.out");
  ifstream cin ("time.in");
  cin >> n >> m >> c;
  for (int i=1;i<=n;i++) {
    cin >> money[i];
  }
  for (int i=0;i<m;i++) {
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
  }
  cout << solve() << endl;
  return 0;
}
