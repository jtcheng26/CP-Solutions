/*
   LANG: C++14
   PROG: ariprog
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

int n, m, diff, root;
vector<pair<int, int> > res;
vector<int> bsqrs;
bool bsqr[125001] = {false};

vector<int> make_bsqrs() {
  vector<int> bsqrs;
  for (int i=0;i<=m;i++) {
    for (int j=0;j<=m;j++) {
      int sqr = i*i + j*j;
      if (!bsqr[sqr]) {
        bsqrs.push_back(sqr);
        bsqr[sqr] = true;
      }
    }
  }
  return bsqrs;
}

void add_res() {
  pair<int, int> pres;
  pres.first = root; pres.second = diff;
  res.push_back(pres);
}

bool sort_res(pair<int, int> a, pair<int, int> b) {
  if (a.second != b.second)
    return a.second < b.second;
  else
    return a.first < b.first;
}

void solve() {
  bsqrs = make_bsqrs();
  sort(bsqrs.begin(), bsqrs.end());
  for (int i=0;i<bsqrs.size();i++) {
    root = bsqrs[i];
    for (int j=i+1;j<bsqrs.size();j++) {
      diff = bsqrs[j] - bsqrs[i]; int k;
      for (k=1;k<n-1;k++) {
        int dex = bsqrs[j] + (k * diff);
        if (dex > 125000 || !bsqr[dex])
          break;
      }
      if (k==n-1)
        add_res();
    }
  }
}

int main() {
  ofstream fout ("ariprog.out");
  ifstream fin ("ariprog.in");
  fin >> n >> m;
  solve();
  sort(res.begin(), res.end(), sort_res);
  if (res.size() == 0)
    fout << "NONE" << endl;
  else {
    for (int i=0;i<res.size();i++) {
      fout << res[i].first << " " << res[i].second << endl;
    }
  }
  return 0;
}
