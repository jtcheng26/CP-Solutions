/*
   LANG: C++11
   PROG: fact4
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

ll n;

int solve() {
  ll f = 1; ll fives = 0; ll twos = 0;
  for (int i=2;i<=n;i++) {
    int j = i;
    while (j > 1 && j % 5 == 0) {
      fives++;
      j /= 5;
    }
    while (j > 1 && j % 2 == 0) {
      twos++;
      j /= 2;
    }
    f = (f * j) % 10;
  }
  for (int i=0;i<twos - fives;i++) {
    f = (f * 2) % 10;
  }
  return f;
}

int main() {
  ofstream cout ("fact4.out");
  ifstream cin ("fact4.in");
  cin >> n;
  cout << solve() << endl;
  return 0;
}
