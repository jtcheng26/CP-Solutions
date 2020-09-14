/*
   LANG: C++14
   PROG: palsquare
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

ll n;

string conv[10] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};

bool isPalindrome(string num) {
  for (int i=0;i<num.size()/2;i++) {
    if (!(num[i] == num[num.size()-i-1]))
      return false;
  }
  return true;
}

string base_convert(ll num, ll nbase) {
  if (nbase == 10 || num == 0)
    return to_string(num);
  int temp = num;
  string res = "";
  for (int i=0;temp>0;i++) {
    int digit = temp % nbase;
    temp /= nbase;
    if (digit >= 10) {
      string dig = conv[digit - 10];
      res = dig + res;
    } else {
      res = to_string(digit) + res;
    }
  }
  return res;
}

vector<pair<string, string> > solve() {
  vector<pair<string, string> > res;
  for (int i=1;i<=300;i++) {
    string num = base_convert(i*i, n);
    if (isPalindrome(num))
      res.push_back(pair<string, string> (base_convert(i, n), num));
  }
  return res;
}

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    fin >> n;
    vector<pair<string, string> > res = solve();
    for (int i=0;i<res.size();i++) {
      fout << res[i].first << " " << res[i].second << endl;
    }
    return 0;
}
