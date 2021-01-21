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

int n;
ll a[21];
ll ans;
ll cnt = 0;
ll sum = 0;

void rec(int j) {
  if (j == n) return;
  cnt += a[j];
  ans = min(ans, abs(cnt - (sum - cnt)));
  rec(j + 1);
  cnt -= a[j];
  ans = min(ans, abs(cnt - (sum - cnt)));
  rec(j + 1);
}

int solve() {
  ans = INF;
  for (int i=0;i<n;i++) {
    sum += a[i];
  }
  rec(0);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << solve() << "\n";
  return 0;
}
