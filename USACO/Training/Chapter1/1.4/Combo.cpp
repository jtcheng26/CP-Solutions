/*
   LANG: C++14
   PROG: combo
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


struct com {
  int a, b, c;
};

ll n; vector<com> combos;

bool cmp(com a, com b) {
  if (a.a == b.a && a.b == b.b && a.c == b.c)
    return true;
  return false;
}

bool check_for(com a) {
  for (int i=0;i<combos.size();i++) {
    if (cmp(combos[i], a))
      return true;
  }
  combos.push_back(a);
  return false;
}

bool check_combo(com c) {
  c.a = c.a < 1 ? n + c.a : c.a;
  c.b = c.b < 1 ? n + c.b : c.b;
  c.c = c.c < 1 ? n + c.c : c.c;
  c.a = c.a > n ? c.a - n: c.a;
  c.b = c.b > n ? c.b - n: c.b;
  c.c = c.c > n ? c.c - n: c.c;
  return !check_for(c);
}

int solve(com john, com master) {
  if (n < 6)
    return n * n * n;
  int res=0;
  for (int i=-2;i<=2;i++) {
    for (int j=-2;j<=2;j++) {
      for (int k=-2;k<=2;k++) {
        com c = {.a = john.a + i, .b = john.b + j, .c = john.c + k};
        if (check_combo(c)) {
          res++;
        }
        c.a = master.a + i;c.b = master.b + j;c.c = master.c + k;
        if (check_combo(c)) {
          res++;

        }
      }
    }
  }
  return res;
}

int main() {
  ofstream fout ("combo.out");
  ifstream fin ("combo.in");
  fin >> n; int a, b, c;
  com john; com master;
  fin >> a >> b >> c;
  john.a = a; john.b = b; john.c = c;
  fin >> a >> b >> c;
  master.a = a; master.b = b; master.c = c;
  fout << solve(john, master) << endl;
  return 0;
}
