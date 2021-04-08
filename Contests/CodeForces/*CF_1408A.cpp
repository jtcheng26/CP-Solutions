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
int nums[3][101];
int ans[101];

int solve() {
  int res = 0;
  ans[0] = nums[0][0];
  for (int i=1;i<n-1;i++) {
    for (int k=0;k<3;k++) {
      if (nums[k][i] != ans[i-1]) {
        ans[i] = nums[k][i];
        continue;
      }
    }
  }
  for (int k=0;k<3;k++) {
    if (nums[k][n-1] != ans[0] && nums[k][n-1] != ans[n-2]) {
      ans[n-1] = nums[k][n-1];
      break;
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
    for (int k=0;k<3;k++) {
      for (int i=0;i<n;i++) {
        cin >> nums[k][i];
      }
    }
    solve();
    for (int i=0;i<n;i++) cout << ans[i] << (i == n-1 ? "\n" : " ");
  }
  return 0;
}
