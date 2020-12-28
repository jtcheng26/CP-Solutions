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
pair<int, double> experiments[100001];

double solve() {
  double res = 0;
  int j;
  for (j=n-1;j>=0;j--) {
    if (a[j] != j + 1) break;
  }
  double bad = 1;
  sort(experiments, experiments + m);
  if (j == -1) return 1;
  for (int i=0;i<m;i++) {
    if (experiments[i].F < j + 1) continue;
    res += bad * experiments[i].S;
    bad *= (1 - experiments[i].S);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<m;i++) cin >> experiments[i].F >> experiments[i].S;
    cout << solve() << "\n";
  }
  return 0;
}
