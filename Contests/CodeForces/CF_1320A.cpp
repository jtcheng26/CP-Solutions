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
int a[200001];
int b[200001];
map<int, ll> cnt;

ll solve() {
  ll res = 0;
  for (int i=0;i<n;i++) {
    b[i] = a[i];
    a[i] -= i;
  }
  for (int i=0;i<n;i++) {
    cnt[a[i]] += b[i];
    res = max(cnt[a[i]], res);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << endl;
  return 0;
}
