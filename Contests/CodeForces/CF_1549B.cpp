#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
vector<char> r[2];

int solve() {
  int res = 0;
  vector<bool> used(n, false);
  for (int i=0;i<n;i++) {
    if (r[0][i] == '0') {
      res += (!used[i] && r[1][i] == '1');
      used[i] = true;
    }
    else {
      if (i > 0 && !used[i-1] && r[1][i-1] == '1') {
        res++;
        used[i-1] = true;
      }
      else if (i < n-1 && !used[i+1] && r[1][i+1] == '1') {
        res++;
        used[i+1] = true;
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
    for (int i=0;i<2;i++) {
      r[i].clear();
      for (int j=0;j<n;j++) {
        char k;
        cin >> k;
        r[i].pb(k);
      }
    }
    cout << solve() << "\n";
  }
  return 0;
}