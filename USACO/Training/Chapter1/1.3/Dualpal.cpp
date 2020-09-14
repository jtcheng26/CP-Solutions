/*
   LANG: C++14
   PROG: dualpal
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

int n, s;

bool isPalindrome(ll num) {
  string temp = to_string(num);
  for (int i=0;i<temp.size()/2;i++) {
    if (!(temp[i] == temp[temp.size()-i-1]))
      return false;
  }
  return true;
}

ll base_convert(int num, int nbase) {
  if (nbase == 10 || num == 0)
    return num;
  ll temp = num;
  ll res = 0;
  for (int i=0;temp>0;i++) {
    int digit = temp % nbase;
    temp /= nbase;
    res += (digit * (pow(10, i)));
  }
  return res;
}

vector<int> solve() {
  vector<int> res;
  int count = 0;
  for (int i=s+1;count<n;i++) {
    int bases = 0;
    for (int j=2;j<=10;j++) {
      ll num = base_convert(i, j);
      if (isPalindrome(num)) {
        bases++;
        if (bases >= 2) {
          res.push_back(i);
          count++;
          break;
        }
      }
    }
  }
  return res;
}

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    fin >> n >> s;
    vector<int> res = solve();
    for (int i=0;i<res.size();i++) {
      fout << res[i] << endl;
    }
    return 0;
}
