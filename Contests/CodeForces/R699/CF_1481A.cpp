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

int x, y;
string s;

int solve() {
  int res = 0;
  int cnt[4] = {0};
  for (int i=0;i<s.length();i++) {
    if (s[i] == 'U') cnt[0]++;
    else if (s[i] == 'R') cnt[1]++;
    else if (s[i] == 'D') cnt[2]++;
    else cnt[3]++;
  }
  if (x >= 0 && y >= 0) {
    if (cnt[0] >= y && cnt[1] >= x) return true;
  } else if (x >= 0 && y <= 0) {
    if (cnt[2] >= -1 * y && cnt[1] >= x) return true;
  } else if (x <= 0 && y <= 0) {
    if (cnt[2] >= -1 * y && cnt[3] >= -1 * x) return true;
  } else if (cnt[0] >= y && cnt[3] >= -1 * x) {
    return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> x >> y;
    cin >> s;
    cout << (solve() ? "YES" : "NO") << "\n";
  }
  return 0;
}
