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


string solve() {
  string res = "Y";
  ll a = 0; ll b = 0;
  for (int i=0;i<n;i++) {
    if (s.substr(i, 1) == "A")
      a++;
    else
      b++;
  }
  if (abs(a - b) > 1)
    res = "N";
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream fin ("alchemy_final.txt");
  ofstream fout ("2020Q2_final.txt");
  int t;
  fin >> t;//
  for (int i=1;i<=t;i++) {
    fin >> n;
    fin >> s;
    fout << "Case #" << i << ": " << solve() << endl;//
  }
  return 0;
}
