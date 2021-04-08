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

ll n;

int solve() {
  int res = 0;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  while (n > 1) {
    cout << n << " ";
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n * 3 + 1;
    }
  }
  cout << "1\n";
  return 0;
}
