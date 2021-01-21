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
#define MOD 1e9+7

typedef long long ll;

using namespace std;

int n;
int x[51];

int solve() {
  int res = 0;
  int a[51] = {0};
  for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      if (a[x[j]-x[i]] == 0) {
        a[x[j]-x[i]] = 1;
        res++;
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> x[i];
    cout << solve() << "\n";
  }
  return 0;
}
