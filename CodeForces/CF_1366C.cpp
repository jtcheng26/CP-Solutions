#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, m;
int matrix[31][31];
int cnt[62][2]; // 0s and 1s at a certain distance away from 0,0
bool visited[31][31];
int path = 0; // length of whole path

void bfs(int row, int col) {
  if (visited[row][col]) return;
  visited[row][col] = true;
  int right = col + 1;
  int down = row + 1;
  if (right < m) bfs(row, right);
  if (down < n) bfs(down, col);
  if (path % 2 == 1 && row + col == path / 2) return;
  cnt[row + col][matrix[row][col]]++;
}

int solve() {
  int res = 0;
  for (int i=0;i<n+m;i++) cnt[i][0] = cnt[i][1] = 0;
  for (int i=0;i<n;i++) for (int j=0;j<m;j++) visited[i][j] = false;
  path = n + m - 1;
  bfs(0, 0);
  for (int i=0;i<(n+m)/2;i++) {
    int zeroes = cnt[i][0] + cnt[n+m - i - 2][0];
    int ones = cnt[i][1] + cnt[n+m - i - 2][1];
    //cout << "dist " << i << ": " << zeroes << " " << ones << endl;
    res += min(zeroes, ones);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
      cin >> matrix[i][j];
    cout << solve() << endl;
  }
  return 0;
}
