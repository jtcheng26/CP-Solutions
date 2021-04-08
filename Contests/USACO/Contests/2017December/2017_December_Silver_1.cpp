#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int a[100001];

vector<int> solve() {
  vector<int> res;
  int sum[n];
  int mn[n];
  sum[n-1] = a[n-1];
  mn[n-1] = a[n-1];
  for (int i=n-2;i>=1;i--) {
    sum[i] = sum[i+1] + a[i];
    mn[i] = min(a[i], mn[i+1]);
  }
  double avg[n];
  double mx = 0;
  for (int i=1;i<n-1;i++) {
    avg[i] = (sum[i] - mn[i]) / ((double)(n - i - 1));
    mx = max(mx, avg[i]);
  }
  for (int i=1;i<n-1;i++) {
    if (fabs(avg[i] - mx) < std::numeric_limits<double>::epsilon()) {
      res.pb(i);
    }
  }
  return res;
}

int main() {
  ofstream cout ("homework.out");
  ifstream cin ("homework.in");
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  vector<int> ans = solve();
  sort(ans.begin(), ans.end());
  for (int i=0;i<ans.size();i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
