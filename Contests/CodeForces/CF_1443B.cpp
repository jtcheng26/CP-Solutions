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

int n, a, b;
string s;

int solve() {
  int res = 0;
  vector<int> nums;
  int curr = 0;
  int cnt = 0;
  for (int i=0;i<n;i++) {
    if (s[i] == '0' && curr == 1)
      curr = 0;
    else if (s[i] == '1' && curr == 0) {
      if (res == 0) res = a;
      else res += min(a, cnt * b);
      cnt = 1;
      curr = 1;
    } else if (s[i] == '0' && curr == 0) cnt++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    cin >> s;
    n = s.length();
    cout << solve() << "\n";
  }
  return 0;
}
