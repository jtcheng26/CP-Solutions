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

ll n;
// 1, 3, 7,
// 1
// 3
// 3, 6
// 7, 10
// 7, 6, 9, 12, 15
ll solve() {
  ll res = 0;
  ll curr = 1;
  ll sum = 1;
  ll add = 2;
  while (sum <= n) {
    res++;
    curr += add;
    sum += (curr * (curr + 1)) / 2;
    add *= 2;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << solve() << endl;
  }
  return 0;
}
