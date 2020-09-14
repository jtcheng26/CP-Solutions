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
string cows[8] = {
  "Bessie",
  "Buttercup",
  "Belinda",
  "Beatrice",
  "Bella",
  "Blue",
  "Betsy",
  "Sue"
};
map<string, int> cow_indexes;
int cow_order[8];
vector<vector<int> > results;

void index_cows() {
  for (int i=0;i<8;i++) {
    cow_indexes[cows[i]] = i;
  }
}

bool follows_constraints(pair<int, int> * pairs) {
  for (int i=0;i<n;i++) {
    for (int j=0;j<8;j++) {
      //cout << cow_order[j];
      if (cow_order[j] == pairs[i].first) {
        if (j == 0) {
          if (cow_order[j+1] != pairs[i].second) return false;
        }
        else if (j == 7) {
          if (cow_order[j-1] != pairs[i].second) return false;
        }
        else if (cow_order[j+1] != pairs[i].second && cow_order[j-1] != pairs[i].second)
          return false;
      }
    }
    //cout << endl;
  }
  return true;
}

bool dfs(int num, pair<int, int> *pairs) {
  if (num == 8) return follows_constraints(pairs);
  for (int i=0;i<8;i++) {
    int j;
    for (j=0;j<num;j++) {
      if (cow_order[j] == i) break;
    }
    if (j != num) continue;
    cow_order[num] = i;
    if (dfs(num+1, pairs)) {
      vector<int> res;
      for (int c=0;c<8;c++) res.push_back(cow_order[c]);
      results.push_back(res);
    }
  }
  return false;
}

bool cmp(vector<int> a, vector<int> b) {
  string as, bs;
  as = bs = "";
  for (int i=0;i<a.size();i++) {
    as += cows[a[i]];
    bs += cows[b[i]];
  }
  return as < bs;
}

void solve(pair<int, int> * pairs) {
  dfs(0, pairs);
  //for (int i=0;i<n;i++) {
    //cout << pairs[i].first << " " << pairs[i].second << endl;
  //}
}

int main() {
  ofstream fout ("lineup.out");
  ifstream fin ("lineup.in");
  fin >> n;
  string temp;
  pair<int, int> cow_pairs[n];
  index_cows();
  string cow_a, cow_b;
  for (int j=0;j<n;j++) {
    fin >> cow_a;
    for (int i=0;i<4;i++) fin >> temp;
    fin >> cow_b;
    pair<int, int> cows(cow_indexes[cow_a], cow_indexes[cow_b]);
    cow_pairs[j] = cows;
  }
  solve(cow_pairs);
  //cout << results.size() << endl;
  sort(results.begin(), results.end(), cmp);
  for (int i=0;i<8;i++) {
    fout << cows[results[0][i]] << endl;
  }
  return 0;
}
