/*
   LANG: C++11
   PROG: game1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int nums[101];
int ans[2];
ll dp[101][101][2]; // optimal points from  i to j if taking first/second

// inclusive
void sch(int beg, int end) {
  //cout << beg << " " << end << endl;
  if (beg == end) return;
  else if (end - beg == 1) {
    dp[beg][end][0] = max(nums[beg], nums[end]);
    dp[beg][end][1] = min(nums[beg], nums[end]);
  }
  else {
    if (dp[beg+1][end][0] == -1) sch(beg+1, end);
    if (dp[beg][end-1][0] == -1) sch(beg, end-1);
    if (dp[beg+1][end][1] + nums[beg] > dp[beg][end-1][1] + nums[end]) {
      dp[beg][end][0] = dp[beg+1][end][1] + nums[beg];
      dp[beg][end][1] = dp[beg+1][end][0];
    } else {
      dp[beg][end][0] = dp[beg][end-1][1] + nums[end];
      dp[beg][end][1] = dp[beg][end-1][0];
    }
  }
}

ll solve() {
  for (int i=0;i<n;i++)
  for (int j=0;j<n;j++)
    if (i == j) dp[i][j][0] = dp[i][j][1] = nums[i];
    else dp[i][j][0] = dp[i][j][1] = -1;
  sch(0, n-1);
  int turn = 0; // 0 = player 1, 1 = player 2
  int beg = 0, end = n-1;
  ans[0] = dp[beg][end][0];
  ans[1] = dp[beg][end][1];
  return 0;
}

int main() {
  ofstream cout ("game1.out");
  ifstream cin ("game1.in");
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> nums[i];
  }
  solve();
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}
