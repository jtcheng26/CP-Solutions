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

int n, m;
int a[100001];

ll solve() {
  ll res = 0;
  int curr = 1;
  for (int i=0;i<m;i++) {
    if (a[i] - curr < 0)
      res += n - curr + a[i];
    else
      res += a[i] - curr;
    curr = a[i];
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i=0;i<m;i++) cin >> a[i];
  cout << solve() << "\n";
  return 0;
}
