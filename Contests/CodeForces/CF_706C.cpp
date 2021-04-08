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
int cost[100001];
string words[1000001][2];

string reverse_str(string s) {
  string res = "";
  for (int i=0;i<s.length();i++) {
    res += s.substr(s.length() - i - 1, 1);
  }
  return res;
}

void reverse_words() {
  for (int i=0;i<n;i++) {
    words[i][1] = reverse_str(words[i][0]);
  }
}

ll solve() {
  reverse_words();
  ll dp[n+1][2];
  for (int i=0;i<n;i++)
  for (int j=0;j<2;j++) dp[i][j] = INFI;
  dp[0][0] = 0;
  dp[0][1] = cost[0];
  for (int i=1;i<n;i++) {
    if (dp[i-1][0] < INFI && words[i][0] >= words[i-1][0])
      dp[i][0] = dp[i-1][0];
    if (dp[i-1][0] < INFI && words[i][1] >= words[i-1][0])
      dp[i][1] = dp[i-1][0] + cost[i];
    if (dp[i-1][1] < INFI && words[i][0] >= words[i-1][1])
      dp[i][0] = min(dp[i][0], dp[i-1][1]);
    if (dp[i-1][1] < INFI && words[i][1] >= words[i-1][1])
      dp[i][1] = min(dp[i][1], dp[i-1][1] + cost[i]);
    if (dp[i][0] >= INFI && dp[i][1] >= INFI) return -1;
  }
  return min(dp[n-1][0], dp[n-1][1]);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> cost[i];
  for (int i=0;i<n;i++)
    cin >> words[i][0];
  cout << solve() << endl;
  return 0;
}
