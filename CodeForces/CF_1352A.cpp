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
vector<int> nums;

int solve() {
  int res = 0;
  int i = 0;
  while (n > 0) {
    int num = n % 10;
    if (pow(10, i) * num > 0)
      nums.pb(num * pow(10, i));
    n /= 10;
    i++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    nums.clear();
    solve();
    cout << nums.size() << "\n";
    for (int i=0;i<nums.size();i++) {
      cout << nums[i] << (i == nums.size()-1 ? "\n" : " ");
    }
  }
  return 0;
}
