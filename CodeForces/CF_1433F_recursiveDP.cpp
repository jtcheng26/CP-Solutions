#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, m, k;
int a[71][71];
int dp[71][71][37][71];

int doStuff(int r, int c, int taken, int rem) {
  if (r < 0 || c < 0) return 0;
  if (dp[r][c][taken][rem] >= 0) return dp[r][c][taken][rem];
  int nextC = c == 0 ? m-1 : c - 1;
  int nextR = c == 0 ? r-1 : r;
  int nextTake = c == 0 ? 0 : taken + 1;
  int nextDont = c == 0 ? 0 : taken;
  int take = 0;
  if (taken < m / 2) {
    int nxt = doStuff(nextR, nextC, nextTake, (k + rem - a[r][c] % k) % k);
    if (nxt % k == (k + rem - a[r][c] % k) % k)
      take = a[r][c] + nxt;
  }
  int dont = doStuff(nextR, nextC, nextDont, rem);
  dp[r][c][taken][rem] = max(take, dont);
  //cout << r << " " << c << " " << taken << " " << rem << " " << dp[r][c][taken][rem] << "\n";
  return dp[r][c][taken][rem];
}

int solve() {
  for (int r=0;r<n;r++) {
    for (int c=0;c<m;c++) {
      for (int t=0;t<=m/2;t++) {
        for (int rem=0;rem<k;rem++) {
          dp[r][c][t][rem] = -1;
        }
      }
    }
  }
  return doStuff(n-1, m-1, 0, 0);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m >> k;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      cin >> a[i][j];
    }
  }
  cout << solve() << "\n";
  return 0;
}
