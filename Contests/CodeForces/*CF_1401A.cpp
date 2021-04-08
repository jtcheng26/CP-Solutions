#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, k;

int solve() {
  int res = 0;
  if (k > n) return k - n;
  else if (n % 2 != k % 2) return 1;
  else return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cout << solve() << endl;
  }
  return 0;
}
