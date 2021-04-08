#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int a[201];
int dp[201][401];

int doStuff(int prevTime, int curr) {
  if (curr >= n) return 0;
  if (dp[curr][prevTime] >= 0) return dp[curr][prevTime];
  int best = INFI;
  for (int i=prevTime+1;i<2*n;i++) {
    best = min(best, doStuff(i, curr+1) + abs(a[curr] - i));
  }
  dp[curr][prevTime] = best;
  return dp[curr][prevTime];
}

int solve() {
  for (int i=0;i<n;i++) {
    for (int j=0;j<2*n;j++) {
      dp[i][j] = -1;
    }
  }
  sort(a, a+n);
  return doStuff(0, 0);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << solve() << "\n";
  }
  return 0;
}
