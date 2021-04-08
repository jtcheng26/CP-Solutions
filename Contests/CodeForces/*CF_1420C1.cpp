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

int n, q;
ll a[300001];

ll solve() {
  ll res = 0;
  ll oddMax = 0;
  ll evenMax = 0;
  for (int i=0;i<n;i++) {
    ll oldOdd = oddMax;
    oddMax = max(oddMax, evenMax + a[i]);
    evenMax = max(evenMax, oldOdd - a[i]);
  }
  return oddMax;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> q;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << solve() << endl;
  }
  return 0;
}
