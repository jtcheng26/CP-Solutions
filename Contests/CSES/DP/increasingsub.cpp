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
int a[200001];

int solve() {
  int dp[n];
  int res = 1;
  for (int i=0;i<n;i++) {
    dp[i] = INF;
  }
  dp[0] = a[0];
  for (int i=1;i<n;i++) {
    int l = 0;
    int r = i;
    while (l < r) {
      int mid = (l + r) / 2;
      if (a[i] > dp[mid]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    dp[l] = min(dp[l], a[i]);
    res = max(res, l + 1);
  }
  return res;
}

int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << solve() << endl;
  return 0;
}
