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
int res[101];

void solve() {
  for (int i=0;i<n;i++) {
    res[i] = i+1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    solve();
    for (int i=0;i<n-1;i++) {
      cout << res[i] << " ";
    }
    cout << res[n-1] << endl;
  }
  return 0;
}
