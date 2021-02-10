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

struct BIT {
  vector<int> bit;
  void init(int n) {
    bit.assign(n, 0);
  }
  int sum(int r) {
    int res = 0;
    for (; r >= 0;r = (r & (r + 1)) - 1)
      res += bit[r];
    return res;
  }
  int sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }
  void add(int idx, int d) {
    for (; idx < bit.size(); idx = idx | (idx + 1))
      bit[idx] += d;
  }
};

int n;
string s;

int solve() {
  int ans = 1;
  BIT bits[26];
  for (int i=0;i<26;i++) bits[i].init(n);
  vector<int> loc[26];
  for (int i=0;i<n;i++) {
    loc[s[i]-'a'].pb(i);
    bits[s[i]-'a'].add(i, 1);
  }
  for (int i=0;i<26;i++) {
    ans = max(ans, (int)loc[i].size());
    if (loc[i].size() > 0) {
      for (int k=0;k<26;k++) {
        int cnt = 0;
        if (k == i) continue;
        for (int j=0;j<loc[i].size()-1;j++) {
          cnt += max(0, bits[k].sum(loc[i][j], loc[i][j+1]) - 1);
        }
        cnt += max(max(0, bits[k].sum(0, loc[i][0]) - 1), max(0, bits[k].sum(loc[i][loc[i].size()-1], n-1) - 1));
        ans = max(ans, (int)loc[i].size()+cnt);
      }
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> s;
  n = s.length();
  cout << solve() << endl;
  return 0;
}
