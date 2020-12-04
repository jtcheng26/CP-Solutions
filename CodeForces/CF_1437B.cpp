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
string s;

int solve() {
  int res1 = 0;
  int res0 = 0;
  for (int i=1;i<n;i++) {
    if (s[i] == s[i-1] && s[i] == '1') res1++;
    if (s[i] == s[i-1] && s[i] == '0') res0++;
  }
  return max(res0, res1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    cout << solve() << "\n";
  }
  return 0;
}
