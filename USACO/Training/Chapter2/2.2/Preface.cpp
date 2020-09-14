/*
   LANG: C++14
   PROG: preface
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

int n;
string conv[3501] = {""};
map<string, int> res;

void compute() {
  conv[1] = "I"; res["I"] = 0;
  conv[5] = "V"; res["V"] = 0;
  conv[10] = "X"; res["X"] = 0;
  conv[50] = "L"; res["L"] = 0;
  conv[100] = "C"; res["C"] = 0;
  conv[500] = "D"; res["D"] = 0;
  conv[1000] = "M"; res["M"] = 0;
  conv[4] = "IV"; conv[9] = "IX";
  conv[40] = "XL"; conv[90] = "XC";
  conv[400] = "CD"; conv[900] = "CM";
}

void count_letters(string ans) {
  res["I"] += count(ans.begin(), ans.end(), 'I');
  res["V"] += count(ans.begin(), ans.end(), 'V');
  res["X"] += count(ans.begin(), ans.end(), 'X');
  res["L"] += count(ans.begin(), ans.end(), 'L');
  res["C"] += count(ans.begin(), ans.end(), 'C');
  res["D"] += count(ans.begin(), ans.end(), 'D');
  res["M"] += count(ans.begin(), ans.end(), 'M');
}

string conv_to_rome(int num) {
  string ans = ""; int ind = 1;
  if (conv[num].length() > 0)
    return conv[num];
  for (int i=num-1;i>0;i--) {
    if (i == 1000 || i == 500 || i == 100 || i == 50 || i == 10 || i == 5 || i == 1 ||
    i == 40 || i == 90 || i == 400 || i == 900) {
      ind = i; break;
    }
  }
  ans = conv[ind] + conv[num-ind];
  conv[num] = ans;
  return ans;
}

int solve() {
  for (int i=1;i<=n;i++) {
    count_letters(conv_to_rome(i));
  }
  return 0;
}

int main() {
  ofstream fout ("preface.out");
  ifstream fin ("preface.in");
  fin >> n;//
  compute();
  solve();
  if (res["I"] > 0)
    fout << "I " << res["I"] << endl;
  if (res["V"] > 0)
    fout << "V " << res["V"] << endl;
  if (res["X"] > 0)
    fout << "X " << res["X"] << endl;
  if (res["L"] > 0)
    fout << "L " << res["L"] << endl;
  if (res["C"] > 0)
    fout << "C " << res["C"] << endl;
  if (res["D"] > 0)
    fout << "D " << res["D"] << endl;
  if (res["M"] > 0)
    fout << "M " << res["M"] << endl;
  return 0;
}
