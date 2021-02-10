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

int h, n;
int a[200002];

int solve() {
  int curr = 0;
  int res = 0;
  while (curr < n - 1) {
    if (a[curr+2] == a[curr+1] - 1) {
      curr += 2;
    } else {
      curr++;
      res++;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> h >> n;
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    a[n] = 0;
    cout << solve() << "\n";
  }
  return 0;
}
