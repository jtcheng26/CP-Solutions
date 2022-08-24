#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <iomanip>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
vector<string> a;

vector<double> solve() {
  vector<double> res;
  res.resize(26);
  double cnt = 0;
  for (string s : a) {
    for (int i=0;i<s.length();i++) {
      if (s[i] - 'A' < 26 && s[i] - 'A' >= 0) {
        res[s[i] - 'A']++;
        cnt++;
      } else if (s[i] - 'a' < 26 && s[i] - 'a' >= 0) {
        res[s[i] - 'a']++;
        cnt++;
      }
    }
  }
  for (int i=0;i<26;i++) {
    res[i] = res[i] / cnt * 100;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  cout << fixed;
  cout << setprecision(2);
  while (t--) {
    a.clear();
    cin >> n;
    string s;
    getline(cin, s);
    for (int i=0;i<n;i++) {
      string b;
      getline(cin, b);
      a.pb(b);
    }
    vector<double> ans = solve();
    for (int i=0;i<ans.size();i++) {
      cout << ((char)('A' + i)) << ": " << ans[i] << "%" << "\n";
    }
  }
  return 0;
}