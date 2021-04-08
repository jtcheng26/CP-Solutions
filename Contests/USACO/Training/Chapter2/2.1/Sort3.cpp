/*
   LANG: C++14
   PROG: sort3
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

int n, a, b, c;
vector<int> nums;

int solve() {
  int res, ab, ac, ba, bc, ca, cb;
  res = ab = ac = ba = bc = ca = cb = 0;
  for (int i=0;i<a;i++) {
    if (nums[i] == 2)
      ab++;
    else if (nums[i] == 3)
      ac++;
  }
  for (int i=a;i<a+b;i++) {
    if (nums[i] == 3)
      bc++;
    else if (nums[i] == 1)
      ba++;
  }
  for (int i=a+b;i<a+b+c;i++) {
    if (nums[i] == 1)
      ca++;
    else if (nums[i] == 2)
      cb++;
  }
  int minab = min(ab, ba);
  int minac = min(ac, ca);
  int minbc = min(bc, cb);
  ab = ba -= minab;
  ac = ca -= minac;
  bc = cb -= minbc;
  int initial_swaps =  minab + minac + minbc;
  res += initial_swaps;
  //minab = min(ab, ba);
  //minac = min(ac, ca);
  //minbc = min(bc, cb);
  //ab = ba -= minab;
  //ac = ca -= minac;
  //bc = cb -= minbc;
  int cycle_swaps = 2 * max(ab, ac);
  res += cycle_swaps;
  //res += ab; res += ac; res += bc;
  return res;
}

int main() {
  ofstream fout ("sort3.out");
  ifstream fin ("sort3.in");
  fin >> n;//
  a = b = c = 0;
  int k;
  for (int i=0;i<n;i++) {
    fin >> k;
    if (k==1) a++;
    else if (k==2) b++;
    else c++;
    nums.push_back(k);
  }
  fout << solve() << endl;//
  return 0;
}
