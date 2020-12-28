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

int n, x;
char s[100001];

int solve() {
  int res = x == 0;
  vector<int> balances;
  int cnt[2] = {0};
  for (int i=0;i<n;i++) {
    cnt[s[i] - '0']++;
    balances.pb(cnt[0] - cnt[1]);
  }
  if (balances[n-1] == 0) {
    for (int b : balances)
      if (b == x)
        res++;
  } else {
    for (int b : balances) {
      if ((x - b) % balances[n-1] == 0 && ((x - b >= 0 && balances[n-1] >= 0) || (x - b <= 0 && balances[n-1] <= 0))) {
        //cout << b << "\n";
        res++;
      }
    }
  }
  if (res > 0 && cnt[0] == cnt[1]) return -1;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    for (int i=0;i<n;i++) cin >> s[i];
    cout << solve() << "\n";
  }
  return 0;
}
