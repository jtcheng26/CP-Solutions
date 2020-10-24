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

string s;

string solve() {
  vector<int> nums;
  for (int i=0;i<s.length();i++) {
    if (s[i] - '0' >= 1 && s[i] - '0' <= 3) {
      nums.pb(s[i] - '0');
    }
  }
  sort(nums.begin(), nums.end());
  int cnt = 0;
  for (int i=0;i<s.length();i++) {
    if (s[i] != '+') {
      s[i] = (char) (nums[cnt] + '0');
      cnt++;
    }
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> s;
  cout << solve() << "\n";
  return 0;
}
