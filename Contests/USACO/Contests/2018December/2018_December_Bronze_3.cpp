#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll a[10];
ll b[10];
bool poss[2000] = {false};

ll solve() {
  poss[1000] = true;
  ll res = 1000; ll ans = 0;
  for (int i=0;i<10;i++) {
    res = 1000 - a[i];
    for (int j=0;j<10;j++) {
      if (!poss[res + b[j]])
        poss[res + b[j]] = true;
    }
    for (int j=i+1;j<10;j++) {
      for (int k=0;k<10;k++) {
        for (int m=k+1;m<10;m++) {
          if (!poss[res - a[j] + b[k] + b[m]])
            poss[res - a[j] + b[k] + b[m]] = true;
        }
      }
    }
  }
  for (int i=0;i<2000;i++) {
    if (poss[i]) {
      //cout << i << endl;
      ans++;
    }
  }
  return ans;
}

int main() {
  ofstream fout ("backforth.out");
  ifstream fin ("backforth.in");
  for (int i=0;i<10;i++) {
    fin >> a[i];
  }
  for (int i=0;i<10;i++) {
    fin >> b[i];
  }
  fout << solve() << endl;
  return 0;
}
