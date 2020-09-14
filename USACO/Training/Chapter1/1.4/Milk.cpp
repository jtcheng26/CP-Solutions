/*
   LANG: C++14
   PROG: milk
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
bool cmp(pair<int, ll> first, pair<int, ll> second) {
  return(first.first < second.first);
}

int solve(vector<pair<int ,ll> > pa) {
  int res = 0;
  sort(pa.begin(), pa.end(), cmp);
  for (int i=0;i<pa.size();i++) {
    for (int j=0;j<pa[i].second&&n>0;j++) {
      res += (pa[i].first);
      n--;
    }
  }
  return res;
}


int main() {
  int m;
  ofstream fout ("milk.out");
  ifstream fin ("milk.in");
  fin >> n >> m;
  vector<pair<int, ll> > pa;
  for (int i=0;i<m;i++) {
    int p; ll a;
    fin >> p >> a;
    pa.push_back(pair<int, ll>(p, a));
  }
  fout << solve(pa) << endl;
  return 0;
}
