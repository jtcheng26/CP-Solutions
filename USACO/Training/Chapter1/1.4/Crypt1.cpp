/*
   LANG: C++14
   PROG: crypt1
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

bool check_size(int num, int size) {
  return to_string(num).length() == size;
}

bool check_digits(int a, vector<int> nums) {
  while (a > 0) {
    if (find(nums.begin(), nums.end(), a % 10) != nums.end()) {
      a /= 10;
    }
    else
      return false;
  }
  return true;
}

bool check(int a, int b, vector<int>nums) {
  int d = b / 10; int e = b % 10;
  if (check_size(a*e, 3) && check_size(a*d, 3) && (check_size(a*b, 4))) {
    if (check_digits(a*e, nums) && check_digits(a*d, nums) && check_digits(a*b, nums)) {
      return true;
    }
  }
  return false;
}

// size of nums has to be int [1, 9] since it is only digits
// as a result, a 5-layered loop is ok, as it only has a worse case of 9^5.
ll solve(vector<int> nums) {
  int res=0; int numa; int numb; int nsize = nums.size();
  for (int a=0;a<nsize;a++) {
    numa = 100 * nums[a];
    int tempa = numa;
    for (int b=0;b<nsize;b++) {
      numa = tempa + (10 * nums[b]);
      int tempb = numa;
      for (int c=0;c<nsize;c++) {
        numa = tempb + nums[c];
        for (int d=0;d<nsize;d++) {
          numb = 10 * nums[d];
          int tempc = numb;
          for (int e=0;e<nsize;e++) {
            numb = tempc + nums[e];
            if (check(numa, numb, nums))
              res++;
          }
        }
      }
    }
  }
  return res;
}

int main() {
  ofstream fout ("crypt1.out");
  ifstream fin ("crypt1.in");
  fin >> n;
  vector<int> nums;
  for (int i=0;i<n;i++) {
    int a; fin >> a;
    nums.push_back(a);
  }
  fout << solve(nums) << endl;
  return 0;
}
