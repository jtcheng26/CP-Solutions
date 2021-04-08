#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int n; string s;

int solve() {
  int res = 0;
  string search_str;
  vector<string> prev_strs;
  for (int i=1;i<n;i++) {
    int j;
    for (j=0;j<=n-i;j++) {
      search_str = s.substr(j, i);
      int m;
      for (m=0;m<prev_strs.size();m++) {
        if (prev_strs[m] == search_str) break;
      }
      if (m == prev_strs.size()) {
        prev_strs.push_back(search_str);
      } else {
        break;
      }
    }
    if (j == n-i+1) return i;
  }
  return res > 0 ? res : n;
}

int main() {
  ifstream fin ("whereami.in");
  ofstream fout ("whereami.out");
  fin >> n;
  fin >> s;
  fout << solve() << endl;
  return 0;
}
