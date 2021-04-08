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
string s;
int dp[1200001];
vector<char> letters;
int occ[21][21];
map<char, int> idx;

int solve() {
  map<char, int> cnt;
  int curr = 1;
  for (int i=0;i<n;i++) {
    cnt[s[i]]++;
    if (cnt[s[i]] == 1) {
      letters.pb(s[i]);
      curr *= 2;
      idx[s[i]] = letters.size() - 1;
    }
  }
  for (int i=0;i<letters.size();i++) {
    for (int j=0;j<letters.size();j++) {
      occ[i][j] = 0;
    }
  }
  for (int i=1;i<n;i++) {
    occ[idx[s[i-1]]][idx[s[i]]]++;
  }
  for (int i=0;i<letters.size();i++) {
    occ[0][i]++;
  }
  dp[0] = 0;
  for (int mask=1;mask<(1 << letters.size());mask++) {
    dp[mask] = n;
    for (int i=0;i<letters.size();i++) {
      if (mask & (1 << i)) {
        int add = dp[mask ^ (1 << i)];
        for (int j=0;j<letters.size();j++) {
          if (mask & (1 << j)) {
            add += occ[i][j];
          }
        }
        dp[mask] = min(dp[mask], add);
      }
    }
  }
  return dp[(1 << letters.size()) - 1];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> s;
  n = s.length();
  cout << solve() << "\n";
  return 0;
}
