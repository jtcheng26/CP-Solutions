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
string t;
int dp[201][201][201];

int answer(int pos, int kcnt, int lcnt) {
  if (pos >= n) return 0;
  if (dp[pos][kcnt][lcnt] != -1) return dp[pos][kcnt][lcnt];
  int opt1, opt2, opt3;
  if (s[pos] == t[0]) { // equal to left
    opt1 = answer(pos+1, kcnt, lcnt+1); // keep
    opt2 = 0;
    if (kcnt < k) opt2 = lcnt + answer(pos+1, kcnt+1, lcnt); // switch to right
    dp[pos][kcnt][lcnt] = max(opt1, opt2);
  } else if (s[pos] == t[1]) { // equal to right
    opt1 = lcnt + answer(pos+1, kcnt, lcnt); // keep
    opt2 = 0;
    if (kcnt < k) opt2 = answer(pos+1, kcnt+1, lcnt+1); // switch to left
    dp[pos][kcnt][lcnt] = max(opt1, opt2);
  } else { // neither
    opt1 = answer(pos+1, kcnt, lcnt); // keep
    opt2 = 0;
    opt3 = 0;
    if (kcnt < k) {
      opt2 = answer(pos+1, kcnt+1, lcnt+1); // switch to left
      opt3 = lcnt + answer(pos+1, kcnt+1, lcnt); // switch to right
    }
    dp[pos][kcnt][lcnt] = max(max(opt1, opt2), opt3);
  }
  //cout << "at position " << pos << " ks used " << kcnt<<  " and lefts " << lcnt << ": " << dp[pos][kcnt][lcnt] << endl;
  return dp[pos][kcnt][lcnt];
}

int solve() {
  if (t[0] == t[1]) {
    int cnt = 0;
    int letters = 0;
    int res = 0;
    for (int i=0;i<n;i++) {
      if (s[i] != t[0] && cnt < k) {
        cnt++;
        res += letters;
        letters++;
      } else if (s[i] == t[0]) {
        res += letters;
        letters++;
      }
    }
    return res;
  }
  for (int i=0;i<=n;i++)
  for (int j=0;j<=k;j++)
  for (int m=0;m<=n;m++)
    dp[i][j][m] = -1;
  return answer(0, 0, 0);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  cin >> s;
  cin >> t;
  cout << solve() << endl;
  return 0;
}
