#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
int a[1001][1001];

int solve() {
  int res = 0;
  for (int i=0;i<n;i++) {
    int col = 0;
    for (int j=0;j<n;j+=2) {
      col += a[i][j];
    }
    int col2 = 0;
    for (int j=1;j<n;j+=2) {
      col2 += a[i][j];
    }
    res += max(col, col2);
  }
  int res2 = 0;
  for (int i=0;i<n;i++) {
    int row = 0;
    for (int j=0;j<n;j+=2) {
      row += a[j][i];
    }
    int row2 = 0;
    for (int j=1;j<n;j+=2) {
      row2 += a[j][i];
    }
    res2 += max(row, row2);
  }
  return max(res, res2);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      cin >> a[i][j];
    }
  }
  cout << solve() << "\n";
  return 0;
}
