/*
   LANG: C++14
   PROG: zerosum
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

int n;
vector<string> ops;
vector<int> op;

void add_res() {
  string res = "";
  for (int i=1;i<n;i++) {
    string oper = " ";
    if (i < n) {
      if (op[i-1]==1) oper = "-";
      else if (op[i-1]==2) oper = "+";
    }
    res = res + to_string(i) + oper;
  }
  res = res + to_string(n);
  ops.push_back(res);
}

bool check_ans() {
  int nums[n+1];
  for (int i=1;i<=n;i++)
    nums[i] = i;
  for (int i=0;i<n-1;i++) {
    if (op[i] == 0) {
      int j = i;
      while(op[j] == 0 && j<n-1) {
        nums[i+1] = nums[i+1] * 10 + nums[j+2];
        nums[j+2] = 0;
        j++;
      }
      i = j;
    } else
      nums[i+2] = i+2;
  }
  /*
  for (int i=1;i<=n;i++) {
    cout << " " << nums[i];
  }
  cout << endl;
  */
  int ans = nums[1];
  for (int i=0;i<n-1;i++) {
    //cout << nums[i+2] << " ";
    //cout << op[i] << " ";
    if (op[i] == 0) continue;
    else if (op[i] == 1) ans -= nums[i+2];
    else ans += nums[i+2];
  }
  //cout << endl;
  //cout << ans << endl;
  return (ans == 0);
}

bool dfs(int num) {
  if (num == n-1) return check_ans();
  for (int i=0;i<3;i++) {
    op[num] = i;
    if (dfs(num+1)) add_res();
  }
  return false;
}

int solve() {
  op.resize(n-1);
  dfs(0);
  return 0;
}

int main() {
  ofstream fout ("zerosum.out");
  ifstream fin ("zerosum.in");
  fin >> n;
  solve();
  sort(ops.begin(), ops.end());
  for (int i=0;i<ops.size();i++) {
    fout << ops[i] << endl;
  }
  return 0;
}
