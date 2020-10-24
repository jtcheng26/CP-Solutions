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
vector<pair<int, int> > pairs;

int solve() {
  int res = 0;
  pairs.clear();
  int left = n-1;
  int right = n;
  while (left > 0) {
    pairs.pb(mp(left, right));
    if (right == left + 1) left--;
    else {
      left--;
      right--;
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
    solve();
    cout << "2\n";
    for (int i=0;i<pairs.size();i++) {
      cout << pairs[i].F << " " << pairs[i].S << "\n";
    }
  }
  return 0;
}
