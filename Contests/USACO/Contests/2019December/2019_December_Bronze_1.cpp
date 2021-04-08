#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int n, k; int sessions[10][20]; int cow_rankings[21][10];

int solve() {
  int res = 0;
  for (int i=0;i<k;i++) {
    for (int j=0;j<n;j++) {
      cow_rankings[sessions[i][j]][i] = j+1;
      //cout << cow_rankings[sessions[i][j]][i] << endl;
    }
  }
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) {
        if (j != i) {
        int m;
        for (m=0;m<k;m++) {
          if (cow_rankings[i][m] > cow_rankings[j][m]) break;
        }
        if (m == k) res++;
      }
    }
  }
  return res;
}

int main() {
  ifstream fin ("gymnastics.in");
  ofstream fout ("gymnastics.out");
  fin >> k >> n;
  for (int i=0;i<k;i++) {
    for (int j=0;j<n;j++) {
      fin >> sessions[i][j];
    }
  }
  fout << solve() << endl;
  return 0;
}
