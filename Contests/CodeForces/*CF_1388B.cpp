#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll t, n;

string solve() {
  string res = "";
  for (int i=0;i<n;i++) {
    res += "9";
  }
  if (n == 1)
    return "8";
  else {
    string eights = "";
    if (n % 4 == 0) {
      for (int i=0;i<n / 4;i++) {
        eights += "8";
      }
    } else {
      for (int i=0;i<(n/4) + 1;i++) {
        eights += "8";
      }
    }
    res = res.substr(0, n-eights.length()) + eights;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> t;
  for (int i=0;i<t;i++) {
    cin >> n;
    cout << solve() << endl;
  }
  return 0;
}
