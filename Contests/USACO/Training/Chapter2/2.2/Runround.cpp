/*
   LANG: C++14
   PROG: runround
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

ll n; int l; int digits[10]; int ndigits[10]; int inc = 0;
vector<ll> nums;


ll to_num() {
  ll num = 0;
  for (int i=l-1;i>=0;i--) {
    //cout << digits[i] << endl;
    num += digits[i] * pow(10, l-i-1);
  }
  return num;
}
bool is_round() {
  int touched[9] = {0};
  int ndig = 0;
  for (int i=0;i<l;i++) {
    //cout << ndig << endl;
    ndig = ndig + digits[ndig] % l;
    if (ndig >= l)
      ndig -= l;
    touched[ndig]++;
  }
  for (int i=0;i<l;i++) {
    //cout << touched[i] << endl;
    if (touched[i] != 1)
      return false;
  }
  //cout << "T" << endl;
  nums.push_back(to_num());
  return true;
}

bool dfs(int curr) {
  if (curr == -1) {
    for (int i=0;i<l;i++) {
      //cout << digits[i];
      if (inc > 0 || digits[i] > ndigits[i])
        break;
      else if (inc == 0 && (digits[i] < ndigits[i] || (i == l-1 && digits[i] <= ndigits[i]))) {
        //cout << endl;
        return false;
      }
    }
    //cout << endl;
    return is_round();
  }
  for (int i=1;i<=9;i++) {
    bool flag = false;
    for (int j=curr+1;j<l;j++) {
      if (digits[j] == i)
        flag = true;
    }
    if (flag)
      continue;
    digits[curr] = i;
    dfs(curr-1);
  }
  return false;
}

ll solve() {
  for (int i=l-1;n>0;i--) {
    ndigits[i] = n % 10;
    digits[i] = n % 10;
    n /= 10;
  }
  while(nums.size() == 0 && l < 10) {
    dfs(l-1);
    l++;inc++;
  }
  sort(nums.begin(),nums.end());
  if (nums.size() == 0)
    return 0;
  //cout << nums.size() << endl;
  return nums[0];
}

int main() {
  ofstream fout ("runround.out");
  ifstream fin ("runround.in");
  fin >> n;//
  l = to_string(n).length();
  fout << solve() << endl;//
  return 0;
}
