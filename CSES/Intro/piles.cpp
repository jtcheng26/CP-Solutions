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

int a, b;

int solve() {
  if ((a + b) % 3 != 0) return false;
  return min(a, b) * 2 >= max(a, b);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    cout << (solve() ? "YES" : "NO") << "\n";
  }
  return 0;
}
