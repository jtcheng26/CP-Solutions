#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int nums[102];
string res[102];

int solve() {
  for (int i=0;i<=n;i++) res[i] = "";
  res[0] = "a";
  for (int i=1;i<nums[0];i++) res[0] += "a";
  for (int i=1;i<n;i++) {
    if (nums[i-1] == 0) {
      string l = res[i-1][0] == 'a' ? "b" : "a";
      res[i] = l;
      while (res[i].length() < nums[i]) {
        res[i] += l;
      }
      continue;
    }
    res[i] = res[i-1].substr(0, nums[i-1]);
    string l = res[i-1].length() == res[i].length() || res[i-1][nums[i-1]] == 'b' ? "a" : "b";
    while (res[i].length() < nums[i]) {
      res[i] += l;
    }
  }
  res[n] = res[n-1].substr(0, nums[n-1]);
  if (nums[n-1] == 0) res[n] = res[n-1][0] == 'a' ? "b" : "a";
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> nums[i];
    solve();
    for (int i=0;i<=n;i++) cout << res[i] << endl;
  }
  return 0;
}
