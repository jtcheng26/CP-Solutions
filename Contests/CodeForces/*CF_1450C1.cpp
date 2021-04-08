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
char a[301][301];

int solve() {
  int res = 0;
  int color[301][301];
  int cnt[2][3] = {0};
  for (int r=0;r<n;r++) {
    for (int c=0;c<n;c++) {
      color[r][c] = (r + c) % 3;
      if (a[r][c] == 'X') cnt[0][color[r][c]]++;
      else if (a[r][c] == 'O') cnt[1][color[r][c]]++;
    }
  }
  pair<int, int> ans(0, 1);
  for (int i=0;i<3;i++) {
    for (int j=0;j<3;j++) {
      if (i == j) continue;
      if (cnt[0][i] + cnt[1][j] < cnt[0][ans.F] + cnt[1][ans.S])
        ans = mp(i, j);
    }
  }
  for (int r=0;r<n;r++) {
    for (int c=0;c<n;c++) {
      if (a[r][c] == 'X' && color[r][c] == ans.F) {
        res++;
        a[r][c] = 'O';
      }
      else if (a[r][c] == 'O' && color[r][c] == ans.S) {
        res++;
        a[r][c] = 'X';
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
        cin >> a[i][j];
      }
    }
    solve();
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
        cout << a[i][j] << (j == n-1 ? "\n" : "");
      }
    }
  }
  return 0;
}
