#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 43200000000000LL
#define SECOND 720000000000LL
#define MINUTE 720000000000LL
#define HOUR 3600000000000LL

typedef long long ll;

using namespace std;

vector<ll> a;
ll h1, m1, s1, n1;

void solve() {
  //cout << "bruh: " << a[0] << " " << a[1] << " " << a[2] << "\n";
  do {
    ll h = a[0];
    ll m = a[1];
    ll s = a[2];
    //cout << h / HOUR << " " << m / MINUTE << " " << s / SECOND << "\n";
    if (12LL * (h % HOUR) == m && 60LL * (m % MINUTE) == s) {
      h1 = h / HOUR;
      m1 = m / MINUTE;
      s1 = s / SECOND;
      return;
    }
    //cout << h << " " << m << " " << s << "\n";
  } while (next_permutation(a.begin(), a.end()));
  //cout << "none" << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  for (int z=1;z<=t;z++) {
    a.clear();
    a.resize(3);
    cin >> a[0] >> a[1] >> a[2];
    solve();
    cout << "Case #" << z << ": " << h1 << " " << m1 << " " << s1 << " " << n1 << "\n";
  }
  return 0;
}