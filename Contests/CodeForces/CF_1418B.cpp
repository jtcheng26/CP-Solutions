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
int a[101];
int locked[101];
vector<int> unlocked;

int solve() {
  int res = 0;
  sort(unlocked.rbegin(), unlocked.rend());
  int idx = 0;
  for (int i=0;i<n;i++) {
    if (!locked[i]) a[i] = unlocked[idx++];
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    unlocked.clear();
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) {
      cin >> locked[i];
      if (!locked[i]) unlocked.pb(a[i]);
    }
    solve();
    for (int i=0;i<n;i++) cout << a[i] << (i == n-1 ? "\n" : " ");
  }
  return 0;
}
