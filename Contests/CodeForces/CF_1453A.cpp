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

int n, m;
int e[2][101];

int solve() {
  int res = 0;
  for (int i=1;i<=100;i++) {
    if (e[0][i] && e[1][i]) res++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i=0;i<=100;i++) e[0][i] = e[1][i] = 0;
    for (int i=0;i<n;i++) {
      int g;
      cin >> g;
      e[0][g] = 1;
    }
    for (int i=0;i<m;i++) {
      int g;
      cin >> g;
      e[1][g] = 1;
    }
    cout << solve() << "\n";
  }
  return 0;
}
