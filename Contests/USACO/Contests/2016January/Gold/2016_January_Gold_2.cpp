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

struct pt {
  int x, y;
};

int n, m;
pt a[1002];
pt b[1002];

int dist(int i, int j) {
  return abs(a[i].x - b[j].x) * abs(a[i].x - b[j].x) + abs(a[i].y - b[j].y) * abs(a[i].y - b[j].y);
}

ll solve() {
  ll dp[n+1][m+1];
  for (int i=0;i<=n;i++) {
    for (int j=0;j<=m;j++) {
      //cout << b[j].x << " " << b[j].y << "\n";
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;
  for (int i=0;i<=n;i++) {
    for (int j=0;j<=m;j++) {
      if (i == 0 && j == 0) continue;
      if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j]);
      if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1]);
      if (i > 0 && j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
      dp[i][j] += dist(i, j);
    }
  }
  return dp[n][m];
}

int main() {
  ofstream cout ("radio.out");
  ifstream cin ("radio.in");
  cin >> n >> m;
  cin >> a[0].x >> a[0].y;
  cin >> b[0].x >> b[0].y;
  pt curr;
  curr.x = a[0].x;
  curr.y = a[0].y;
  for (int i=0;i<n;i++) {
    char c;
    cin >> c;
    if (c == 'N') curr.y++;
    else if (c == 'W') curr.x--;
    else if (c == 'E') curr.x++;
    else curr.y--;
    a[i+1].x = curr.x;
    a[i+1].y = curr.y;
  }
  curr.x = b[0].x;
  curr.y = b[0].y;
  for (int i=0;i<m;i++) {
    char c;
    cin >> c;
    if (c == 'N') curr.y++;
    else if (c == 'W') curr.x--;
    else if (c == 'E') curr.x++;
    else curr.y--;
    b[i+1].x = curr.x;
    b[i+1].y = curr.y;
  }
  cout << solve() << endl;
  return 0;
}
