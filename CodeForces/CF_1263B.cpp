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
char a[11][5];

int solve() {
  int dig[10] = {0};
  int res = 0;
  for (int i=0;i<n;i++) dig[a[i][0] - '0']++;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (i == j) continue;
      int d;
      for (d=0;d<4;d++) if (a[i][d] != a[j][d]) break;
      if (d == 4) {
        for (int k=0;k<10;k++) {
          if (dig[k] == 0) {
            dig[k]++;
            a[i][0] = '0' + k;
            res++;
            break;
          }
        }
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
      for (int j=0;j<4;j++) cin >> a[i][j];
    }
    cout << solve() << endl;
    for (int i=0;i<n;i++) {
      for (int j=0;j<3;j++)
        cout << a[i][j];
      cout << a[i][3] << endl;
    }
  }
  return 0;
}
