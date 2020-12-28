#include <iostream>

typedef long long ll;

using namespace std;

ll n;

bool valid(ll k) {
  ll a = k;
  while (a > 0) {
    int digit = a % 10;
    a /= 10;
    if (digit > 0 && k % digit != 0) return false;
  }
  return true;
}

ll solve() {
  ll res = n;
  while (!valid(res)) res++;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << solve() << "\n";
  }
  return 0;
}
