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
// 6 2 1 4 3 5
int n;
int a[100001];
int ans[100001];

int solve() {
  if (n <= 2) {
    for (int i=0;i<n;i++)
      ans[i] = a[i];
    return 0;
  }
  int res = 0;
  int small = 0;
  sort(a, a+n);
  ans[0] = a[n-2];
  ans[n-1] = a[n-1];
  int curr = n - 3;
  int idx = n - 3;
  while (idx > 0) {
    ans[idx] = a[curr];
    curr--;
    idx -= 2;
  }
  idx = n - 2;
  while (curr >= 0) {
    ans[idx] = a[curr];
    curr--;
    idx -= 2;
  }
  for (int i=1;i<n-1;i++)
    if (ans[i] < ans[i-1] && ans[i] < ans[i+1]) res++;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << "\n";
  for (int i=0;i<n;i++) cout << ans[i] << (i == n-1 ? "\n" : " ");
  return 0;
}
