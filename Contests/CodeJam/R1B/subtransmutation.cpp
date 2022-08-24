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

int n, d, b;
int a[500];

int solve() {
  int cnt = 0;
  int mx = 0;
  int res = 0;
  for (int i=1;i<=n;i++) {
    if (a[i] > 0) {
      cnt += a[i];
      mx = i;
    }
  }
  int i = 0;
  int j = 0;
  while (cnt > 1) {
    int temp = a[i];
    for (int k=0;k<min(temp, j);k++) {
      a[i]--;
      j--;
      cnt--;
      a[i+1]++;
    }
    a[i+2] += a[i] / 2;
    cnt -= a[i] / 2;
    j += a[i] % 2;
    i++;
  }
  return i - 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  for (int z=1;z<=t;z++) {
    cin >> n >> d >> b;
    for (int i=1;i<=n;i++) {
      cin >> a[i];
    }
    cout << "Case #" << z << ": " << solve() << "\n";
  }
  return 0;
}