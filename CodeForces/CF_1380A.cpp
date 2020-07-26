#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int t, n, last, curr, nextn;

int solve() {
  int res = 0;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> t;
  for (int i=0;i<t;i++) {
    cin >> n >> last >> curr;
    bool flag = false;
    for (int j=2;j<n;j++) {
      cin >> nextn;
      if (!flag && curr > last && curr > nextn) {
        cout << "YES" << endl;
        cout << j - 1 << " " << j << " " << j + 1 << endl;
        flag = true;
      }
      last = curr;
      curr = nextn;
    }
    if (!flag)
      cout << "NO" << endl;
  }
  return 0;
}
