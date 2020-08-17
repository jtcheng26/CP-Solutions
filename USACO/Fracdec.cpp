/*
   LANG: C++14
   PROG: fracdec
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <bitset>

typedef long long ll;

using namespace std;

int n, d;
int digits[100001] = {0};
int repeat = 0;
vector<int> rem;
bitset<1000001> fnd;

int solve() {
  int s = d * (n / d);
  int dig = 0;
  bool a = false; // skipping places
  if (n % d == 0) return 1;
  //cout << n << endl;
  int r = n;
  if (r / d > 9) {
    r = n - d * (n / d);
  }
  while (true) {
    if (fnd[r]) break;
    //cout << r << endl;
    if (!a) {
      fnd[r] = 1;
      rem.push_back(r);
    }
    a = false;
    if (r == 0) break;
    if (r / d == 0) {
      r *= 10;
      dig++;
      a = true;
      if (r / d == 0) a = false;
      continue;
    }
    digits[dig-1] = r / d;
    s = d * digits[dig-1];
    r -= s;
  }
  if (r == 0) repeat = 0;
  else repeat = dig - distance(rem.begin(), find(rem.begin(), rem.end(), r));
  //cout << dig << endl;
  //cout << dig << " " << repeat << endl;
  return dig;
}

int main() {
  ofstream cout ("fracdec.out");
  ifstream cin ("fracdec.in");
  cin >> n >> d;
  cout << (n / d) << ".";
  int len = to_string(n / d).length();
  int res = solve();
  for (int i=0;i<res - repeat - 1;i++) {
    cout << digits[i];
  }
  if (res - repeat > 0 && repeat == 0)
    cout << digits[res - repeat - 1] << endl;
  else if (res - repeat > 0)
    cout << digits[res - repeat - 1];
  if (repeat > 0) {
    cout << "(";
    int i;
    for (i=res - repeat;i<min((res-repeat) + 73 - len - (res - repeat), res-1);i++) {
      cout << digits[i];
    }
    if (i >= res-1) {
      cout << digits[res-1] << ")" << endl;
      i = res;
    } else {
      cout << digits[i] << endl;
      i++;
    }
    while (i < res) {
      int j;
      for (j=i;j<min(i+75, res-1);j++) {
        cout << digits[j];
      }
      if (j == res - 1 && res - i <= 75) {
        cout << digits[j] << ")" << endl;
        i = res;
      } else if (res - i == 76) {
        cout << digits[i] << endl;
        cout << ")" << endl;
      }
      else {
        cout << digits[j] << endl;
        i += 76;
      }
    }
  }
  return 0;
}
