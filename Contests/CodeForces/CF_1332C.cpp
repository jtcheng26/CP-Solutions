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

int n, k;
string s;

int solve() {
  int res = 0;
  vector<char> comps[k+1];
  for (int i=0;i<n;i+=k) {
    for (int j=0;j<(k+1)/2;j++) {
      if (k % 2 == 1 && j == k / 2) {
        comps[j].pb(s[i+j]);
        continue;
      }
      comps[j].pb(s[i + j]);
      comps[j].pb(s[i+k-j-1]);
    }
  }
  for (int i=0;i<(k+1)/2;i++) {
    int cnt[26] = {0};
    int change = comps[i].size();
    for (int j=0;j<comps[i].size();j++) {
      cnt[comps[i][j] - 'a']++;
    }
    for (int j=0;j<26;j++) {
      change = min(change, (int)comps[i].size() - cnt[j]);
    }
    res += change;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cin >> s;
    cout << solve() << endl;
  }
  return 0;
}
