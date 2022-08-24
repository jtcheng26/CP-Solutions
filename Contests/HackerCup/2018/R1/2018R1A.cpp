#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define N 0
#define W 1
#define S 2
#define E 3
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
int arr[3][1001];
ll dp[3][1001][4];

ll sch(int from_r, int from_c, int from_d, int to_r, int to_c) {
  //cout << to_r << " " << to_c << " " << from_d << endl;
  if (dp[to_r][to_c][from_d] > -1) return dp[to_r][to_c][from_d];
  if (to_r == 1 && to_c == 0 && from_d == E) return 1;
  if (arr[to_r][to_c] == 1 || to_c < 0) return 0;
  if (to_r == 1 && from_d == E)
    dp[to_r][to_c][from_d] = (sch(to_r, to_c, S, 0, to_c) + sch(to_r, to_c, N, 2, to_c)) % MOD;
  else if (to_r == 1) {
    dp[to_r][to_c][from_d] = sch(to_r, to_c, E, 1, to_c - 1);
  } else if (to_r == 0) {
    if (from_d == S)
      dp[to_r][to_c][from_d] = sch(to_r, to_c, E, 0, to_c - 1);
    else if (from_d == E)
      dp[to_r][to_c][from_d] = sch(to_r, to_c, N, 1, to_c);
  } else if (to_r == 2) {
    if (from_d == N)
      dp[to_r][to_c][from_d] = sch(to_r, to_c, E, 2, to_c - 1);
    else if (from_d == E)
      dp[to_r][to_c][from_d] = sch(to_r, to_c, S, 1, to_c);
  }
  return dp[to_r][to_c][from_d];
}

ll solve() {
  if (n == 1) return 0;
  if (arr[0][0] == 1 || arr[1][0] == 1 || arr[1][1] == 1
  || arr[2][n-1] == 1 || arr[1][n-1] == 1 || arr[1][n-2] == 1)
    return 0;
  for (int a=0;a<3;a++)
  for (int b=0;b<n;b++)
  for (int c=0;c<4;c++)
    dp[a][b][c] = -1;
  return sch(1, n-1, E, 1, n-2);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream cin ("let_it_flow_input.txt");
  ofstream cout ("2018R1A.txt");
  int t;
  cin >> t;//
  for (int i=1;i<=t;i++) {
    cin >> n; string s;
    for (int j=0;j<3;j++) {
      cin >> s;
      for (int k=0;k<n;k++) {
        if (s[k] == '.') arr[j][k] = 0;
        else arr[j][k] = 1;
      }
    }
    cout << "Case #" << i << ": " << solve() << endl;//
  }
  return 0;
}
