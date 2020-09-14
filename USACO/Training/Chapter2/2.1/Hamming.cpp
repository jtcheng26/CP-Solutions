/*
   LANG: C++14
   PROG: hamming
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

int n, b, d;
int bits[8];
vector<string> res;
vector<string> options;

void add_option() {
  string s = "";
  for (int i=0;i<b;i++) {
    s += to_string(bits[i]);
  }
  //cout << s << endl;
  options.push_back(s);
}

int gen_opts(int loc) {
  if (loc == b) {
    add_option();
    return 0;
  }
  for (int i=0;i<2;i++) {
    bits[loc] = i;
    gen_opts(loc+1);
  }
  return 0;
}

bool is_dist(string a, string bs) {
  int diff = 0;
  for (int i=0;i<b;i++) {
    if (a.substr(i, 1) != bs.substr(i, 1))
      diff++;
    if (diff >= d)
      return true;
  }
  return false;
}

bool add_if_poss(string a) {
  for (int i=0;i<res.size();i++) {
    if (!is_dist(res[i], a))
      return false;
  }
  return true;
}

int solve() {
  gen_opts(0);
  res.push_back(options[0]);
  for (int i=1;i<options.size()&&res.size()<n;i++) {
    if (add_if_poss(options[i]))
      res.push_back(options[i]);
  }
  return 0;
}

int bin_to_int(string a) {
  int res = 0;
  for (int i=a.length()-1;i>=0;i--) {
    if (a.substr(i, 1) == "1")
      res += (pow(2, a.length()-i-1));
  }
  return res;
}

int main() {
  ofstream fout ("hamming.out");
  ifstream fin ("hamming.in");
  fin >> n >> b >> d;//
  solve();
  int c = 0;
  for (int i=0;i<res.size();i++) {
    c++;
    if (c % 10 == 0 || i == res.size()-1) {
      fout << bin_to_int(res[i]) << endl;//
    } else
      fout << bin_to_int(res[i]) << " ";//
  }
  return 0;
}
