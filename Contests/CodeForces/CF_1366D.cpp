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
int a[500001];
int minPrime[10000001];
int ans[2][500001];

void precompute() { // precompute all primes/powers of primes
  int limit = 10000000;
  minPrime[0] = minPrime[1] = 1;
  for (int i=2;i*i<=limit;i++) {
    if (minPrime[i] == 0) {
      minPrime[i] = i;
      for (int j=i*i;j<=limit;j+=i) {
        if (minPrime[j] == 0) minPrime[j] = i;
        else minPrime[j] = min(minPrime[j], i);
      }
    }
  }
}

vector<int> primeFactors(int n) {
  vector<int> nums;
  int curr = n;
  while (curr != 1) {
    if (minPrime[curr] == 0) minPrime[curr] = curr;
    if (nums.empty() || nums[nums.size()-1] != minPrime[curr])
      nums.pb(minPrime[curr]);
    curr /= minPrime[curr];
  }
  return nums;
}

int solve() {
  int res = 0;
  precompute();
  for (int i=0;i<n;i++) {
    vector<int> factors = primeFactors(a[i]);
    if (factors.size() <= 1) {
      ans[0][i] = ans[1][i] = -1;
      continue;
    }
    ans[0][i] = factors[0];
    ans[1][i] = factors[1];
    for (int j=2;j<factors.size();j++) ans[1][i] *= factors[j];
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  solve();
  for (int j=0;j<2;j++) {
    for (int i=0;i<n;i++)
      cout << ans[j][i] << (i == n-1 ? "\n" : " ");
  }
  return 0;
}
