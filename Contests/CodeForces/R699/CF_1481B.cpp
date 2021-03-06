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

int n, k;
int a[101];

int solve() {
  int res = -1;
  int i = 1;
  bool flag = false;
  while (i <= k && !flag) {
    flag = true;
    int j;
    for (j=0;j<n-1;j++) {
      if (a[j] < a[j+1]) {
        a[j]++;
        flag = false;
        break;
      }
    }
    if (i == k && !flag)
      res = j + 1;
    i++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << solve() << "\n";
  }
  return 0;
}
