#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

string s; map<string, int> cnt;

bool is_cyclic(string a) {
  //cout << a << endl;
  string b = a.substr(1) + a.substr(0, 1);
  string c = a.substr(a.length()-1, 1) + a.substr(0, a.length()-1);
  //cout << b << " " << c << endl;
  return b == c;
}

int sch_str(string sch) {
  int res = 0; int curr = 0;
  for (int i=0;i<s.length();i++) {
    if (s.substr(i, 1) == sch.substr(curr, 1)) {
      if (curr == 1)
        res += 2;
      curr = curr == 0 ? 1 : 0;
    }
  }
  //cout << sch << " " << res << endl;
  return res;
}

int sch_one(string sch) {
  int res = 0;
  for (int i=0;i<s.length();i++) {
    if (s.substr(i, 1) == sch)
      res++;
  }
  //cout << sch << " " << res << endl;
  return res;
}

int solve() {
  if (is_cyclic(s)) return 0;
  int mx = 0;
  string sch = "";
  for (int i=0;i<=9;i++) {
    sch = to_string(i);
    mx = max(mx, sch_one(sch));
    for (int j=0;j<=9;j++) {
      if (j == i) continue;
      sch = to_string(i) + to_string(j);
      mx = max(mx, sch_str(sch));
    }
  }
  //cout << mx << endl;
  return s.length() - mx;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  for (int i=0;i<t;i++) {
    cnt.clear();
    cin >> s;
    cout << solve() << endl;
  }
  return 0;
}
