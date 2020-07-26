#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int t, n;

string solve(string a) {
  string res = "";
  int r = 0; int s = 0; int p = 0;
  for (int i=0;i<a.length();i++) {
    if (a.substr(i, 1) == "R")
      r++;
    else if (a.substr(i, 1) == "P")
      p++;
    else
      s++;
  }
  int m1 = max(r, p);
  int m2 = max(m1, s);
  if ((r == p && s == 0) ||(r == s && p == 0) || (s == p && r == 0) || (r == p && p == s)) {
    for (int i=0;i<n;i++) {
      string win_str;
      if (a.substr(i, 1) == "S") win_str = "R";
      else if (a.substr(i, 1) == "R") win_str = "P";
      else win_str = "S";
      res += win_str;
    }
  } else {
    string max_str;
    if (m2 == s) max_str = "R";
    else if (m2 == r) max_str = "P";
    else max_str = "S";
    for (int i=0;i<n;i++) {
      res += max_str;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> t; string a;
  for (int i=0;i<t;i++) {
    cin >> a;
    n = a.length();
    cout << solve(a) << endl;
  }
  return 0;
}
