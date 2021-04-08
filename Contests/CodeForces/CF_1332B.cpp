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

int n;
int a[1001];
int ans[1001];
int m;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

vector<int> primeFactors(int n) {
  vector<int> nums;
  if (n % 2 == 0) nums.pb(2);
  while (n % 2 == 0) {
    n = n/2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    if (n % i == 0) nums.pb(i);
    while (n % i == 0) {
      n = n/i;
    }
  }
  if (n > 2) nums.pb(n);
  return nums;
}

int solve() {
  int res = 0;
  m = 1;
  vector<int> factors[n];
  for (int i=0;i<n;i++) {
    factors[i] = primeFactors(a[i]);
  }
  int unique[1001] = {0};
  int factor[n][1001];
  for (int i=0;i<n;i++)
  for (int j=0;j<1000;j++)
    factor[i][j] = false;
  int used[n];
  for (int i=0;i<n;i++) {
    used[i] = false;
    for (int j=0;j<factors[i].size();j++) {
      unique[factors[i][j]]++;
      factor[i][factors[i][j]] = true;
    }
  }
  for (int i=2;i<1000;i++) {
    if (unique[i] == 0) continue;
    //cout << i << endl;
    bool flag = false;
    for (int j=0;j<n;j++) {
      if (used[j]) continue;
      if (factor[j][i]) {
        flag = true;
        used[j] = true;
        ans[j] = m;
      }
    }
    if (flag) m++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    solve();
    cout << m - 1 << endl;
    for (int i=0;i<n;i++) cout << ans[i] << (i == n-1 ? "\n" : " ");
  }
  return 0;
}
