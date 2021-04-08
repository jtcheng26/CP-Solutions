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
int a[200001];

ll solve() {
  ll res = 0;
  sort(a, a+n);
  res = a[n-1];
  for (int i=n-2;i>=n-k-1;i--) {
    res += a[i];
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << solve() << endl;
  }
  return 0;
}
