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
int a[3001];

ll solve() {
  ll prs[n+1]; // possible pairings to the right
  ll res = 0;
  for (int i=0;i<=n;i++) prs[i] = 0;
  for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      if (a[i] == a[j]) prs[i]++;
    }
  }
  for (int i=0;i<n;i++) {
    int j;
    for (j=0;j<i - 1;j++) {
      if (a[j] == a[i]) break;
    }
    if (j == i - 1) continue;
    ll csum = 0;
    if (a[j] == a[i]) {
      int seen[3001] = {0};
      seen[a[i]] = 1;
      //cout << "i " << i << endl;
      for (int k=i-1;k>j;k--) {
        //cout << prs[k] << endl;
        res += prs[k] - seen[a[k]];
        if (a[k] == a[i] && i - k > 1) res += csum;
        csum += prs[k] - seen[a[k]];
        seen[a[k]]++;
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << solve() << endl;
  }
  return 0;
}
