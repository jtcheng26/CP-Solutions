/*
   LANG: C++14
   PROG: sprime
*/
// Really proud of this one.
// Did it in about 10mins and knew exactly what to do the whole time.
// Feels really good to feel like your really learning something.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int n; ll num;
vector<ll> ribs;

bool isPrime(ll n) {
  if (n <= 3)
    return n > 1;
  else if (n % 2 == 0 || n % 3 == 0)
    return false;
  for (int i=5;i*i<=n;i+=6) {
    if (n % i == 0 || n % (i+2) == 0)
      return false;
  }
  return true;
}

void dfs(int d) {
  if (d==0) {
    num = 0;
    dfs(d+1);
  }
  else if (d > n)
    ribs.push_back(num);
  else {
    for (int i=1;i<=9;i++) {
      num *= 10; num += i;
      if (isPrime(num))
        dfs(d+1);
      num -= i; num /= 10;
    }
  }
}

int solve() {
  dfs(0);
  return 0;
}

int main() {
  ofstream fout ("sprime.out");
  ifstream fin ("sprime.in");
  fin >> n;
  solve();
  for (int i=0;i<ribs.size();i++) {
    fout << ribs[i] << endl;
  }
  return 0;
}
