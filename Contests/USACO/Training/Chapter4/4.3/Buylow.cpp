/*
   LANG: C++11
   PROG: buylow
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

struct bigNum {
  vector<int> digits;
  int numDigits = 1;
  void init() {
    digits.resize(500);
    digits[0] = 0;
  }
  void initAs(int num) {
    digits.resize(500);
    numDigits = 1; int dig;
    while (num > 0) {
      numDigits++;
      dig = num % 10;
      num /= 10;
      digits[numDigits-2] = dig;
    }
    numDigits-=1;
  }
  void add(bigNum b) {
    int carry = 0;
    int mxDig = max(numDigits, b.numDigits);
    for (int i=0;i<mxDig;i++) {
      int temp = digits[i];
      digits[i] = (digits[i] + b.digits[i] + carry) % 10;
      carry = (temp + b.digits[i] + carry) / 10;
    }
    if (carry > 0) {
      digits[mxDig] = carry;
      numDigits = mxDig + 1;
    } else numDigits = mxDig;
  }
  void setTo(bigNum b) {
    for (int i=0;i<b.numDigits;i++) digits[i] = b.digits[i];
    for (int i=b.numDigits;i<numDigits;i++) digits[i] = 0;
    numDigits = b.numDigits;
  }
  string toString() {
    string s = "";
    for (int i=numDigits-1;i>=0;i--) s += to_string(digits[i]);
    return s;
  }
};

int n;
int seqLen;
bigNum seqCnt;
int prices[5001];

int solve() {
  seqLen = 0;
  seqCnt.init();
  //cout << seqCnt.toString() << endl;
  set<int> prev[n]; // unique previous elements that give same subsequence length
  int dp[n]; // longest decreasing subsequence ending at index i
  bigNum cnt[n]; // alternative subsequences
  for (int i=0;i<n;i++) {
    dp[i] = 1;
    cnt[i].initAs(1);
    for (int j=i-1;j>=0;j--) { // r -> l and keep rightmost copy of elements
      if (prices[j] <= prices[i]) continue;
      if (dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        prev[i].clear();
        prev[i].insert(prices[j]);
        cnt[i].setTo(cnt[j]);
      } else if (dp[j] + 1 == dp[i] && prev[i].find(prices[j]) == prev[i].end()) {
        cnt[i].add(cnt[j]);
        prev[i].insert(prices[j]);
      }
    }
  }
  set<int> used;
  for (int i=n-1;i>=0;i--) {
    if (dp[i] > seqLen) {
      used.clear();
      used.insert(prices[i]);
      seqLen = dp[i];
      seqCnt.setTo(cnt[i]);
    } else if (dp[i] == seqLen && used.find(prices[i]) == used.end()) {
      seqCnt.add(cnt[i]);
      used.insert(prices[i]);
    }
  }
  return 0;
}

int main() {
  ofstream cout ("buylow.out");
  ifstream cin ("buylow.in");
  cin >> n;
  for (int i=0;i<n;i++) cin >> prices[i];
  solve();
  cout << seqLen << " " << seqCnt.toString() << endl;
  return 0;
}
