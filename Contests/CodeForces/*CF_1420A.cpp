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
int a[50001];

bool solve() {
  bool ok = false;
  for (int i=1;i<n;i++) {
    if (a[i] == a[i-1] || a[i] > a[i-1]) ok = true;
  }
  return ok;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++)
      cin >> a[i];
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}
