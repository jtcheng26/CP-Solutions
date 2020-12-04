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
int dist[2001][10];
char nums[2001][7];
string number[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string ans;
int dp[2001][2001];

bool recurse(int pos, int remaining) {
  if (pos >= n) return remaining == 0;
  if (dp[pos][remaining] != 2) return dp[pos][remaining];
  for (int i=9;i>=0;i--) {
    if (dist[pos][i] <= remaining) {
      ans[pos] = (char)('0' + i);
      if (recurse(pos+1, remaining-dist[pos][i])) {
        dp[pos][remaining] = true;
        return true;
      }
    }
  }
  dp[pos][remaining] = false;
  return false;
}

bool solve() {
  for (int i=0;i<n;i++)
  for (int j=0;j<=k;j++)
    dp[i][j] = 2;
  for (int i=0;i<n;i++) {
    for (int j=0;j<10;j++) {
      dist[i][j] = 0;
      for (int m=0;m<7;m++) {
        if (nums[i][m] == '1' && number[j][m] == '0') {
          dist[i][j] = k+1;
          break;
        }
        dist[i][j] += nums[i][m] != number[j][m];
      }
    }
  }
  for (int i=0;i<n;i++) ans += "0";
  return recurse(0, k);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i=0;i<n;i++) {
    for (int j=0;j<7;j++) {
      cin >> nums[i][j];
    }
  }
  if (solve()) {
    cout << ans << "\n";
  } else {
    cout << "-1\n";
  }
  return 0;
}
