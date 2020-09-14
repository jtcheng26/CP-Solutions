/*
   LANG: C++14
   PROG: milk3
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

vector<int> res;
vector<vector<int> > tried;
int cap[3] = {0};
int mb[3] = {0};
bool empty[3] = {true, true, false};

bool is_tried() {
  for (int i=0;i<tried.size();i++) {
    int j;
    for (j=0;j<3;j++) {
      if (tried[i][j] != mb[j]) break;
    }
    if (j == 3)
      return true;
  }
  return false;
}

int dfs(int depth) {
  if (depth > 100 || is_tried())
    return 2;
  vector<int> test;
  for (int i=0;i<3;i++)
    test.push_back(mb[i]);
  tried.push_back(test);
  if (mb[0] == 0) {
    //cout << mb[2] << endl;
    if (find(res.begin(), res.end(), mb[2]) == res.end())
      res.push_back(mb[2]);
  }
  for (int j=0;j<3;j++) {
    if (!empty[j]) {
      for (int k=0;k<3;k++) {
        if (k != j) {
          int tempj = mb[j]; int tempk = mb[k];
          if (cap[k] >= mb[j] + mb[k]) {
            empty[k] = false;
            empty[j] = true;
            mb[k] = mb[j] + mb[k];
            mb[j] = 0;
          } else {
            empty[k] = false;
            mb[j] = mb[j] - (cap[k] - mb[k]);
            mb[k] = cap[k];
          }
          //cout << mb[0] << " " << mb[1] << " " << mb[2] << endl;
          dfs(++depth);
          mb[j] = tempj; mb[k] = tempk;
          empty[j] = false; empty[k] = tempk > 0 ? false : true;
        }
      }
    }
  }
  return 0;
}

int solve() {
  dfs(4);
  return 0;
}

int main() {
  ofstream fout ("milk3.out");
  ifstream fin ("milk3.in");
  for (int i=0;i<3;i++) {
    fin >> cap[i];
  }
  mb[2] = cap[2];
  solve();
  sort(res.begin(), res.end());
  for (int i=0;i<res.size()-1;i++) {
    fout << res[i] << " ";
  }
  fout << res[res.size()-1] << endl;
  return 0;
}
