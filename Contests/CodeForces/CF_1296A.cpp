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
int a[2001];

bool solve() {
  int res = 0;
  bool ok[2] = {false};
  for (int i=0;i<n;i++) ok[a[i] % 2] = true;
  return (ok[0] && ok[1]) || (ok[1] && n % 2);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}
