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
  sort(a, a+n);
  int res = 0;
  int idx = 0;
  for (int i=1;i<n;i+=2)
    ans[i] = a[idx++];
  for (int i=0;i<n;i+=2)
    ans[i] = a[idx++];
  for (int i=1;i<n-1;i++)
    res += ans[i] < ans[i-1] && ans[i] < ans[i+1];
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
