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

int n;
int a[1001];
int b[1001];

int solve() {
  int dp[n+1][n+1];
  for (int i=0;i<=n;i++) {
    for (int j=0;j<=n;j++) {
      dp[i][j] = 0;
    }
  }
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) {
      dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] + (abs(a[i] - b[j]) <= 4));
    }
  }
  return dp[n][n];
}

int main() {
  ofstream cout ("nocross.out");
  ifstream cin ("nocross.in");
  cin >> n;
  for (int i=1;i<=n;i++) {
    cin >> a[i];
  }
  for (int i=1;i<=n;i++) {
    cin >> b[i];
  }
  cout << solve() << endl;
  return 0;
}
