#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
string s;

int solve() {
  int ans = 1;
  int cnt[26] = {0};
  int l = 0;
  int r = 0;
  while (r < n) {
    cnt[s[r]-'a']++;
    if (cnt[s[r]-'a'] > ans) {
      ans = cnt[s[r]-'a'];
      while (l < r && s[l] != s[r]) {
        l++;
      }
      l++;
    }
    r++;
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
