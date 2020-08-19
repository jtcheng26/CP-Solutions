#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll n;
ll a[51];
ll b[51];
ll min_a = 1000000001;
ll min_b = 1000000001;

ll solve() {
  ll res = 0;
  for (int i=0;i<n;i++) {
    ll bm = min(a[i] - min_a, b[i] - min_b);
    res += bm;
    res += max(a[i] - min_a, b[i] - min_b) - bm;
    //cout << bm << endl;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    min_a = 1000000001;
    min_b = 1000000001;
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> a[i];
      min_a = min(min_a, a[i]);
    }
    for (int i=0;i<n;i++) {
      cin >> b[i];
      min_b = min(min_b, b[i]);
    }
    //cout << min_a << " " << min_b << endl;
    cout << solve() << endl;
  }

  return 0;
}
