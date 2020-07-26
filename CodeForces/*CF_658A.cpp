#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int t, n, m;

vector<int> narr;
vector<int> marr;
int res = 0;

void solve() {
  res = 0;
  for (int i=1;i<=1000;i++) {
    if (find(narr.begin(), narr.end(), i)!=narr.end() && find(marr.begin(), marr.end(), i)!=marr.end()) {
      res = i;
      break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> t;
  for (int i=0;i<t;i++) {
    narr.clear(); marr.clear();
    cin >> n >> m; int x;
    for (int j=0;j<n;j++) {
      cin >> x;
      narr.push_back(x);
    }
    for (int j=0;j<m;j++) {

      cin >> x;
      marr.push_back(x);
    }
    solve();
    if (res > 0) {
      cout << "YES" << endl;
      cout << "1" << " ";
      cout << res << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
