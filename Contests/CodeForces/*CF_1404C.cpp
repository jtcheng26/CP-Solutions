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

bool solve() {
  bool must[2][n];
  for (int i=0;i<2;i++)
  for (int j=0;j<n;j++)
    must[i][j] = false;
  for (int i=0;i<n;i++)
    if (s[i] != '?')
      must[s[i] - '0'][i] = true;
  for (int i=0;i<n-k;i++) {
    if (must[0][i]) must[0][i+k] = true;
    else if (must[1][i]) must[1][i+k] = true;
  }
  for (int i=n-1;i>=k;i--) {
    if (must[0][i]) must[0][i-k] = true;
    else if (must[1][i]) must[1][i-k] = true;
  }
  int cnt[2] = {0};
  for (int i=0;i<n;i++) {
    if (must[0][i] && must[1][i]) return false;
    else if (must[0][i]) s[i] = '0';
    else if (must[1][i]) s[i] = '1';
  }
  for (int i=0;i<k;i++) {
    if (s[i] != '?')
      cnt[s[i] - '0']++;
  }
  return cnt[0] <= k / 2 && cnt[1] <= k / 2;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cin >> s;
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}
