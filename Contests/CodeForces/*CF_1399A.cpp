#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll n;
int arr[51];

bool solve() {
  if (n == 1) return true;
  sort(arr, arr+n);
  for (int i=1;i<n;i++) {
    if (arr[i] - arr[i-1] > 1)
      return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> arr[i];
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}
