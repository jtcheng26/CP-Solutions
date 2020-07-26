/*
   LANG: C++14
   PROG: castle
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

struct wall_to_rem {
  int r; int c; string d;
};

int n, m, a; // inputs: w, h, adj val
int r, s, l; // outputs: rooms, max size, rem size
wall_to_rem w;

vector<vector<int> > mods; // [vertex][neighbors]
vector<int> comps; // components
vector<int> comp_sizes;

void flood_fill(int comp) {
  int visited = 0;
  do {
    visited = 0;
    for (int i=0;i<mods.size();i++) {
      if (comps[i] == -1) {
        comps[i] = comp;
        comp_sizes[comp]++;
        for (int j=0;j<mods[i].size();j++) {
          visited++;
          if (comps[mods[i][j]] == -2)
            comps[mods[i][j]] = -1;
        }
      }
    }
  } while (visited > 0);
  if (comp_sizes[comp] > s)
    s = comp_sizes[comp];
}

int ff() {
  int comp = 0;
  comps.resize(n*m);
  for (int i=0;i<mods.size();i++) {
    comps[i] = -2;
  }
  for (int i=0;i<comps.size();i++) {
    if (comps[i]==-2) {
      comps[i] = -1;
      comp_sizes.resize(comp_sizes.size()+1);
      flood_fill(comp++);
    }
  }
  return comp;
}

bool tie_break(int r, int c, string d) {
  if (c < w.c)
    return true;
  if (c > w.c)
    return false;
  if (c == w.c) {
    if (r > w.r)
      return true;
    if (r < w.r)
      return false;
    if (w.d == "N")
      return false;
  }
  return true;
}

void max_rem() {
  // horizontal pairs
  for (int i=0;i<m;i++) {
    for (int j=0;j<n-1;j++) {
      int k = i*n+j;
      if (find(mods[k].begin(), mods[k].end(), k+1) == mods[k].end()) {
        if (comps[k] != comps[k+1] && comp_sizes[comps[k]] + comp_sizes[comps[k+1]] >= l) {
          if (comp_sizes[comps[k]] + comp_sizes[comps[k+1]] == l && !tie_break(i+1, j+1, "E")) {
            continue;
          }
          //cout << i+1 << " " << j+1 << endl;
          l = comp_sizes[comps[k]] + comp_sizes[comps[k+1]];
          w.r = i+1; w.c = j+1; w.d = "E";
        }
      }
    }
  }
  // vertical pairs
  for (int i=0;i<n;i++) {
    for (int j=0;j<m-1;j++) {
      int k = i+n*j;
      if (find(mods[k].begin(), mods[k].end(), k+n) == mods[k].end()) {
        if (comps[k] != comps[k+n] && comp_sizes[comps[k]] + comp_sizes[comps[k+n]] >= l) {
          if (comp_sizes[comps[k]] + comp_sizes[comps[k+n]] == l && !tie_break(j+2, i+1, "N")) {
            continue;
          }
          //cout << j+2 << " " << i+1 << endl;
          l = comp_sizes[comps[k]] + comp_sizes[comps[k+n]];
          w.r = j+2; w.c = i+1; w.d = "N";
        }
      }
    }
  }
}

int solve() {
  r = ff();
  max_rem();
  return 0;
}

int main() {
  ofstream fout ("castle.out");
  ifstream fin ("castle.in");
  fin >> n >> m;//
  mods.resize(n*m);
  for (int i=0;i<n*m;i++) {
    fin >> a;
    a = 15 - a;
    if (a % 2 != 0) {
      mods[i].push_back(i-1);
      a -= 1;
    }
    if (a >= 8) {
      mods[i].push_back(i+n);
      a -= 8;
    }
    if (a >= 4) {
      mods[i].push_back(i+1);
      a -= 4;
    }
    if (a >= 2)
      mods[i].push_back(i-n);
    /*
    cout << i << ": " << endl;
    for (int j=0;j<mods[i].size();j++) {
      cout << mods[i][j] << endl;
    }
    */
  }
  solve();
  fout << r << endl;
  fout << s << endl;
  fout << l << endl;
  fout << w.r << " " << w.c << " " << w.d << endl;
  return 0;
}
