#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll n, k, x;

int should_turn(ll r, ll c) {
  if (r < x) return 0;
  if (r == x) {
    if (k - (r+1) >= 2 * r + 1) return 0;
  }
  ll cnt = 0;
  cnt = (((r - 1) + x) * (r - x)) / 2;
  if (k - (c + cnt + 2 * r + 1) >= 0) return 0;
  if (k - (c + cnt + r - x) > 0) return 2;
  return 1;
}

ll solve() {
  ll seconds = 0; ll curr = 0; ll rate = 0; int flag = 0;
  while (curr < k) {
    if (flag == 1) {
      if (should_turn(rate, curr) == 2) {
        flag = 2;
      } else {
        if (rate == x) flag = 2;
        else rate--;
      }
    }
    else if (flag == 0 && rate >= x) {
      flag = should_turn(rate, curr);
      if (flag == 0) rate++;
      else if (flag == 1) rate--;
    } else if (flag == 0) {
      rate++;
    } else {
      if (should_turn(rate, curr) == 1) {
        flag = 1;
        if (rate > x) rate--;
      }
    }
    curr += rate;
    seconds++;
  }
  return seconds;
}

int main() {
  ofstream fout ("race.out");
  ifstream fin ("race.in");
  fin >> k >> n;
  for (int i=0;i<n;i++) {
    fin >> x;
    fout << solve() << endl;
  }
  return 0;
}
