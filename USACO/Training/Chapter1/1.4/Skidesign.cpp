/*
   LANG: C++14
   PROG: skidesign
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

int solve(vector<int> hills) {
  sort(hills.begin(), hills.end());
  int res = -1;
  int max = hills[hills.size()-1]; int min = hills[0];
  int diff = max - min;
  if (diff <= 17 || hills.size() < 2)
    return 0;
  int cost = 0;
  for (int i=min;i<max-17;i++) {
    int lbd = i; int ubd = i + 17;
    for (int j=0;j<hills.size();j++) {
      if (hills[j] < lbd)
        cost += (lbd - hills[j]) * (lbd - hills[j]);
      else if (hills[j] > ubd)
        cost += (hills[j] - ubd) * (hills[j] - ubd);
    }
    if (cost < res || res == -1)
      res = cost;
    cost = 0;
  }
  return res;
}

int main() {
  ofstream fout ("skidesign.out");
  ifstream fin ("skidesign.in");
  fin >> n; vector<int> hills;
  for (int i=0;i<n;i++) {
    int h; fin >> h;
    hills.push_back(h);
  }
  fout << solve(hills) << endl;
  return 0;
}
