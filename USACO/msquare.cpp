/*
   LANG: C++11
   PROG: msquare
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 100000007

typedef long long ll;

using namespace std;

map<string, int> seen;
string res;

struct sqr {
  int nums[8]; string seq;

  void init(int* curr, string s) {
    for (int i=0;i<8;i++) {
      nums[i] = curr[i];
    }
    seq = s;
  }

  bool valid(int* goal) {
    for (int i=0;i<8;i++) {
      if (nums[i] != goal[i]) return false;
    }
    return true;
  }

  void flip(int* temp) {
    for (int i=0;i<8;i++) {
      temp[i] = nums[7 - i];
    }
  }

  void shft(int* temp) {
    temp[0] = nums[3];
    for (int i=1;i<4;i++) {
      temp[i] = nums[i-1];
    }
    temp[7] = nums[4];
    for (int i=6;i>=4;i--) {
      temp[i] = nums[i+1];
    }
  }

  void rot(int* temp) {
    for (int i=0;i<8;i++) temp[i] = nums[i];
    temp[1] = nums[6];
    temp[2] = nums[1];
    temp[5] = nums[2];
    temp[6] = nums[5];
  }
};

string conv(sqr s) {
  string c = "";
  int n = 0;
  for (int i=0;i<8;i++) {
    n += s.nums[i] * pow(10, 7 - i);
  }
  return to_string(n);
}

void sch(int* curr, int* goal) {
  string seq = "";
  sqr one;
  one.init(curr, seq);
  queue<sqr> q;
  q.push(one);
  int cnt = 0;
  while (q.size() > 0) {
    sqr s = q.front();
    q.pop();
    string con = conv(s);
    if (seen[con]) continue;
    cnt++;
    seen[con]++;
    if (s.valid(goal)) {
      res = s.seq;
      break;
    }
    int anums[8]; int bnums[8]; int cnums[8];
    s.flip(anums);
    s.shft(bnums);
    s.rot(cnums);
    sqr a, b, c;
    a.init(anums, s.seq + "A");
    b.init(bnums, s.seq + "B");
    c.init(cnums, s.seq + "C");
    if (!seen[conv(a)]) q.push(a);
    if (!seen[conv(b)]) q.push(b);
    if (!seen[conv(c)]) q.push(c);
  }
}

string solve(int* goal) {
  int curr[8];
  for (int i=0;i<8;i++) {
    curr[i] = i+1;
  }
  sch(curr, goal);
  return res;
}

int main() {
  ofstream cout ("msquare.out");
  ifstream cin ("msquare.in");
  int target[8];
  for (int i=0;i<8;i++) {
    cin >> target[i];
  }
  string res = solve(target);
  cout << res.length() << endl;
  int i = 0;
  while (i < res.length()) {
    while(i<min(int(res.length()) - 1, 59)) {
      cout << res[i];
      i++;
    }
    cout << res[i++] << endl;
  }
  if (res.length() == 0)
    cout << "" << endl;
  return 0;
}
