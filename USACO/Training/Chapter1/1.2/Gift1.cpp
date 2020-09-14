/*
  LANG: C++14
  PROG: gift1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map<string, int> nmap;

int solve(int m, int ng, string names[], string giver) {
  if (ng == 0) {
    nmap[giver] += m;
    return 0;
  }
  int res = m / ng;
  for (int i=0;i<ng;i++) {
    nmap[names[i]] += res;
  }
  nmap[giver] -= m;
  nmap[giver] += (m - (ng * res));
  return 0;
}

int main() {
    ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");
    int np, m, ng;
    fin >> np;
    string norder[np];
    for (int i=0;i<np;i++) {
      string name;
      fin >> name;
      nmap[name] = 0;
      norder[i] = name;
    }
    for (int i=0;i<np;i++) {
      string giver;
      fin >> giver; fin >> m; fin >> ng;
      string names[ng];
      for (int j=0;j<ng;j++) {
        fin >> names[j];
      }
      solve(m, ng, names, giver);
    }
    for (int i=0;i<np;i++) {
      fout << norder[i] << " " << nmap[norder[i]] << endl;
    }
    return 0;
}
