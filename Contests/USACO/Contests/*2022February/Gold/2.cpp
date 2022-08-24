#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int t, k;

int choose(int n, int k) {
  if (k == 0)
    return 1;
  return (n * choose(n - 1, k - 1)) / k;
}

double binom(int n, int k) { return choose(n, k) * pow(0.5, n); }

double solve() {
  double res = 0;
  for (int i = (t - 1) / 2; i <= t - 1; i++) {
    double prob = (double)binom(t - 1, i);
    double val = 0;
    cout << prob << "\n";
    for (int j = 1; j <= k; j++) {
      val += i * prob * pow(1 - prob, j - 1);
    }
    res += val;
  }
  return res + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t >> k;
  cout << solve() << "\n";
  return 0;
}
