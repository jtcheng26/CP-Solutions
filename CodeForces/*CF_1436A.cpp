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
int a[101];

bool solve() {
  int sum = 0;
  for (int i=0;i<n;i++) {
    sum += a[i];
  }
  return sum == m;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}
