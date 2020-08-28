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
vector<int> ans;

int solve() {
  int res = 2;
  int s = (int) sqrt(n);
  bool exists[s + 2];
  for (int i=0;i*i<=n;i++) exists[i] = false;
  ans.pb(0); ans.pb(1);
  exists[0] = exists[1] = true;
  for (int i=1;i*i<=n;i++) {
    if (n / i > s || !exists[n / i]) {
      ans.pb(n / i);
      if (n / i <= s)
        exists[n / i] = true;
      res++;
    }
    if (!exists[i]) {
      ans.pb(i);
      exists[i] = true;
      res++;
    }
  }
  sort(ans.begin(), ans.end());
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ans.clear();
    cin >> n;
    cout << solve() << endl;
    for(int i=0;i<ans.size();i++) {
      cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    }
  }
  return 0;
}
