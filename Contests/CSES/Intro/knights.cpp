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
#define MOD 1e9+7

typedef long long ll;

using namespace std;

int n;
ll mult[100001];

ll solve(ll k) {
  ll res = (k * k) * (k * k - 1) / 2;
  if (k < 3) return res;
  return res - 8 * mult[k];
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  ll curr = 1;
  mult[1] = mult[2] = 0;
  for (int i=3;i<=n;i++) {
    mult[i] = mult[i-1] + curr++;
  }
  for (int i=1;i<=n;i++) {
    cout << solve(i) << "\n";
  }
  return 0;
}
