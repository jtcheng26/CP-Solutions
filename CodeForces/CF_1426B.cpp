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
int tiles[101][5];

bool solve() {
  if (m % 2 != 0) return false;
  for (int i=0;i<n;i++) {
    if (tiles[i][1] == tiles[i][2]) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i=0;i<n;i++) {
      for (int j=0;j<4;j++)
        cin >> tiles[i][j];
    }
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}
