#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 100000007

typedef long long ll;

using namespace std;

int n, m;
int arr[101][101];

int solve() {
  int res = 0;
  for (int i=0;i<m;i++) {
    if (arr[n-1][i] == 2)
      res++;
  }
  for (int i=0;i<n;i++) {
    if (arr[i][m-1] == 1)
      res++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  string s;
  while (t--) {
    cin >> n >> m;
    string s;
    for (int i=0;i<n;i++) {
      string s;
      cin >> s;
      for (int j=0;j<m;j++) {
        arr[i][j] = s[j] == 'R' ? 1 : 2;
        if (i == n-1 && j == m-1) arr[i][j] = 3;
      }
    }
    cout << solve() << endl;
  }
  return 0;
}
