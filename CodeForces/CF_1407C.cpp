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
int a[10001];

int solve() {
  int prev = 0; // last unfound index
  int curr = 0; // current test
  int fnd = 0;
  while (fnd < n-1) {
    int m1, m2;
    curr++;
    cout << "? " << prev+1 << " " << curr+1 << endl;
    cin >> m1;
    cout << "? " << curr+1 << " " << prev+1 << endl;
    cin >> m2;
    if (m1 > m2) {
      a[prev] = m1;
      prev = curr;
    } else {
      a[curr] = m2;
    }
    fnd++;
  }
  bool used[10001] = {false};
  int missing = 0;
  for (int i=0;i<n;i++) {
    used[a[i]] = true;
    if (a[i] == 0) missing = i;
  }
  for (int i=1;i<=n;i++) if (!used[i]) a[missing] = i;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  solve();
  cout << "! ";
  for (int i=0;i<n;i++) cout << a[i] << (i == n-1 ? "\n" : " ");
  return 0;
}
