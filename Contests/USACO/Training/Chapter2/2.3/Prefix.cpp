/*
   LANG: C++14
   PROG: prefix
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int n = 0; int m = 0;
string prim[200];
int dp[200001];
string s = "";
bool check_pfx(int be, int len) {
  if (be + len > s.length())
    return false;
  for (int i=0;i<n;i++) {
    if (s.substr(be, len) == prim[i]) {
      return true;
    }
  }
  return false;
}

int dfs(int be) {
  //cout << "Start " << be << endl;
  int max_pfx = 0;
  if (be >= s.size())
    return 0;
  for (int j=1;j<=m;j++) {
    if (be+j <= s.size() && check_pfx(be, j)) {
      int ans;
      if (dp[be+j] == -1) {
        dp[be+j] = dfs(be+j);
      }
      ans = j + dp[be+j];
      if (ans > dp[be]) {
        dp[be] = ans;
      }
    }
  }
  //cout << dp[be] << endl;
  return dp[be] >= 0 ? dp[be] : 0;
}

int solve() {
  return dfs(0);
}

int main() {
  ofstream fout ("prefix.out");
  ifstream fin ("prefix.in");
  for (int i=0;i<200001;i++)
    dp[i] = -1;
  fin >> s;
  for (int i=0;s!="."&&i<200;i++) {
    n++;
    if (s.length() > m)
      m = s.length();
    prim[i] = s;
    fin >> s;
  }
  s = "";
  string line;
  fin.ignore();
  while(getline(fin, line)) {
    if (line.empty())
      break;
    s += line;
  }
  //cout << s << endl;
  fout << solve() << endl;
  return 0;
}
