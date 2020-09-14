/*
   LANG: C++14
   PROG: holstein
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

int v, g, m;
int req[25];
int feed[15][25];
bool chosen[15] = {false};
vector<int> res;

bool try_solution() {
  vector<int> attempt;
  for (int i=0;i<g;i++) {
    if (chosen[i])
      attempt.push_back(i);
  }
  for (int i=0;i<v;i++) {
    int r = req[i];
    for (int j=0;j<attempt.size();j++) {
      r -= feed[attempt[j]][i];
    }
    if (r > 0)
      return false;
  }
  if (res.size() == 0 || attempt.size() <= res.size()) {
    if (attempt.size() == res.size()) {
      int atsize = 0; int solsize = 0;
      for (int i=0;i<attempt.size();i++) {
        atsize += attempt[i]; solsize += res[i];
      }
      if (solsize < atsize)
        return false;
    }
    res = attempt;
    return true;
  }
  return false;
}

void solve(int curr) {
  if (curr == g) {
    try_solution();
  }
  else {
    for (int i=0;i<2;i++) {
      chosen[curr] = i;
      solve(curr+1);
    }
  }
}

int main() {
  ofstream fout ("holstein.out");
  ifstream fin ("holstein.in");
  fin >> v; int t;//
  for (int i=0;i<v;i++) {
    fin >> req[i];
  }
  fin >> g;
  for (int i=0;i<g;i++) {
    for (int j=0;j<v;j++) {
      fin >> feed[i][j];
    }
  }
  solve(0);
  sort(res.begin(), res.end());
  fout << res.size();
  for (int i=0;i<res.size()-1;i++) {
    fout << " " << res[i]+1;
  }
  fout << " " << res[res.size()-1]+1 << endl;
  return 0;
}
