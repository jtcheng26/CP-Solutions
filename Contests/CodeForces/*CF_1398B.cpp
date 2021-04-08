#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 100000007

typedef long long ll;

using namespace std;

int n; string s;

int solve() {
  vector<int> oneLens;
  int res = 0;
  int cnt = 0;
  for (int i=0;i<s.length();i++) {
    if (s[i] == '1') cnt++;
    else if (cnt > 0) {
      oneLens.push_back(cnt);
      cnt = 0;
    }
  }
  if (cnt > 0) oneLens.push_back(cnt);
  sort(oneLens.rbegin(), oneLens.rend());
  for (int i=0;i<oneLens.size();i++) {
    if (i % 2 == 0)
      res += oneLens[i];
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> s;
    cout << solve() << endl;
  }
  return 0;
}
