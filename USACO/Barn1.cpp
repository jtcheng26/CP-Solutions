/*
   LANG: C++14
   PROG: barn1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int m;

int solve(vector<int> gaps) {
  if (m > gaps.size())
    return 0;
  sort(gaps.begin(), gaps.end());
  int res = 0;
  for (int i=0;i<gaps.size()-(m-1);i++)
    res += gaps[i];
  return res;
}

int main() {
  ofstream fout ("barn1.out");
  ifstream fin ("barn1.in");
  int s, c;
  vector<int> stalls, gaps;
  fin >> m >> s >> c;
  for (int i=0;i<c;i++) {
    int stall;
    fin >> stall;
    stalls.push_back(stall);
  }
  sort(stalls.begin(), stalls.end());
  int prev = stalls[0];
  for (int i=1;i<c;i++) {
    int curr = stalls[i];
    gaps.push_back(curr - prev - 1);
    prev = curr;
  }
  fout << solve(gaps) + c << endl;
  return 0;
}
