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
int cnt[8001];
int a[8001];

int solve() {
  int res = 0;
  int pfx[n];
  pfx[0] = a[0];
  for (int i=1;i<n;i++) pfx[i] = pfx[i-1] + a[i];
  for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      int c;
      if (i == 0) c = pfx[j];
      else c = pfx[j] - pfx[i-1];
      if (c > 8000) break;
      res += cnt[c];
      cnt[c] = 0;
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
    for (int i=0;i<=8000;i++) cnt[a[i]] = 0;
    for (int i=0;i<n;i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    cout << solve() << endl;
  }
  return 0;
}
