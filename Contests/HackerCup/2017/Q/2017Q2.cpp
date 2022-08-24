#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int n;
int w[101];

int solve() {
  int res = 0;
  sort(w, w+n);
  if (w[0] >= 50) return n;
  int l = 0; int r = n-1;
  while (l < r) {
    int weight = w[r];
    if (weight < 50) {
      int req = ceil(50.0 / (double)w[r]);
      //cout << weight << " " << req << endl;
      l += req - 2;
      if (l >= r) res--;
      l++;
    }
    r--;
    res++;
  }
  return res > 0 ? res : 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream fin ("lazy_loading_input.txt");
  ofstream fout ("2017Q2.txt");
  int t;
  fin >> t;//
  for (int i=1;i<=t;i++) {
    fin >> n;
    for (int j=0;j<n;j++) {
      fin >> w[j];
    }
    fout << "Case #" << i << ": " << solve() << endl;//
  }
  return 0;
}
