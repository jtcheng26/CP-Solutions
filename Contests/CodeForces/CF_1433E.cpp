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

ll factorial(int num) {
  ll res = 1;
  for (int i=2;i<=num;i++) {
    res *= i;
  }
  return res;
}

ll solve() {
  ll res = 1;
  for (int i=0;i<n/2-1;i++) {
    res *= n - 1 - i;
  }
  res *= factorial(n / 2 - 1);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  cout << solve() << "\n";
  return 0;
}
