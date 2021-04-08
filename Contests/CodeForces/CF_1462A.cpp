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
int a[301];
int ans[301];

void solve() {
  int l = 0;
  int r = n - 1;
  int cnt = 0;
  while (l <= r) {
    ans[cnt++] = a[l];
    ans[cnt++] = a[r];
    l++;
    r--;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    solve();
    for (int i=0;i<n;i++) cout << ans[i] << (i == n-1 ? "\n": " ");
  }
  return 0;
}
