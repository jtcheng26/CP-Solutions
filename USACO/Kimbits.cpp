/*
   LANG: C++11
   PROG: kimbits
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

typedef long long ll;
typedef unsigned int ui;

using namespace std;

ui n, l, k;
string res = "";
int arr[32][32];

void sch(int bits, int ones, int cnt) {
  if (bits == 0) return;
  ll s = arr[bits-1][ones];
  if (s <= cnt) {
    res += "1";
    sch(bits-1, ones-1, cnt - s);
  }
  else {
    res += "0";
    sch(bits-1, ones, cnt);
  }
}

string solve() {
  for (int j=0;j<=l;j++)
    arr[0][j] = 1;
  for (int i=1;i<=n;i++) {
    arr[i][0] = 1;
    for (int j=1;j<=l;j++) {
      if (j > i) {
        arr[i][j] = arr[i][j-1];
        continue;
      }
      arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
    }
  }
  sch(n, l, k - 1);
  return res;
}

int main() {
  ofstream cout ("kimbits.out");
  ifstream cin ("kimbits.in");
  cin >> n >> l >> k;
  cout << solve() << endl;
  return 0;
}
