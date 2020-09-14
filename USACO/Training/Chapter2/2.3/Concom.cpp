/*
   LANG: C++14
   PROG: concom
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

int n, c;
vector<vector<int> > com;
vector<vector<int> > pct;
vector<pair<int, int> > res;
int own_pct[102][102];

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}

int dfs(int company, int* own_pcts) {
  //cout << company << endl;
  for (int k=0;k<com[company].size();k++) {
    //cout << "wrong" << endl;
    if (com[company][k] != company && own_pcts[com[company][k]] <= 50) {
      own_pcts[com[company][k]] += pct[company][k];
      if (own_pcts[com[company][k]] > 50) {
        dfs(com[company][k], own_pcts);
      }
    }
  }
  return 0;
}

int solve() {
  for (int i=1;i<=n;i++) {
    int own_pcts[n+1];
    for (int j=0;j<=n;j++) {
      own_pcts[j] = 0;
    }
    dfs(i, own_pcts);
    for (int j=1;j<=n;j++) {
      //cout << j << " " << own_pcts[j] << endl;
      if (own_pcts[j] > 50 && j != i) {
        //cout << i << " " << j << " " << own_pcts[j] << endl;
        pair<int, int> r(i, j);
        res.push_back(r);
      }
    }
  }
  return 0;
}

int main() {
  ofstream fout ("concom.out");
  ifstream fin ("concom.in");
  int i, j, p;
  n = 1;
  fin >> c;
  com.resize(101);
  pct.resize(101);
  for (int a=1;a<=100;a++) {
    vector<int> controls; vector<int> pcts;
    com[a] = controls;
    pct[a] = pcts;
  }
  for (int a=0;a<c;a++) {
    fin >> i >> j >> p;
    if (i > n) n = i;
    if (j > n) n = j;
    com[i].push_back(j);
    pct[i].push_back(p);
  }
  solve();
  sort(res.begin(), res.end(), cmp);
  for (int i=0;i<res.size();i++) {
    fout << res[i].first << " " << res[i].second << endl;
  }
  return 0;
}
