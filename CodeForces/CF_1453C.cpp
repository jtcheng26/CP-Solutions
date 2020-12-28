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
int a[2001][2001];
ll ans[10];

void solve() {
  int top[10]; // uppermost y index
  int bot[10];
  int left[10];
  int right[10];
  for (int i=0;i<10;i++) {
    ans[i] = top[i] = bot[i] = left[i] = right[i] = -1;
  }
  for (int i=0;i<n;i++) {
    int leftmost[10];
    for (int k=0;k<10;k++) leftmost[k] = -1;
    int rightmost[10];
    for (int j=0;j<n;j++) {
      if (top[a[i][j]] == -1) top[a[i][j]] = i;
      if (leftmost[a[i][j]] == -1) leftmost[a[i][j]] = j;
      rightmost[a[i][j]] = j;
      bot[a[i][j]] = i;
    }
    for (int k=0;k<10;k++) {
      if (leftmost[k] != -1) {
        ans[k] = max(ans[k], ((ll)(rightmost[k] - leftmost[k])) * ((ll)max(i, n - i - 1)));
      }
    }
  }
  for (int j=0;j<n;j++) {
    int topmost[10];
    for (int k=0;k<10;k++) topmost[k] = -1;
    int botmost[10];
    for (int i=0;i<n;i++) {
      if (left[a[i][j]] == -1) left[a[i][j]] = j;
      if (topmost[a[i][j]] == -1) topmost[a[i][j]] = i;
      botmost[a[i][j]] = i;
      right[a[i][j]] = j;
    }
    for (int k=0;k<10;k++) {
      if (topmost[k] != -1) {
        ans[k] = max(ans[k], ((ll)(botmost[k] - topmost[k])) * ((ll)max(j, n - j - 1)));
      }
    }
  }
  for (int i=0;i<10;i++) {
    if (top[i] == -1) ans[i] = 0;
  }
  for (int k=0;k<10;k++) {
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
        ans[a[i][j]] = max(ans[a[i][j]], ((ll)max(bot[a[i][j]] - i, i - top[a[i][j]])) * ((ll)max(n - j - 1, j)));
        ans[a[i][j]] = max(ans[a[i][j]], ((ll)max(right[a[i][j]] - j, j - left[a[i][j]])) * ((ll)max(n - i - 1, i)));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    char c;
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
        cin >> c;
        a[i][j] = c - '0';
      }
    }
    solve();
    for (int i=0;i<10;i++) {
      cout << ans[i] << (i == 9 ? "\n" : " ");
    }
  }
  return 0;
}
