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
#define MOD 1e9+7

typedef long long ll;

using namespace std;

int n;
int a[100001];

int solve() {
  int res = 0;
  int cnt[2*n+2];
  for (int i=0;i<=2*n+1;i++) {
    cnt[i] = 0;
  }
  for (int i=0;i<n;i++) {
      cnt[a[i]]++;
      if (cnt[a[i]] == 1)
        res++;
  }
  for (int i=n-1;i>=0;i--) {
    if (cnt[a[i]+1] == 0) {
      cnt[a[i]+1]++;
      cnt[a[i]]--;
      if (cnt[a[i]] > 0) res++;
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
    cout << solve() << "\n";
  }
  return 0;
}
