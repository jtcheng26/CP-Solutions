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

int rec(vector<int> nums, int bit) {
  if (bit == -1) {
    return nums.size();
  }
  vector<int> s[2];
  for (int i : nums) {
    s[(a[i]>>bit)&1].pb(i);
  }
  if (!s[0].empty() && !s[1].empty()) {
    int s0 = rec(s[0], bit-1);
    int s1 = rec(s[1], bit-1);
    return 1 + max(s0, s1);
  } else {
    return rec(nums, bit-1);
  }
}

int solve() {
  vector<int> nums;
  for (int i=0;i<n;i++) {
    nums.pb(i);
  }
  return n - rec(nums, 31);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << "\n";
  return 0;
}
