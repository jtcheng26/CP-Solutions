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
string s;

string solve() {
  string res = "";
  if (n == 1) return s.substr(0, 1);
  else {
    for (int i=0;i<n;i++) {
      res += s.substr((2 * n - 1) / 2, 1);
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
    cin >> s;
    cout << solve() << endl;
  }
  return 0;
}
