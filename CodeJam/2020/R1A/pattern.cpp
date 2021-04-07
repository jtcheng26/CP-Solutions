#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
string a[51];

string solve() {
  string pfx = "";
  string sfx = "";
  for (int i=0;i<n;i++) {
    int j = 0;
    while (a[i][j] != '*') {
      if (j + 1 > pfx.length()) {
        pfx += a[i][j];
      } else if (pfx[j] != a[i][j]) {
        return "*";
      }
      j++;
    }
    j = a[i].length() - 1;
    while (a[i][j] != '*') {
      if (a[i].length() - j > sfx.length()) {
        sfx += a[i][j];
      } else if (sfx[a[i].length() - j - 1] != a[i][j]) {
        return "*";
      }
      j--;
    }
  }
  for (int i=0;i<n;i++) {
    int o = 0;
    string s = "";
    for (int j=0;j<a[i].length();j++) {
      if (a[i][j] == '*') {
        if (o == 1) {
          pfx += s;
          s = "";
        } else {
          o = 1;
        }
      } else if (o == 1) {
        s += a[i][j];
      }
    }
  }
  for (int i=sfx.length()-1;i>=0;i--) {
    pfx += sfx[i];
  }
  return pfx;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  for (int c=1;c<=t;c++) {
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    cout << "Case #" << c << ": " << solve() << "\n";
  }
  return 0;
}