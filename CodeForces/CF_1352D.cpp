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
int a[1001];
int ans[2], total;

int solve() {
  int turn = 1;
  int prev = a[0];
  int l = 1; int r = n-1;
  ans[0] = a[0]; ans[1] = 0; total = 1;
  while (l <= r) {
    int cnt = 0;
    while (cnt <= prev && l <= r) {
      if (turn == 0) cnt += a[l++];
      else cnt += a[r--];
    }
    prev = cnt;
    total++;
    ans[turn] += cnt;
    turn = !turn;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    solve();
    cout << total << " " << ans[0] << " " << ans[1] << "\n";
  }
  return 0;
}
