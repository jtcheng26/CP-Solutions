#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int a[300002];
int ans[100002];
set<pair<int, int> > s;

int solve() {
  int j = 0;
  for (int i=0;i<n;i++) {
    while (j < 2 * n + i && (s.empty() || a[j] * 2 >= s.rbegin()->F)) {
      s.insert(mp(a[j], j));
      j++;
    }
    if (j == 2 * n + i) ans[i] = -1;
    else ans[i] = j - i;
    s.erase(s.find(mp(a[i], i)));
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i];
    a[n + i] = a[i];
    a[2 * n + i] = a[i];
  }
  solve();
  for (int i=0;i<n-1;i++) {
    cout << ans[i] << " ";
  }
  cout << ans[n-1] << endl;
  return 0;
}
