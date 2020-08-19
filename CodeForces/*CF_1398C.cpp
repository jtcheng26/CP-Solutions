#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 100000007

typedef long long ll;

using namespace std;

int n;
int arr[100001];
string s;

ll solve() {
  ll res = 0;
  map<ll, ll> cnt;
  cnt[0] = 1;
  for (ll i=1;i<=n;i++) {
    //if (s[i-1] - '0' == 1) res++;
    cnt[arr[i] - i]++;
  }
  for (auto k : cnt) {
    //cout << k.first << " " << k.second << endl;
    if (k.second > 1) res += (k.second * (k.second - 1)) / 2;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    arr[0] = 0;
    arr[1] = s[0] - '0';
    for (int i=2;i<=n;i++) {
      //cout << arr[n-i] << endl;
      arr[i] = arr[i-1] + (s[i-1] - '0');
    }
    cout << solve() << endl;
  }
  return 0;
}
