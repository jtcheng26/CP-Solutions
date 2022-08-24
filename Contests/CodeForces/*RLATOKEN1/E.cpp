#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, k;

void solve() {
  vector<int> all;
  for (int i=0;i<k-1;i++) {
    all.pb(i+1);
  }
  int ans = 0;
  int r;
  for (int i=0;i<n;i+=k) {
    if (i + k <= n) {
      cout << "? ";
      for (int j=1;j<=k;j++) {
        cout << (i + j) << " ";
      }
      cout << endl;
      cin >> r;
      ans ^= r;
    }
  }
  cout << "? ";
  for (int j=1;j<=k - (n%k)/2;j++)
    cout << j << " ";
  for (int j=0;j<(n%k)/2;j++) {
    cout << (j + n - n % k + 1)  << " ";
  }
  cout << endl;
  cin >> r;
  ans ^= r;
  cout << "? ";
  for (int j=1;j<=k - (n%k)/2;j++)
    cout << j << " ";
  for (int j=0;j<(n%k)/2;j++) {
    cout << (n - j)  << " ";
  }
  cout << endl;
  cin >> r;
  ans ^= r;
  cout << "! " << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  if ((n % k) % 2 == 1) {
    cout << "-1" << endl;
  } else {
    solve();
  }
  return 0;
}