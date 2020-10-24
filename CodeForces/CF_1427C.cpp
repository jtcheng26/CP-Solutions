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

struct pt {
  int time, x, y;
};

int r, n;
vector<pt> pts;

int dist(pt a, pt b) {
  return abs(a.x - b.x) + abs(a.y - b.y);
}

int solve() {
  int res = 0;
  pt start;
  start.time = 0;
  start.x = 1;
  start.y = 1;
  if (pts.size() == 0) return 0;
  int dp[n];
  int prevDP = 0;
  dp[0] = 1;
  for (int i=0;i<n;i++) {
    dp[i] = 1; // from starting point to here
    for (int j=i-1;j>=max(i-2*r+1, 0);j--) {
      if (dist(pts[i], pts[j]) <= pts[i].time - pts[j].time) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    if (i >= 2 * r) {
      prevDP = max(prevDP, dp[i-2*r]);
      dp[i] = max(dp[i], prevDP+1);
    }
    //cout << i << " " << dp[i] << endl;
    //cout << prevDP << endl;
    res = max(res, dp[i]);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> r >> n;
  pts.resize(n);
  pt start;
  start.x = 1;
  start.y = 1;
  for (int i=0;i<n;i++) {
    cin >> pts[i].time >> pts[i].x >> pts[i].y;
    if (dist(pts[i], start) > pts[i].time) {
      n--;
      i--;
    }
  }
  cout << solve() << "\n";
  return 0;
}
