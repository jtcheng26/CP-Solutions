/*
   LANG: C++14
   PROG: lamps
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

ll n, c, l;

int req[101] = {0};
bool lamps[101] = {false};
vector<vector<bool> > res;

bool bin_cmp(vector<bool> a, vector<bool> b) {
  for (int i=0;i<a.size();i++) {
    if (a[i] != b[i])
      return a[i] < b[i];
  }
  return true;
}

bool is_poss() {
  for (int i=1;i<=n;i++) {
    if (req[i] == 1 && lamps[i] == false)
      return false;
    if (req[i] == -1 && lamps[i] == true)
      return false;
  }
  return true;
}

void add_ans() {
  vector<bool> ans;
  for (int i=1;i<=n;i++) {
    ans.push_back(lamps[i]);
  }
  res.push_back(ans);
}

void flip_all() {
  for (int i=1;i<=n;i++) {
    lamps[i] = !lamps[i];
  }
}

void flip_odd() {
  for (int i=1;i<=n;i+=2) {
    lamps[i] = !lamps[i];
  }
}

void flip_even() {
  for (int i=2;i<=n;i+=2) {
    lamps[i] = !lamps[i];
  }
}

void flip_other() {
  for (int i=1;i<=n;i+=3) {
    lamps[i] = !lamps[i];
  }
}

int solve() {
  flip_all();
  if (is_poss()) add_ans();
  if (c > 0) {
    flip_all();
    if (is_poss()) add_ans();
    flip_all();
    flip_odd();
    if (is_poss()) add_ans();
    flip_odd();
    flip_even();
    if (is_poss()) add_ans();
    flip_even();
    flip_other();
    if (is_poss()) add_ans();
    flip_other();
    if (c > 1) {
      flip_other();
      flip_all();
      if (is_poss()) add_ans();
      flip_all();
      flip_odd();
      if (is_poss()) add_ans();
      flip_odd();
      flip_even();
      if (is_poss()) add_ans();
    }
  }
  return 0;
}

int main() {
  ofstream fout ("lamps.out");
  ifstream fin ("lamps.in");
  fin >> n >> c;
  fin >> l;
  while (l != -1) {
    req[l] = 1;
    fin >> l;
  }
  fin >> l;
  while (l != -1) {
    req[l] = -1;
    fin >> l;
  }
  solve();
  if (res.size() == 0) {
    fout << "IMPOSSIBLE" << endl;
  } else {
    sort(res.begin(), res.end(), bin_cmp);
    for (int i=0;i<res.size();i++) {
      for (int j=0;j<res[i].size()-1;j++) {
        fout << res[i][j];
      }
      fout << res[i][res[i].size()-1] << endl;
    }
  }
  return 0;
}
