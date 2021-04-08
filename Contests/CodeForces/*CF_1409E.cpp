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

int n, k;
int x[200001];

int solve() {
  if (n == 1) return 1;
  sort(x, x+n);
  int res = 0;
  int l[n]; int r[n]; // points within k distance to left/right
  l[0] = 1; r[n-1] = 1;
  int left = 0;
  int right = 0;
  for (right=0;right<n;right++) {
    while (x[right] - x[left] > k) left++;
    l[right] = right - left + 1;
  }
  right = n-1;
  for (left=n-1;left>=0;left--) {
    while (x[right] - x[left] > k) right--;
    r[left] = right - left + 1;
  }
  for (int i=1;i<n;i++) {
    l[i] = max(l[i-1], l[i]);
  }
  for (int i=n-2;i>=0;i--) {
    r[i] = max(r[i+1], r[i]);
  }
  for (int i=0;i<n-1;i++) {
    res = max(res, l[i] + r[i+1]);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int y;
    for (int i=0;i<n;i++) {
      cin >> x[i];
    }
    for (int i=0;i<n;i++) cin >> y;
    cout << solve() << endl;
  }
  return 0;
}
