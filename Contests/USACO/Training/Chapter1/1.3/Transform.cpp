/*
   LANG: C++14
   PROG: transform
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int n;

bool check(vector<vector<char> > orig, vector<vector<char> > res) {
  for (int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      if (orig[i][j] != res[i][j])
        return false;
    }
  }
  return true;
}

vector<vector<char> > sqrotate(vector<vector<char> > sqr) {
  vector<vector<char> > rtres;
  for (int i=0;i<n;i++) {
    vector<char> row (n, 0);
    rtres.push_back(row);
  }
  for (int i=0;i<n;i++) {
    for (int j=n-1;j>=0;j--) {
      rtres[j][i] = sqr[i][n - j - 1];
    }
  }
  return rtres;
}

vector<vector<char> > reflect(vector<vector<char> > sqr) {
  vector<vector<char> > rfres;
  for (int i=0;i<n;i++) {
    vector<char> row (n, 0);
    rfres.push_back(row);
  }
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      rfres[i][j] = sqr[i][n-j-1];
    }
  }
  return rfres;
}

int solve(vector<vector<char> > orig, vector<vector<char> > sqr) {
  vector<vector<char> > p;
  for (int i=3;i>=1;i--) {
    p = orig;
    for (int j=0;j<i;j++)
      p = sqrotate(p);
    if (check(sqr, p))
      return 4 - i;
  }
  vector<vector<char> > pref;
  pref = reflect(orig);
  if (check(sqr, pref)) {
    return 4;
  }
  for (int i=3;i>=1;i--) {
    p = pref;
    for (int j=0;j<i;j++)
      p = sqrotate(p);
    if (check(sqr, p))
      return 5;
  }
  if (check(orig, sqr))
    return 6;
  return 7;
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    vector<vector<char> > orig, sqr;
    fin >> n;
    for (int i=0;i<n;i++) {
      vector<char> row;
      for(int j=0;j<n;j++) {
        char val;
        fin >> val;
        row.push_back(val);
      }
      orig.push_back(row);
    }
    for (int i=0;i<n;i++) {
      vector<char> row;
      for(int j=0;j<n;j++) {
        char val;
        fin >> val;
        row.push_back(val);
      }
      sqr.push_back(row);
    }
    fout << solve(orig, sqr) << endl;
    return 0;
}
