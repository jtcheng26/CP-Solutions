#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 100000007

typedef long long ll;

using namespace std;

int n;
int a[200001];

int solve() {
  int res = 1;
  int i;
  for (i=0;i<n-1;i++) {
    if (a[i] != a[i+1]) break;
  }
  if (i == n-1) return n;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    cout << solve() << endl;
  }
  return 0;
}
