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

int n;
string orig;
vector<string> ans;
bool used[9];
string s;

void rec(int j) {
  map<char, int> usedc;
  if (j == n) {
    ans.pb(s);
  }
  for (int i=0;i<n;i++) {
    if (!used[i] && !usedc[orig[i]]) {
      s[j] = orig[i];
      used[i] = true;
      usedc[orig[i]] = true;
      rec(j+1);
      used[i] = false;
    }
  }
}

void solve() {
  for (int i=0;i<n;i++) {
    used[i] = false;
  }
  rec(0);
  sort(ans.begin(), ans.end());
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> orig;
  n = orig.length();
  s = orig;
  solve();
  cout << ans.size() << "\n";
  for (int i=0;i<ans.size();i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
