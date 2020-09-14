/*
   LANG: C++14
   PROG: namenum
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long n;

string poss[10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};

vector<string> solve(vector<int> digits, vector<string> dict) {
  vector<string> possible_names;
  for (int i=0;i<dict.size();i++) {
    if (dict[i].size() == digits.size()) {
      int j;
      for (j=0;j<digits.size();j++) {
        if (poss[digits[j]].find(dict[i].substr(j, 1)) == -1)
          break;
      }
      if (j == digits.size())
        possible_names.push_back(dict[i]);
    }
  }
  return possible_names;
}

int main() {
    ifstream dict_file;
    dict_file.open("dict.txt");
    vector<string> dict;
    for (int i=0;i<5000;i++) {
      string name;
      dict_file >> name;
      dict.push_back(name);
    }
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    fin >> n;
    vector<int> digits;
    for (int i=0;n>0;i++) {
      int dig = n % 10;
      digits.insert(digits.begin(), dig);
      n = n / 10;
    }
    vector<string> possible_names = solve(digits, dict);
    if (possible_names.size() > 0) {
      for (int i=0;i<possible_names.size();i++) {
        fout << possible_names[i] << endl;
      }
    } else {
      fout << "NONE" << endl;
    }
    return 0;
}
