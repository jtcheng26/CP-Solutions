
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll n, k;
string s[100];
vector<string> lines;

int solve() {
  string str = ""; int lsize = 0;
  for (int i=0;i<n;i++) {
    lsize += s[i].length();
    if (str == "") str = s[i];
    else if (lsize > k) {
      lsize = s[i].length();
      lines.push_back(str);
      str = s[i];
    } else {
      str += " " + s[i];
    }
  }
  lines.push_back(str);
  return 0;
}

int main() {
  ofstream fout ("word.out");
  ifstream fin ("word.in");
  fin >> n >> k;
  for (int i=0;i<n;i++) {
    fin >> s[i];
  }
  solve();
  for (int i=0;i<lines.size();i++) {
    fout << lines[i] << endl;
  }
  return 0;
}
