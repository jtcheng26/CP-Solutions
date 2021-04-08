#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, m;
int a[300001];
int b[300001];

ll solve() {
  ll res = 0;
  sort(a, a+n);
  int j = 0;
  for (int i=n-1;i>=0;i--) {
    if (j < m && j <= a[i]-1 && b[a[i]-1] > b[j]) {
      res += b[j];
      j++;
    } else {
      res += b[a[i]-1];
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<m;i++) cin >> b[i];
    cout << solve() << "\n";
  }
  return 0;
}
