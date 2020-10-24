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
int ans[3];

bool solve() {
  if (n == 4 || n < 3) return false;
  ans[0] = n / 3;
  ans[1] = 0;
  ans[2] = 0;
  if (n % 3 == 1) {
    ans[0] -= 2;
    ans[2] = 1;
  } else if (n % 3 == 2) {
    ans[0] -= 1;
    ans[1] = 1;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    if (solve())
      cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
    else
      cout << "-1\n";
  }
  return 0;
}
