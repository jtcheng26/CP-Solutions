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
int a[200005];
int oneRep[400005]; // number of pairs that can be set to i in 1 replacement
int zCnt[400005]; // existing sum count

int cost(int sum) {
  //cout << "sum " << sum << "\n";
  //cout << oneRep[sum] << "\n";
  //cout << zCnt[sum] << "\n";
  return oneRep[sum] - zCnt[sum] + 2 * (n / 2 - oneRep[sum]);
}

int solve() {
  int res = n / 2;
  map<int, int> cnt;
  for (int i=0;i<=2*k;i++) {
    oneRep[i] = zCnt[i] = 0;
  }
  for (int i=0;i<n/2;i++) {
    cnt[a[i]]++;
    zCnt[a[i]+a[n-1-i]]++;
    oneRep[min(a[i], a[n-1-i]) + 1]++;
    oneRep[max(a[i], a[n-1-i]) + k + 1]--;
  }
  for (int i=3;i<=2*k;i++) {
    oneRep[i] += oneRep[i-1];
    //cout << oneRep[i] << (i == 2*k ? "\n" : " ");
  }
  for (int i=0;i<n/2;i++) {
    res = min(res, cost(a[i] + a[n-1-i]));
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << solve() << "\n";
  }
  return 0;
}
