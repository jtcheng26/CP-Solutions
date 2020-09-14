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
ll a[100001];
ll num;
ll mx;
ll mn;

ll solve() {
  ll res = 0;
  for (int i=0;i<n;i++) {
    if (i > 0 && a[i] == -1 && a[i-1] != -1)
      mn = min(mn, a[i-1]), mx = max(mx, a[i-1]);
    if (i < n-1 && a[i] == -1 && a[i+1] != -1)
      mn = min(mn, a[i+1]), mx = max(mx, a[i+1]);
  }
  if (mn == INFI)
    num = 1;
  else
    num = (mx + mn) / 2;
  //cout << "k " << num << endl;
  for (int i=0;i<n;i++) {
    if (a[i] == -1) a[i] = num;
  }
  for (int i=1;i<n;i++) {
    res = max(res, abs(a[i] - a[i-1]));
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    mx = 0;
    mn = INFI;
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    cout << solve() << " " << num << endl;
  }
  return 0;
}
