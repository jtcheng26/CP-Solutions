#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll cap[3];
ll milk[3];

void solve() {
  int a = 1;
  for (int i=0;i<100;i++) {
    a = i % 3 == 2 ? -2 : 1;
    ll p = min(milk[i%3] + milk[i%3+a], cap[i%3+a]);
    milk[i%3] -= (p - milk[i%3+a]);
    milk[i%3+a] = p;
  }
}

int main() {
  ofstream fout ("mixmilk.out");
  ifstream fin ("mixmilk.in");
  fin >> cap[0] >> milk[0];
  fin >> cap[1] >> milk[1];
  fin >> cap[2] >> milk[2];
  solve();
  fout << milk[0] << endl;
  fout << milk[1] << endl;
  fout << milk[2] << endl;
  return 0;
}
