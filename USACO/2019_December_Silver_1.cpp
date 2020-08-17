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

ll solve() {
  ll m = (n-1) % 16;
  ll k = n / 16;
  vector<ll> nums;
  for (int i=1;i<=30;i++) {
    if (i % 3 != 0 && i % 5 != 0)
      nums.push_back(i);
  }
  return (k * 30) + nums[m];
  return 0;
}

int main() {
  ofstream fout ("moobuzz.out");
  ifstream fin ("moobuzz.in");
  fin >> n;
  fout << solve() << endl;
  return 0;
}
