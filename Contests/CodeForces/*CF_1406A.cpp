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
int a[101];

int solve() {
  int res = 0;
  sort(a, a+n);
  int curr[2] = {0};
  int cnt[101] = {0};
  for (int i=0;i<n;i++) {
    if (a[i] == curr[0] && cnt[a[i]] == 0) {
      curr[0]++;
      cnt[a[i]]++;
    }
    else if (a[i] == curr[1] && cnt[a[i]] == 1) {
      curr[1]++;
      cnt[a[i]]++;
    }
    //cout << curr[0] << " " << curr[1] << endl;
  }
  return curr[0] + curr[1];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << solve() << endl;
  }
  return 0;
}
