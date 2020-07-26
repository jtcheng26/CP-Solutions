/*
   LANG: C++14
   PROG: ariprog
*/


// Notes:
/*
  Tried to dfs it since the reading before this one was literally
  about dfs/bfs but couldnt find a way to keep it under the time.
  Gained a lot better understanding of dfs in this attempt but
  I guess brute force is still the way to go here.
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
int poss[25] = {-1};

vector<int> make_bsqrs() {
  vector<int> bsqrs;
  for (int i=0;i<=m;i++) {
    for (int j=0;j<=m;j++) {
      if (find(bsqrs.begin(), bsqrs.end(), i*i+j*j)==bsqrs.end()) {
        bsqrs.push_back(i*i + j*j);
      }
    }
  }
  return bsqrs;
}

void add_res() {
  pair<int, int> pres;
  pres.first = bsqrs[poss[0]]; pres.second = diff;
  res.push_back(pres);
}

bool sort_res(pair<int, int> a, pair<int, int> b) {
  if (a.second != b.second)
    return a.second < b.second;
  else
    return a.first < b.first;
}
// dfs only continues if next item is valid.
int dfs(int seq_n) {
  if (seq_n == n) { // base case (all filled already)
    add_res();
    return 1;
  }
  int start = root+1;
  for (int i=start;i<bsqrs.size();i++) {
    if (seq_n == 0 || bsqrs[i] > bsqrs[poss[seq_n-1]]) { // if 0th item in seq or if next item is greater
      if (seq_n == 0) root = i;
      else if (seq_n == 1) diff = bsqrs[i] - bsqrs[poss[seq_n-1]]; // set diff if 1st item
      if (seq_n <= 1 || bsqrs[i] == bsqrs[poss[seq_n-1]] + diff) { // recurse if diff checks out or 0th or 1st in seq
        poss[seq_n] = i;
        dfs(seq_n+1); // find next
        poss[seq_n] = -1;
      }
    }
  }
  return 0;
}

void solve() {
  bsqrs = make_bsqrs();
  sort(bsqrs.begin(), bsqrs.end());
  dfs(0);
}

int main() {
  //ofstream fout ("ariprog.out");
  //ifstream fin ("ariprog.in");
  cin >> n >> m;//
  solve();
  sort(res.begin(), res.end(), sort_res);
  if (res.size() == 0)
    cout << "NONE" << endl;//
  else {
    for (int i=0;i<res.size();i++) {
      cout << res[i].first << " " << res[i].second << endl;//
    }
  }
  return 0;
}
