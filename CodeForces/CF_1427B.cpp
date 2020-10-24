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
bool games[100000];

int solve() {
  int res = 0;
  vector<int> streaks;
  int left = k;
  int Lcnt = 0;
  int streak = 0;
  int start = 0;
  for (int i=0;i<n;i++) {
    res += games[i];
    Lcnt += !games[i];
    if (i > 0 && games[i] && games[i-1]) res++;
  }
  for (start=0;start<n;start++)
    if (games[start]) break;
  if (start == n && k > 0) return (k-1) * 2 + 1;
  for (int i=start;i<n;i++) {
    if (!games[i])
      streak++;
    else if (streak > 0) {
      streaks.pb(streak);
      streak = 0;
    }
  }
  sort(streaks.begin(), streaks.end());
  for (int i=0;i<streaks.size();i++) {
    if (left >= streaks[i]) {
      res += streaks[i] * 2 + 1;
      left -= streaks[i];
      Lcnt -= streaks[i];
    }
  }
  res += min(Lcnt, left) * 2;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i=0;i<n;i++) {
      char a;
      cin >> a;
      if (a == 'W') games[i] = true;
      else games[i] = false;
    }
    cout << solve() << endl;
  }
  return 0;
}
