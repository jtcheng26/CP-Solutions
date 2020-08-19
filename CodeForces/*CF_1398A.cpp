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
int arr[50001];

int solve() {
  int res = 0;
  ll s = arr[0] + arr[1];
  if (arr[n-1] < s) {
    cout << "-1" << endl;
    return 0;
  } else {
    cout << 1 << " " << 2 << " " << n << endl;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++)
      cin >> arr[i];
    solve();
  }
  return 0;
}
