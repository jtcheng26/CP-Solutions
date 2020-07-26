/*
   LANG: C++14
   PROG: frac1
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

struct frac {
  int n; int d; float val;
};

vector<frac> nums;
int n;

bool cmp(frac a, frac b) {
  return (int)(a.val*100000) < (int)(b.val*100000);
}

frac reduce_frac(frac a) {
  int g = __gcd(a.n, a.d);
  if (g > 1) {
    a.n = a.n / g;
    a.d = a.d / g;
  }
  return a;
}

bool check_dup(frac num) {
  for (int i=1;i<nums.size();i++) {
    if (num.n == nums[i].n && num.d == nums[i].d) {
      return true;
    }
  }
  return false;
}

int solve() {
  frac z;
  z.n = 0; z.d = 1; z.val = 0;
  nums.push_back(z);
  for (int i=1;i<n;i++) {
    for (int j=i+1;j<=n;j++) {
      frac num;
      num.n = i; num.d = j; num.val = (float)((float) i / (float) j);
      num = reduce_frac(num);
      if (!check_dup(num))
        nums.push_back(num);
    }
  }
  frac o;
  o.n = 1; o.d = 1; o.val = 1;
  nums.push_back(o);
  sort(nums.begin(), nums.end(), cmp);
  return 0;
}

int main() {
  ofstream fout ("frac1.out");
  ifstream fin ("frac1.in");
  fin >> n;//
  solve();
  for (int i=0;i<nums.size();i++) {
    fout << nums[i].n << "/" << nums[i].d << endl;
  }
  return 0;
}
