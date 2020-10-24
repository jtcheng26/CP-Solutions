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

int n;
int square[101][101];

int solve() {
  int res = 0;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (j == i || j == i+1)
        square[i][j] = 1;
      else
        square[i][j] = 0;
    }
  }
  square[n-1][0] = 1;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    solve();
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
      cout << square[i][j] << (j == n-1 ? "\n" : " ");
  }
  return 0;
}
